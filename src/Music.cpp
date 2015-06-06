//
// Music.cpp for Music in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  2 09:49:05 2015 Leo Thevenet
// Last update Sat Jun  6 17:23:37 2015 Leo Thevenet
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
  for (size_t i = 0; i < this->_sons.size(); ++i)
    this->_sons[i]->release();
}

void Music::createSound(FMOD::Sound **pSound, const char* pFile)
{
  this->_sys->createSound(pFile, FMOD_DEFAULT, 0, pSound);
  this->_sons.push_back(*pSound);
}

void Music::playSound(FMOD::Sound *pSound, bool bLoop = false)
{
  if (!bLoop)
    pSound->setMode(FMOD_LOOP_OFF);
  else
    {
      pSound->setMode(FMOD_LOOP_NORMAL);
      pSound->setLoopCount(-1);
    }
  this->_sys->playSound(pSound, NULL, false, 0);
}
