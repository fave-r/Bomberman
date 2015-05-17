//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Sun May 17 23:23:43 2015 clément jean
//


#include "Bomberman.hh"

Bomberman::Bomberman(const unsigned int &x, const unsigned int &y)
{
  MapGenerator *map = new MapGenerator(x, y);
  map->Generate();
  this->_map = map->GetMap();
  PhysicalPlayer *p1 = new PhysicalPlayer(0, 0, ACharacter::DOWN);
  PhysicalPlayer *p2 = new PhysicalPlayer(x - 1, y - 1, ACharacter::UP);
  this->_playerlist.pushback(p2);
  this->_playerlist.pushback(p1);
  this->ShowMap();
}

void	Bomberman::ShowMap()
{
  for (unsigned int i = 0; i < this->_map.size(); i++)
    {
      for (unsigned int j = 0; j < this->_map[i].size(); j++)
        {
	  if (this->_map[i][j] != NULL)
	    std::cout << "\033[1;31m" << this->_map[i][j]->ToString() << "\033[0m";
          else
	    std::cout << this->_map[i][j] << " ";
        }
      std::cout << std::endl;
    }
}

Bomberman::~Bomberman()
{

}
