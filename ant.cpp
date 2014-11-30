#include "ant.h"

#include <cstdlib>
#include <algorithm>

#include "scene.h"
#include "app.h"

Ant::Ant(const ModelPoint& location,
          const std::string& name,
          std::shared_ptr<Colony> col )
    :
      ColonyBlock( location, name, col ),
      direction( ModelPoint::right ),
      state( idle ),
      label( std::unique_ptr<Label>( new Label( App::getApp()->getGraphics()->smallFont, location, col->color, name ) ) )
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
        direction = ( existingWho->getPlace() - getPlace() ).norm();
    }
}

void Ant::action()
{   
    switch( state )
    {
    case idle :
    {
        target_ = nearest( App::getApp()->getScene()->food );
        auto target = target_.lock();
        if( target && ( getPlace().distance(target->getPlace()) < 50 ) )
        {
            state = goingToFood;
        }
        else
        {
            target_.reset();
            if( (rand()% 10) == 0 )
              direction = ModelPoint( rand() % 31 - 15, rand() % 31 - 15 ).norm();
        }
    }
        break;

    case goingToFood :
    {
        auto target = target_.lock();
        if( (!target) || (rand()% 10) == 0 )//раз на 10 кроків "забуваємо", що робили, щоб перевірити, де їжа
        {
            state = idle;
            target_.reset();
        }
        else
        {
            if( getPlace().distance( target->getPlace() ) < 1 )
            {
                App::getApp()->getScene()->forgetFood( target_ );
                target_ = nearest( getColony()->bases );
                state = carringFoodHome;
            }
        }
    }
        break;
    case carringFoodHome :
    {
        auto target = target_.lock();
        if( target && ( getPlace().distance( target->getPlace() ) < 1 ) )
        {
            getColony()->score++;
            state = idle;
            target_.reset();
        }
    }
        break;
    default:
        SDL_assert( false );
        break;
    }
    if( target_.lock() )
    {
        turnTo( target_ );
    }
    step(direction);
}

void Ant::step(const ModelPoint &shift)
{
    ModelPoint newPlace = getPlace() + shift;
    setPlace( App::getApp()->getScene()->map.projection( newPlace ) );
}

void Ant::draw()
{
    std::shared_ptr<Graphics> graphics = App::getApp()->getGraphics();
    graphics->setColor( getColony()->color );
    SDL_Rect rect = ScreenRectangle( getPlace(), ModelPoint(0.9, 0.9) );
    SDL_RenderDrawRect( graphics->renderer, &rect );

    label->setPlace( getPlace() );
    label->draw();
}
