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
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::setActive (bool a)
{
	DRAGONWIND::SceneActionBlock::setActive (a);

	if (a && !areLiftsMoving ())
		liftsToMove (true);
	if (!a && areLiftsMoving ())
		liftsToMove (false);
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
	_lift [0] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Base_3"))); // The ciclic lift
	_lift [1] = dynamic_cast <QGAMES::TileLayer*> (pM -> layer (std::string ("Base_4"))); // The one shoot lift
	assert (_lift [0] && _lift [1]);
	
	reStartAllCounters ();
	reStartAllOnOffSwitches ();

	onOffSwitch (_SWITCHLIFTSTOMOVE) -> set (initialActive ());
	liftsToMove (onOffSwitch (_SWITCHLIFTSTOMOVE) -> isOn ());
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::updatePositions ()
{
	DRAGONWIND::SceneActionBlock::updatePositions ();

	QGAMES::Layer::SetOfMovementsBehaviour* mBhv = 
		dynamic_cast <QGAMES::Layer::SetOfMovementsBehaviour*> (_lift [0] -> movement ());
	assert (mBhv);

	// The movement has already been defined as ciclic,
	// But the position has also to be moved back to the very benining before starting back the cycle.
	if (mBhv -> hasCurrentMovementFinished ())
		_lift [0] -> setPosition (QGAMES::Position::_cero);
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::finalize ()
{
	DRAGONWIND::SceneActionBlock::finalize ();

	_lift = QGAMES::TileLayers ();
}

// ---
void DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::liftsToMove (bool m)
{
	if (_lift.empty ())
		return; // Not defined yect, so nothing to do!

	assert (_lift.size () == _NUMBERLIFTS);

	_lift [0] -> setMove (m);
	_lift [1] -> setMove (m);

	// Some sound to indicate whether it moves or not...
}

// ---
bool DragonTheRevenge::MoveLiftsMountainsScene2ActionBlock::areLiftsMoving ()
{
	if (_lift.empty ())
		return (false); // Not defined yet, no moving is understood!

	assert (_lift.size () == _NUMBERLIFTS);

	return (_lift [0] -> moves () && _lift [1] -> moves ());
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
