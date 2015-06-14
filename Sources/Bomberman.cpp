//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Sun Jun 14 18:14:19 2015 polydo_s
//

#include "Bomberman.hh"
#include "HighScore.hh"

Bomberman::Bomberman()
  : _w(Parseur::getX()), _h(Parseur::getY()), _p(Parseur::getPlayer())
{
  this->_map = Map::generate();
  this->_namedMap = "";
  this->_numberOfSave = 0;
}

Bomberman::Bomberman(const std::string & NamedMap) : _namedMap(NamedMap)
{}

void	Bomberman::getMap()
{
  std::tuple<int, int, int, std::vector< std::vector<AObject *> >, std::list<APlayer *> > TupleMap = MapSaver::getMap(this->_namedMap);
  if ((this->_w = std::get<0>(TupleMap)) == 0)
    throw std::runtime_error("No saved map");
  this->_h = std::get<1>(TupleMap);
  this->_p = std::get<2>(TupleMap);
  this->_map = std::get<3>(TupleMap);
  this->_playerlist = std::get<4>(TupleMap);
}

void	Bomberman::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;

  if (!this->_context.start(1920, 1080, "My bomberman!"))
    throw std::runtime_error("Cannot instanciate the window");
  if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_VIDEO) < 0)
    throw loading_error("Bomberman : Joystick error");

  if (!this->_shader.load("./Ressources/lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./Ressources/lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    throw std::runtime_error("shader erreur");

  projection = glm::perspective(70.0f, 1920.0f / 1080.0f, 0.1f, 1000.0f);
  this->_shader.bind();
  this->_shader.setUniform("projection", projection);

  this->_SoundPlayer = new Music();
  this->_texturePool = new TexturePool();
  this->_modelPool = new ModelPool();

  this->_texturePool->init();
  this->_modelPool->init();

  glEnable(GL_DEPTH_TEST);

  if (this->_namedMap != "")
    getMap();
  if (!this->_shader.load("./Ressources/lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./Ressources/lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    throw std::runtime_error("shader erreur");

  if (this->_playerlist.size() == 0)
    this->_playerlist = Map::spawnPlayers(this->_map);
  projection = glm::perspective(70.0f, 1920.0f / 1080.0f, 0.1f, 1000.0f);
  this->_shader.bind();
  this->_shader.setUniform("projection", projection);
  init_map();
  init_player();
  setCam();
  draw();
  this->_SoundPlayer->createSound("./Ressources/Sounds/BackgroundSound.wav", "game");
  this->_SoundPlayer->playSound("game", true);
}

void	Bomberman::init_map()
{
  AObject        *model;

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
	model = new Ground(j, i);
	model->setModel(this->_modelPool->getGround());
	model->setTexture(this->_texturePool->getGround());
	model->translate(glm::vec3(j, 0, i));
	this->_objects.push_back(model);
	if (this->_map[i][j] != NULL)
	  {
	    if (this->_map[i][j]->getType() == "W")
	      {
		this->_map[i][j]->setModel(this->_modelPool->getGeometry());
		this->_map[i][j]->setTexture(this->_texturePool->getWall());
	      }
	    else if (this->_map[i][j]->getType() == "B")
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
  std::list<APlayer *>::const_iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      (*it)->setTexture(this->_texturePool->getPlayer());
      (*it)->move((*it)->getY(), 1, (*it)->getX());
    }
}

bool Bomberman::update()
{
  IUpdatable		*updatable;
  int			rot;
  unsigned int		iaDead = 0;
  unsigned int		pDead = 0;

  this->_context.updateClock(this->_clock);
  this->_context.updateInputs(this->_input);

  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    return false;
  if (this->_input.getKey(SDLK_F5))
    {
      MapSaver::saveMap(this->_map, this->_playerlist, this->_w, this->_h, this->_p);
      std::stringstream	ss;
      this->_numberOfSave++;
      ss << "Screenshots/Save" << this->_numberOfSave << ".tga";
      saveScreenshot(ss.str(), 1920, 1080);
      usleep(200000);
    }
  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
	if ((updatable = dynamic_cast<IUpdatable *>(this->_map[i][j])))
	  updatable->update(this->_clock, this->_map, this->_playerlist);
      }

  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      if ((*it)->isDead() == false)
	{
	  if ((*it)->getType() == "P")
	    static_cast<PhysicalPlayer *>(*it)->setInput(this->_input);
	  (*it)->update(this->_clock, this->_map, this->_playerlist);
	  (*it)->resetRotate();
	  rot = ((*it)->getOrientation() % 2 == 0) ? (*it)->getOrientation() * 90 - 180 : (*it)->getOrientation() * 90;
	  (*it)->rotate(glm::vec3(0, 1, 0), rot);
	  (*it)->SetPos(glm::vec3((*it)->getX(), 1.001, (*it)->getY()));
	}
      else
	{
	  if ((*it)->getID() == 0)
	    iaDead++;
	  else
	    pDead++;
	}
    }
  it = this->_playerlist.begin();
  if (static_cast<int>(pDead) == this->_p || (static_cast<int>(pDead) == (this->_p - 1) && (iaDead + this->_p) == this->_playerlist.size()))
    {
      int ended = 0;
      Score::addNewScore((*it)->getScore(), 1);
      if ((*(it))->isDead() == false)
	ended = 1;
      ++it;
      if ((*it)->getID() != 0)
	{
	  Score::addNewScore((*it)->getScore(), 2);
	  if ((*it)->isDead() == false)
	    ended = 2;
	}
      HighScore *hg = new HighScore(ended);
      hg->getKey();
      delete hg;
      return false;
    }
  return true;
}

void Bomberman::draw()
{
  std::list<APlayer *>::iterator it;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_shader);

  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    if (!(*it)->isDead())
      (*it)->draw(this->_shader);

  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      if (this->_map[i][j])
	{
	  if (this->_map[i][j]->getType() == "F")
	    {
	      this->_map[i][j]->setModel(this->_modelPool->getGeometry());
	      this->_map[i][j]->setTexture(this->_texturePool->getFire());
	    }
	  this->_map[i][j]->draw(this->_shader);
	}
  setCam();
  this->_context.flush();
}

