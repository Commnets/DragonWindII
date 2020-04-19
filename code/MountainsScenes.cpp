#include "MountainsScenes.hpp"
		
const int DragonTheRevenge::MountainsScene0::_SWITCHTOSHOWSOLIDWALL [_NUMBERSOLIDS] = { 0, 1 };
const int DragonTheRevenge::MountainsScene1::_COUNTERSOLIDTOMOVE [_NUMBERSOLIDS] = { 0, 1, 2, 3 };
const int DragonTheRevenge::MountainsScene1::_SWITCHSOLIDMOVING [_NUMBERSOLIDS] = { 0, 1, 2, 3 };

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

	// The layers involved in the solid appearence are extraxted one by one...
	QGAMES::AdvancedTileLayers tL1;
	tL1 [0] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_2")));
	assert (tL1 [0]);
	QGAMES::AdvancedTileLayers tL2;
	tL2 [0] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_3")));
	assert (tL2 [0]);

	_solidLayers.resize (2);
	_solidLayers [0] = tL1;
	_solidLayers [1] = tL2;

	for (int i = 0; i < _NUMBERSOLIDS; i++)
		showSolidWall (i, onOffSwitch (_SWITCHTOSHOWSOLIDWALL [i]) -> isOn ());
}

// ---
void DragonTheRevenge::MountainsScene0::updatePositions ()
{
	DragonTheRevenge::MountainsScene::updatePositions ();

	for (int i = 0; i < _NUMBERSOLIDS; i++)
	{
		if (onOffSwitch (_SWITCHTOSHOWSOLIDWALL [i]) -> isOn () && !isSolidVisible (i))
			showSolidWall (i, true);
		if (!onOffSwitch (_SWITCHTOSHOWSOLIDWALL [i]) -> isOn () && isSolidVisible (i))
			showSolidWall (i, false);
	}
}

// ---
void DragonTheRevenge::MountainsScene0::finalize ()
{
	DragonTheRevenge::MountainsScene::finalize ();

	_solidLayers = std::vector <QGAMES::AdvancedTileLayers> ();
}

// ---
bool DragonTheRevenge::MountainsScene0::isSolidVisible (int s)
{
	assert (s >= 0 && s < _NUMBERSOLIDS);

	bool result = true;
	for (QGAMES::AdvancedTileLayers::const_iterator i = _solidLayers [s].begin ();
			i != _solidLayers [s].end () && result; result &= (*i++).second -> isVisible ());

	return (result);
}

// ---
void DragonTheRevenge::MountainsScene0::showSolidWall (int s, bool a)
{
	assert (s >= 0 && s < _NUMBERSOLIDS);

	for (QGAMES::AdvancedTileLayers::const_iterator i = _solidLayers [s].begin ();
			i != _solidLayers [s].end (); (*i++).second -> setVisible (a));
}

// ---
void DragonTheRevenge::MountainsScene0::explosionAround (const QGAMES::Position& pos, QGAMES::bdata rdx)
{
	DragonTheRevenge::MountainsScene::explosionAround (pos, rdx);

	if ((pos - QGAMES::Position (__BD 864, __BD 96, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWSOLIDWALL [0]) -> set (false);
	if ((pos - QGAMES::Position (__BD 1728, __BD 120, __BD 0)).module () < (rdx * __BD 2))
		onOffSwitch (_SWITCHTOSHOWSOLIDWALL [1]) -> set (false);
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::MountainsScene0::OnOffSwitches)
{
	for (int i = 0; i < _NUMBERSOLIDS; i++)
		addOnOffSwitch (new QGAMES::OnOffSwitch 
			(DragonTheRevenge::MountainsScene0::_SWITCHTOSHOWSOLIDWALL [i], true));
}

// ---
void DragonTheRevenge::MountainsScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE1MAPID__);

	DragonTheRevenge::MountainsScene::initialize ();

	QGAMES::TiledMap* pM = dynamic_cast <QGAMES::TiledMap*> (activeMap ());
	assert (pM); // Just in case...

	// The layers involved in the pillars movement...
	_solidLayers [0] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_1")));
	_solidLayers [1] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_2")));
	_solidLayers [2] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_3")));
	_solidLayers [3] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_4")));
	assert (_solidLayers [0] && _solidLayers [1] && _solidLayers [2]);

	reStartAllCounters ();
	reStartAllOnOffSwitches ();

	for (int i = 0; i < _NUMBERSOLIDS; i++)
		counter (_COUNTERSOLIDTOMOVE [i]) -> initialize 
			((int) (2.1 * (rand () % (game () -> framesPerSecond ()) + 1)), 0, true, true);

	for (int i = 0; i < _NUMBERSOLIDS; i++)
		movePillar (i, onOffSwitch (_SWITCHSOLIDMOVING [i]) -> isOn ());
}

// ---
void DragonTheRevenge::MountainsScene1::updatePositions ()
{
	for (int i = 0; i < _NUMBERSOLIDS; i++)
		if (onOffSwitch (_SWITCHSOLIDMOVING [i]) -> isOn () && !isPillarMoving (i))
			movePillar (i, true);

	DragonTheRevenge::MountainsScene::updatePositions ();

	for (int i = 0; i < _NUMBERSOLIDS; i++)
		onOffSwitch (_SWITCHSOLIDMOVING [i]) -> set (isPillarMoving (i));

	for (int i = 0; i < _NUMBERSOLIDS; i++)
	{
		if (!onOffSwitch (_SWITCHSOLIDMOVING [i]) -> isOn () &&
			counter (_COUNTERSOLIDTOMOVE [i]) -> isEnd ())
		{
			onOffSwitch (_SWITCHSOLIDMOVING [i]) -> set (true);

			counter (_COUNTERSOLIDTOMOVE [i]) -> initialize 
				((int) (1.1 * (rand () % (game () -> framesPerSecond ()) + 1)), 0, true, true);
		}
	}
}

// ---
void DragonTheRevenge::MountainsScene1::finalize ()
{
	DragonTheRevenge::MountainsScene::finalize ();

	_solidLayers = QGAMES::AdvancedTileLayers ();
}

// ---
bool DragonTheRevenge::MountainsScene1::isPillarMoving (int nP)
{
	assert (nP >= 0 && nP < _NUMBERSOLIDS);

	return (_solidLayers [nP] -> moves () &&
			!_solidLayers [nP] -> movement () -> hasFinished ());
}

// ---
void DragonTheRevenge::MountainsScene1::movePillar (int nP, bool m)
{
	assert (nP >= 0 && nP < _NUMBERSOLIDS);

	if (m)
	{
		QGAMES::Layer::MovementBehaviour* mov = _solidLayers [nP] -> movement ();
		assert (mov);
		mov -> initialize ();
	}

	_solidLayers [nP] -> setMove (m);
}

// ---
__IMPLEMENTCOUNTERS__ (DragonTheRevenge::MountainsScene1::Counters)
{
	for (int i = 0; i < _NUMBERSOLIDS; i++)
		addCounter (new QGAMES::Counter 
			(DragonTheRevenge::MountainsScene1::_COUNTERSOLIDTOMOVE [i], 
				(int) (QGAMES::Game::game () -> framesPerSecond () * 2.1), 0, true, true));
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::MountainsScene1::OnOffSwitches)
{
	for (int i = 0; i < _NUMBERSOLIDS; i++)
		addOnOffSwitch (new QGAMES::OnOffSwitch 
			(DragonTheRevenge::MountainsScene1::_SWITCHSOLIDMOVING [i], false));
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
	_badGuyEnergyLevel = NULL;

	DragonTheRevenge::MountainsScene::finalize ();
}

