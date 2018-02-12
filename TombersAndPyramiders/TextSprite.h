#pragma once
#pragma once

#include "GameObject.h"
#include "Shader.h"
#include "Sprite.h"
#include <string>

//MenuSprite* TitleMenu("Title.png", x, y, scale = 1, nondefaultShader = nullptr);
class TextSprite : public GameObject
{
private:
	Shader* m_shader;
	Sprite* m_sprite;
public:
	TextSprite (std::string path, float x, float y, float z = 0.0f, Shader* nonDefaultShader = nullptr);
	//~SimpleSprite();
};