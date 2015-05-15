//
// MapGenerator.cpp for MapGenerator.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:34:23 2015 clément jean
// Last update Fri May 15 14:01:46 2015 clément jean
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(const int &width, const int &height)
{
  this->_width = width;
  this->_height = height;
  this->_maze.resize(this->_width * this->_height);
}

void	MapGenerator::Generate()
{
  this->Initialize();
  this->Carve(2, 2);
  this->_maze[this->_width + 2] = true;
  this->_maze[(this->_height - 2) *
	       this->_width + this->_width - 3] = true;
}

void	MapGenerator::Initialize()
{
  std::fill(this->_maze.begin(), this->_maze.end(), false);
  for(int x = 0; x < this->_width; x++) {
    this->_maze[x] = true;
    this->_maze[(this->_height - 1) * this->_width + x] = true;
  }
  for(int y = 0; y < this->_height; y++) {
    this->_maze[y * this->_width] = true;
    this->_maze[y * this->_width + this->_width - 1] = true;
  }
}

void MapGenerator::Carve(const int &x, const int &y)
{
  this->_maze[y * this->_width + x] = true;
  int d = std::rand();
  int dirs[] = { 1, -1, 0, 0 };

  for(int i = 0; i < 4; i++) {
    int dx = dirs[(i + d + 0) % 4];
    int dy = dirs[(i + d + 2) % 4];
    int x1 = x + dx, y1 = y + dy;
    int x2 = x1 + dx, y2 = y1 + dy;
    if(!this->_maze[y1 * this->_width + x1]
       && !this->_maze[y2 * this->_width + x2]) {
      this->_maze[y1 * this->_width + x1] = true;
      Carve(x2, y2);
    }
  }
}

const std::vector<bool>     &MapGenerator::getMap()
{
  return this->_maze;
}

MapGenerator::~MapGenerator()
{

}
