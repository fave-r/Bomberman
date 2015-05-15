//
// MapGenerator.cpp for MapGenerator.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:34:23 2015 clément jean
// Last update Fri May 15 17:20:16 2015 clément jean
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(const int &width, const int &height)
{
  this->_width = width;
  this->_height = height;

  this->_map.resize(height);
  for (int i = 0; i < height; i++)
    {
      this->_map[i].resize(width);
      this->_map[i][0] = NULL;
    }
}

void	MapGenerator::Generate()
{

}

void	MapGenerator::Initialize()
{

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
	  std::cout << '{' << this->_map[i][j] << "} ";
	}
      std::cout << std::endl;
    }
}

MapGenerator::~MapGenerator()
{

}
