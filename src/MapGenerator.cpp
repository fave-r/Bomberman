//
// MapGenerator.cpp for MapGenerator.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:34:23 2015 clément jean
// Last update Fri May 15 17:46:24 2015 clément jean
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(const int &width, const int &height)
{
  this->_width = width;
  this->_height = height;
  this->Initialize();
}

void	MapGenerator::Generate()
{

}

void	MapGenerator::Initialize()
{
  this->_map.resize(this->_height);
  for (int i = 0; i < this->_height; i++)
    {
      this->_map[i].resize(this->_width);
      this->_map[i][0] = NULL;
    }
}

void MapGenerator::Carve(const int &x, const int &y)
{
  (void)x;
  (void)y;
}

void MapGenerator::Show()
{
  for (std::vector< std::vector<AElement *> >::size_type i = 0; i < this->_map.size(); i++)
    {
      for (std::vector<AElement *>::size_type j = 0; j < this->_map[i].size(); j++)
	{
	  if (j == 0 || j == this->_map[i].size() - 1 || i == 0 || i == this->_map.size() - 1)
	    {
	      Wall *w = new Wall(i, j);
	      this->_map[i][j] = w;
	    }
	  std::cout << (this->_map[i][j])->ToString() << " ";
	}
      std::cout << std::endl;
    }
}

MapGenerator::~MapGenerator()
{

}
