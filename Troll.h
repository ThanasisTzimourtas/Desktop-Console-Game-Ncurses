#ifndef TROLL_H
#define TROLL_H

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


class Troll: public Moving{
private:
  const char* msgview;

public:
  const char* warcry ();
  ~Troll();

};

#endif // TROLL_H
