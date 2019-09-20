#include "StdAfx.h"
#include "PlayerPaddle.h"
#include "Game.h"

//Класс для примера, объекты этого класса это прямоугольники которые можно двигать влево вправо стрелками на клавиатуре. 

PlayerPaddle::PlayerPaddle() :
	_velocity(0)
{
	Load("images/paddle.png");
	assert(IsLoaded());

}


PlayerPaddle::~PlayerPaddle()
{
}


float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle::Update(sf::Event& event)
{
	

	if (event.key.code == sf::Keyboard::Left)
	{
		_velocity = -0.1f;
	}
	if (event.key.code == sf::Keyboard::Right)
	{
		_velocity = 0.1f;
	}

	if (event.key.code == sf::Keyboard::Down)
	{
		_velocity = 0.0f;
	}


	sf::Vector2f pos = this->GetPosition();
	
	if (pos.x  < GetSprite().getTexture()->getSize().x / 2)					//Проверка не вылаза за экран
	{
		_velocity = 0; 
		SetPosition(GetSprite().getTexture()->getSize().x / 2 + 0.1, pos.y);	//Если у края то находиться в милиметре(0,1) от края со скоростью 0 
	}

	if (pos.x > (Game::SCREEN_WIDTH - GetSprite().getTexture()->getSize().x / 2)) 	//Проверка не вылаза за экран
	{
		_velocity = 0; 
		SetPosition(Game::SCREEN_WIDTH - GetSprite().getTexture()->getSize().x / 2 - 0.1, pos.y);	//Если у края то находиться в милиметре(0,1) от края со скоростью 0 
	}

	
	GetSprite().move(_velocity, 0);
}

void PlayerPaddle::Restart() {		//Отцентровка с нулевой скоростью
	_velocity = 0.0f;
	SetPosition((1024 / 2) - 45, 700);
}