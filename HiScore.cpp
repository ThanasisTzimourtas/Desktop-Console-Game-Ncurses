#include "HiScore.h"


HiScore::HiScore (){

  times = 0;
  val = 0;
}

HiScore::~HiScore (){

}

int HiScore::gethiscore (){

  if (times != 0){
    for (int i = 0; i < times; i++){
      if (tablesocres[i]->getplayerscore() > val)
        val = tablesocres[i]->getplayerscore ();
    }

  }
  return val;
}

void HiScore::operator<< (Hero *h){
  if (tablesocres == NULL){
    times = 1;
    Hero **buffer = new Hero *[1];
    tablesocres = buffer;
    tablesocres[0] = h;
  }
  else{
    times++;
    Hero **newtablesocres = new Hero *[times];
    for (int i = 0; i < times - 1; i++){
      newtablesocres[i] = tablesocres[i];
    }
    newtablesocres[times - 1] = h;
    tablesocres = newtablesocres;
  }
}

void HiScore::printinfile (){
  std::fstream F("HiScore.bin",std::ios::in| std::ios::out|std::ios::trunc);
  F << "HiScores from the game Mpampis Poteridis:";
  for (int i = 0; i < times; i++){
    int namesize = tablesocres[i]->getsize();
    char* hname = tablesocres[i]->getname();
    std::string str;
    for (int j =namesize-1; j>=0; j--){
      str += hname[j]+48;
    }
    F <<"\nName: "<< str <<", Score: "<<tablesocres[i]->getplayerscore();
  }
  F.close();
}

void HiScore::showhighscore (){
  int count;
  int row,col;
  getmaxyx(stdscr,row,col);
  initscr ();
  move((row/2)-1,(col/2-15));
  printw("High Scores:");
  for (int i = 0; i < times; i++){
    count = 6;
    move((row/2)+i,(col/2-15));
    int namesize = tablesocres[i]->getsize();
    char* hname = tablesocres[i]->getname();
    std::string str;
    printw ("Name: ");
    for (int j =namesize-1; j>=0; j--){
      count += 1;
      move((row/2+i),(col/2-15)+count);
      printw("%c", hname[j]+48);

    }
    move((row/2)+i,(col/2-15)+1+count);
    printw(", Score: %d", tablesocres[i]->getplayerscore());
    refresh();
  }

}
