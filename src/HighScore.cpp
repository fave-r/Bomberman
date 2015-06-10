//
// HighScore.cpp for HighScore in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  9 15:39:29 2015 Leo Thevenet
// Last update Wed Jun 10 10:16:53 2015 Leo Thevenet
//

#include "HighScore.hh"

void HighScore::init(SDL_Window *windows, SDL_Renderer *_Main_Renderer, SDL_Event *event)
{
  if (TTF_Init() == -1)
    std::cout << "ttf error" << std::endl;
  if (!(this->_font = TTF_OpenFont("font/simple.ttf", 150)))
    std::cout << TTF_GetError() << std::endl;// balancer exeption
  this->windows = windows;
  this->_Main_Renderer = _Main_Renderer;
  this->_event = event;
  this->_backS = IMG_Load("./Assets/Menu/BackgroundMenu.jpg");
  this->_backT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_backS);
  SDL_RenderClear(this->_Main_Renderer);
  SDL_RenderCopy(this->_Main_Renderer, this->_backT, NULL, NULL);
}

HighScore::HighScore(SDL_Window *windows, SDL_Renderer *_Main_Renderer, SDL_Event *event)
{
  init(windows, _Main_Renderer, event);
  this->_y = 150;
  showAllScore();
  SDL_RenderPresent(this->_Main_Renderer);
}

HighScore::HighScore(SDL_Window *windows, SDL_Renderer *_Main_Renderer, SDL_Event *event, const int &p)
{
  init(windows, _Main_Renderer, event);
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

void HighScore::showWinner(std::string str)
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

void HighScore::showAllScore()
{
  std::vector<int> _all = Score::getAllScore();
  if (_all.empty())
    {
      std::string str = "No score";
      putOneScore(str);
    }
  else
    {
      std::string str = "First score = ";
      str += std::to_string(_all.front());
      putOneScore(str);
      str = "Last score = ";
      str += std::to_string(_all.back());
      putOneScore(str);
    }
}

void HighScore::putOneScore(std::string str)
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

void HighScore::getKey()
{
  while (42)
    {
      SDL_WaitEvent(this->_event);
      switch ((*this->_event).type)
	{
	case SDL_QUIT:
	  return;
	case SDL_KEYDOWN:
	  switch ((*this->_event).key.keysym.sym)
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
