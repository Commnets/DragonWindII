/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Entities.hpp \n
 *	Game: DragonwindII (The Revenge) \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 31/03/2020 \n
 *	Description: Entities defined in Dragonwind The Revenge. \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_ENTITIES__
#define __DRAGONWINDTHEREVENGE_ENTITIES__

#include <DragonwindLike/dwinclude.hpp>

namespace DragonTheRevenge
{
	/** The bad guys of the game. */
	class BadGuy : public DRAGONWIND::BadGuy
	{
		public:
		// Just a couple of defines to simplify the definition of the very bad guys defined here...
		#define __DRAGONWIND_DINOSTATESID__ \
			DRAGONWIND::BadGuy::StatesId (80, 90, 81, 91, 82, 92, 83, 93, 84, 94, 85, 95, 86, 96)
		#define __DRAGONWIND_MALEZOMBIESTATESID__ \
			DRAGONWIND::BadGuy::StatesId (100, 110, 101, 111, 102, 112, 103, 113, 104, 114, 105, 115, 106, 116)
		#define __DRAGONWIND_FEMALEZOMBIESTATESID__ \
			DRAGONWIND::BadGuy::StatesId (120, 130, 121, 131, 122, 132, 123, 133, 124, 134, 125, 135, 126, 136)

		BadGuy (int cId, const QGAMES::Forms& f = QGAMES::Forms (), 
			const QGAMES::PlatformArtist::Data& d = QGAMES::PlatformArtist::Data ())
			: DRAGONWIND::BadGuy (cId, f, d)
							{ }

		/** @see parent. */
		virtual QGAMES::Entity* clone () const;

		protected:
		/** @see parent. */
		virtual StatesId statesIdForType (int t);
	};

	// Defines to declare types of bad guys of this version of Dragonwind
	#define __DRAGONWIND_DINOTYPEID__				4
	#define __DRAGONWIND_MALEZOMBIETYPEID__			5
	#define __DRAGONWIND_FEMALEZOMBIETYPEID__		6
}

#endif

// End of the file
/*@}*/
