#include "MountainsScenes.hpp"

// ---
void DragonTheRevenge::MountainsScene::initialize ()
{
	setBackgroundMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDBACKGROUNDMAPID__);

	DRAGONWIND::PlayingScene::initialize ();
}

// ---
void DragonTheRevenge::MountainsScene0::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE0MAPID__);

	DragonTheRevenge::MountainsScene::initialize ();

	QGAMES::TiledMap* pM = dynamic_cast <QGAMES::TiledMap*> (activeMap ());
	assert (pM); // Just in case...
	_solidLayers [0] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_2")));
	_solidLayers [1] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_3")));
	assert (_solidLayers [0] && _solidLayers [1]);

	showSolid1Wall (onOffSwitch (_SWITCHTOSHOWSOLID1WALL) -> isOn ());
	showSolid2Wall (onOffSwitch (_SWITCHTOSHOWSOLID2WALL) -> isOn ());
}

// ---
void DragonTheRevenge::MountainsScene0::updatePositions ()
{
	DragonTheRevenge::MountainsScene::updatePositions ();

	if (onOffSwitch (_SWITCHTOSHOWSOLID1WALL) -> isOn () && !isSolid1Visible ())
		showSolid1Wall (true);
	if (!onOffSwitch (_SWITCHTOSHOWSOLID1WALL) -> isOn () && isSolid1Visible ())
		showSolid1Wall (false);

	if (onOffSwitch (_SWITCHTOSHOWSOLID2WALL) -> isOn () && !isSolid2Visible ())
		showSolid2Wall (true);
	if (!onOffSwitch (_SWITCHTOSHOWSOLID2WALL) -> isOn () && isSolid2Visible ())
		showSolid2Wall (false);
}

// ---
void DragonTheRevenge::MountainsScene0::explosionAround (const QGAMES::Position& pos, QGAMES::bdata rdx)
{
	DragonTheRevenge::MountainsScene::explosionAround (pos, rdx);

	if ((pos - QGAMES::Position (__BD 864, __BD 96, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWSOLID1WALL) -> set (false);
	if ((pos - QGAMES::Position (__BD 1728, __BD 120, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWSOLID2WALL) -> set (false);
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::MountainsScene0::OnOffSwitches)
{
	addOnOffSwitch (new QGAMES::OnOffSwitch 
		(DragonTheRevenge::MountainsScene0::_SWITCHTOSHOWSOLID1WALL, true));
	addOnOffSwitch (new QGAMES::OnOffSwitch 
		(DragonTheRevenge::MountainsScene0::_SWITCHTOSHOWSOLID2WALL, true));
}

// ---
void DragonTheRevenge::MountainsScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE1MAPID__);

	DragonTheRevenge::MountainsScene::initialize ();
}

// ---
void DragonTheRevenge::MountainsScene2::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE2MAPID__);

	DragonTheRevenge::MountainsScene::initialize ();
}

// ---
void DragonTheRevenge::MountainsScene3::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE3MAPID__);

	DragonTheRevenge::MountainsScene::initialize ();

	setBackgroundMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDLARGEWORLDBKMAPID__);
	backgroundMap () -> initialize ();
	backgroundMap () -> stop ();
}

// ---
void DragonTheRevenge::MountainsScene4::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE4MAPID__);

	DragonTheRevenge::MountainsScene::initialize ();

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
void DragonTheRevenge::MountainsScene4::finalize ()
{
	_badGuyEnergyLevel -> setVisible (false);
	_badGuyEnergyLevel -> unObserve (_mainBadGuy);

	DragonTheRevenge::MountainsScene::finalize ();
}

