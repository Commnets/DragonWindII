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
}

// ---
void DragonTheRevenge::DarkForestScene1::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE1MAPID__);

	DragonTheRevenge::DarkForestScene::initialize ();
}

// ---
void DragonTheRevenge::DarkForestScene2::initialize ()
{
	setMap (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE2MAPID__);

	DragonTheRevenge::DarkForestScene::initialize ();
}
