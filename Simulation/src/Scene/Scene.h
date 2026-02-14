#pragma once

class Renderer;
class Input;
class SceneManager;


class Scene
{
protected:
	SceneManager* sceneManager_ = nullptr;
	virtual void end();

public:
	virtual ~Scene() = default;
	virtual void update(const Input& input) = 0;
	virtual void draw(Renderer& renderer) = 0;
	virtual void onEnter();
	bool isEnd() const;
	void setSceneManager(SceneManager* mgr)
	{
		sceneManager_ = mgr;
	}

private:
	bool isEnd_ = false;
};