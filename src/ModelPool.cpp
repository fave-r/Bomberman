//
// ModelPool.cpp for ModelPool.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Wed May 27 22:09:10 2015 clément jean
// Last update Wed May 27 22:16:06 2015 clément jean
//

#include "ModelPool.hh"

ModelPool::ModelPool()
{
}

ModelPool::~ModelPool()
{
}

bool		       ModelPool::init()
{
  if (this->_modelPhysicalPlayer.load("./Assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model" << std::endl;
      return (false);
    }
  return true;
}

const gdl::Model      &ModelPool::getPhysicalPlayer()
{
  return this->_modelPhysicalPlayer;
}

const gdl::Model      &ModelPool::getArtificialPlayer()
{
  return this->_modelArtificialPlayer;
}