void	Bomberman::setCam()
{
  glm::mat4	transformation;
  int		nb = 0;

  std::list<APlayer *>::iterator it = this->_playerlist.begin();
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    if ((*it)->isDead() == false && (*it)->getID() != 0)
      nb++;
  it = this->_playerlist.begin();

  if (nb == 2)
    {
      std::list<APlayer *>::iterator itt;
      itt = std::next(this->_playerlist.begin(), 1);
      transformation = glm::lookAt(glm::vec3(((*it)->getX() + (*itt)->getX()) / 2.0,
					     ten(middle((*it)->getX(), (*it)->getY(), (*itt)->getX(), (*itt)->getY()) * 0.8),
					     ((*it)->getY() + (*itt)->getY()) / 1.99),
				   glm::vec3(((*it)->getX() + (*itt)->getX()) / 2.0, 0, ((*it)->getY() + (*itt)->getY()) / 2.0),
				   glm::vec3(0, 1, 0));
    }
  else
    {
      if ((*it)->isDead() == true)
	it = std::next(this->_playerlist.begin());
      transformation = glm::lookAt(glm::vec3((*it)->getX(), 15, (*it)->getY() + 5),
				   glm::vec3((*it)->getX(), 0, (*it)->getY()),
				   glm::vec3(0, 1, 0));
    }
  this->_shader.setUniform("view", transformation);
}

Bomberman::~Bomberman()
{
  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    delete (*it);
  delete this->_texturePool;
  delete this->_modelPool;
  delete this->_SoundPlayer;
  this->_context.stop();
}
