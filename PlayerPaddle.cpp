#include "StdAfx.h"
#include "PlayerPaddle.h"
#include "Game.h"

//����� ��� �������, ������� ����� ������ ��� �������������� ������� ����� ������� ����� ������ ��������� �� ����������. 

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
	
	if (pos.x  < GetSprite().getTexture()->getSize().x / 2)					//�������� �� ������ �� �����
	{
		_velocity = 0; 
		SetPosition(GetSprite().getTexture()->getSize().x / 2 + 0.1, pos.y);	//���� � ���� �� ���������� � ���������(0,1) �� ���� �� ��������� 0 
	}

	if (pos.x > (Game::SCREEN_WIDTH - GetSprite().getTexture()->getSize().x / 2)) 	//�������� �� ������ �� �����
	{
		_velocity = 0; 
		SetPosition(Game::SCREEN_WIDTH - GetSprite().getTexture()->getSize().x / 2 - 0.1, pos.y);	//���� � ���� �� ���������� � ���������(0,1) �� ���� �� ��������� 0 
	}

	
	GetSprite().move(_velocity, 0);
}

void PlayerPaddle::Restart() {		//����������� � ������� ���������
	_velocity = 0.0f;
	SetPosition((1024 / 2) - 45, 700);
}