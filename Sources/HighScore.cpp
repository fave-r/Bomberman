//
// HighScore.cpp for HighScore in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  9 15:39:29 2015 Leo Thevenet
// Last update Sun Jun 14 10:20:10 2015 clément jean
//

#include "HighScore.hh"

HighScore::HighScore(SDL_Window *windows, SDL_Renderer *_Main_Renderer, SDL_Event *event)
{
  this->_event = *event;
  this->windows = windows;
  this->_Main_Renderer = _Main_Renderer;
  init();
  this->_y = 150;
  showAllScore();
  SDL_RenderPresent(this->_Main_Renderer);
}

HighScore::HighScore(const int &p)
{
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    throw std::runtime_error("SDL could not initialize!");
  this->windows = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1050, 0);
  this->_Main_Renderer = SDL_CreateRenderer(this->windows, -1, SDL_RENDERER_ACCELERATED);

  init();
  this->_y = 100;
  std::string str = ((p == 1) ? "Player 1" : (p == 2) ? "Player 2" : "Nobody");
  str += " Win the game !";
  showWinner(str);
  showAllScore();
  SDL_RenderPresent(this->_Main_Renderer);
}

HighScore::~HighScore()
{
  SDL_DestroyTexture(this->_backT);
  SDL_FreeSurface(this->_backS);
  if (this->_font)
    TTF_CloseFont(this->_font);
  TTF_Quit();
}

void		HighScore::init()
{
  if (TTF_Init() == -1)
    throw loading_error("HighScore : TTF error");
  if (!(this->_font = TTF_OpenFont("Ressources/font/simple.ttf", 150)))
    throw loading_error(TTF_GetError());
  this->_backS = IMG_Load("./Assets/Menu/BackgroundMenu.jpg");
  this->_backT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_backS);
  SDL_RenderClear(this->_Main_Renderer);
  SDL_RenderCopy(this->_Main_Renderer, this->_backT, NULL, NULL);
}

void		HighScore::showWinner(const std::string &str)
{
  SDL_Rect r;
  r.x = 470;
  r.y = this->_y;
  r.w = 900;
  r.h = 180;

  SDL_Surface *surf = TTF_RenderText_Blended(this->_font, str.c_str(), {255, 255, 255, 255});
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, surf);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, &r);
  SDL_DestroyTexture(_BackGroundT);
  SDL_FreeSurface(surf);
  this->_y += 200;
}

void		HighScore::showAllScore()
{
  std::pair<int, int> _all = Score::getAllScore();

  std::string str = "Player 1 : ";
  str += std::to_string(_all.first);
  putOneScore(str);
  str = "Player 2 : ";
  str += std::to_string(_all.second);
  putOneScore(str);
}

void		HighScore::putOneScore(const std::string &str)
{
  SDL_Rect r;
  r.x = 660;
  r.y = this->_y;
  r.w = 500;
  r.h = 100;

  SDL_Surface *surf = TTF_RenderText_Blended(this->_font, str.c_str(), {255, 255, 255, 255});
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, surf);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, &r);
  SDL_DestroyTexture(_BackGroundT);
  SDL_FreeSurface(surf);
  this->_y += 120;
}

void		HighScore::getKey()
{
  while (42)
    {
      SDL_WaitEvent(&(this->_event));
      switch (this->_event.type)
      	{
      	case SDL_QUIT:
      	  return;
      	case SDL_KEYDOWN:
      	  switch (this->_event.key.keysym.sym)
      	    {
      	    case SDLK_ESCAPE:
      	      return;
      	    case SDLK_RETURN:
      	      return;
      	      break;
      	    default:
      	      break;
      	    }
      	default:
      	  break;
      	}
    }
}
