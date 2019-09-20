#pragma once

#include "VisibleGameObject.h"

class Target :
	public VisibleGameObject
{
public:
	Target();
	~Target();

	void Update(sf::Event& event);
	bool getState();


private:
	bool isActive;
	
};