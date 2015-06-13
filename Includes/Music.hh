//
// Music.hh for Music in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  2 09:48:39 2015 Leo Thevenet
// Last update Sat Jun 13 18:30:20 2015 clément jean
//

#ifndef __MUSIC_HH__
#define __MUSIC_HH__

#include <map>
#include <stdlib.h>
#include <iostream>
#include "fmod.hpp"
#include "Error.hh"

class Music
{
  FMOD::System				*_sys;
  std::map<std::string, FMOD::Sound*>	_sons;
public:
  Music();
  ~Music();

public:
  void					createSound(const char*, const char*);
  void					playSound(const char*, bool);
};

#endif
