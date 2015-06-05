//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Fri Jun  5 02:48:24 2015 clément jean

#include "Bomberman.hh"

Bomberman::Bomberman(unsigned int x, unsigned int y, unsigned int p)
  : _x(x), _y(y), _p(p)
{
}

void	Bomberman::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;
  //  FMOD::Sound	*son;

  if (!this->_context.start(1920, 1080, "My bomberman!"))
    throw std::runtime_error("Cannot instanciate the window");

  this->_map = Map::generate(this->_x, this->_y, this->_p);
  //this->_SoundPlayer = new Music();
  this->_texturePool = new TexturePool();
  this->_modelPool = new ModelPool();

  if (this->_texturePool->init() == false)
    throw std::runtime_error("TexturePool fail");
  if (this->_modelPool->init() == false)
    throw std::runtime_error("ModelPool fail");

  glEnable(GL_DEPTH_TEST);

  if (!this->_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    throw std::runtime_error("shader erreur");

  projection = glm::perspective(70.0f, 1920.0f / 1080.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(this->_x / 2, (this->_x + this->_y) / 2, this->_y / 2),
			       glm::vec3(this->_x / 2, 0, this->_y / 2 - 0.0001),
			       glm::vec3(0, 1, 0));

  this->_shader.bind();
  this->_shader.setUniform("view", transformation);
  this->_shader.setUniform("projection", projection);
  init_map();
  init_player();
  draw();
  //this->_SoundPlayer->createSound(&son, "./Assets/Sounds/BackgroundSound.wav");
  //this->_SoundPlayer->playSound(son, true);
}

void	Bomberman::init_map()
{
  AObject        *model;

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
	model = new Cube(j, i);
	model->setModel(this->_modelPool->getGeometry());
 	model->setTexture(this->_texturePool->getGround());
 	model->translate(glm::vec3(j, 0, i));
 	this->_objects.push_back(model);
 	if (this->_map[i][j] != NULL)
	  {
 	    if (dynamic_cast<Wall *>(this->_map[i][j]))
	      {
		this->_map[i][j]->setModel(this->_modelPool->getGeometry());
		this->_map[i][j]->setTexture(this->_texturePool->getWall());
	      }
 	    else if (dynamic_cast<Box *>(this->_map[i][j]))
	      {
		this->_map[i][j]->setModel(this->_modelPool->getGeometry());
		this->_map[i][j]->setTexture(this->_texturePool->getBox());
	      }
 	    else
	      {
		this->_map[i][j]->setModel(this->_modelPool->getGeometry());
		this->_map[i][j]->setTexture(this->_texturePool->getWall());
	      }
 	    this->_map[i][j]->translate(glm::vec3(j, 1, i));
 	  }
      }
}

void	Bomberman::init_player()
{
  PhysicalPlayer *p1 = new PhysicalPlayer(1, 1, APlayer::DOWN);
  PhysicalPlayer *p2 = new PhysicalPlayer(this->_x - 2, this->_y - 2, APlayer::UP);

  this->_playerlist.push_back(p1);
  this->_playerlist.push_back(p2);

  std::list<APlayer *>::const_iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      (*it)->setTexture(this->_texturePool->getPlayer());
      (*it)->move((*it)->getY(), 1, (*it)->getX());
    }
}

bool Bomberman::update()
{
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    {
      std::cout << "Exit" << std::endl;
      return false;
    }
  this->_context.updateClock(this->_clock);
  this->_context.updateInputs(this->_input);

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
 	IUpdatable *updatable = dynamic_cast<IUpdatable *>(this->_map[i][j]);
 	if (updatable)
 	  {
 	    PhysicalPlayer *physicalPlayer = dynamic_cast<PhysicalPlayer *>(updatable);
 	    if (physicalPlayer)
 	      physicalPlayer->setInput(this->_input);
 	    APlayer *aplayer = dynamic_cast<APlayer *>(updatable);
 	    updatable->update(this->_clock, this->_map);
 	    if (aplayer)
	      {
	      }
	    //	    updatable->update(this->_clock, this->_map);
 	  }
      }

  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      PhysicalPlayer *player = dynamic_cast<PhysicalPlayer *>(*it);
      if (player)
 	player->setInput(this->_input);
      (*it)->update(this->_clock, this->_map);
      (*it)->resetRotate();
      int rot = ((*it)->getOrientation() % 2 == 0) ? (*it)->getOrientation() * 90 - 180 : (*it)->getOrientation() * 90;
      (*it)->rotate(glm::vec3(0, 1, 0), rot);
      (*it)->SetPos(glm::vec3((*it)->getX(), 1.001, (*it)->getY()));
    }
  this->_shader.bind();
  return true;
}

void Bomberman::draw()
{
  float	x = 0, y = 0;
  glm::mat4 transformation;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->_shader.bind();

  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_shader); // a virer
  /*for (size_t i = 0; i < this->_objplayers.size(); ++i)
    this->_objplayers[i]->draw(this->_shader); // a virer*/
  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      x += (*it)->getX();
      y += (*it)->getY();
      (*it)->draw(this->_shader);
    }
  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      if (this->_map[i][j])
	this->_map[i][j]->draw(this->_shader);
  //  if (this->_players == 2)
    transformation = glm::lookAt(glm::vec3(x / 2.0, (x + y) / 2, y / 1.99),
				 glm::vec3(x / 2.0, 0, y / 2.0),
				 glm::vec3(0, 1, 0));
    //else
    //transformation = glm::lookAt(glm::vec3(x, 12, y / 0.99),
    //				 glm::vec3(x, 0, y),
    //				 glm::vec3(0, 1, 0));
  this->_shader.bind();
  this->_shader.setUniform("view", transformation);

  this->_context.flush();
}

Bomberman::~Bomberman()
{
  //  for (size_t i = 0; i < this->_objects.size(); ++i)
  //delete this->_objects[i];
  //for (unsigned int i = 0; i < this->_map.size(); i++)
  //for (unsigned int j = 0; j < this->_map[i].size(); j++)
  //  if (this->_map[i][j])
  //	delete this->_map[i][j];
  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    delete (*it);
  delete this->_texturePool;
  delete this->_modelPool;
  //  delete this->_SoundPlayer;
}
