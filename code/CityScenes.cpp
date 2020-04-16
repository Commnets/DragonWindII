#include "CityScenes.hpp"

// ---
void DragonTheRevenge::CityScene::initialize ()
{
	setBackgroundMap (__DRAGONWINDTHEREVENGE_CITYWORLDBACKGROUNDMAPID__);

	DRAGONWIND::PlayingScene::initialize ();
}

// ---
void DragonTheRevenge::CityScene0::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE0MAPID__);

	DragonTheRevenge::CityScene::initialize ();
}

// ---
void DragonTheRevenge::CityScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE1MAPID__);

	DragonTheRevenge::CityScene::initialize ();

	// Get all monsters playing in the scene...
	_theBadGuysToKill = QGAMES::Entities ();
	std::vector <int> tM = { __DRAGONWIND_CATTYPEID__, __DRAGONWIND_DOGTYPEID__ };
	for (QGAMES::Entities::const_iterator i = characters ().begin (); i != characters ().end (); i++)
		if (dynamic_cast <DRAGONWIND::BadGuy*> ((*i).second) && 
			std::find (tM.begin (), tM.end (), ((DRAGONWIND::BadGuy*) ((*i).second)) -> definition () -> _type) != tM.end ())
			_theBadGuysToKill [(*i).first] = (*i).second; // The three elements to die...

	// Which are the layers involved in the moat?
	QGAMES::TiledMap* pM = dynamic_cast <QGAMES::TiledMap*> (activeMap ());
	assert (pM); // Just in case...
	_layersMoat [0] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Solid_Moat")));
	_layersMoat [1] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Base_Moat")));
	_layersMoat [2] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Liquid_Moat")));
	_layersMoat [3] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Base_LakeMoat")));
	assert (_layersMoat [0] && _layersMoat [1] && _layersMoat [2] && _layersMoat [3]);

	reStartAllOnOffSwitches ();

	showMoat (onOffSwitch (_SWITCHTOSHOWMOAT) -> isOn ());
}

// ---
void DragonTheRevenge::CityScene1::finalize ()
{
	DragonTheRevenge::CityScene::finalize ();

	_layersMoat = QGAMES::TileLayers ();
}

// ---
void DragonTheRevenge::CityScene1::updatePositions ()
{
	DragonTheRevenge::CityScene::updatePositions ();

	bool someAlive = false;
	for (QGAMES::Entities::const_iterator i = _theBadGuysToKill.begin (); 
			i != _theBadGuysToKill.end () && !someAlive; someAlive |= ((DRAGONWIND::BadGuy*) (*i++).second) -> isAlive ());
	if (!someAlive && onOffSwitch (_SWITCHTOSHOWMOAT) -> isOn ())
		onOffSwitch (_SWITCHTOSHOWMOAT) -> set (false); // All bad guys have died...

	if (isMoatVisible () && !onOffSwitch (_SWITCHTOSHOWMOAT) -> isOn ())
	{
		game () -> sound (__DRAGONWINDTHEREVENGE_OPENDOORSOUNDID__) -> play (-1);

		showMoat (false);
	}
}

// ---
bool DragonTheRevenge::CityScene1::isMoatVisible ()
{
	return (!_layersMoat [0] -> isVisible () &&	!_layersMoat [1] -> isVisible () &&
			_layersMoat [2] -> isVisible () && _layersMoat [3] -> isVisible ());
}

// ---
void DragonTheRevenge::CityScene1::showMoat (bool a)
{
	_layersMoat [0] -> setVisible (!a);
	_layersMoat [1] -> setVisible (!a);
	_layersMoat [2] -> setVisible (a);
	_layersMoat [3] -> setVisible (a);
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::CityScene1::OnOffSwitches)
{
	addOnOffSwitch (new QGAMES::OnOffSwitch (DragonTheRevenge::CityScene1::_SWITCHTOSHOWMOAT, true));
}

// ---
void DragonTheRevenge::CityScene2::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE2MAPID__);

	DragonTheRevenge::CityScene::initialize ();
}

// ---
void DragonTheRevenge::CityScene3::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE3MAPID__);

	DragonTheRevenge::CityScene::initialize ();

	DRAGONWIND::Game::Conf* cfg = dynamic_cast <DRAGONWIND::Game::Conf*> (game () -> configuration ());
	assert (cfg);

	QGAMES::TiledMap* pM = dynamic_cast <QGAMES::TiledMap*> (activeMap ());
	assert (pM); 
	QGAMES::PlatformTileLayer* bE = 
		dynamic_cast <QGAMES::PlatformTileLayer*> (pM -> layer (std::string ("Base_7Easy")));
	QGAMES::PlatformTileLayer* bM = 
		dynamic_cast <QGAMES::PlatformTileLayer*> (pM -> layer (std::string ("Base_7Medium")));
	QGAMES::PlatformTileLayer* bD = 
		dynamic_cast <QGAMES::PlatformTileLayer*> (pM -> layer (std::string ("Base_7Difficult")));
	assert (bE && bM && bD);

	// The most moveable layer visible will depend on the difficulty level too
	bE -> setVisible (cfg -> difficulty () == 0);
	bM -> setVisible (cfg -> difficulty () == 1);
	bD -> setVisible (cfg -> difficulty () == 2);
}

// ---
void DragonTheRevenge::CityScene4::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE4MAPID__);

	DragonTheRevenge::CityScene::initialize ();

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
void DragonTheRevenge::CityScene4::finalize ()
{
	_badGuyEnergyLevel -> setVisible (false);
	_badGuyEnergyLevel -> unObserve (_mainBadGuy);
	_badGuyEnergyLevel = NULL;

	DragonTheRevenge::CityScene::finalize ();
}
