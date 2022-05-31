#include "Player.h"

void Player::initPromenne() {
	this->movementSpeed = 10.f;
}

void Player::initShape() {
	this->shape.setFillColor(sf::Color(CERVENA));
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setOutlineColor(sf::Color(BILA));
	this->shape.setOutlineThickness(1.f);
	/*
	LOG("Size = " << shape.getSize().x << "x  " << shape.getSize().y << "y\n");
	LOG("Position = "<<shape.getPosition().x<<"x  "<< shape.getPosition().y<<"y\n");
	LOG("GlobalBounds = " << shape.getGlobalBounds().height << " height  " << shape.getGlobalBounds().width << " width  "
		<< shape.getGlobalBounds().left << " left   " << shape.getGlobalBounds().top << " top\n");
		*/
}

Player::Player(float x, float y) {
	this->shape.setPosition(x, y);
	this->initPromenne();
	this->initShape();
}

Player::~Player() {

}

void Player::updateInput() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(0.f, -this->movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(0.f, this->movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->shape.move(-this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->shape.move(this->movementSpeed, 0.f);
	}
}


//Window bounds collisions

void Player::updateWindowBoundsCollisions(const sf::RenderTarget* target) {
	//Left
	if (shape.getGlobalBounds().left < 0.f) {
		this->shape.setPosition(0.f + shape.getOutlineThickness(), shape.getGlobalBounds().top + shape.getOutlineThickness());
		LOG("Left triggered\n");
	}
	//Right
	if (shape.getGlobalBounds().left + shape.getGlobalBounds().width > target->getSize().x) {
		this->shape.setPosition(target->getSize().x - shape.getGlobalBounds().width, shape.getGlobalBounds().top + shape.getOutlineThickness());
		LOG("Right triggered\n");
	}
	//Top
	if (shape.getGlobalBounds().top < 0.f) {
		this->shape.setPosition(shape.getGlobalBounds().left + shape.getOutlineThickness(), 0.f + shape.getOutlineThickness());
		LOG("Top triggered\n");
		shape.getGlobalBounds() = this->shape.getGlobalBounds();
	}
	//Bottom
	if (shape.getGlobalBounds().top + shape.getGlobalBounds().height > target->getSize().y) {
		this->shape.setPosition(shape.getGlobalBounds().left + shape.getOutlineThickness(), target->getSize().y - shape.getGlobalBounds().height);
		LOG("Bottom triggered\n");
	}
}



void Player::upate(const sf::RenderTarget* target) {

	this->updateInput();

	//do collisions
	this->updateWindowBoundsCollisions(target);
}

void Player::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
