#include "Timer.h"
#include <sstream>

//Класс для отрисовки таймера и засекания времени

Timer::Timer() :
	text("", font, 150)
{

	gameTimeClock.restart();
	text.setStyle(sf::Text::Bold);
	text.setPosition(50, 400);
}

Timer::~Timer() {

}

void Timer::Load(std::string filename) {
	font.loadFromFile(filename);
}

sf::Time Timer::GetTime() {
	return gameTimeClock.getElapsedTime();
}

void Timer::Draw(sf::RenderWindow & renderWindow) {
	float gameTime = gameTimeClock.getElapsedTime().asMilliseconds() / 1000.0;
	std::ostringstream timerStr;
	timerStr << gameTime;
	text.setString(timerStr.str());
	renderWindow.draw(text);
}

void Timer::Restart() {
	gameTimeClock.restart();
}
	