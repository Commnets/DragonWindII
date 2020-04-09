/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Worlds.hpp \n
 *	Game: DragonWind II (The Revenge) \n
 *	Author: Ignacio Cea Forni�s (Community Networks) \n
 *	Creation Date: 10/04/2020 \n
 *	Description: Defines the base for all worlds in DragonWind II  \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_DARKFORESTWORLDS__
#define __DRAGONWINDTHEREVENGE_DARKFORESTWORLDS__

#include <DragonwindLike/dwinclude.hpp>
#include "Defs.hpp"

namespace DragonTheRevenge
{
	/** Class to define common funtionality to any world in a DragonWind II game. */
	class DarkForestWorld : public DRAGONWIND::World
	{
		public:
		DarkForestWorld (const QGAMES::Scenes& scns, 
				const QGAMES::WorldProperties& prps = QGAMES::WorldProperties ())
			: DRAGONWIND::World (__DRAGONWINDTHEREVENGE_DARKFORESTWORLDID__, scns, prps)
							{ }

		/** @see parent. */
		virtual void initialize ();
		virtual void finalize ();

		protected:
	};
}

#endif

// End of the file
/*@}*/
