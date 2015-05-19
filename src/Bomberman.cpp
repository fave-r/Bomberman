//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Wed May 20 00:28:10 2015 polydo_s
//

#include "Bomberman.hh"

Bomberman::Bomberman(const unsigned int &x, const unsigned int &y)
{
  MapGenerator *map = new MapGenerator(x, y);
  this->_x = x;
  this->_y = y;
  map->Generate();
  this->_map = map->GetMap();

  // Visual *game = new Visual(x, y);

  // if (game->initialize() == false)
  //   return;// false;
  // while (game->update() == true)
  //   game->draw();

  // this->ShowMap();
}

bool	Bomberman::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;
  //  gdl::Texture _texture;

  if (!this->_context.start(1910, 1070, "My bomberman!"))
    {
      std::cout << "peut pas faire de fenetre" << std::endl;
      return false;
    }
  PhysicalPlayer *p1 = new PhysicalPlayer(1, 1, ACharacter::DOWN, &this->_context);
  PhysicalPlayer *p2 = new PhysicalPlayer(this->_x - 2, this->_y - 2, ACharacter::UP, &this->_context);
  this->_playerlist.push_back(p2);
  this->_playerlist.push_back(p1);
  glEnable(GL_DEPTH_TEST);
  if (!this->_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    {
      std::cout << "shader erreur" << std::endl;
      return false;
    }
  projection = glm::perspective(60.0f, 1000.0f / 1000.0f, 0.1f, 2000.0f);
  transformation = glm::lookAt(glm::vec3(0, 30, 30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  this->_shader.bind();
  this->_shader.setUniform("view", transformation);
  this->_shader.setUniform("projection", projection);

  Cube        *old = new Cube;
  Cube        *model;

  old->initialize();
  old->newTexture();
  this->_objects.push_back(old);

  for (unsigned int i = 0; i < this->_map.size(); i++)
    {
      for (unsigned int j = 0; j < this->_map[i].size(); j++)
	{
	  model = new Cube;
	  model->move(j, 0, i);
	  this->_objects.push_back(model);
	  if (this->_map[i][j] != NULL)
	    {
	      model = new Cube;
	      model->move(j, 1, i);
	      this->_objects.push_back(model);
	    }
	}
    }
  std::list<APlayer *>::const_iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      float y = (*it)->getY();
      float x = (*it)->getX();
      model = new Cube;
      model->move(y, 2, x);
      this->_objects.push_back(model);
    }



  for (size_t i = 0; i < _objects.size(); ++i)
    {
      if (_objects[i]->initialize() == false)
	{
	  std::cout << "object" << std::endl;
	  return false;
	}
      ((Cube *)_objects[i])->setTexture(old->_texture);
    }
  draw();
  return true;
}

bool	Bomberman::update()
{
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    {
      std::cout << "update" << std::endl;
      return false;
    }
  this->_context.updateClock(_clock);
  this->_context.updateInputs(_input);

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      if (this->_map[i][j])
	this->_map[i][j]->update(this->_map);

  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    (*it)->update(this->_map);

  this->_shader.bind();
  return true;
}

void	Bomberman::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->_shader.bind();
  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_shader);
  this->_context.flush();
}

Bomberman::~Bomberman()
{
  for (size_t i = 0; i < this->_objects.size(); ++i)
    delete this->_objects[i];
}
