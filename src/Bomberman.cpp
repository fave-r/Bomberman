//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Fri May 29 03:48:36 2015 clément jean
//

#include <time.h>

#include "Bomberman.hh"
#include "GenMap.hh"

Bomberman::Bomberman(const unsigned int &x, const unsigned int &y)
{
  GenMap *map = new GenMap(x, y, 2);

  this->_x = x;
  this->_y = y;
  map->generate();
  this->_map = map->getMap();

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

  clock_t t;
  t = clock();
  if (!this->_context.start(1920, 1080, "My bomberman!"))
    {
      std::cout << "peut pas faire de fenetre" << std::endl;
      return false;
    }
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();

  this->_texturePool = new TexturePool();
  this->_modelPool = new ModelPool();
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  if (this->_texturePool->init() == false)
    {
      std::cout << "TexturePool fail" << std::endl;
      return false;
    }
  if (this->_modelPool->init() == false)
    {
      std::cout << "ModelPool fail" << std::endl;
      return false;
    }
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();

  glEnable(GL_DEPTH_TEST);
  if (!this->_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    {
      std::cout << "shader erreur" << std::endl;
      return false;
    }
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  projection = glm::perspective(70.0f, 1920.0f / 1080.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(this->_x / 2, (this->_x + this->_y) / 2, this->_y / 2),
			       glm::vec3(this->_x / 2, 0, this->_y / 2 - 0.0001),
			       glm::vec3(0, 1, 0));
  this->_shader.bind();
  this->_shader.setUniform("view", transformation);
  this->_shader.setUniform("projection", projection);
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  init_map();
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  init_player();
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  if (init_texture() == false)
    return false;
  t = clock() - t;
  std::cout << "time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  return true;
}

bool	Bomberman::init_texture()
{
  // Cube        *_cube = new Cube(0, 0); /*texture pool*/

  // _cube->initialize();
  //_cube->setTexture(this->_texturePool->getWall());
  //_cube->newTexture();
  // this->_objects.push_back(_cube);
  clock_t t;

  t = clock();
  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      if (this->_map[i][j])
	if (this->_map[i][j]->initialize() == false)
	  return false;
  /*  this->_map[2][2] = new Bomb(2, 2);
  this->_map[2][2]->initialize();
  (*this->_map[2][2]).setTexture(this->_texturePool->getBomb());
  this->_map[2][2]->translate(glm::vec3(2, 1, 2));
  */
  t = clock() - t;
  std::cout << "--time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();

  for (size_t i = 0; i < this->_objects.size(); ++i)
    if (this->_objects[i]->initialize() == false)
      {
	std::cout << "object" << std::endl;
	return false;
      }
  t = clock() - t;
  std::cout << "--time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();

  for (size_t i = 0; i < this->_objplayers.size(); ++i)
    if (this->_objplayers[i]->initialize() == false)
      {
	std::cout << "object" << std::endl;
	return false;
      }

  t = clock() - t;
  std::cout << "--time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  draw();
  t = clock() - t;
  std::cout << "--time elapsed : " << ((float)t)/CLOCKS_PER_SEC << std::endl;
  t = clock();
  return true;
}

void	Bomberman::init_map()
{
  AObject        *model;

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
	model = new Cube((float)j, (float)i);
	model->setTexture(this->_texturePool->getGround());
	model->translate(glm::vec3(j, 0, i));
	this->_objects.push_back(model);
	if (this->_map[i][j] != NULL) // en fonction
	  {
	    if (dynamic_cast<Wall *>(this->_map[i][j]))
 	      this->_map[i][j]->setTexture(this->_texturePool->getWall());
	    else if (dynamic_cast<Box *>(this->_map[i][j]))
	      this->_map[i][j]->setTexture(this->_texturePool->getBox());
	    else
	      this->_map[i][j]->setTexture(this->_texturePool->getWall());
	    this->_map[i][j]->translate(glm::vec3(j, 1, i));
	  }
      }
}

void	Bomberman::init_player()
{
  PhysicalPlayer *p1 = new PhysicalPlayer(1, 1, APlayer::DOWN);
  PhysicalPlayer *p2 = new PhysicalPlayer(this->_x - 2, this->_y - 2, APlayer::UP);
  Model	         *model = new Model(p1->getX(), p1->getY());

  this->_playerlist.push_back(p1);
  this->_playerlist.push_back(p2);

  std::list<APlayer *>::const_iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      model = new Model((*it)->getY(), (*it)->getX());
      model->setTexture(this->_texturePool->getPlayer());
      model->setModel(this->_modelPool->getPhysicalPlayer());
      model->move((*it)->getY(), 1, (*it)->getX());
      this->_objplayers.push_back(model);
    }
}

bool	Bomberman::update()
{
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    {
      std::cout << "Exit" << std::endl;
      return false;
    }
  this->_context.updateClock(_clock);
  this->_context.updateInputs(_input);

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
	IUpdatable *updatable = dynamic_cast<IUpdatable *>(this->_map[i][j]);
	if (updatable)
	  updatable->update(this->_clock, this->_map);
      }

  std::list<APlayer *>::iterator it;
  int i = 0;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      PhysicalPlayer *player = dynamic_cast<PhysicalPlayer *>(*it);
      if (player)
	player->setInput(this->_input);
      (*it)->update(this->_clock, this->_map);
      this->_objplayers[i]->resetRotate();
      int rot = ((*it)->getOrientation() % 2 == 0) ? (*it)->getOrientation() * 90 - 180 : (*it)->getOrientation() * 90;
      this->_objplayers[i]->rotate(glm::vec3(0, 1, 0), rot);
      this->_objplayers[i]->SetPos(glm::vec3((*it)->getX(), 1.001, (*it)->getY()));
      i++;
    }
  this->_shader.bind();
  return true;
}

void	Bomberman::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->_shader.bind();

  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_shader); // a virer
  for (size_t i = 0; i < this->_objplayers.size(); ++i)
    this->_objplayers[i]->draw(this->_shader); // a virer

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      if (this->_map[i][j])
	this->_map[i][j]->draw(this->_shader);
  this->_context.flush();
}

Bomberman::~Bomberman()
{
  for (size_t i = 0; i < this->_objects.size(); ++i)
    delete this->_objects[i];
  for (unsigned int i = 0; i < this->_map.size(); i++)
    for (unsigned int j = 0; j < this->_map[i].size(); j++)
      if (this->_map[i][j])
	delete this->_map[i][j];
}
