//
// Music.cpp for Music in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  2 09:49:05 2015 Leo Thevenet
// Last update Tue Jun  2 11:34:34 2015 Leo Thevenet
//

#include "Music.hh"
#include <stdlib.h>

Music::Music()
{
  if (FMOD::System_Create(&(this->sys)) != FMOD_OK)
    return;
  int driverCount = 0;
  this->sys->getNumDrivers(&driverCount);
  if (driverCount == 0)
      return;
  this->sys->init(36, FMOD_INIT_NORMAL, NULL);
}

Music::~Music()
{}

void Music::createSound(FMOD::Sound **pSound, const char* pFile)
{
  this->sys->createSound(pFile, FMOD_DEFAULT, 0, pSound);
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
  this->sys->playSound(pSound, NULL, false, 0);
}
