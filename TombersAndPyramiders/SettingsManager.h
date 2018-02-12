#pragma once
#include "GameObject.h"

class SettingsManager : GameObject {
private:

public:
	SettingsManager ();
	void onStart ();
	void onUpdate (int ticks);
	void onEnd ();
};