#ifndef HISCORE
#define HISCORE

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
#include <list>


#include "Engine.h"

class HiScore{
private:
  int hiscore;
  char* playername;
  size_t size;
  int times;
  int val;

  Hero **tablesocres;
  //std::list <Hero> herostats;
  //std::list <Hero>::iterator ilist;

public:
  HiScore ();
  ~HiScore ();

  int gethiscore ();

  void showhighscore ();
  void appendscore(Hero);
  void print ();
  void printinfile (std::string);
  void operator<< (Hero *);


};



#endif // HISCORE
