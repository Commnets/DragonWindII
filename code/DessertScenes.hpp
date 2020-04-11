/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Scenes.hpp \n
 *	Game: Dragonwind II (The Revenge) \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 11/04/2020 \n
 *	Description: Defines the base for all scenes in Dragonwind II \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_DESSERTSCENES__
#define __DRAGONWINDTHEREVENGE_DESSERTSCENES__

#include <DragonwindLike/dwinclude.hpp>
#include "Defs.hpp"

namespace DragonTheRevenge
{
	/** Base for DessertScenes */
	class DessertScene : public DRAGONWIND::PlayingScene
	{
		public:
		DessertScene (int c, const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DRAGONWIND::PlayingScene (c, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Dessert Scene 0 */
	class DessertScene0 : public DessertScene
	{
		public:
		DessertScene0 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DessertScene (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE0ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Dessert Scene 1 */
	class DessertScene1 : public DessertScene
	{
		public:
		DessertScene1 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DessertScene (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE1ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Dessert Scene 2 */
	class DessertScene2 : public DessertScene
	{
		public:
		DessertScene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DessertScene (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE2ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Dessert Scene 3 */
	class DessertScene3 : public DessertScene
	{
		public:
		DessertScene3 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DessertScene (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE3ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Dessert Scene 4 */
	class DessertScene4 : public DessertScene
	{
		public:
		DessertScene4 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DessertScene (__DRAGONWINDTHEREVENGE_DESSERTWORLDSCENE4ID__, m, cn, p, ePL),
			  _mainBadGuy (NULL),
			  _badGuyEnergyLevel (NULL)
							{ }

		/** @see parent. */
		virtual void initialize ();
		virtual void finalize ();

		private:
		DRAGONWIND::BadGuy* _mainBadGuy;
		DRAGONWIND::EntityEnergy* _badGuyEnergyLevel;
	};
}

#endif

// End of the file
/*@}*/
