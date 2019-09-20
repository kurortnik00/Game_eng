#include "StdAfx.h"
#include "VisibleGameObject.h"

//Класс всех видимых объектов
VisibleGameObject::VisibleGameObject()
{
	_isLoaded = false;
}


VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)		//Простейшая загрузка спрайтов, загружается вся картинка целиком
{
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;

		
		_texture.loadFromImage(_image);

		sf::Sprite sprite;
		_sprite.setTexture(_texture);

		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

void VisibleGameObject::Update(sf::Event& event)
{

}

bool VisibleGameObject::getState()		//в дальнейшем может понадобится, возвращает состояние объекта: жив или мёртв, активен не активен. ТРебуется переопределение в дочернем классе
{
	return true;
}

sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}	

bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}

float VisibleGameObject::GetHeight() const
{
	return _sprite.getTexture()->getSize().y;
}

float VisibleGameObject::GetWidth() const
{
	return _sprite.getTexture()->getSize().x;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const		//Прямоугольник для просчитывания взаиможействия
{
	sf::Vector2u size = _sprite.getTexture()->getSize();
	sf::Vector2f position = _sprite.getPosition();

	return sf::Rect<float>(
		position.x - size.x / 2,
		position.y - size.y / 2,
		position.x + size.x / 2,
		position.y + size.y / 2
		);
}

void VisibleGameObject::Restart() {				//Для обновления игры, переопределяется в дочерних классах

}