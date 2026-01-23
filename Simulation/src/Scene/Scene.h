#pragma once

class Renderer;

class Scene
{
public:
	virtual ~Scene() = default;
	virtual void update() = 0;
	virtual void draw(Renderer& renderer) = 0;
};