#pragma once
#include "Scene/SceneManager.h"
#include "Graphic/Renderer.h"

class GameManager
{
public:
	void initialize();
	void update();
	void draw();

private:
	SceneManager sceneManager;
	Renderer renderer;
};