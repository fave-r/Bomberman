//
// Music.hh for Music in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  2 09:48:39 2015 Leo Thevenet
// Last update Wed Jun  3 14:48:29 2015 Leo Thevenet
//

#ifndef __MUSIC_HH__
#define __MUSIC_HH__

#include <vector>
#include "fmod.hpp"

class Music
{
  FMOD::System			*_sys;
  std::vector<FMOD::Sound*>	_sons;
public:
  Music();
  ~Music();
  void createSound(FMOD::Sound**, const char*);
  void playSound(FMOD::Sound*, bool);
};

#endif
