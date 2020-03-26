#include "Builders.hpp"
#include "Worlds.hpp"
#include "Scenes.hpp"
#include "Defs.hpp"

// ---
QGAMES::World* DragonTheRevenge::WorldBuilder::createWorldObject (int no, const QGAMES::Scenes& s, 
			const QGAMES::WorldProperties& p)
{
	if (no == __DRAGONWINDTHEREVENGE_CITYWORLDID__)
		return (new DragonTheRevenge::CityWorld (s, p));

	__WLOGPLUS (std::string ("DRAGONWINDII World: ") + 
		std::to_string (no) + std::string (" not defined"));
	__WLOGPLUS ("Going for the deafult builder...");

	return (DRAGONWIND::WorldBuilder::createWorldObject (no, s, p));
}

// ---
QGAMES::Scene* DragonTheRevenge::WorldBuilder::createSceneObject (int ns, const QGAMES::Maps& m, 
			const QGAMES::Scene::Connections& cn, 
			const QGAMES::SceneProperties& p, const QGAMES::EntitiesPerLayer& ePL)
{
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
