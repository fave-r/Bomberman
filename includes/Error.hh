//
// Error.hh for Error in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Thu Jun 11 10:45:57 2015 Leo Thevenet
// Last update Thu Jun 11 14:59:31 2015 Leo Thevenet
//

#ifndef __ERROR_HH__
#define __ERROR_HH__

#include <stdexcept>

class loading_error : public std::runtime_error
{
public:
  loading_error():runtime_error("Loading error"){}
  loading_error(std::string msg):runtime_error(msg.c_str()) {}
};

class exec_error : public std::runtime_error
{
public:
  exec_error():runtime_error("execution error"){}
  exec_error(std::string msg):runtime_error(msg.c_str()) {}
};

#endif
