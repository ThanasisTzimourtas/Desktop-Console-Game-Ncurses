#ifndef HERO_H
#define HERO_H

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <panel.h>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include <string>

#include "Moving.h"


class Hero: public Moving{
private:
  char* name;
  size_t sizename;
  int playerscore;


public:
  Hero ();
  Hero (const Hero &);
  ~Hero ();

  void setname(const char*);
  void setplayerscore (int);
  void windowplayname ();

  char* getname ();
  size_t getsize ();
  int getplayerscore ();

};

#endif // HERO_H
