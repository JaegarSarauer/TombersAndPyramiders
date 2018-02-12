#include "Textbox.h"
#include "MessageManager.h"
#include "TextSprite.h"
#include "InputManager.h"
#include <memory>

TextBox::TextBox () : GameObject(false) {
	inputString = "";
	textSprite = std::make_shared<TextSprite>("hey", 0, 0);
}

void TextBox::onStart () {
}

void TextBox::onUpdate (int ticks) {
	if (InputManager::getInstance ()->onKeyPressed (SDLK_1)) {
		updateText (inputString + '1');
	}
}

void TextBox::updateText (std::string newString) {
	inputString = newString;
	textSprite = std::make_shared<TextSprite> (newString, 0, 0);
}

void TextBox::onEnd () {
	MessageManager::unSubscribe ("MOUSE_DOWN", this->m_mousePressedListenerID);
}