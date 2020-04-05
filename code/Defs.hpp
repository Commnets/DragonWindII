/** \ingroup DWTheRevege */
/*@{*/

/**	
 *	@file	
 *	File: Defs.hpp \n
 *	Framework: Dragonwind II (the revenge) \n
 *	Author: Ignacio Cea Forni�s (Community Networks) \n
 *	Creation Date: 24/01/2020 \n
 *	Description: Defines and general includes of Dragonwind II Game
 *	Versions: 1.0 Initial
 */

#ifndef __DRAGONWINDTHEREVENGE_DRAGONWINDGAMEDEFINES__
#define __DRAGONWINDTHEREVENGE_DRAGONWINDGAMEDEFINES__

#include <DragonwindLike/dwdefinitions.hpp>

// A standard configuration parameter to declare the number of lives
#define __DRAGONWINDTHEREVENGE_MAXNUMBEROFLIVESPARAMETER__			"LIVES"
#define __DRAGONWINDTHEREVENGE_DEFAULTMAXNUMBEROFLIVESPARAMETER__	"3"
// same related with showing or not the FPS
#define __DRAGONWINDTHEREVENGE_SHOWFPSPARAMETER__					"FPS"
#define __DRAGONWINDTHEREVENGE_DEFAULTSHOWFPSPARAMETER__			"NO"

// The city world
#define __DRAGONWINDTHEREVENGE_CITYWORLDID__						50001
#define __DRAGONWINDTHEREVENGE_CITYWORLDBACKGROUNDMAPID__			__DRAGONWIND_CITYBKMAPID__
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE0ID__					60002
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE0MAPID__				60002
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE1ID__					60003
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE1MAPID__				60003
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE2ID__					60004
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE2MAPID__				60004
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE3ID__					60005
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE3MAPID__				60005
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE4ID__					60006
#define __DRAGONWINDTHEREVENGE_CITYWORLDSCENE4MAPID__				60006

// The landscape world
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDID__					50002
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDBACKGROUNDMAPID__		__DRAGONWIND_LANDSCAPEBKMAPID__
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE0ID__				70000
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE0MAPID__			70000
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1ID__				70001
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE1MAPID__			70001
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE2ID__				70002
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE2MAPID__			70002
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE3ID__				70003
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE3MAPID__			70003
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE4ID__				70004
#define __DRAGONWINDTHEREVENGE_LANDSCAPEWORLDSCENE4MAPID__			70004

// Type of standard shootings
#define __DRAGONWINDTHEREVENGE_BALLOFFIRETYPE__						21

// The specific entities
#define __DRAGONWIND_DINOTYPEID__				4
#define __DRAGONWIND_MALEZOMBIETYPEID__			5
#define __DRAGONWIND_FEMALEZOMBIETYPEID__		6
#define __DRAGONWIND_KONGTYPEID__				7
#define __DRAGONWIND_ORCUSTYPEID__				8

// Flock of vultures
#define __DRAGONWINDTHEREVENGE_VULTUREBASEID__						60000
#define __DRAGONWINDTHEREVENGE_FLOACKOFVULTUREBASE__				60120
#define __DRAGONWINDTHEREVENGE_VULTUREFLYMOVEMENTBASEID__			70000
#define __DRAGONWINDTHEREVENGE_VULTURESTANDMOVEMENTBASEID__			70010
// Flock of wasps
#define __DRAGONWINDTHEREVENGE_WASPBASEID__							61000
#define __DRAGONWINDTHEREVENGE_FLOACKOFWASPBASE__					61120
#define __DRAGONWINDTHEREVENGE_WASPFLYMOVEMENTBASEID__				71000
#define __DRAGONWINDTHEREVENGE_WASPSTANDMOVEMENTBASEID__			71010
// Flock of bats
#define __DRAGONWINDTHEREVENGE_BATBASEID__							62000
#define __DRAGONWINDTHEREVENGE_FLOACKOFBATBASE__					62120
#define __DRAGONWINDTHEREVENGE_BATFLYMOVEMENTBASEID__				72000
#define __DRAGONWINDTHEREVENGE_BATSTANDMOVEMENTBASEID__				72010

// Sounds
#define __DRAGONWINDTHEREVENGE_OPENDOORSOUNDID__					80000
#define __DRAGONWINDTHEREVENGE_BEEWASPSSOUNDID__					80007
#define __DRAGONWINDTHEREVENGE_BATSSOUNDID__						80008
#define __DRAGONWINDTHEREVENGE_VULTURESSOUNDID__					80009

// Action Blocks
// Flock of Vultures
#define __DRAGONWINDTHEREVENGE_ACTIONBLOCKFMONSTERTYPEVULTURE__		2
#define __DRAGONWINDTHEREVENGE_ACTIONBLOCKFMONSTERTYPEWASP__		3
#define __DRAGONWINDTHEREVENGE_ACTIONBLOCKFMONSTERTYPEBAT__			4

#endif
  
// End of the file
/*@}*/