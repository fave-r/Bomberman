//
// Music.hh for Music in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  2 09:48:39 2015 Leo Thevenet
// Last update Thu Jun 11 14:55:47 2015 Leo Thevenet
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
  void createSound(const char*, const char*);
  void playSound(const char*, bool);
};

#endif
