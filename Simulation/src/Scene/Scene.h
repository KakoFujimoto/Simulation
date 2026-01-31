#pragma once

class Renderer;
class Input;


class Scene
{
public:
	virtual ~Scene() = default;
	virtual void update(const Input& input) = 0;
	virtual void draw(Renderer& renderer) = 0;
	virtual void onEnter();
	bool isEnd() const;

protected:
	void end();

private:
	bool isEnd_ = false;
};