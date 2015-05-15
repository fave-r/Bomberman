//
// PhysicalPlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:59:33 2015 polydo_s
// Last update Fri May 15 16:59:24 2015 polydo_s
//

#ifndef PHYSICAL_PLAYER_HH
#define PHYSICAL_PLAYER_HH

/**
 * @class PhysicalPlayer
 * @brief A human controlled player
 *
 * The action are decided based on user's
 * inputs
 *
 * @author Swann Polydor (polydo_s)
 * @version 0.1
 * @bug No known bugs.
 *
 * @date May 5, 2015
 */
class	PhysicalPlayer : public APlayer {

public:
  virtual void	update();
};

#endif
