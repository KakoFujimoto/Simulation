#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"
#include "UI/TextInput.h"
#include <string>


class Renderer;
class Input;


class NameInputScene : public Scene
{
public:
	NameInputScene();
	void update(const Input& input) override;
	void draw(Renderer& renderer) override;
	void onEnter() override;
	const std::string& getResultName() const;

private:
	TextInput textInput_;
	int displayPosition_ = 
		GameConfig::NameInputSceneConfig::DisplayPosition;
	int displayPositionBelow_ =
		GameConfig::NameInputSceneConfig::DisplayPositionBelow;
	static constexpr int MaxNameLength =
		GameConfig::NameInputSceneConfig::MaxNameLength;
	int keyInputHandle_;
	std::string currentName_;
};