/**	
 *	@file	
 *	File: main.cpp \n
 *	Game: Dragonwind II (The Revenge) \n
 *	Author: Ignacio Cea Forni�s (Community Networks) \n
 *	Creation Date: 04/01/2019 \n
 *	Description: Main program for Dragonwind II \n
 *	Versions: 1.0 Initial
 */

#include "stdafx.h"

#include "Game.hpp"

using namespace DragonTheRevenge;

#ifndef _CONSOLE
#include <SDL.h>
#ifdef __cplusplus
#define C_LINKAGE "C"
#else
#define C_LINKAGE
#endif /* __cplusplus */
#if _MSC_VER >= 1900
extern C_LINKAGE FILE __iob_func [3] = { *stdin, *stdout, *stderr };
#endif
extern C_LINKAGE int main (int argc, char *argv [])
#else
int _tmain (int argc, char *argv [])
#endif /* _CONSOLE */
{
#ifdef NDEBUG
	// In the release version, the resources are in a zip file
	// This instruction reads them and store in temporally files when needed!
	// The resource reader is deleted at the end, and all the temporal file with them!
	QGAMES::InZipResourceReader rR 
		(std::string (".") + __PATH_SEPARATOR__ + std::string ("temp"));
#endif

	Game game;
	game.setLinkDrawToFrameRate (true);
	/** Forms are not preloaded. */
	game.exec ();

	return (0);
}
