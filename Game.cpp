#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Target.h"
#include "Timer.h"


void Game::Start(void)	//инициализация объектов
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

	_gameState = Game::ShowingSplash;		//Начинаем с заставки

	while (!IsExiting())
	{
		GameLoop();
	}

	Game::_mainWindow.close();
}

bool Game::IsExiting()//для остановки GameLoop()
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

			
			_gameObjectManager.UpdateAll(currentEvent);		//Обновляет все объекты
			_gameObjectManager.DrawAll(_mainWindow);		//Рисует все объекты

			_mainWindow.display();

			if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape)		//Выход из сцены игры в меню по клавише ESC
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
	splashScreen.Show(_mainWindow);					//Внутри бесконечный цикл прерываемый по нажатию любой клавиши
													
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);   //Возврацает значение нажатой "кнопки", т.е. что делать дальше: Играть или выйти из игры
																//Внутри бесконечный цикл прерываемый по нажатию одной из "кнопок" или закрытию окна
																	
	

	switch (result)
	{
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			_gameObjectManager.Get("timer1")->Restart();	//Обнуления таймера начала игры
			_gameObjectManager.Get("Paddle1")->Restart();	//Оцентровка прямоугольника
			break;
	}
}

GameObjectManager Game::_gameObjectManager;
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;




