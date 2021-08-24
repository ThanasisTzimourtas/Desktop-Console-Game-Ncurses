#include "Engine.h"
#include "HiScore.h"

int main (){

  int ch;
  char c;
  bool Flag = TRUE;
  HiScore hiscore;
  do {
    do {
      Flag = TRUE;
      Engine *engine = new Engine;
      engine->play ();
      if (engine->Flag == FALSE){
        c = engine->menu();
        hiscore << &engine->player;
        hiscore.printinfile();
        engine->setprevscore(hiscore.gethiscore());
        delete engine;
        Flag = FALSE;
      }
    }
    while(Flag);
  }
  while (c == 'Y');
  hiscore.showhighscore ();
  ch = getch ();
  endwin ();
  return 0;

}
