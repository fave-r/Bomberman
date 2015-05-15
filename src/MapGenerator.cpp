//
// MapGenerator.cpp for MapGenerator.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:34:23 2015 clément jean
// Last update Fri May 15 22:42:11 2015 clément jean
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
  for (unsigned int i = 0; i < this->_map.size(); i++)
    {
      for (unsigned int j = 0; j < this->_map[i].size(); j++)
        {
	  if (i == 0 || i == this->_map.size() - 1 || j == 0 || j == this->_map[i].size() - 1)
            {
	      Wall *w = new Wall((float)i, (float)j);
              this->_map[i][j] = w;
	    }
	}
    }
}

void	MapGenerator::Initialize()
{
  this->_map.resize(this->_height);
  for (int i = 0; i < this->_height; i++)
    this->_map[i].resize(this->_width);
}

void MapGenerator::Show()
{
  for (unsigned int i = 0; i < this->_map.size(); i++)
    {
      for (unsigned int j = 0; j < this->_map[i].size(); j++)
	{
	  if (this->_map[i][j] != NULL)
	    std::cout << this->_map[i][j]->ToString() << " ";
	  else
	    std::cout << this->_map[i][j] << " ";
	}
      std::cout << std::endl;
    }
}

MapGenerator::~MapGenerator()
{
}
