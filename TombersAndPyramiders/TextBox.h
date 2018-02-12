#pragma once

#include "TextSprite.h"
#include "GameObject.h"
#include "SpriteRendererManager.h"

class TextBox : public GameObject
{
private:
	std::string inputString;
	int m_mousePressedListenerID; 
	std::shared_ptr<TextSprite> textSprite;

public:
	void TextBox::updateText (std::string newString);
	TextBox ();
	void onStart ();
	void onUpdate (int ticks);
	void onEnd ();
};