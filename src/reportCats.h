///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "catDatabase.h"

extern bool printAllCats() ;

const char* toColor ( Color color );
const char* toBreedName ( Breed breed);
const char* toGenderName ( Gender gender);
const char* toIsFixedName (bool isFixed);
Cat* findCatByName(const char* nameToFind);