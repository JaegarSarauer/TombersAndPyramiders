#include "NetworkTestScene.h"
#include "GLHeaders.h"
#include "SpriteRendererManager.h"
#include "Shader.h"
#include "SharedConstants.h"
#include <iostream>
#include "Camera.h"
#include "MovingSquare.h"
#include "MiscSquare.h"
#include <vector>
#include "SpawnManager.h"
#include <SDL_ttf.h>
#include "SpriteRendererManager.h"
#include "TextSprite.h"
#include <math.h>
#include "InputManager.h"
#include "TextBox.h"
#include <memory>
#include "SettingsManager.h"

std::shared_ptr<TextBox> box;

NetworkTestScene::NetworkTestScene ()
{
}

void NetworkTestScene::onStart ()
{
	box = std::make_shared<TextBox> ();
}

void NetworkTestScene::onPause ()
{
}

void NetworkTestScene::onEnd ()
{

}

void NetworkTestScene::onUpdate (int ticks)
{
}