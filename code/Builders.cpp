#include "Builders.hpp"
#include "Worlds.hpp"
#include "Scenes.hpp"
#include "Entities.hpp"
#include "ActionBlolcks.hpp"
#include "Defs.hpp"

// ---
QGAMES::Entity* DragonTheRevenge::EntityBuilder::createEntity (const QGAMES::EntityBuilder::EntityDefinition& def)
{
	QGAMES::Entity* result = NULL;

	if (def._id >= __DRAGONWINDTHEREVENGE_VULTUREBASEID__ &&
		def._id < (__DRAGONWINDTHEREVENGE_VULTUREBASEID__ + __DRAGONWIND_MAXNUMBEROFFLYMONSTERSFLOCK__))
		result = new DRAGONWIND::FlyingMonster (def._id);
	else
		result = DRAGONWIND::EntityBuilder::createEntity (def);

	return (result);
}

// ---
QGAMES::CompositeEntity* DragonTheRevenge::EntityBuilder::createCompositeEntity 
	(const QGAMES::EntityBuilder::EntityDefinition& def)
{
	QGAMES::CompositeEntity* result = NULL;

	QGAMES::Entities eties = entities (def._entities);
	QGAMES::Entities etiesClone;
	for (QGAMES::Entities::const_iterator i = eties.begin (); i != eties.end (); i++)
		etiesClone [(*i).first] = (*i).second -> clone ();

	QGAMES::Entity::Data dt;
	dt._capacities = def._capacities;
	dt._physics = def._physics;
	dt._parameters = def._parameters;

	// Creates the bees
	if (def._id >= __DRAGONWINDTHEREVENGE_FLOACKOFVULTUREBASE__ &&
		def._id < (__DRAGONWINDTHEREVENGE_FLOACKOFVULTUREBASE__ + __DRAGONWIND_MAXNUMBEROFFLOACKS__))
		result = new DragonTheRevenge::FlockOfVultures (def._id, etiesClone, dt);
	else
		result = DRAGONWIND::EntityBuilder::createCompositeEntity (def);

	return (result);
}

// ---
QGAMES::BadGuy* DragonTheRevenge::EntityBuilder::createBadGuy (const QGAMES::EntityBuilder::EntityDefinition& def)
{
	return (new DragonTheRevenge::BadGuy (def._id));
}

// ---
QGAMES::Movement* DragonTheRevenge::MovementBuilder::createMovement 
	(const QGAMES::MovementBuilder::MovementDefinition& def)
{
	QGAMES::Movement* result = NULL;

	if (def._id >= __DRAGONWINDTHEREVENGE_VULTUREFLYMOVEMENTBASEID__ && 
		def._id < (__DRAGONWINDTHEREVENGE_VULTUREFLYMOVEMENTBASEID__ + __DRAGONWIND_MAXNUMBEROFFLYMONSTERSFLOCK__))
		result = new QGAMES::IncrementalLinearMovement (def._id, def._variables);
	else
	if (def._id >= __DRAGONWINDTHEREVENGE_VULTURESTANDMOVEMENTBASEID__ && 
		def._id < (__DRAGONWINDTHEREVENGE_VULTURESTANDMOVEMENTBASEID__ + __DRAGONWIND_MAXNUMBEROFFLYMONSTERSFLOCK__))
		result = new QGAMES::NoMovement (def._id, def._variables);
	else
		result = DRAGONWIND::MovementBuilder::createMovement (def);

	return (result);
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
	QGAMES::SceneActionBlock* result = NULL;

	if (nAB >= __DRAGONWIND_ACTIONBLOCKFLYMONSTERBASEID__ && 
		nAB < (__DRAGONWIND_ACTIONBLOCKFLYMONSTERBASEID__ + __DRAGONWIND_ACTIONBLOCKFLYMONSTERNUMBER__))
		return (new DragonTheRevenge::FlyingMonstersActionBlock (nAB, 
					new DRAGONWIND::FlyingMonstersActionBlock::Properties (prps)));

	__WLOGPLUS (std::string ("DRAGONWINDII Action Block: ") + 
		std::to_string (nAB) + std::string (" not defined"));
	__WLOGPLUS ("Going for the default builder...");

	return (DRAGONWIND::WorldBuilder::createSceneActionBlockObject (nAB, prps));
}
