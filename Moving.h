#ifndef MOVING_H
#define MOVING_H

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



class Moving{
private:
  int movex, movey;
  int herox, heroy;
  int rx, ry;  int ch;

public:
  Moving ();
  int getmovex ();
  int getmovey ();

  void setmovex (int);
  void setmovey (int);

  virtual void move (int, int);
  virtual void movegnome(int, int, int, int);
  virtual void movetroll(int, int, int, int);
};

#endif // HERO_H
