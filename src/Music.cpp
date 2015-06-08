//
// Music.cpp for Music in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  2 09:49:05 2015 Leo Thevenet
// Last update Mon Jun  8 11:55:15 2015 Leo Thevenet
//

#include "Music.hh"
#include <stdlib.h>
#include <iostream>

Music::Music()
{
  if (FMOD::System_Create(&(this->_sys)) != FMOD_OK)
    return;
  int driverCount = 0;
  this->_sys->getNumDrivers(&driverCount);
  if (driverCount == 0)
      return;
  this->_sys->init(42, FMOD_INIT_NORMAL, NULL);
}

Music::~Music()
{
  std::map<std::string, FMOD::Sound*>::iterator it;
  for (it = this->_sons.begin(); it != this->_sons.end(); ++it)
    (*it).second->release();
}

void Music::createSound(const char* pFile, const char* id)
{
  FMOD::Sound	*son;

  this->_sys->createSound(pFile, FMOD_DEFAULT, 0, &son);
  this->_sons[id] = son;
}

void Music::playSound(const char* id, bool bLoop = false)
{
  if (!bLoop)
    this->_sons[id]->setMode(FMOD_LOOP_OFF);
  else
    {
      this->_sons[id]->setMode(FMOD_LOOP_NORMAL);
      this->_sons[id]->setLoopCount(-1);
    }
  this->_sys->playSound(this->_sons[id], NULL, false, 0);
}
