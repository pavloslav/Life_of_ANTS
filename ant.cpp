#include "ant.h"

#include <cstdlib>
#include <algorithm>

#include "scene.h"
#include "app.h"

Ant::Ant( int x,
          int y,
          const std::string& name,
          std::shared_ptr<Colony> col )
    :
      ColonyBlock( x, y, name, col ),
      direction( right ),
      state( idle ),
      label( std::unique_ptr<Label>( new Label( App::getApp()->getGraphics()->smallFont, 0, 0, col->color, name ) ) )
{
}

Ant::~Ant()
{
}

void Ant::turnTo( std::weak_ptr<Block> who )
{
    std::shared_ptr<Block> existingWho( who.lock() );
    if( existingWho )
    {
       /* if ( (getY() < existingWho->getY() ) && ( direction != Block::down ) )
        {
            direction = Block::up;
        }
        else if ( (getY()>existingWho->getY()) && (direction != Block::up) )
        {
            direction = Block::down;
        }
        else if ( (getX()<existingWho->getX()) && (direction != Block::left) )
        {
            direction = Block::right;
        }
        else if ( (getX()>existingWho->getX()) && (direction != Block::right) )
        {
            direction = Block::left;
        }*/
        direction = ( existingWho->getPlace() - getPlace() ).norm();
    }
}

void Ant::action()
{   
    std::shared_ptr<Block> target = target_.lock();
    switch( state )
    {
    case idle :
        target_ = nearest( App::getApp()->getScene()->food );
        if( getPlace().distance(target->getPlace()) < 50 )
        {
            state = goingToFood;
        }
        else
        {
            target_.reset();
        }
        break;

    case goingToFood :
        if( (!target) || (rand()% 10) == 0 )//раз на 10 кроків "забуваємо", що робили, щоб перевірити, де їжа
        {
            state = idle;
            target_.reset();
        }
        else
        {
            if( getPlace() == target->getPlace() )
            {
                App::getApp()->getScene()->forgetFood( target_ );
                target_ = nearest( getColony()->bases );
                state = carringFoodHome;
            }
        }
        break;
    case carringFoodHome :
        if( getPlace() == target->getPlace() )
        {
            getColony()->score++;
            state = idle;
            target_.reset();
        }
        break;
    default:
        SDL_assert( false );
        break;
    }
    if( target )
    {
        turnTo( target_ );
    }
    step(direction);
}

void Ant::draw()
{
    std::shared_ptr<Graphics> graphics = App::getApp()->getGraphics();
    graphics->setColor( getColony()->color );
    SDL_Rect rect = Graphics::rect( getPlace(), ModelPoint(0.9, 0.9) );
    SDL_RenderDrawRect( graphics->renderer, &rect );

    SDL_Point realPoint = Graphics::point( getX(), getY() );
    label->setXY( realPoint.x + 2, realPoint.y - 10 );
    label->draw();
}
