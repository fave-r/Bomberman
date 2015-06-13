//
// Error.hh for Error in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Thu Jun 11 10:45:57 2015 Leo Thevenet
// Last update Sat Jun 13 18:16:03 2015 clément jean
//

#ifndef __ERROR_HH__
#define __ERROR_HH__

#include <stdexcept>

class loading_error : public std::runtime_error
{
public:
  loading_error():runtime_error("Loading error"){}
  loading_error(const std::string &msg):runtime_error(msg.c_str()) {}
};

class exec_error : public std::runtime_error
{
public:
  exec_error():runtime_error("execution error"){}
  exec_error(const std::string &msg):runtime_error(msg.c_str()) {}
};

#endif
