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

#ifndef __DRAGONWINDTHEREVENGE_DARKFORESTSCENES__
#define __DRAGONWINDTHEREVENGE_DARKFORESTSCENES__

#include <DragonwindLike/dwinclude.hpp>
#include "Defs.hpp"

namespace DragonTheRevenge
{
	/** Base for any DarkForest scene. */
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
			: DarkForestScene (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE0ID__, m, cn, p, ePL),
			  _layersHole (), 
			  _secondsToVanishPerFrame (QGAMES::Game::game () -> framesPerSecond () / 6)
							{ }

		/** @see parent. */
		virtual void initialize ();
		virtual void updatePositions ();
		virtual void finalize ();

		private:
		// To manage the holes
		bool isHoleDisappearing (int h);
		void dissapearHole (int h);
		bool hasHoleDissapear (int h);
		bool isHoleAppearing (int h);
		void appearHole (int h);
		bool hasHoleAppear (int h);

		__DECLARECOUNTERS__ (Counters);
		virtual QGAMES::Counters* createCounters ()
							{ return (new Counters ()); }
		__DECLAREONOFFSWITCHES__ (OnOffSwitches);
		virtual QGAMES::OnOffSwitches* createOnOffSwitches ()
							{ return (new OnOffSwitches ()); }

		private:
		// Implamentation
		std::vector <QGAMES::AdvancedTileLayers> _layersHole;
		int _secondsToVanishPerFrame;

		static const int _NUMBERHOLES = 2;
		static const int _COUNTERTOSHOWDISAPPEARHOLE [_NUMBERHOLES];
		static const int _SWITCHHOLEVISIBLE [_NUMBERHOLES];
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
		virtual void drawOn (QGAMES::Screen* s, const QGAMES::Position& p = QGAMES::Position::_noPoint);
	};

	/** DarkForest Scene 2 */
	class DarkForestScene2 : public DarkForestScene
	{
		public:
		DarkForestScene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DarkForestScene (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDSCENE2ID__, m, cn, p, ePL),
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
