#include "Hero.h"


Hero::Hero (): Moving(){
  windowplayname ();
}

 Hero::~Hero (){
  delete name;
 }


Hero::Hero (const Hero &h){
  sizename = h.sizename;
  name = new char [sizename];
  memcpy (name, h.name, sizename);
  playerscore = h.playerscore;
}

void Hero::setname (const char* name){
  size_t len = strlen (name);
  if (len){
    this->name = new char [len];
    for (int i = 0; i <= len; i++){
      this->name[i] = name[len-1-i] - 48;
    }
    this->sizename = len;
  }
}

void Hero::setplayerscore (int score){
  this->playerscore = score;
}

void Hero::windowplayname (){
	char mesg [] = "Give your name: ";
	char str[80];
	int row,col;
	initscr ();
	getmaxyx(stdscr,row,col);
	mvprintw(row/2,(col-strlen(mesg))/2,"%s", mesg);
	getstr(str);
  setname(str);
	endwin ();


}


char* Hero::getname (){return this->name;}
size_t Hero::getsize (){return this->sizename;}
int Hero::getplayerscore (){return this->playerscore;}
