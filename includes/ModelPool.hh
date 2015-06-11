//
// ModelPool.hh for ModelPool.hh in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun  5 00:16:00 2015 clément jean
// Last update Thu Jun 11 15:35:48 2015 Leo Thevenet
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

private:
  gdl::Geometry	_geometry;
};

#endif
