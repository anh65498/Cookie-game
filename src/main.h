#ifndef MAIN_H
#define MAIN_H

#include <SFML/Graphics.hpp>


enum GAME_STATE { OPENING_SCREEN, HOWTO_SCREEN, DURING_GAME, ENDING_GAME };				//definition		
const int numOfCookie = 3;
				
const int numFire = 3;
const int LENGTHWINDOW = 800;
const int WIDTHWINDOW = 600;
																			/* Charizard */

#endif
/*
put enum data type here so you can include them in other file
if you don't include this definition in other source file that use this file, the compiler wouldn't know what is GAME_STATE type when a variable is 
declared of its type because you write this data type, it is not available in C++ library
*/

/* 
Purpose of main.h
contain declaration of GAME_STATE so multiple source file can use
*/