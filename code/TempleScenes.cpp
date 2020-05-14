#include "TempleScenes.hpp"

const int DragonTheRevenge::TempleScene2::_SWITCHDOOROPEN [_NUMBERDOORS] = { 0, 1, 2 };

// ---
void DragonTheRevenge::TempleScene::initialize ()
{
	setBackgroundMap (__DRAGONWINDTHEREVENGE_TEMPLEWORLDBACKGROUNDMAPID__);

	DRAGONWIND::PlayingScene::initialize ();
}

// ---
void DragonTheRevenge::TempleScene0::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_TEMPLEWORLDSCENE0MAPID__);

	DragonTheRevenge::TempleScene::initialize ();
}

// ---
void DragonTheRevenge::TempleScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_TEMPLEWORLDSCENE1MAPID__);

	DragonTheRevenge::TempleScene::initialize ();
}

// ---
void DragonTheRevenge::TempleScene2::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_TEMPLEWORLDSCENE2MAPID__);

	DragonTheRevenge::TempleScene::initialize ();

	_doorActionBlocks = 
		std::vector <DRAGONWIND::MoveLinearASetOfLayersActionBlock*> (_NUMBERDOORS);
	for (int i = 0; i < _NUMBERDOORS; i++)
	{
		_doorActionBlocks [i] = 
			dynamic_cast <DRAGONWIND::MoveLinearASetOfLayersActionBlock*> (actionBlock (74005 + i));
		assert (_doorActionBlocks [i]);
	}

	reStartAllOnOffSwitches ();

	if (_ninja -> numberOfTypesInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) != 3)
		_ninja -> toSay (std::string ("The paper to open   doors are possible"),
			DRAGONWIND::DragonArtist::DialogProperties (__QGAMES_COURIER10WHITELETTERS__, 5, 10, 
				__QGAMES_SHADOWCOLOR__, __QGAMES_WHITECOLOR__, 255, __BD 1.5, 
				QGAMES::Vector (__BD -100, __BD -100, __BD 0)));

	onOffSwitch (_SWITCHDOOROPEN [0]) -> 
		set (_ninja -> numberOfTypesInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) > 0);
	onOffSwitch (_SWITCHDOOROPEN [1]) -> 
		set (_ninja -> numberOfTypesInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) > 1);
	onOffSwitch (_SWITCHDOOROPEN [2]) -> 
		set (_ninja -> numberOfTypesInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) > 2);
}

// ---
void DragonTheRevenge::TempleScene2::updatePositions ()
{
	DragonTheRevenge::TempleScene::updatePositions ();

	onOffSwitch (_SWITCHDOOROPEN [0]) -> 
		set (_ninja -> numberOfTypesInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) > 0);
	onOffSwitch (_SWITCHDOOROPEN [1]) -> 
		set (_ninja -> numberOfTypesInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) > 1);
	onOffSwitch (_SWITCHDOOROPEN [2]) -> 
		set (_ninja -> numberOfTypesInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) > 2);

	for (int i = 0; i < _NUMBERDOORS; i++)
	{
		if (onOffSwitch (_SWITCHDOOROPEN [i]) -> isOn ())
			_doorActionBlocks [i] -> toMoveForward ();
		else
			_doorActionBlocks [i] -> toMoveBackward ();
	}
}

// ---
void DragonTheRevenge::TempleScene2::finalize ()
{
	DragonTheRevenge::TempleScene::finalize ();

	_doorActionBlocks = 
		std::vector <DRAGONWIND::MoveLinearASetOfLayersActionBlock*> ();
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::TempleScene2::OnOffSwitches)
{
	for (int i = 0; i < _NUMBERDOORS; i++)
		addOnOffSwitch (new QGAMES::OnOffSwitch 
			(DragonTheRevenge::TempleScene2::_SWITCHDOOROPEN [i], true));
}
