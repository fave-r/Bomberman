//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Tue May 19 15:04:14 2015 polydo_s
//


#include "Bomberman.hh"

Bomberman::Bomberman(const unsigned int &x, const unsigned int &y)
{
  MapGenerator *map = new MapGenerator(x, y);
  map->Generate();
  this->_map = map->GetMap();
  PhysicalPlayer *p1 = new PhysicalPlayer(1, 1, ACharacter::DOWN);
  PhysicalPlayer *p2 = new PhysicalPlayer(x - 2, y - 2, ACharacter::UP);
  this->_playerlist.push_back(p2);
  this->_playerlist.push_back(p1);
  this->ShowMap();
}

void	Bomberman::ShowMap()
{
  for (unsigned int i = 0; i < this->_map.size(); i++)
    {
      for (unsigned int j = 0; j < this->_map[i].size(); j++)
        {
	  bool isPlayer = false;
	  std::list<APlayer *>::const_iterator it;
	  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
	    {
	      unsigned int y = (*it)->getY();
	      unsigned int x = (*it)->getX();
	      if (y == i && x == j)
		{
		  std::cout << "\033[1;32m" << (*it)->ToString() << "\033[0m";
		  isPlayer = true;
		}
	    }
	  if (isPlayer == false)
	    {
	      if (this->_map[i][j] != NULL)
		std::cout << "\033[1;31m" << this->_map[i][j]->ToString() << "\033[0m";
	      else
		std::cout << this->_map[i][j];
	    }
	  std::cout << " ";
        }
      std::cout << std::endl;
    }
}

Bomberman::~Bomberman()
{

}
