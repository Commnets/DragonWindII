#include "Entities.hpp"

// ---
QGAMES::Entity* DragonTheRevenge::BadGuy::clone () const
{
	QGAMES::Entity* result = new DragonTheRevenge::BadGuy (_id, _forms, _data);

	result -> setMovements (movements ());
	result -> setAnimations (cloneAnimations ());
	result -> setStates (cloneStates ());

	return (result);
}

// ---
DRAGONWIND::BadGuy::StatesId DragonTheRevenge::BadGuy::statesIdForType (int t)
{
	DRAGONWIND::BadGuy::StatesId result;

	switch (t)
	{
		case __DRAGONWIND_DINOTYPEID__:
			result = __DRAGONWIND_DINOSTATESID__;
			break;
		
		case __DRAGONWIND_MALEZOMBIETYPEID__:
			result = __DRAGONWIND_MALEZOMBIESTATESID__;
			break;

		case __DRAGONWIND_FEMALEZOMBIETYPEID__:
			result = __DRAGONWIND_FEMALEZOMBIESTATESID__;
			break;

		default:
			result = DRAGONWIND::BadGuy::statesIdForType (t);
			break;
	}

	return (result);
}

// ---
QGAMES::Entity* DragonTheRevenge::FlockOfVultures::clone () const
{
	QGAMES::Entities eties;
	for (QGAMES::Entities::const_iterator i = _entities.begin (); i != _entities.end (); i++)
		eties [(*i).first] = (*i).second -> clone (); 
	
	QGAMES::Entity* result = new DragonTheRevenge::FlockOfVultures (_id, eties, _data);

	result -> setMovements (movements ());
	result -> setAnimations (cloneAnimations ());
	result -> setStates (cloneStates ());

	return (result);
}

// ---
void DragonTheRevenge::FlockOfVultures::initialize ()
{
	DRAGONWIND::FlockOfMonsters::initialize ();
}

// ---
void DragonTheRevenge::FlockOfVultures::finalize ()
{
	DRAGONWIND::FlockOfMonsters::finalize ();
}
