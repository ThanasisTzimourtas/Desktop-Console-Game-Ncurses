#ifndef GNOME_H
#define GNOME_H

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


class Gnome: public Moving{
private:
	const char* msgview;

public:
  Gnome ();
	~Gnome();
  const char* see_at_x ();
  const char* see_at_y ();
  const char* gnomeandtroll ();
};

#endif // GNOME_H
