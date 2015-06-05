//
// ModelPool.hh for ModelPool.hh in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun  5 00:16:00 2015 clément jean
// Last update Fri Jun  5 00:24:56 2015 clément jean
//

#ifndef __MODELPOOL_H__
# define __MODELPOOL_H__

#include <Geometry.hh>

class	ModelPool
{
public:
  ModelPool();
  bool	init();
  ~ModelPool();
  const gdl::Geometry	&getGeometry() const;

private:
  gdl::Geometry	_geometry;
};

#endif
