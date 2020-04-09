/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Scenes.hpp \n
 *	Game: Dragonwind II (The Revenge) \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 30/03/2020 \n
 *	Description: Defines the base for all scenes in Dragonwind II \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_DARKFORESTSCENES__
#define __DRAGONWINDTHEREVENGE_DARKFORESTSCENES__

#include <DragonwindLike/dwinclude.hpp>
#include "Defs.hpp"

namespace DragonTheRevenge
{
	/** Base for DarkForestScenes */
	class DarkForestScene : public DRAGONWIND::PlayingScene
	{
		public:
		DarkForestScene (int c, const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DRAGONWIND::PlayingScene (c, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** DarkForest Scene 0 */
	class DarkForestScene0 : public DarkForestScene
	{
		public:
		DarkForestScene0 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DarkForestScene (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE0ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** DarkForest Scene 1 */
	class DarkForestScene1 : public DarkForestScene
	{
		public:
		DarkForestScene1 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DarkForestScene (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE1ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** DarkForest Scene 2 */
	class DarkForestScene2 : public DarkForestScene
	{
		public:
		DarkForestScene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DarkForestScene (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE2ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};
}

#endif

// End of the file
/*@}*/
