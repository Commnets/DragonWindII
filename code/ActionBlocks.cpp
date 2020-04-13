#include "ActionBlolcks.hpp"
#include "Scenes.hpp"
#include "Defs.hpp"

// ---
DRAGONWIND::FlockOfMonsters* DragonTheRevenge::FlyingMonstersActionBlock::flock ()
{
	DRAGONWIND::FlockOfMonsters* result = NULL;

	DRAGONWIND::Game::Conf* cfg = dynamic_cast <DRAGONWIND::Game::Conf*> (game () -> configuration ());
	assert (cfg);
	assert (cfg -> difficulty () < 3); // Easy, Medium, Difficult

	switch (_properties -> _typeOfMonster)
	{
		case __DRAGONWINDTHEREVENGE_ACTIONBLOCKFMONSTERTYPEVULTURE__:
			result = dynamic_cast <DRAGONWIND::FlockOfMonsters*> 
				(game () -> entity (__DRAGONWINDTHEREVENGE_FLOACKOFVULTUREBASE__ + (cfg -> difficulty () << 1) + (rand () % 2)));
			break;

		case __DRAGONWINDTHEREVENGE_ACTIONBLOCKFMONSTERTYPEWASP__:
			result = dynamic_cast <DRAGONWIND::FlockOfMonsters*> 
				(game () -> entity (__DRAGONWINDTHEREVENGE_FLOACKOFWASPBASE__ + (cfg -> difficulty () << 1) + (rand () % 2)));
			break;

		case __DRAGONWINDTHEREVENGE_ACTIONBLOCKFMONSTERTYPEBAT__:
			result = dynamic_cast <DRAGONWIND::FlockOfMonsters*> 
				(game () -> entity (__DRAGONWINDTHEREVENGE_FLOACKOFBATBASE__ + (cfg -> difficulty () << 1) + (rand () % 2)));
			break;

		default:
			result = DRAGONWIND::FlyingMonstersActionBlock::flock ();
			break;
	}

	return (result);
}

// ---
DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::Properties::Properties 
		(const std::map <std::string, std::string>& dt)
	: _sToGoBack (2)
{
	if (dt.find (std::string (__DRAGONWINDTHEREVENGE_MEORLDSSCENE2BLOCKSECPARAMID__)) != dt.end ())
		_sToGoBack = __BD (std::atof ((*dt.find (__DRAGONWINDTHEREVENGE_MEORLDSSCENE2BLOCKSECPARAMID__)).second.c_str ()));
}

// ---
QGAMES::SetOfOpenValues 
	DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::Properties::asSetOfOpenValues () const
{
	QGAMES::SetOfOpenValues result;

	result.addOpenValue (0, QGAMES::OpenValue (_sToGoBack));

	return (result);
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::Properties::fromSetOfOpenValues 
	(const QGAMES::SetOfOpenValues& oV)
{
	assert (oV.existOpenValue (0));

	_sToGoBack = oV.openValue (0).bdataValue ();
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::initialize ()
{
	DRAGONWIND::SceneActionBlock::initialize ();

	DragonTheRevenge::MountainsScene2* scn = dynamic_cast <DragonTheRevenge::MountainsScene2*> (scene ());
	assert (scn);

	// Which are the layers involved in the contingency?
	QGAMES::TiledMap* pM = dynamic_cast <QGAMES::TiledMap*> (scn -> activeMap ());
	assert (pM); // Just in case...
	_lift [0] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Base_3")));
	_lift [1] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Base_4")));
	assert (_lift [0] && _lift [1]);
	
	_lift [0] -> setPosition (QGAMES::Position::_cero);
	_lift [0] -> setMove (false);
	_lift [1] -> setPosition (QGAMES::Position::_cero);
	_lift [1] -> setMove (false);

	reStartAllCounters ();
	reStartAllOnOffSwitches ();

	liftsToMove (onOffSwitch (_SWITCHLIFTSTOMOVE) -> isOn ());
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::updatePositions ()
{
	DRAGONWIND::SceneActionBlock::updatePositions ();

	if (isActive () && !areLiftsMoving ())
		liftsToMove (true);
	if (!isActive () && areLiftsMoving ())
		liftsToMove (false);
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::finalize ()
{
	DRAGONWIND::SceneActionBlock::finalize ();
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::liftsToMove (bool m)
{
	// TODO
}

// ---
bool DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::areLiftsMoving () const
{
	// TODO

	return (false);
}

// ---
__IMPLEMENTCOUNTERS__ (DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::Counters)
{
	addCounter (new QGAMES::Counter 
		(DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::_COUNTERTOGOBACK, 
			0 /** It will reset at initialize. */, 0, true, true));
}

// ---
__IMPLEMENTONOFFSWITCHES__ (DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::OnOffSwitches)
{
	addOnOffSwitch (new QGAMES::OnOffSwitch 
		(DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::_SWITCHLIFTSTOMOVE, false));
}
