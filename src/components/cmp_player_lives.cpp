#include "cmp_player_lives.h"
#include <engine.h>

using namespace sf;

/*
* Component which handles the lives of the player and draws them on the screen.
*/

PlayerLivesComponent::PlayerLivesComponent(Entity* p, int maxLives) : Component(p), _maxLives(maxLives), _lives(_maxLives) {
    _panel = Panel(Vector2f(100.f, 32.f), Vector2f(0, 0), "DoctorSoos.ttf");
    _panel.setPanelColour(Color(192, 192, 192, 128));
}

//update positions of GUI stuff
void PlayerLivesComponent::update(double dt) {
    _panel.setText("HP " + std::to_string(_lives));
    _panel.update(dt);
}

void PlayerLivesComponent::render() {
    _panel.render();
}

//increases the number of lives by adding num to current lives
void PlayerLivesComponent::increaseLives(int num) {
    _lives += num;
    //make sure lives are not more than the set maximum
    if(_lives > _maxLives) {
        _lives = _maxLives;
    }
}

//decreases lives by num
void PlayerLivesComponent::decreaseLives(int num) {
    _lives -= num;
    //make sure lives are not less than zero
    if(_lives <= 0) { 
        //if they are 
        _lives = 0;
        //the player is dead
        _parent->setForDelete();
    }

    if(_lives <= 1) {
        _panel.setTextColour(Color(204, 0, 0));
    } else {
        _panel.setTextColour(Color(0, 0, 0));
    }
    
}

//returns lives
int PlayerLivesComponent::getLives() const {
    return _lives;
}
