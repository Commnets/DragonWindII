#include "Builders.hpp"
#include "Worlds.hpp"
#include "Scenes.hpp"
#include "Entities.hpp"
#include "Defs.hpp"

// ---
QGAMES::BadGuy* DragonTheRevenge::EntityBuilder::createBadGuy (const QGAMES::EntityBuilder::EntityDefinition& def)
{
	return (new DragonTheRevenge::BadGuy (def._id));
}

// ---
QGAMES::World* DragonTheRevenge::WorldBuilder::createWorldObject (int no, const QGAMES::Scenes& s, 
			const QGAMES::WorldProperties& p)
{
	if (no == __DRAGONWINDTHEREVENGE_CITYWORLDID__)
		return (new DragonTheRevenge::CityWorld (s, p));
	else
	if (no == __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDID__)
		return (new DragonTheRevenge::LandscapeWorld (s, p));

	__WLOGPLUS (std::string ("DRAGONWINDII World: ") + 
		std::to_string (no) + std::string (" not defined"));
	__WLOGPLUS ("Going for the default builder...");

	return (DRAGONWIND::WorldBuilder::createWorldObject (no, s, p));
}

// ---
QGAMES::Scene* DragonTheRevenge::WorldBuilder::createSceneObject (int ns, const QGAMES::Maps& m, 
			const QGAMES::Scene::Connections& cn, 
			const QGAMES::SceneProperties& p, const QGAMES::EntitiesPerLayer& ePL)
{
	// The city scenes...
	if (ns ==  __DRAGONWINDTHEREVENGE_CITYWORLDSCENE0ID__)
		return (new DragonTheRevenge::CityScene0 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_CITYWORLDSCENE1ID__)
		return (new DragonTheRevenge::CityScene1 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_CITYWORLDSCENE2ID__)
		return (new DragonTheRevenge::CityScene2 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_CITYWORLDSCENE3ID__)
		return (new DragonTheRevenge::CityScene3 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_CITYWORLDSCENE4ID__)
		return (new DragonTheRevenge::CityScene4 (m, cn, p, ePL));
	else

	// The landscape scenes...
	if (ns ==  __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE0ID__)
		return (new DragonTheRevenge::LandscapeScene0 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1ID__)
		return (new DragonTheRevenge::LandscapeScene1 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE2ID__)
		return (new DragonTheRevenge::LandscapeScene2 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE3ID__)
		return (new DragonTheRevenge::LandscapeScene3 (m, cn, p, ePL));
	else if (ns == __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE4ID__)
		return (new DragonTheRevenge::LandscapeScene4 (m, cn, p, ePL));

	__WLOGPLUS (std::string ("DRAGONWINDII Scene: ") + 
		std::to_string (ns) + std::string (" not defined"));
	__WLOGPLUS ("Going for the deafult builder...");

	return (DRAGONWIND::WorldBuilder::createSceneObject (ns, m, cn, p, ePL));
}

// ---
QGAMES::SceneActionBlock* DragonTheRevenge::WorldBuilder::createSceneActionBlockObject (int nAB, 
			const QGAMES::SceneActionBlockProperties& prps)
{
	return (DRAGONWIND::WorldBuilder::createSceneActionBlockObject (nAB, prps));
}
