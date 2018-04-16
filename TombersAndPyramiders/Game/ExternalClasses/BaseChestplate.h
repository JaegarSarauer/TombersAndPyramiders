/*===================================================================================*//**
	BaseChestplate
	
	Abstract class for a base chestplate

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseEquippableItem.h"

/*========================================================================================
	BaseChestplate	
========================================================================================*/
class BaseChestplate : public BaseEquippableItem, public std::enable_shared_from_this<BaseChestplate>
{
    /*----------------------------------------------------------------------------------------
		Static Fields
    ----------------------------------------------------------------------------------------*/
	public:
		const static float WOODEN_CHESTPLATE_DAMAGE_MULTIPLIER;
		const static float SILVER_CHESTPLATE_DAMAGE_MULTIPLIER;
		const static float GOLD_CHESTPLATE_DAMAGE_MULTIPLIER;

    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
	private:
		float m_damageMultiplier;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        explicit BaseChestplate() = delete;

		explicit BaseChestplate(float damageMultiplier);

		virtual ~BaseChestplate() {};

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		/**
			Returns the actual amount of damage the character should take after absorption 
			by the chestplate.
		*/
		virtual int calculateRealDamage(int damage);

	protected:
		std::shared_ptr<BaseItem> addSubclassToInventory();

	private:

};
