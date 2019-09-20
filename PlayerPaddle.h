#pragma once
#include "VisibleGameObject.h"

class PlayerPaddle :
	public VisibleGameObject
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update(sf::Event& event);
	void Restart();

	float GetVelocity() const;

private:
	float _velocity;  // -- left ++ right
};