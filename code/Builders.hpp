/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Builders.hpp \n
 *	Game: DragonwindII (The Revenge) \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 24/01/2020 \n
 *	Description: Builders needed for Dragonwind II \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_BUILDERS__
#define __DRAGONWINDTHEREVENGE_BUILDERS__

#include <DragonwindLike/dwinclude.hpp>

namespace DragonTheRevenge
{
	/** To create the entities of the Dragonwind II. */
	class EntityBuilder : public DRAGONWIND::EntityBuilder
	{
		public:
		EntityBuilder (const std::string& eDef, QGAMES::FormBuilder* fB, QGAMES::MovementBuilder* mB)
			: DRAGONWIND::EntityBuilder (eDef, fB, mB)
							{ }

		protected:
		/** @see parent. */
		virtual QGAMES::Entity* createEntity (const QGAMES::EntityBuilder::EntityDefinition& def);
		virtual QGAMES::CompositeEntity* createCompositeEntity (const QGAMES::EntityBuilder::EntityDefinition& def);

		/** @see parent. */
		virtual QGAMES::BadGuy* createBadGuy (const QGAMES::EntityBuilder::EntityDefinition& def);
	};

	/** To create the movements of the Dragonwind II. */
	class MovementBuilder : public DRAGONWIND::MovementBuilder
	{
		public:
		MovementBuilder (const std::string& fDef)
			: DRAGONWIND::MovementBuilder (fDef)
								{ }
	
		protected:
		/** @see parent. */
		virtual QGAMES::Movement* createMovement (const QGAMES::MovementBuilder::MovementDefinition& def);
	};

	/** To create the worlds and scenes of Dragonwind II. */
	class WorldBuilder : public DRAGONWIND::WorldBuilder
	{
		public:
		WorldBuilder (const std::string& eDef, QGAMES::MapBuilder* mB)
			: DRAGONWIND::WorldBuilder (eDef, mB)
							{ }

		/** @see parent. */
		virtual QGAMES::World* createWorldObject (int no, const QGAMES::Scenes& s, 
			const QGAMES::WorldProperties& p);
		virtual QGAMES::Scene* createSceneObject (int ns, const QGAMES::Maps& m, 
			const QGAMES::Scene::Connections& cn, 
			const QGAMES::SceneProperties& p, const QGAMES::EntitiesPerLayer& ePL);
		virtual QGAMES::SceneActionBlock* createSceneActionBlockObject (int nAB, 
			const QGAMES::SceneActionBlockProperties& prps);
	};
}

#endif

// End of the file
/*@}*/
