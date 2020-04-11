#include "DessertScenes.hpp"

// ---
void DragonTheRevenge::DessertScene::initialize ()
{
	setBackgroundMap (__DRAGONWINDTHEREVENGE_DESSERTWORLDBACKGROUNDMAPID__);

	DRAGONWIND::PlayingScene::initialize ();
}

// ---
void DragonTheRevenge::DessertScene0::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE0MAPID__);

	DragonTheRevenge::DessertScene::initialize ();
}

// ---
void DragonTheRevenge::DessertScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE1MAPID__);

	DragonTheRevenge::DessertScene::initialize ();
}

// ---
void DragonTheRevenge::DessertScene2::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE2MAPID__);

	DragonTheRevenge::DessertScene::initialize ();
}

// ---
void DragonTheRevenge::DessertScene3::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE3MAPID__);

	DragonTheRevenge::DessertScene::initialize ();
}

// ---
void DragonTheRevenge::DessertScene4::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE4MAPID__);

	DragonTheRevenge::DessertScene::initialize ();

	assert (!_badGuys.empty ());
	_mainBadGuy = dynamic_cast <DRAGONWIND::BadGuy*> ((*_badGuys.begin ()).second);
	assert (_mainBadGuy);

	DRAGONWIND::Game* dG = dynamic_cast <DRAGONWIND::Game*> (game ());
	assert (dG);
	_badGuyEnergyLevel = dG -> badGuyEnergyLevelScoreObject ();
	assert (_badGuyEnergyLevel);

	_badGuyEnergyLevel -> observe (_mainBadGuy);
	_badGuyEnergyLevel -> setVisible (true);
}

// ---
void DragonTheRevenge::DessertScene4::finalize ()
{
	_badGuyEnergyLevel -> setVisible (false);
	_badGuyEnergyLevel -> unObserve (_mainBadGuy);

	DragonTheRevenge::DessertScene::finalize ();
}

