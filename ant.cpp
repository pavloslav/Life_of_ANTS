#include "ant.h"
#include "scene.h"

#include <cstdlib>
#include <algorithm>

Ant::Ant( std::shared_ptr<Scene> scene,
          int x,
          int y,
          const std::string& name,
          std::shared_ptr<Colony> col )
    :
      ColonyBlock( scene, x, y, name, col ),
      direction( right ),
      state( idle ),
      label( std::unique_ptr<Label>( new Label( mainScene->graphics, mainScene->graphics->smallFont, 0, 0, col->color, name ) ) )
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
        if ( (getY() < existingWho->getY() ) && ( direction != Block::down ) )
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
        }
    }
}

void Ant::action()
{   
    std::shared_ptr<Block> target = target_.lock();
    switch( state )
    {
    case idle :
        target_ = nearest( mainScene->food );
        if( distance(target_) < 50 )
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
            if( isOn( target_ ) )
            {
                mainScene->forgetFood( target_ );
                target_ = nearest( getColony()->bases );
                state = carringFoodHome;
            }
        }
        break;
    case carringFoodHome :
        if( isOn( target_ ) )
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
    mainScene->graphics->setColor( getColony()->color );
    SDL_Rect rect = Graphics::rect( getX(), getY(), 0.9, 0.9 );
    SDL_RenderDrawRect( mainScene->graphics->renderer, &rect );
    SDL_Point realPoint = mainScene->graphics->point( getX(), getY() );
    label->setXY( realPoint.x + 2, realPoint.y - 10 );
    label->draw();
}
