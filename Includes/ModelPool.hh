//
// ModelPool.hh for ModelPool.hh in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun  5 00:16:00 2015 clément jean
// Last update Fri Jun 12 22:39:22 2015 clément jean
//

#ifndef __MODELPOOL_H__
# define __MODELPOOL_H__

#include <Geometry.hh>

class	ModelPool
{
public:
  ModelPool();
  void	init();
  ~ModelPool();
  const gdl::Geometry	&getGeometry() const;
  const gdl::Geometry	&getGround() const;

private:
  gdl::Geometry	_geometry;
  gdl::Geometry	_ground;
};

#endif
