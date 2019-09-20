#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Target.h"
#include "Timer.h"


void Game::Start(void)	//������������� ��������
{
	if (_gameState != Uninitialized) return;

	_mainWindow.create(sf::VideoMode(1200, 800), "Pang!");

	PlayerPaddle *player1 = new PlayerPaddle();
	player1->Load("images/padle.png");
	player1->SetPosition((1024 / 2) - 45, 700);
	_gameObjectManager.Add("Paddle1", player1);


	Target *tar1 = new Target();
	tar1->Load("images/target.png");
	tar1->SetPosition(500, 500);
	_gameObjectManager.Add("target1", tar1);

	Timer *time1 = new Timer();
	time1->Load("font/11583.ttf");
	_gameObjectManager.Add("timer1", time1);

	_gameState = Game::ShowingSplash;		//�������� � ��������

	while (!IsExiting())
	{
		GameLoop();
	}

	Game::_mainWindow.close();
}

bool Game::IsExiting()//��� ��������� GameLoop()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

sf::RenderWindow& Game::GetWindow()
{
	return Game::_mainWindow;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	
	switch (_gameState)
	{
		
		case Game::ShowingMenu:
		{
			ShowMenu();		
			break;
		}
		case Game::ShowingSplash:
		{
		
			ShowSplashScreen();
			break;
		}
		case Game::Playing:
		{
		
			_mainWindow.clear(sf::Color(0, 0, 0));

			
			_gameObjectManager.UpdateAll(currentEvent);		//��������� ��� �������
			_gameObjectManager.DrawAll(_mainWindow);		//������ ��� �������

			_mainWindow.display();

			if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape)		//����� �� ����� ���� � ���� �� ������� ESC
				{
					_gameState = Game::ShowingMenu;
					ShowMenu();
				}
			}
			break;
		}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);					//������ ����������� ���� ����������� �� ������� ����� �������
													
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);   //���������� �������� ������� "������", �.�. ��� ������ ������: ������ ��� ����� �� ����
																//������ ����������� ���� ����������� �� ������� ����� �� "������" ��� �������� ����
																	
	

	switch (result)
	{
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			_gameObjectManager.Get("timer1")->Restart();	//��������� ������� ������ ����
			_gameObjectManager.Get("Paddle1")->Restart();	//���������� ��������������
			break;
	}
}

GameObjectManager Game::_gameObjectManager;
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;




