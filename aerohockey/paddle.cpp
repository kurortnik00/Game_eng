#include "paddle.hpp"

#define SCALE_FACTOR 0.70711

Paddle::Paddle (float radius, sf::Color color, sf::Vector2f position, float velocity,
                sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right) 
      : radius_ (radius), color_ (color), position_ (position), score_ (0), velocity_ (velocity), 
		up_ (up), down_ (down), left_ (left), right_ (right)
{
    current_velocity_ = sf::Vector2f(0.f, 0.f);
    stop();
    shape_.setRadius(radius_);
    shape_.setFillColor(color_);
    shape_.setPosition(position_);
}


void Paddle::handleInput()
{
	vx_ = 0;
	vy_ = 0;
    if (sf::Keyboard::isKeyPressed(up_))
    {
		vy_ -= velocity_;
    }
    if (sf::Keyboard::isKeyPressed(down_))
    {
		vy_ += velocity_;
    }
    if (sf::Keyboard::isKeyPressed(left_))
    {
		vx_ -= velocity_;
    }
    if (sf::Keyboard::isKeyPressed(right_))
    {
		vx_ += velocity_;
    }
	if ((vx_ != 0) && (vy_ != 0))
	{
		vx_ *= SCALE_FACTOR;
		vy_ *= SCALE_FACTOR;
	}
}


void Paddle::stop()
{
	vx_ = 0;
	vy_ = 0;
}

void Paddle::update (int width, int height, float delta)
{
	current_velocity_.x = vx_;
	current_velocity_.y = vy_;
    shape_.move(current_velocity_ * delta);
    position_ = shape_.getPosition();
    stop();
}


sf::CircleShape Paddle::shape()
{
    return shape_;
}


float Paddle::radius()
{
    return radius_;
}


sf::Vector2f & Paddle::position()
{
    return position_;
}


sf::Vector2f & Paddle::velocity()
{
    return current_velocity_;
}

unsigned Paddle::score()
{
	return score_;
}

void Paddle::scored()
{
	score_++;
}