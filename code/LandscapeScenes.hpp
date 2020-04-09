/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Scenes.hpp \n
 *	Game: Dragonwind II (The Revenge) \n
 *	Author: Ignacio Cea Forni�s (Community Networks) \n
 *	Creation Date: 30/03/2020 \n
 *	Description: Defines the base for all scenes in Dragonwind II \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_LANDSCAPESCENES__
#define __DRAGONWINDTHEREVENGE_LANDSCAPESCENES__

#include <DragonwindLike/dwinclude.hpp>
#include "Defs.hpp"

namespace DragonTheRevenge
{
	/** Base for LandscapeScenes */
	class LandscapeScene : public DRAGONWIND::PlayingScene
	{
		public:
		LandscapeScene (int c, const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DRAGONWIND::PlayingScene (c, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** LandscapeWorld Scene 0 */
	class LandscapeScene0 : public LandscapeScene
	{
		public:
		LandscapeScene0 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: LandscapeScene (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE0ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** LandscapeWorld Scene 1 */
	class LandscapeScene1 : public LandscapeScene
	{
		public:
		LandscapeScene1 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: LandscapeScene (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
		virtual void updatePositions ();

		private:
		__DECLAREONOFFSWITCHES__ (OnOffSwitches);
		virtual QGAMES::OnOffSwitches* createOnOffSwitches ()
							{ return (new OnOffSwitches ()); }

		/** To know whether the left / right removeable walls are or not visible. */
		bool isLeftWallVisible ();
		bool isRightWallVisible ();
		/** To hide or show the left / right wall. */
		void showLeftWall (bool a);
		void showRightWall (bool a);

		/** @see parent. 
			When the explosion happens the walls (right / left) could be destroyed too, 
			cleaning up the way to interesting lateral caves. */
		virtual void explosionAround (const QGAMES::Position& pos, QGAMES::bdata rdx = __BD 50);

		private:
		// Implementation
		/** A reference to the layers with the information to hide or show. */
		QGAMES::TileLayers _layersLeftWall;
		QGAMES::TileLayers _layersRightWall;

		static const int _SWITCHTOSHOWLEFTWALL = 0;
		static const int _SWITCHTOSHOWRIGHTWALL = 1;
	};

	/** LandscapeWorld Scene 2 */
	class LandscapeScene2 : public LandscapeScene
	{
		public:
		LandscapeScene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: LandscapeScene (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE2ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** LandscapeWorld Scene 3 */
	class LandscapeScene3 : public LandscapeScene
	{
		public:
		LandscapeScene3 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: LandscapeScene (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE3ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** LandscapeWorld Scene 4 */
	class LandscapeScene4 : public LandscapeScene
	{
		public:
		LandscapeScene4 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: LandscapeScene (__DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE4ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};
}

#endif

// End of the file
/*@}*/
