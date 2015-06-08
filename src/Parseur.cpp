//
// Parseur.cpp for Parseur in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Thu May 28 15:44:49 2015 Leo Thevenet
// Last update Mon Jun  8 18:19:22 2015 Leo Thevenet
//

#include <fstream>
#include <iostream>
#include <string>

#include "Parseur.hh"

namespace	Parseur
{
  void		setConf(int largeur, int longueur, int joueur, int IA, int densite)
  {
    std::ofstream fichier(".conf", std::ofstream::out | std::ofstream::trunc);

    if(fichier)
      {
    	fichier << largeur << std::endl << longueur << std::endl << joueur << std::endl << IA << std::endl << densite << std::endl;
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
	x = (x < 10) ? 10 : x;
      }
    else
      x = 20;
    return x;
  }

  int		getY()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int y;

    if(fichier)
      {
  	fichier >> y >> y;
  	fichier.close();
	y = (y < 10) ? 10 : y;
      }
    else
      y = 20;
    return y;
  }

  int		getPlayer()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int p;

    if(fichier)
      {
  	fichier >> p >> p >> p;
  	fichier.close();
	p = (p < 1) ? 1 : (p > 2) ? 2 : p;
      }
    else
      p = 2; //remettre 1 quand Bomberman.cpp sera patch
    return p;
  }

  int		getIA()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int ia;

    if(fichier)
      {
  	fichier >> ia >> ia >> ia >> ia;
  	fichier.close();
	ia = (ia < 0) ? 0 : ia;
      }
    else
      ia = 0; //remettre 1 quand Bomberman.cpp sera patch
    return ia;
  }

  int		getDensite()
  {
    std::ifstream fichier(".conf", std::ifstream::in);
    int d;

    if(fichier)
      {
  	fichier >> d >> d >> d >> d >> d;
  	fichier.close();
      }
    else
      d = 40;
    return d;
  }
}
