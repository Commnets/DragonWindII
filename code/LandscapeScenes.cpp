#include "LandscapeScenes.hpp"

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

	// Which are the layers involved in the contingency?
	QGAMES::TiledMap* pM = dynamic_cast <QGAMES::TiledMap*> (activeMap ());
	assert (pM); // Just in case...
	_layersLeftWall  [0] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("SolidRemoveable_Left")));
	_layersLeftWall  [1] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("BaseRemoveable_Left")));
	_layersRightWall [0] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("SolidRemoveable_Right")));
	_layersRightWall [1] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("BaseRemoveable_Right")));
	assert (_layersLeftWall [0] && _layersLeftWall [1] && 
			_layersRightWall [0] && _layersRightWall [1]);

	reStartAllOnOffSwitches ();

	showLeftWall (onOffSwitch (_SWITCHTOSHOWLEFTWALL) -> isOn ());
	showRightWall (onOffSwitch (_SWITCHTOSHOWRIGHTWALL) -> isOn ());
}

// ---
void DragonTheRevenge::LandscapeScene1::updatePositions ()
{
	DragonTheRevenge::LandscapeScene::updatePositions ();

	if (onOffSwitch (_SWITCHTOSHOWLEFTWALL) -> isOn () && !isLeftWallVisible ())
		showLeftWall (true);
	if (!onOffSwitch (_SWITCHTOSHOWLEFTWALL) -> isOn () && isLeftWallVisible ())
		showLeftWall (false);

	if (onOffSwitch (_SWITCHTOSHOWRIGHTWALL) -> isOn () && !isRightWallVisible ())
		showRightWall (true);
	if (!onOffSwitch (_SWITCHTOSHOWRIGHTWALL) -> isOn () && isRightWallVisible ())
		showRightWall (false);
}

// ---
bool DragonTheRevenge::LandscapeScene1::isLeftWallVisible ()
{
	return (_layersLeftWall [0] -> isVisible () && !_layersLeftWall [1] -> isVisible ());
}

// ---
bool DragonTheRevenge::LandscapeScene1::isRightWallVisible ()
{
	return (_layersRightWall [0] -> isVisible () && !_layersRightWall [1] -> isVisible ());
}

// ---
void DragonTheRevenge::LandscapeScene1::showLeftWall (bool a)
{
	_layersLeftWall [0] -> setVisible (a);
	_layersLeftWall [1] -> setVisible (!a);
}

// ---
void DragonTheRevenge::LandscapeScene1::showRightWall (bool a)
{
	_layersRightWall [0] -> setVisible (a);
	_layersRightWall [1] -> setVisible (!a);
}

// ---
void DragonTheRevenge::LandscapeScene1::explosionAround (const QGAMES::Position& pos, QGAMES::bdata rdx)
{
	DragonTheRevenge::LandscapeScene::explosionAround (pos, rdx);

	if ((pos - QGAMES::Position (__BD 264, __BD 1680, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWLEFTWALL) -> set (false);
	if ((pos - QGAMES::Position (__BD 1454, __BD 1680, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWRIGHTWALL) -> set (false);
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::LandscapeScene1::OnOffSwitches)
{
	addOnOffSwitch (new QGAMES::OnOffSwitch (DragonTheRevenge::LandscapeScene1::_SWITCHTOSHOWLEFTWALL, true));
	addOnOffSwitch (new QGAMES::OnOffSwitch (DragonTheRevenge::LandscapeScene1::_SWITCHTOSHOWRIGHTWALL, true));
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
}

// ---
void DragonTheRevenge::LandscapeScene4::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE4MAPID__);

	DragonTheRevenge::LandscapeScene::initialize ();
}
