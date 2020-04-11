#include "DarkforestScenes.hpp"

// ---
void DragonTheRevenge::DarkForestScene::initialize ()
{
	setBackgroundMap (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDBACKGROUNDMAPID__);

	DRAGONWIND::PlayingScene::initialize ();
}

// ---
void DragonTheRevenge::DarkForestScene0::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE0MAPID__);

	DragonTheRevenge::DarkForestScene::initialize ();

	// Which are the layers involved in the base movement?
	QGAMES::TiledMap* pM = dynamic_cast <QGAMES::TiledMap*> (activeMap ());
	assert (pM); // Just in case...
	_layersBase1 [0] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Base_2")));
	_layersBase1 [1] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_2")));
	_layersBase2 [0] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Base_3")));
	_layersBase2 [1] = dynamic_cast <QGAMES::AdvancedTileLayer*> (pM -> layer (std::string ("Solid_3")));
	assert (_layersBase1 [0] && _layersBase1 [1] && _layersBase2 [0] && _layersBase2 [1]);

	reStartAllCounters ();
	reStartAllOnOffSwitches ();
}

// ---
void DragonTheRevenge::DarkForestScene0::updatePositions ()
{
	DragonTheRevenge::DarkForestScene::updatePositions ();

	if (onOffSwitch (_SWITCHHOLE1VISIBLE) -> isOn ())
	{
		if (!_layersBase1 [0] -> isDisappearing () &&
			counter (_COUNTERTOSHOWDISAPPEARHOLE1) -> isEnd ())
		{
			_layersBase1 [0] -> disappear (game () -> framesPerSecond () / 6);
			_layersBase1 [1] -> disappear (game () -> framesPerSecond () / 6);
		}

		if (_layersBase1 [0] -> transparent (__BD 0))
			onOffSwitch (_SWITCHHOLE1VISIBLE) -> set (false);
	}
	else
	{
		if (!_layersBase1 [0] -> isAppearing () &&
			counter (_COUNTERTOSHOWDISAPPEARHOLE1) -> isEnd ())
		{
			_layersBase1 [0] -> appear (game () -> framesPerSecond () / 6);
			_layersBase1 [1] -> appear (game () -> framesPerSecond () / 6);
		}

		if (_layersBase1 [0] -> solid (__BD 1))
			onOffSwitch (_SWITCHHOLE1VISIBLE) -> set (true);
	}

	if (onOffSwitch (_SWITCHHOLE2VISIBLE) -> isOn ())
	{
		if (!_layersBase2 [0] -> isDisappearing () &&
			counter (_COUNTERTOSHOWDISAPPEARHOLE2) -> isEnd ())
		{
			_layersBase2 [0] -> disappear (game () -> framesPerSecond () / 6);
			_layersBase2 [1] -> disappear (game () -> framesPerSecond () / 6);
		}

		if (_layersBase2 [0] -> transparent (__BD 0))
			onOffSwitch (_SWITCHHOLE2VISIBLE) -> set (false);
	}
	else
	{
		if (!_layersBase2 [0] -> isAppearing () &&
			counter (_COUNTERTOSHOWDISAPPEARHOLE2) -> isEnd ())
		{
			_layersBase2 [0] -> appear (game () -> framesPerSecond () / 6);
			_layersBase2 [1] -> appear (game () -> framesPerSecond () / 6);
		}

		if (_layersBase2 [0] -> solid (__BD 1))
			onOffSwitch (_SWITCHHOLE2VISIBLE) -> set (true);
	}
}

// ---
__IMPLEMENTCOUNTERS__ (DragonTheRevenge::DarkForestScene0::Counters)
{
	addCounter (new QGAMES::Counter 
		(DragonTheRevenge::DarkForestScene0::_COUNTERTOSHOWDISAPPEARHOLE1, 
			(int) (QGAMES::Game::game () -> framesPerSecond () * 2.1) /** To avoid a little bit the "control" */, 0, true, true));
	addCounter (new QGAMES::Counter 
		(DragonTheRevenge::DarkForestScene0::_COUNTERTOSHOWDISAPPEARHOLE2, 
			(int) (QGAMES::Game::game () -> framesPerSecond () * 1.1) /** Idem */, 0, true, true));
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::DarkForestScene0::OnOffSwitches)
{
	addOnOffSwitch (new QGAMES::OnOffSwitch (DragonTheRevenge::DarkForestScene0::_SWITCHHOLE1VISIBLE, false));
	addOnOffSwitch (new QGAMES::OnOffSwitch (DragonTheRevenge::DarkForestScene0::_SWITCHHOLE2VISIBLE, false));
}

// ---
void DragonTheRevenge::DarkForestScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE1MAPID__);

	DragonTheRevenge::DarkForestScene::initialize ();
}

// ---
void DragonTheRevenge::DarkForestScene1::drawOn (QGAMES::Screen* s, const QGAMES::Position& p)
{
	int sW = s -> visualWidth ();
	int sH = s -> visualHeight ();

	DRAGONWIND::Game* g = dynamic_cast <DRAGONWIND::Game*> (game ());
	assert (g);
	DRAGONWIND::Ninja* n = dynamic_cast <DRAGONWIND::Ninja*> (g -> mainArtist ());
	assert (n);
	QGAMES::Position pN =
		n -> centerPosition () + (__BD 10 * n -> orientation ());
	int rdx = n -> carriesTypeInPocket (__DRAGONWIND_NINJATHINGPAPERTYPE__) ? 150 : 150;

	QGAMES::Mask* mask = new QGAMES::OUTCircleMask (10000 /* id */, 3,
			QGAMES::OUTCircleMask::Properties (rdx, QGAMES::Position 
				(pN.posX () / __BD sW, pN.posY () / __BD sH, __BD 0), __QGAMES_WHITECOLOR__), sW, sH);
	QGAMES::Mask* oMask = mask -> opposite ();

	QGAMES::Screen::Buffer* bA = mask -> bufferOver (s);			
	QGAMES::Screen::Buffer* gSA = s -> openBuffer (QGAMES::Screen::Buffer::_ADDBLENDMODE);
	DragonTheRevenge::DarkForestScene::drawOn (s, p);
	s -> drawRectangle (QGAMES::Rectangle 
		(QGAMES::Position (__BD 0, __BD 0, __BD 0), QGAMES::Position (__BD sW, __BD sH, __BD 0)), 
			QGAMES::Color (0, 0, 0, 220), true);
	bA -> moveToBuffer (gSA);
	s -> closeBuffer (gSA);

	QGAMES::Screen::Buffer* bB = oMask -> bufferOver (s);
	QGAMES::Screen::Buffer* gSB = s -> openBuffer (QGAMES::Screen::Buffer::_PUREBLENDMODE);
	DragonTheRevenge::DarkForestScene::drawOn (s, p);
	bB -> moveToBuffer (gSB);
	s -> closeBuffer (gSB);

	gSB -> moveToScreen ();
	gSA -> moveToScreen ();								
	
	delete (gSB);
	delete (gSA);

	delete (oMask);
	delete (mask);
}

// ---
void DragonTheRevenge::DarkForestScene2::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE2MAPID__);

	DragonTheRevenge::DarkForestScene::initialize ();

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
void DragonTheRevenge::DarkForestScene2::finalize ()
{
	_badGuyEnergyLevel -> setVisible (false);
	_badGuyEnergyLevel -> unObserve (_mainBadGuy);

	DragonTheRevenge::DarkForestScene::finalize ();
}

