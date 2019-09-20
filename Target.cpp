#include "StdAfx.h"
#include "Target.h"
#include "Game.h"

//Класс для примера, объекты класса спрайты которые уничтожаются по нажатию стрелки "влево"

Target::Target()
{
	Load("images/Target.png");
	assert(IsLoaded());
	isActive = true;

}

Target::~Target()
{
}

bool Target::getState()
{
	return isActive;
}

void Target::Update(sf::Event& event) {

	if (event.key.code == sf::Keyboard::Left)
	{
		isActive = false;
	}

}

