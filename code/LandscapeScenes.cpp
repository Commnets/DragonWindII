#include "LandscapeScenes.hpp"

// ---
const int DragonTheRevenge::LandscapeScene1::_SWITCHTOSHOWWALLS [_NUMBERWALLS] = { 0, 1 };


// ---
void DragonTheRevenge::LandscapeScene::initialize ()
{
	setBackgroundMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDBACKGROUNDMAPID__);

	DRAGONWIND::PlayingScene::initialize ();
}

// ---
void DragonTheRevenge::LandscapeScene0::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE0MAPID__);

	DragonTheRevenge::LandscapeScene::initialize ();
}

// ---
void DragonTheRevenge::LandscapeScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1MAPID__);

	DragonTheRevenge::LandscapeScene::initialize ();

	setBackgroundMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWITHCAVEWORLDBKMAPID__);
	backgroundMap () -> initialize ();
	backgroundMap () -> stop ();

	_blockRemoveableActionBlocks = 
		std::vector <DRAGONWIND::SwitchVisibilityBetweenASetOfLayersActionBlock*> (_NUMBERWALLS);
	for (int i = 0; i < _NUMBERWALLS; i++)
	{
		_blockRemoveableActionBlocks [i] = 
			dynamic_cast <DRAGONWIND::SwitchVisibilityBetweenASetOfLayersActionBlock*> 
				(actionBlock (73000 + i)); // The base is 73000 in this screen...
		assert (_blockRemoveableActionBlocks [i]);
	}

	_gorilla = firstBadGuyType (__DRAGONWIND_KONGTYPEID__);
	assert (_gorilla);
	_gorillaActionBlock = actionBlockControlling (_gorilla);
	assert (_gorillaActionBlock);

	reStartAllOnOffSwitches ();
}

// ---
void DragonTheRevenge::LandscapeScene1::updatePositions ()
{
	DragonTheRevenge::LandscapeScene::updatePositions ();

	for (int i = 0; i < _NUMBERWALLS; i++)
		_blockRemoveableActionBlocks [i] -> activeSetOfLayers 
			(onOffSwitch (_SWITCHTOSHOWWALLS [i]) -> isOn () ? 0 : 1);

	// If the coin in the scene?
	// If it is, the gorilla should move close to it and leave the portal empty!
	if (isThingVisible (__DRAGONWIND_NINJATHINGCOINTYPE__) && _gorilla -> stepsMonitor () != NULL &&
		_gorilla -> stepsMonitor () -> id () != __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1GORILLAABID__)
	{
		_gorilla -> addControlStepsMonitor 
			(game () -> characterMonitorBuilder () -> monitorFor 
				(__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1GORILLAABID__, _gorilla));
		_gorillaActionBlock -> properties ()-> _monitorId = __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1GORILLAABID__;
	}
}

// ---
void DragonTheRevenge::LandscapeScene1::finalize ()
{
	DragonTheRevenge::LandscapeScene::finalize ();

	_blockRemoveableActionBlocks = 
		std::vector <DRAGONWIND::SwitchVisibilityBetweenASetOfLayersActionBlock*> ();

	_gorilla = NULL;
	_gorillaActionBlock = NULL;
}

// ---
void DragonTheRevenge::LandscapeScene1::explosionAround (DRAGONWIND::Shooting* sth, QGAMES::bdata rdx)
{
	DragonTheRevenge::LandscapeScene::explosionAround (sth, rdx);

	if ((sth -> centerPosition () - QGAMES::Position (__BD 264, __BD 1680, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWWALLS [0]) -> set (false);
	if ((sth -> centerPosition () - QGAMES::Position (__BD 1454, __BD 1680, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWWALLS [1]) -> set (false);
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::LandscapeScene1::OnOffSwitches)
{
	for (int i = 0; i < _NUMBERWALLS; i++)
		addOnOffSwitch (new QGAMES::OnOffSwitch 
			(DragonTheRevenge::LandscapeScene1::_SWITCHTOSHOWWALLS [i], true));
}

// ---
void DragonTheRevenge::LandscapeScene2::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE2MAPID__);

	DragonTheRevenge::LandscapeScene::initialize ();

	setBackgroundMap (__DRAGONWINDTHEREVENGE_CAVEWORLDBKMAPID__);
	backgroundMap () -> initialize ();
	backgroundMap () -> stop ();
}

// ---
void DragonTheRevenge::LandscapeScene3::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE3MAPID__);

	DragonTheRevenge::LandscapeScene::initialize ();

	setBackgroundMap (__DRAGONWINDTHEREVENGE_CAVEWORLDBKMAPID__);
	backgroundMap () -> initialize ();
	backgroundMap () -> stop ();
}

// ---
void DragonTheRevenge::LandscapeScene4::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE4MAPID__);

	DragonTheRevenge::LandscapeScene::initialize ();

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
void DragonTheRevenge::LandscapeScene4::finalize ()
{
	_badGuyEnergyLevel -> setVisible (false);
	_badGuyEnergyLevel -> unObserve (_mainBadGuy);
	_badGuyEnergyLevel = NULL;

	DragonTheRevenge::LandscapeScene::finalize ();
}

