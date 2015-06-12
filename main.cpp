//
// main.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 13:51:26 2015 polydo_s
// Last update Fri Jun 12 22:10:12 2015 clément jean
//

#include "Error.hh"
#include "Menu.hh"
#include "Music.hh"

int	main()
{
      Menu		menu;
  try
    {
      Music		*SoundPlayer = new Music();

      SoundPlayer->createSound("./Ressources/Sounds/intro.mp3", "intro");
      SoundPlayer->playSound("intro", true);
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
