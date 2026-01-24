#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"


class Renderer;
class Input;

class EndingScene : public Scene
{
public:
	void update(const Input& input) override;
	void draw(Renderer& renderer) override;

};
