#include "SettingsManager.h"
#include "InputManager.h"

SettingsManager::SettingsManager () : GameObject (true) {

}

void SettingsManager::onStart () {
	SDL_CaptureMouse (SDL_TRUE);
}

void SettingsManager::onUpdate (int ticks) {
	if (InputManager::getInstance ()->onKeyReleased (SDLK_ESCAPE))
		SDL_CaptureMouse (SDL_WINDOW_MOUSE_CAPTURE ? SDL_FALSE : SDL_TRUE);
}

void SettingsManager::onEnd () {

}