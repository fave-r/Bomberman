//
// Parseur.cpp for Parseur in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Thu May 28 15:44:49 2015 Leo Thevenet
// Last update Sun May 31 15:52:22 2015 Leo Thevenet
//

#include <fstream>
#include <iostream>
#include <string>

#include "Parseur.hh"

namespace	Parseur
{
  void		setConf(int largeur, int longueur, int joueur, int densite)
  {
    std::ofstream fichier(".conf", std::ofstream::out | std::ofstream::trunc);

    if(fichier)
      {
    	fichier << largeur << std::endl << longueur << std::endl << joueur << std::endl << densite << std::endl;
    	fichier.close();
      }
    else
      std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }

  int		getX()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int x;

    if(fichier)
      {
  	fichier >> x;
  	fichier.close();
      }
    else
      x = 20;
    return x;
  }

  int		getY()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int x, y;

    if(fichier)
      {
  	fichier >> x >> y;
  	fichier.close();
      }
    else
      y = 20;
    return y;
  }

  int		getPlayer()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int x, y, p;

    if(fichier)
      {
  	fichier >> x >> y >> p;
  	fichier.close();
      }
    else
      p = 2; //remettre 1 quand Bomberman.cpp sera patch
    return p;
  }

  int		getDensite()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int x, y, p, d;

    if(fichier)
      {
  	fichier >> x >> y >> p >> d;
  	fichier.close();
      }
    else
      d = 40;
    return d;
  }
}
