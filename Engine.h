#ifndef ENGINE_H
#define ENGINE_H

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
#include "Hero.h"
#include "Gnome.h"
#include "Troll.h"

class Engine{
private:
  char Map[200][200];
  int maxwidth, maxheight;
  int randposx, randposy, posgem_x, posgem_y, randgnomx, randgnomy, randtrollx, randtrolly;
  int posx, posy;
  int curx, cury;
  int gnomex, gnomey;
  int trollx, trolly;
  int score, num_gems;
  char type, prevscore;
  int playesranswer;
  int maxwidthmenu, maxheightmenu;
  int counter;
  std::string mapname;


public:
  Gnome &gnome;
  Hero &player;
  Troll &troll;
	Engine (); // constructor
  ~Engine ();

  void read_map ();
  void startparameters ();
  void display_map ();
  void display_hero (int, int);
  void display_gnome (int, int);
  void display_troll (int, int);
  void checkspawn ();
  void gems (char);
  void takegem ();
  bool takepapyrus ();
  void printscore ();
  void won ();
  void lost ();

  int get_curx ();
  int get_cury ();
  int get_posx ();
  int get_posy ();
  int getscore ();
  int getgnomex ();
  int getgnomey ();
  int gettrolly ();
  int gettrollx ();
  void setprevscore(int);

  bool ShowFlags (std::fstream &);
  void npc_responses ();
  void printprevsocre ();
  void display_engine_stats ();
  void display_name(const char* name, size_t size);
  void windowname_map ();
  const char menu ();
  void play ();
	//void PrintScore() ;

  bool Flag;
  bool fisrtFlag;
};

#endif // ENGINE_H
