#include "Defs.hpp"
#include "ActionBlolcks.hpp"

// ---
DRAGONWIND::FlockOfMonsters* DragonTheRevenge::FlyingMonstersActionBlock::flock ()
{
	DRAGONWIND::FlockOfMonsters* result = NULL;

	DRAGONWIND::Game::Conf* cfg = dynamic_cast <DRAGONWIND::Game::Conf*> (game () -> configuration ());
	assert (cfg);
	assert (cfg -> difficulty () < 3); // Easy, Medium, Difficult

	switch (_properties -> _typeOfMonster)
	{
		case __DRAGONWINDTHEREVENGE_ACTIONBLOCKFMONSTERTYPEVULTURE__: // Vulture...
			result = dynamic_cast <DRAGONWIND::FlockOfMonsters*> 
				(game () -> entity (__DRAGONWINDTHEREVENGE_FLOACKOFVULTUREBASE__ + (cfg -> difficulty () << 1) + (rand () % 2)));
			break;

		default:
			result = DRAGONWIND::FlyingMonstersActionBlock::flock ();
			break;
	}

	return (result);
}
