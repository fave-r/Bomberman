//
// ModelPool.hh for ModelPool.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Wed May 27 22:06:08 2015 clément jean
// Last update Wed May 27 23:02:01 2015 clément jean
//

#ifndef __MODELPOOL_HH__
# define __MODELPOOL_HH__

#include <iostream>
#include <Model.hh>

class	ModelPool
{
public:
  ModelPool();
  ~ModelPool();
  const gdl::Model      &getPhysicalPlayer();
  const gdl::Model      &getArtificialPlayer();
  bool			init();

private:
  gdl::Model    _modelPhysicalPlayer;
  gdl::Model    _modelArtificialPlayer;
};

#endif
