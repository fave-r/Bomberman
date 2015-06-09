//
// main.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 13:51:26 2015 polydo_s
// Last update Tue Jun  9 16:35:39 2015 Leo Thevenet
//

#include "Menu.hh"
#include "Music.hh"

int	main()
{
  Menu          menu;
  Music		*SoundPlayer = new Music();

  SoundPlayer->createSound("./Assets/Sounds/intro.mp3", "intro");
  SoundPlayer->playSound("intro", true);

  try
    {
      VideoPlay();
      delete SoundPlayer;
      menu.initialize();
    }
  catch (const std::runtime_error &e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  while (menu.update() == true)
    menu.draw();
  return (0);
}
