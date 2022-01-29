#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/ioctl.h>

#include "Engine.h"
#include "HiScore.h"

int main (int argc, char** argv){


  int ch;
  char c;
  bool Flag = TRUE;
  HiScore hiscore;
  if (argc < 3){
    if (argc < 3){
         std::cout << "Warning: You forgot to enter a map or name the savescore file. Remember first goes the name of the map 'mapname.txt' and then the save file 'filename.bin'!!" << std::endl;
         std::cout << "Note: In order to select the map, the map must be in the folder named Maps" <<std::endl;
    }
    exit (1);
}
std::string mapname(argv[1]);
std::string scorename(argv[2]);
do {
  do {
    Flag = TRUE;
    Engine *engine = new Engine(mapname);
    engine->play ();
    if (engine->Flag == FALSE){
      c = engine->menu();
      hiscore << &engine->player;
      hiscore.printinfile(scorename);
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
