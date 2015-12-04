#include "ResourcePath.h"

std::string resourcePath()
{
	return "..\\..\\";				//only for MicroSoft VS, current working direcrtory is Vs2015proj
			//when program runs, it starts at vs2015proj folder, if you copy asset to vs2015proj, u wouldn't need resourcePath()
			//backslash and .. is to travel back 1 folder at a time.
			//Vs2015proj\\projects\\assets
}
