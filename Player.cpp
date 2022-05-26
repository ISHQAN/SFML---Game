#include "Player.h"

void Player::initPromenne(){

}

void Player::initShape() {
	this->shape.setFillColor(sf::Color(CERVENA));
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setPosition(sf::Vector2f(100.f, 100.f));
	this->shape.setOutlineColor(sf::Color(BILA));
	this->shape.setOutlineThickness(2.f);
}

Player::Player() {
	this->initPromenne();
	this->initShape();
}

Player::~Player() {

}

void Player::upate() {

}

void Player::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
