//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Tue May 26 16:30:51 2015 Leo Thevenet
//

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

  if (!this->_context.start(1920, 1080, "My bomberman!"))
    {
      std::cout << "peut pas faire de fenetre" << std::endl;
      return false;
    }

  this->_texturePool = new TexturePool();
  if (this->_texturePool->init() == false)
    {
      std::cout << "TexturePool fail" << std::endl;
      return false;
    }

  glEnable(GL_DEPTH_TEST);
  if (!this->_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    {
      std::cout << "shader erreur" << std::endl;
      return false;
    }
  projection = glm::perspective(70.0f, 1920.0f / 1080.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(this->_x / 2, (this->_x + this->_y) / 2, this->_y / 2),
			       glm::vec3(this->_y / 2, 0, this->_x / 2 - 0.0001),
			       glm::vec3(0, 1, 0));
  this->_shader.bind();
  this->_shader.setUniform("view", transformation);
  this->_shader.setUniform("projection", projection);
  init_map();
  init_player();
  if (init_texture() == false)
    return false;
  return true;
}

bool	Bomberman::init_texture()
{
  // Cube        *_cube = new Cube(0, 0); /*texture pool*/

  // _cube->initialize();
  //_cube->setTexture(this->_texturePool->getWall());
  //_cube->newTexture();
  // this->_objects.push_back(_cube);

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      if (this->_map[i][j])
	if (this->_map[i][j]->initialize() == false)
	  return false;

  for (size_t i = 0; i < this->_objects.size(); ++i)
    if (this->_objects[i]->initialize() == false)
      {
	std::cout << "object" << std::endl;
	return false;
      }
  for (size_t i = 0; i < this->_objplayers.size(); ++i)
    if (this->_objplayers[i]->initialize() == false)
      {
	std::cout << "object" << std::endl;
	return false;
      }
  draw();
  return true;
}

void	Bomberman::init_map()
{
  AObject        *model;

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
	model = new Cube((float)j, (float)i); // sol
	model->setTexture(this->_texturePool->getWall());
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
  Cube        *model = new Cube(p1->getX(), p1->getY());

  this->_playerlist.push_back(p2);
  this->_playerlist.push_back(p1);

  std::list<APlayer *>::const_iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      model = new Cube((*it)->getY(), (*it)->getX());
      model->setTexture(this->_texturePool->getPlayer());
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
      this->_objplayers[i]->SetPos(glm::vec3((*it)->getY(), 1, (*it)->getX()));
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
