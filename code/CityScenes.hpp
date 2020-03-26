/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Scenes.hpp \n
 *	Game: Dragonwind II (The Revenge) \n
 *	Author: Ignacio Cea Forni�s (Community Networks) \n
 *	Creation Date: 24/01/2020 \n
 *	Description: Defines the base for all scenes in Dragonwind II \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_CITYSCENES__
#define __DRAGONWINDTHEREVENGE_CITYSCENES__

#include <DragonwindLike/dwinclude.hpp>
#include "Defs.hpp"

namespace DragonTheRevenge
{
	/** Base for CityScenes */
	class CityScene : public DRAGONWIND::PlayingScene
	{
		public:
		CityScene (int c, const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: DRAGONWIND::PlayingScene (c, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** CityWorld Scene 0 */
	class CityScene0 : public CityScene
	{
		public:
		CityScene0 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: CityScene (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE0ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** CityWorld Scene 1 */
	class CityScene1 : public CityScene
	{
		public:
		CityScene1 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: CityScene (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE1ID__, m, cn, p, ePL),
			  _theBadGuysToKill (),
			  _layersMoat () // The base, the solid and the liquid...
							{ _layersMoat [0] = _layersMoat [1] = _layersMoat [2] = NULL; }

		/** @see parent. */
		virtual void initialize ();
		virtual void updatePositions ();

		private:
		__DECLAREONOFFSWITCHES__ (OnOffSwitches);
		virtual QGAMES::OnOffSwitches* createOnOffSwitches ()
							{ return (new OnOffSwitches ()); }

		/** To know whether the moat is or not visible. */
		bool isMoatVisible ();
		/** To hide or show the moat. */
		void showMoat (bool a);

		private:
		// Implementation
		/** A list with all bad guys that when dying make the removable platform to come true. */
		QGAMES::Entities _theBadGuysToKill;
		/** A reference to the layers with the information to hide or show. */
		QGAMES::TileLayers _layersMoat;

		static const int _SWITCHTOSHOWMOAT = 0;
	};

	/** CityWorld Scene 2 */
	class CityScene2 : public CityScene
	{
		public:
		CityScene2 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: CityScene (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE2ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** CityWorld Scene 3 */
	class CityScene3 : public CityScene
	{
		public:
		CityScene3 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: CityScene (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE3ID__, m, cn, p, ePL)
							{ }

		/** @see parent. */
		virtual void initialize ();
	};

	/** CityWorld Scene 4 */
	class CityScene4 : public CityScene
	{
		public:
		CityScene4 (const QGAMES::Maps& m, 
			   const QGAMES::Scene::Connections& cn = QGAMES::Scene::Connections (), 
			   const QGAMES::SceneProperties& p = QGAMES::SceneProperties (), 
			   const QGAMES::EntitiesPerLayer& ePL = QGAMES::EntitiesPerLayer ())
			: CityScene (__DRAGONWINDTHEREVENGE_CITYWORLDSCENE4ID__, m, cn, p, ePL),
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
