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

#ifndef __DRAGONWINDTHEREVENGE_MOUNTAINSSCENES__
#define __DRAGONWINDTHEREVENGE_MOUNTAINSSCENES__

#include <DragonwindLike/dwinclude.hpp>
#include "Defs.hpp"

namespace DragonTheRevenge
{
	/** Base for any Mountains scene. */
	class MountainsScene : public DRAGONWIND::PlayingScene
	{
		public:
		MountainsScene (int c, const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DRAGONWIND::PlayingScene (c, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Mountain Scene 0 */
	class MountainsScene0 : public MountainsScene
	{
		public:
		MountainsScene0 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: MountainsScene (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE0ID__, m, cn, p, ePL),
			  _solidLayers ()
							{ }

		/** @see parent. */
		virtual void initialize ();
		virtual void updatePositions ();
		virtual void finalize ();

		private:
		__DECLAREONOFFSWITCHES__ (OnOffSwitches);
		virtual QGAMES::OnOffSwitches* createOnOffSwitches ()
							{ return (new OnOffSwitches ()); }

		/** To manage the solid parts of the map. */
		bool isSolidVisible (int s);
		void showSolidWall (int s, bool a);

		/** @see parent. 
			When the explosion happens the walls (1 / 2) could be destroyed too, 
			cleaning up the way to interesting lateral caves. */
		virtual void explosionAround (const QGAMES::Position& pos, QGAMES::bdata rdx = __BD 50);

		private:
		// Implementation
		std::vector <QGAMES::AdvancedTileLayers> _solidLayers;

		static const int _NUMBERSOLIDS = 2;
		static const int _SWITCHTOSHOWSOLIDWALL [_NUMBERSOLIDS];
	};

	/** Mountain Scene 1 */
	class MountainsScene1 : public MountainsScene
	{
		public:
		MountainsScene1 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: MountainsScene (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE1ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Mountain Scene 2 */
	class MountainsScene2 : public MountainsScene
	{
		public:
		MountainsScene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: MountainsScene (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE2ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
		virtual void updatePositions ();
	};

	/** Mountain Scene 3 */
	class MountainsScene3 : public MountainsScene
	{
		public:
		MountainsScene3 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: MountainsScene (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE3ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** Mountain Scene 4 */
	class MountainsScene4 : public MountainsScene
	{
		public:
		MountainsScene4 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: MountainsScene (__DRAGONWINDTHEREVENGE_MOUNTAINSWORLDSCENE4ID__, m, cn, p, ePL),
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
