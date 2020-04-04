/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: ActionBlocks.hpp \n
 *	Game: DragonwindII (The Revenge) \n
 *	Author: Ignacio Cea Forniés (Community Networks) \n
 *	Creation Date: 03/04/2020 \n
 *	Description: Specific action blocks for Dragonwind II. \n
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_ACTIONBLOCKS__
#define __DRAGONWINDTHEREVENGE_ACTIONBLOCKS__

#include <DragonwindLike/dwinclude.hpp>

namespace DragonTheRevenge
{
	/** To include other flying entities in the Dragonwind II. */
	class FlyingMonstersActionBlock : public DRAGONWIND::FlyingMonstersActionBlock
	{
		public:
		DragonTheRevenge::FlyingMonstersActionBlock (int id, Properties* prps = new Properties ())
			: DRAGONWIND::FlyingMonstersActionBlock (id, prps)
							{ }

		protected:
		/** @see parent. */
		virtual DRAGONWIND::FlockOfMonsters* flock ();
	};
}

#endif

// End of the file
/*@}*/
