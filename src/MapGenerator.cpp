//
// MapGenerator.cpp for MapGenerator.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:34:23 2015 clément jean
// Last update Sun May 17 22:44:45 2015 clément jean
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(const unsigned int &width, const unsigned int &height)
{
  this->_width = width;
  this->_height = height;
  this->Initialize();
  //  srand(time(NULL));
}

void	MapGenerator::Generate()
{
  //unsigned int	count = 0;
  unsigned int	i;
  unsigned int	j;

  for (i = 0; i < this->_map.size(); i++)
    {
      for (j = 0; j < this->_map[i].size(); j++)
        {
	  if (i == 0 || i == this->_map.size() - 1 || j == 0 || j == this->_map[i].size() - 1)
            {
	      Wall *w = new Wall((float)i, (float)j);
              this->_map[i][j] = w;
	    }
	}
    }
  //  PhysicalPlayer *p = new PhysicalPlayer(1, 1, ACharacter::DOWN);
  //this->_map[1][1] = p;
  /*  while (count < (this->_width * this->_height) / 4)
    {
      j = rand() % this->_width + 1;
      i = rand() % this->_height + 1;
      if ((i > 0 && j > 0 && i < this->_height - 1 && j < this->_width - 1)
	  && (this->_map[i - 1][j] == NULL
	      || this->_map[i + 1][j] == NULL
	      || this->_map[i][j - 1] == NULL
	      || this->_map[i][j + 1] == NULL))
	{
	  Box *b = new Box((float)i, (float)j);
	  this->_map[i][j] = b;
	  count++;
	}
	}*/
}

void	MapGenerator::Initialize()
{
  this->_map.resize(this->_height);
  for (unsigned int i = 0; i < this->_height; i++)
    this->_map[i].resize(this->_width);
}

const std::vector< std::vector<AElement *> >	&MapGenerator::GetMap()
{
  return (this->_map);
}

MapGenerator::~MapGenerator()
{
}
