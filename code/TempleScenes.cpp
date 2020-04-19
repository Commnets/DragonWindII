#include "TempleScenes.hpp"

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
}
