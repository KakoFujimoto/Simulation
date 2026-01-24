#include "GameManager.h"

void GameManager::initialize()
{

}

void GameManager::update()
{
	input.update();
	sceneManager.update(input);
}

void GameManager::draw()
{
	sceneManager.draw(renderer);
}