#include "TextSprite.h"
#include "SpriteRendererManager.h"
#include "Sprite.h"
#include "Transform.h"
#include "Shader.h"
#include "HelperFunctions.h"
#include <algorithm>

TextSprite::TextSprite (std::string text, float x, float y, float z, Shader* nonDefaultShader) : GameObject (false)
{
	int w, h;
	SDL_Renderer* renderer = SDL_CreateRenderer (SpriteRendererManager::getInstance ()->m_mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode (renderer, SDL_BLENDMODE_BLEND);

	TTF_Init ();

	TTF_Font* Sans = TTF_OpenFont ("Game/Assets/Fonts/jott.ttf", 128); //this opens a font style and sets a size

	TTF_SizeText (Sans, text.c_str(), &w, &h);

	SDL_Color White = { 255, 255, 255, 0 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
	SDL_Color BG = { 255, 0, 0, 0 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Blended (Sans, text.c_str(), White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	GLuint titleTexture = SpriteRendererManager::getInstance ()->generateTexture (surfaceMessage);
	m_sprite = new Sprite (titleTexture);
	SpriteRenderer* spriteRenderer = new SpriteRenderer (this);
	Transform* transform = getTransform ();
	if (nonDefaultShader != nullptr)
	{
		m_shader = nonDefaultShader;
		spriteRenderer->setActiveShader (m_shader);
	}
	spriteRenderer->setActiveSprite (m_sprite);
	transform->setPosition (x, y, z);
	transform->setScale (w / (h / 2));
	addComponent<SpriteRenderer*> (spriteRenderer);
	SDL_FreeSurface (surfaceMessage);
}
