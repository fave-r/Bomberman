//
// MapGenerator.cpp for MapGenerator.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:34:23 2015 clément jean
// Last update Fri May 15 13:58:03 2015 clément jean
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(const int &width, const int &height)
{
  this->_m_width = width;
  this->_m_height = height;
  this->_m_maze.resize(this->_m_width * this->_m_height);
}

void	MapGenerator::Generate()
{
  this->Initialize();
  this->Carve(2, 2);
  this->_m_maze[this->_m_width + 2] = true;
  this->_m_maze[(this->_m_height - 2) *
	       this->_m_width + this->_m_width - 3] = true;
}

void	MapGenerator::Initialize()
{
  std::fill(this->_m_maze.begin(), this->_m_maze.end(), false);
  for(int x = 0; x < this->_m_width; x++) {
    this->_m_maze[x] = true;
    this->_m_maze[(this->_m_height - 1) * this->_m_width + x] = true;
  }
  for(int y = 0; y < this->_m_height; y++) {
    this->_m_maze[y * this->_m_width] = true;
    this->_m_maze[y * this->_m_width + this->_m_width - 1] = true;
  }
}

void MapGenerator::Carve(const int &x, const int &y)
{
  this->_m_maze[y * this->_m_width + x] = true;
  int d = std::rand();
  int dirs[] = { 1, -1, 0, 0 };

  for(int i = 0; i < 4; i++) {
    int dx = dirs[(i + d + 0) % 4];
    int dy = dirs[(i + d + 2) % 4];
    int x1 = x + dx, y1 = y + dy;
    int x2 = x1 + dx, y2 = y1 + dy;
    if(!this->_m_maze[y1 * this->_m_width + x1]
       && !this->_m_maze[y2 * this->_m_width + x2]) {
      this->_m_maze[y1 * this->_m_width + x1] = true;
      Carve(x2, y2);
    }
  }
}

const std::vector<bool>     &MapGenerator::getMap()
{
  return this->_m_maze;
}

MapGenerator::~MapGenerator()
{

}
