#include "SwagBall.h"

void SwagBall::initShape(const sf::RenderWindow& window) {
	this->shape.setRadius(static_cast<float>(rand() % 10+10));
	this->shape.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));


	this->shape.setPosition(sf::Vector2f(static_cast<float>(rand() % window.getSize().x - shape.getGlobalBounds().width),
		static_cast<float>(rand() % window.getSize().y - shape.getGlobalBounds().height)));


	this->shape.setOutlineThickness(1.f);
}

SwagBall::SwagBall(const sf::RenderWindow& window) {
	this->initShape(window);
}

SwagBall::~SwagBall() {

}

void SwagBall::update() {

}

void SwagBall::render(sf::RenderTarget& target) {
	target.draw(this->shape);
}
