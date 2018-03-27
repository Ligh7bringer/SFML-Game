#include "panel.h"
#include "../../engine/src/system_renderer.h"
#include "../../engine/src/system_resources.h"
#include <engine.h>
#include "../Log.h"

using namespace sf;

/*
* A panel which displays a rectangle with a string centered in it.
*/

View currView;

//initialise everything needed
Panel::Panel(const Vector2f& pos, const Vector2f& size, const std::string& font) : _size(size), _position(pos) {
    _font = Resources::get<sf::Font>(font);
    _text.setFont(*_font);
    _text.setCharacterSize(32);
    _text.setFillColor(Color::Black);
    _text.setString("----");
    _text.setPosition(pos);
    _rect = RectangleShape(size);
    _rect.setPosition(pos);
    _rect.setFillColor(sf::Color(255,255,255,128));
    _isGUI = true;
}

void Panel::update(double dt) {
    //if panel is a GUI panel
    if(_isGUI) {
        //set the position
        _rect.setPosition(_position);
    }
}

//render the panel and the text
void Panel::render() {
    if(_isGUI) {
        //using a view seems to work better for GUI stuff
        currView = Engine::getCurrentView();
        View v = View(FloatRect(0, 0, currView.getSize().x, currView.getSize().y));
        Renderer::setView(v);
        Engine::GetWindow().draw(_rect);
        Engine::GetWindow().draw(_text);
        Renderer::setView(currView);
    } else {
        Renderer::queue(&_rect);
        Renderer::queue(&_text);
    }
}

//repositions the text so it is in the centre of the panel
void Panel::recentreText() {
    //get all needed dimensions and positions
    sf::Vector2f txtSize(_text.getGlobalBounds().width, _text.getGlobalBounds().height);
    sf::Vector2f containerSize(_rect.getGlobalBounds().width, _rect.getGlobalBounds().height);
    //global bounds contain transformations and translations which means the position will be correct
    //i.e. the text will always be in the view because the container is 
    sf::Vector2f containerPosition(_rect.getGlobalBounds().left, _rect.getGlobalBounds().top);

    //set position
    Vector2f newPos = (containerSize / 2.f) - (txtSize / 2.f) + containerPosition;
    newPos.y -= containerSize.y / 2.f;
    _text.setPosition(newPos);
}

//------ SETTERS ------
//sets the text displayed in the panel
void Panel::setText(const std::string& text) {
    _renderString = text;
    _text.setString(_renderString);
    //make sure the text is centered
    recentreText();
}

//sets non english string as the text
void Panel::setTextLocalised(const wchar_t* text) {
    _text.setString(text);
    //LOG(DEBUG) << text;
}

//sets the colour of the panel
void Panel::setPanelColour(const Color& colour) {
    _rect.setFillColor(colour);
}

//sets the colour of the text
void Panel::setTextColour(const Color& colour) {
    _text.setFillColor(colour);
}

//sets the position of the panel
void Panel::setPosition(const Vector2f& pos) {
    _rect.setPosition(pos);
    recentreText();
}

//sets the size of the text
void Panel::setTextSize(const int size) {
    _text.setCharacterSize(size);
}

//sets wheter the panel is a GUI panel or not
//if a panel is a GUI panel, then it "moves" with the view, i.e. it is always at a constant position within the view (e.g. the player HP)
//the enemy health bars are not GUI and they follow the enemies
void Panel::setGUI(bool value) {
    _isGUI = value;
}

FloatRect Panel::getBoundingBox() const {
    return _rect.getGlobalBounds();
}