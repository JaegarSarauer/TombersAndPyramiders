

#pragma once
#include "ComplexSprite.h"
#include "BasePilot.h"
#include "Character.h"

class NetworkCharacter : public Character
{
	/*----------------------------------------------------------------------------------------
	Instance Fields
	----------------------------------------------------------------------------------------*/
private:


	/*----------------------------------------------------------------------------------------
	Resource Management
	----------------------------------------------------------------------------------------*/
public:
	/** Default constructor. */
	explicit NetworkCharacter(BasePilot* basePilot, int networkingID);

	/*----------------------------------------------------------------------------------------
	Instance Getter Methods
	----------------------------------------------------------------------------------------*/
public:


	/*----------------------------------------------------------------------------------------
	Instance Setter Methods
	----------------------------------------------------------------------------------------*/
public:


	/*----------------------------------------------------------------------------------------
	Instance Methods
	----------------------------------------------------------------------------------------*/
public:
	void onUpdate(int ticks);

private:
};
