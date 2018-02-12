#include "InputManager.h"
#include "MessageManager.h"

InputManager* InputManager::s_instance;

InputManager* InputManager::getInstance()
{
	if (s_instance == NULL)
		s_instance = new InputManager();
	return s_instance;
}

bool InputManager::onKeyPressed(SDL_Keycode code)
{
	std::map<SDL_Keycode, KeyAction>::iterator it = m_keys.find(code);
	if (it != m_keys.end())
		return it->second == InputManager::KeyAction::PRESSED;
	return false;
}

bool InputManager::onKey(SDL_Keycode code)
{
	std::map<SDL_Keycode, KeyAction>::iterator it = m_keys.find(code);
	if (it != m_keys.end())
		return it->second != InputManager::KeyAction::NONE;
	return false;
}

bool InputManager::onKeyReleased(SDL_Keycode code)
{
	std::map<SDL_Keycode, KeyAction>::iterator it = m_keys.find(code);
	if (it != m_keys.end())
		return it->second == InputManager::KeyAction::RELEASED;
	return false;
}

InputManager::KeyAction InputManager::getKeyState(SDL_Keycode code)
{
	std::map<SDL_Keycode, KeyAction>::iterator it = m_keys.find(code);
	if (it != m_keys.end())
		return it->second;
	else
		return InputManager::KeyAction::NONE;
}

void InputManager::updateKeys()
{
	for (std::map<SDL_Keycode, KeyAction>::iterator it = m_keys.begin(); it != m_keys.end(); ++it)
	{
		if (it->second == InputManager::KeyAction::PRESSED)
			it->second = InputManager::KeyAction::HELD;
		if (it->second == InputManager::KeyAction::RELEASED)
			it->second = InputManager::KeyAction::NONE;
	}
}

void InputManager::handlePolledEvent(SDL_Event event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		std::map<std::string, void*> data;
		data["x"] = (void*)event.button.x;
		data["y"] = (void*)event.button.y;
		data["isDoubleClick"] = (void*)(event.button.clicks - 1);
		MessageManager::sendEvent ("MOUSE_DOWN", data);
	}
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		std::map<std::string, void*> data;
		data["x"] = (void*)event.button.x;
		data["y"] = (void*)event.button.y;
		data["isDoubleClick"] = (void*)(event.button.clicks - 1);
		MessageManager::sendEvent ("MOUSE_UP", data);
	}
	if (event.type == SDL_MOUSEMOTION) {
		std::map<std::string, void*> data;
		data["x"] = (void*)event.button.x;
		data["y"] = (void*)event.button.y;
		data["state"] = (void*)event.button.state;
		MessageManager::sendEvent ("MOUSE_MOVE", data);
		std::cout << event.button.state << std::endl;
	}

	if (event.type != SDL_KEYDOWN && event.type != SDL_KEYUP)
		return;
	SDL_Keycode code = event.key.keysym.sym;
	std::map<SDL_Keycode, KeyAction>::iterator it = m_keys.find(code);
	if (event.type == SDL_KEYDOWN)
		if (it == m_keys.end() || (it != m_keys.end() && it->second != InputManager::KeyAction::HELD))
			m_keys[code] = InputManager::KeyAction::PRESSED;
	if (event.type == SDL_KEYUP)
		if (it != m_keys.end() && it->second == InputManager::KeyAction::HELD)
			m_keys[code] = InputManager::KeyAction::RELEASED;
}