//
// ModelPool.hh for ModelPool.hh in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun  5 00:16:00 2015 clément jean
// Last update Sat Jun 13 18:29:16 2015 clément jean
//

#ifndef __MODELPOOL_H__
# define __MODELPOOL_H__

#include <Geometry.hh>

class	ModelPool
{
public:
  ModelPool();
  ~ModelPool();

public:
  void	init();
  const gdl::Geometry	&getGeometry() const;
  const gdl::Geometry	&getGround() const;

private:
  gdl::Geometry		_geometry;
  gdl::Geometry		_ground;
};

#endif
