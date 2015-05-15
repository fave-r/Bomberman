//
// MapGenerator.hh for MapGenerator.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:44:50 2015 clément jean
// Last update Fri May 15 13:46:29 2015 clément jean
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>

class MapGenerator {
public:

  MapGenerator(const int &width, const int &height);
  void Generate();
  void Show();
  void Initialize();
  void Carve(const int &x, const int &y);
  const std::vector<bool>	&getMap();
  ~MapGenerator();
private:
  int _m_width;
  int _m_height;
  std::vector<bool> _m_maze;
};
