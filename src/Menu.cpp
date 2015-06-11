//
// Menu.cpp for Menu.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:34:29 2015 clément jean
// Last update Thu Jun 11 18:59:23 2015 Leo Thevenet

#include "Menu.hh"
#include "Options.hh"
#include "SDL2/SDL_image.h"
#include "HighScore.hh"

Menu::Menu()
{
  this->_SoundPlayer = new Music();
}

Menu::~Menu()
{
  if (this->_font)
    TTF_CloseFont(this->_font);
  TTF_Quit();
}

void		Menu::initialize()
{
  this->_SoundPlayer->createSound("./Assets/Sounds/MenuSound.wav", "menu");
  this->_SoundPlayer->playSound("menu", true);
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    throw std::runtime_error("SDL could not initialize!");
  this->_Main_Window = SDL_CreateWindow("Bomberman",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1050, 0);
  this->_Main_Renderer = SDL_CreateRenderer(this->_Main_Window, -1, SDL_RENDERER_ACCELERATED);
  this->_path = "./Assets/Menu/BackgroundMenu.jpg";
  if (TTF_Init() == -1)
    throw loading_error("HighScore : TTF error");
  if (!(this->_font = TTF_OpenFont("font/simple.ttf", 150)))
    throw std::runtime_error(TTF_GetError());
  this->_select = 0;
  this->_BackGroundS = IMG_Load(this->_path.c_str());
  this->_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_BackGroundS);
  GetAllMap();
  SetScreen();
}

void		Menu::SetScreen()
{
  SDL_Rect r;
  SDL_Color fg = {255, 255, 255, 255};
  SDL_Color sl = {255, 55, 55, 255};
  r.x = 250;
  r.y = 150;
  r.w = 500;
  r.h = 170;

  SDL_RenderClear(this->_Main_Renderer);
  SDL_RenderCopy(this->_Main_Renderer, this->_BackGroundT, NULL, NULL);

  PutStringOnScreen((this->_select == 0) ? sl : fg, r, "Jouer");
  r.y += 200;
  r.w += 30;
  PutStringOnScreen((this->_select == 1) ? sl : fg, r, "Charger");
  r.x += 600;
  r.w = 350;
  r.h = 150;
  PutStringOnScreen(fg, r, this->_allMap[this->_selectMap]);
  r.x -= 600;
  r.w = 500;
  r.h = 170;
  r.y += 200;
  r.w += 30;
  PutStringOnScreen((this->_select == 2) ? sl : fg, r, "HighScore");
  r.w -= 30;
  r.y += 200;
  PutStringOnScreen((this->_select == 3) ? sl : fg, r, "Options");
  r.y += 200;
}

void		Menu::PutStringOnScreen(SDL_Color fg, SDL_Rect r, std::string str)
{
  SDL_Surface *surf = TTF_RenderText_Blended(this->_font, str.c_str(), fg);
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, surf);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, &r);
  SDL_DestroyTexture(_BackGroundT);
  SDL_FreeSurface(surf);
}

void		Menu::MoveCursor(int where)
{
  this->_select += where;
  this->_select = (this->_select < 0) ? 3 : this->_select;
  this->_select = (this->_select > 3) ? 0 : this->_select;
}

void		Menu::GetAllMap()
{
  DIR		*dpdf;
  struct dirent	*epdf;

  dpdf = opendir("./map/");
  if (dpdf != NULL)
    while ((epdf = readdir(dpdf)))
      if (epdf->d_name[0] != '.')
	this->_allMap.push_back(epdf->d_name);
  this->_selectMap = 0;
  if (this->_allMap.empty())
    this->_allMap.push_back("No saved map");
}

void		Menu::MoveForLoad(int i)
{
  this->_selectMap += i;
  this->_selectMap = (this->_selectMap < 0) ? this->_allMap.size() -1 : this->_selectMap;
  this->_selectMap = (this->_selectMap >= (int)this->_allMap.size()) ? 0 : this->_selectMap;
}

bool		Menu::update()
{
  SDL_Joystick *aa = SDL_JoystickOpen(0);
  int a = 10000;

  if (SDL_JoystickGetButton(aa, 4) == 1)
    MoveCursor(-1);
  else if (SDL_JoystickGetButton(aa, 6) == 1)
    MoveCursor(1);
  else if (SDL_JoystickGetButton(aa, 5) == 1)
    {
      if (this->_select == 1)
	MoveForLoad(1);
    }
  else if (SDL_JoystickGetButton(aa, 7) == 1)
    {
      if (this->_select == 1)
	MoveForLoad(1);
    }
  else if (SDL_JoystickGetButton(aa, 14) == 1)
    {
      if (Check_Path() == false)
	return false;
    }
  else
    a = 0;
  usleep(a);

  SDL_WaitEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return false;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  exit(0);
	case SDLK_RETURN:
	  if (Check_Path() == false)
	    return false;
	  break;
	case SDLK_DOWN:
	  MoveCursor(1);
	  break;
	case SDLK_UP:
	  MoveCursor(-1);
	  break;
	case SDLK_RIGHT:
	  if (this->_select == 1)
	    MoveForLoad(1);
	  break;
	case SDLK_LEFT:
	  if (this->_select == 1)
	    MoveForLoad(-1);
	  break;
	}
      break;
    }
  SetScreen();
  return true;
}

void		Menu::launchBomberman(Bomberman *bomberman)
{
  while (bomberman->update() == true)
    bomberman->draw();
  delete bomberman;
}

bool          Menu::Check_Path()
{
  if (this->_select == 0)
    {
      delete this->_SoundPlayer;
      SDL_Quit();
      try
	{
	  Bomberman *bomberman = new Bomberman(Parseur::getX(), Parseur::getY(), Parseur::getPlayer());
	  bomberman->initialize();
	  launchBomberman(bomberman);
	}
      catch (const std::runtime_error &e)
	{
	  std::cerr << e.what() << std::endl;
	  return (false);
	}
    }
  else if (this->_select == 1)
    {
      delete this->_SoundPlayer;
      SDL_Quit();
      try
	{
	  Bomberman *bomberman = new Bomberman("./map/" + this->_allMap[this->_selectMap]);
	  bomberman->initialize();
	  launchBomberman(bomberman);
	}
      catch (const std::runtime_error &e)
	{
	  std::cerr << e.what() << std::endl;
	  return (false);
	}
    }
  else if (this->_select == 2)
    {
      HighScore *hg = new HighScore(this->_Main_Window, this->_Main_Renderer, &(this->event), 1);
      hg->getKey();
      delete hg;
      return true;
    }
  else
    {
      Options *opt = new Options(this->_Main_Window, this->_Main_Renderer, &(this->event));
      opt->FirstView();
      delete opt;
      return true;
    }
  return false;
}

void          Menu::draw()
{
  // SDL_RenderCopy(this->_Main_Renderer, this->_BackGroundT, NULL, NULL);
  SDL_RenderPresent(this->_Main_Renderer);
}
