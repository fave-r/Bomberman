//
// Bomberman.cpp for Bomberman.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:37:06 2015 clément jean
// Last update Fri Jun 12 04:10:52 2015 clément jean
//

#include "Bomberman.hh"
#include "MapSaver.hh"

Bomberman::Bomberman(unsigned int w, unsigned int h, unsigned int p)
  : _w(w), _h(h), _p(p)
{
  this->_map = Map::generate(this->_w, this->_h, this->_p);
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
  if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    throw loading_error("Bomberman : Joystick error");

  this->_SoundPlayer = new Music();
  this->_texturePool = new TexturePool();
  this->_modelPool = new ModelPool();

  this->_texturePool->init();
  this->_modelPool->init();

  glEnable(GL_DEPTH_TEST);

  if (this->_namedMap != "")
    getMap();
  if (!this->_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_shader.build())
    throw std::runtime_error("shader erreur");

  projection = glm::perspective(70.0f, 1920.0f / 1080.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(this->_w / 2, ten((this->_w + this->_h) / 2), this->_h / 2),
			       glm::vec3(this->_w / 2, 0, this->_h / 2 - 0.0001),
			       glm::vec3(0, 1, 0));

  this->_shader.bind();
  this->_shader.setUniform("view", transformation);
  this->_shader.setUniform("projection", projection);
  init_map();
  if (this->_playerlist.empty())
    init_player();
  else
    end_init_player();
  draw();
  //  this->_SoundPlayer->createSound("./Assets/Sounds/BackgroundSound.wav", "game");
  //this->_SoundPlayer->playSound("game", true);
}

void	Bomberman::init_map()
{
  AObject        *model;

  //this->_objects.push_back(new Skybox(-1, -1));
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
  p1->setTexture(this->_texturePool->getPlayer());
  this->_playerlist.push_back(p1);
  if (this->_p == 2)
    {
      PhysicalPlayer *p2 = new PhysicalPlayer(this->_w - 2, this->_h - 2, APlayer::UP);
      this->_playerlist.push_back(p2);
    }
  end_init_player();
}

void	Bomberman::end_init_player()
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
  this->_context.updateClock(this->_clock);
  this->_context.updateInputs(this->_input);

  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    return false;
  if (this->_input.getKey(SDLK_F5))
    {
      MapSaver::saveMap(this->_map, this->_playerlist, this->_w, this->_h, this->_p);
      std::stringstream ss;
      this->_numberOfSave++;
      ss << "Save" << this->_numberOfSave << ".tga";
      saveScreenshot(ss.str(), 1920, 1080);
    }
  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      {
	IUpdatable *updatable = dynamic_cast<IUpdatable *>(this->_map[i][j]);
	if (updatable)
	  updatable->update(this->_clock, this->_map, this->_playerlist);
      }

  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    {
      if (!(*it)->isDead())
	{
	  PhysicalPlayer *player = dynamic_cast<PhysicalPlayer *>(*it);
	  if (player)
	    player->setInput(this->_input);
	  (*it)->update(this->_clock, this->_map, this->_playerlist);
	  (*it)->resetRotate();
	  int rot = ((*it)->getOrientation() % 2 == 0) ? (*it)->getOrientation() * 90 - 180 : (*it)->getOrientation() * 90;
	  (*it)->rotate(glm::vec3(0, 1, 0), rot);
	  (*it)->SetPos(glm::vec3((*it)->getX(), 1.001, (*it)->getY()));
	}
    }
  this->_shader.bind();
  return true;
}

void Bomberman::draw()
{
  glm::mat4 transformation;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->_shader.bind();

  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_shader); // a virer
  std::list<APlayer *>::iterator it;
  for (it = this->_playerlist.begin(); it != this->_playerlist.end(); ++it)
    if (!(*it)->isDead())
      (*it)->draw(this->_shader);
  for (unsigned int i = 0; i < this->_map.size(); ++i)
    for (unsigned int j = 0; j < this->_map[i].size(); ++j)
      if (this->_map[i][j])
	{
	  Fire	*fire = dynamic_cast<Fire *>(this->_map[i][j]);
	  if (fire)
	    {
	      this->_map[i][j]->setModel(this->_modelPool->getGeometry());
	      this->_map[i][j]->setTexture(this->_texturePool->getFire());
	    }
	  this->_map[i][j]->draw(this->_shader);
	}
  it = this->_playerlist.begin();
  if (this->_p == 2)
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
    transformation = glm::lookAt(glm::vec3((*it)->getX(), 15, (*it)->getY() + 5),
				 glm::vec3((*it)->getX(), 0, (*it)->getY()),
				 glm::vec3(0, 1, 0));
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
  delete this->_SoundPlayer;
}
