#include "Engine.h"

Engine::Engine ():player(*(new Hero )), gnome(*(new Gnome )), troll(*(new Troll )){
  clear ();
  num_gems = 0;
  score = 0;
  num_gems = 0;

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  windowname_map ();
  read_map (mapname);
  checkspawn ();
  startparameters ();
  display_map ();
  display_engine_stats ();
  gems ('@');
  refresh ();
}


Engine::Engine (std::string mapname):player(*(new Hero )), gnome(*(new Gnome )), troll(*(new Troll )){
  clear ();
  num_gems = 0;
  score = 0;
  num_gems = 0;

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  read_map (mapname);
  checkspawn ();
  startparameters ();
  display_map ();
  display_engine_stats ();
  gems ('@');
  refresh ();
}

Engine::~Engine (){
  clear ();
  nodelay(stdscr, false);
  endwin ();

}


int Engine::get_curx (){return curx;}
int Engine::get_cury (){return cury;}

int Engine::get_posx (){return posx;}
int Engine::get_posy (){return posy;}

int Engine::getscore (){return score;}

int Engine::getgnomex (){return gnomex;}
int Engine::getgnomey (){return gnomey;}

int Engine::gettrollx (){return trollx;}
int Engine::gettrolly (){return trolly;}



void Engine::startparameters (){
	initscr();
	nodelay(stdscr,TRUE);
	noecho();
	curs_set(0);
}

void Engine::read_map (std::string mapname){
	int i =0, j = 0;
	int width = 0;
	std::ifstream in;
	in.open("Maps/"+ mapname);

	while (!in.eof()){
		char next = in.get();
		if ( next != '\n'){
			Map[i][j++] = next;

		}
		else{
			width = j;
			j = 0;
			i++;
		}

	}
 	maxheight = i;
	maxwidth = width;
}

void Engine::display_map (){
	int i,j;
	for (i = 0; i < maxheight; i++){
		for (j = 0; j < maxwidth; j++){
			move (i,j);
			if ((Map[i][j]) == '*'){
				addch((char)220);
			}
		}
	}
}

void Engine::display_hero (int x, int y){

	move (cury, curx);
	addch ('C');
	move (cury, curx);
	addch (' ');

  if ((Map[y][x]) != '*'){
    cury = y;
    curx = x;
  }
  else{

  }

 	move (cury, curx);
	addch ('C');

}

void Engine::display_gnome (int x, int y){

  move (gnomey, gnomex);
  addch ('G');
  move (gnomey, gnomex);
  addch (' ');

  if ((gnomex == posgem_x) && (gnomey == posgem_x)){
    move(posgem_y, posgem_x);
    addch (' ');
    move(posgem_y, posgem_x);
    addch('@');
  }

  if ((Map[y][x]) != '*'){
    gnomey = y;
    gnomex = x;
  }
  else{

  }

  move (gnomey, gnomex);
  addch ('G');

  if ((gnomex == posgem_x) && (gnomey == posgem_y)){
    move(posgem_y, posgem_x);
    addch (' ');
    move(posgem_y, posgem_x);
    addch('@');
  }
}

void Engine::display_troll (int x, int y){

  move (trolly, trollx);
  addch ('T');
  move (trolly, trollx);
  addch (' ');

  if ((trollx == posgem_x) && (trolly == posgem_y)){
    move(posgem_y, posgem_x);
    addch (' ');
    move(posgem_y, posgem_x);
    addch('@');
  }

  if ((Map[y][x]) != '*'){
    trolly = y;
    trollx = x;
  }
  else{

  }

  move (trolly, trollx);
  addch ('T');

  if ((trollx == posgem_x) && (trolly == posgem_y)){
    move(posgem_y, posgem_x);
    addch (' ');
    move(posgem_y, posgem_x);
    addch('@');
  }
}

void Engine::display_name (const char* name, size_t size){
	move((maxheight/2), (maxwidth + 5));
	printw("Name: ");
  for (int i = size-1; i >= 0; i--){
    printw("%c", name[i]+48);
  }
}

void Engine::display_engine_stats (){
	move((maxheight/2)-1, (maxwidth + 5));
    printw("Stats of Player");
}

void Engine::windowname_map (){
  std::fstream file;
	char mesg [] = "Give the name of the map: ";
  do{
  clear ();
	char str[80];
	int row,col;
	initscr ();
	getmaxyx(stdscr,row,col);
	mvprintw(row/2,(col-strlen(mesg))/2,"%s", mesg);
	getstr(str);

  std::string filename = std::string(str);
  file.open(filename.c_str());
	refresh ();
	mapname = str;
  }
  while(ShowFlags(file));
	clear ();
	endwin ();

}

bool Engine::ShowFlags (std::fstream &F){

  if(F.fail() == 1){
    return TRUE;
  }
  else{
    return FALSE;
  }
}

void Engine::checkspawn (){
	while(1){
		randposx = rand()%maxwidth; // +1 to avoid the 0
		randposy = rand()%maxheight;

		if ((Map[randposy][randposx]) != ' ')
		{
			continue;
		}

		curx = randposx;
		cury = randposy;
		break;
	}
  while(1)
  {
    randgnomx = rand()%maxwidth-3; // +1 to avoid the 0
    randgnomy = rand()%maxheight-3;

    if ((Map[randgnomy][randgnomx]) != ' ')
    {
      continue;
    }

    gnomex = randgnomx;
    gnomey = randgnomy;
    break;
  }

  refresh();
  while(1)
  {
    randtrollx = rand()%maxwidth-5; // +1 to avoid the 0
    randtrolly = rand()%maxheight-5;

    if ((Map[randtrolly][randtrollx]) != ' ')
    {
      continue;
    }

    trollx = randtrollx;
    trolly = randtrolly;
    break;
  }

  refresh();
}




void Engine::gems (char type){
	while(1)
	{
		randposx = rand()%maxwidth; // +1 to avoid the 0
		randposy = rand()%maxheight;


		if ((Map[randposy][randposx]) != ' ')
		{
			continue;
		}

		posgem_x = randposx;
		posgem_y = randposy;
		break;
	}

	move(posgem_y, posgem_x);
	addch(type);
	refresh();
}

void Engine::takegem (){
	//move(maxheight-3, 10);
	//printw("possgemx: %d, posgemy: %d ", posgem_x, posgem_y);
	if ((curx == posgem_x) && (cury == posgem_y)){
		num_gems++;
		score +=10;
		addch (' ');
		gems('@');
		printscore();


	}
}

bool Engine::takepapyrus (){
  if ((curx == posgem_x) && (cury == posgem_y)){
    score += 100;
    addch(' ');
    printscore ();
    refresh ();
    sleep (1);
    won ();
    return TRUE;
  }
  else{
    return FALSE;
  }

}

void Engine::printscore (){
	move((maxheight/2)+1, (maxwidth + 5));
	printw("Score: %d", score);

}

void Engine::setprevscore(int prevscore){
  this->prevscore = prevscore;
}

void Engine::printprevsocre (){
  move((maxheight/2)+2, (maxwidth + 5));
  printw("Previous Highscore: %d", prevscore);
}

void Engine::won (){

	move(((maxheight/2)+3), (maxwidth + 5));
	addch ('C');
	move (cury, curx);
	addch (' ');
  move(((maxheight/2)+3), (maxwidth + 7));
  addch('p');
  refresh ();
}

void Engine::lost (){

  move(((maxheight/2)+3), (maxwidth + 5));
  printw("YOU LOST!!");
  refresh();
}


void Engine::npc_responses (){
  if (((((curx < gnomex || curx > gnomex) && cury == gnomey)) && ((curx < trollx || curx > trollx) && cury == trolly)) || (((cury < gnomey || cury > gnomey) && curx == gnomex) && ((cury < trolly || cury > trolly) && curx == trollx))){
      move(((maxheight/2)+3), (maxwidth + 5));
      printw(gnome.gnomeandtroll());
      refresh();
  }
  else if ((curx < gnomex || curx > gnomex) && cury == gnomey){
    move(((maxheight/2)+3), (maxwidth + 5));
    printw(gnome.see_at_x());
    refresh();
  }
  else if((cury < gnomey || cury > gnomey) && curx == gnomex){
    move(((maxheight/2)+3), (maxwidth + 5));
    printw(gnome.see_at_y());
    refresh();

  }
  else if((curx < trollx || curx > trollx) && cury == trolly){
    move(((maxheight/2)+3), (maxwidth + 5));
    printw(troll.warcry());
    refresh();
  }
  else if((cury < trolly || cury > trolly) && curx == trollx){
    move(((maxheight/2)+3), (maxwidth + 5));
    printw(troll.warcry());
    refresh();

  }
  else{
    move(((maxheight/2)+3), (maxwidth + 5));
    printw ("                                                       ");
    refresh();
  }
}


const char Engine::menu (){
  initscr();
  noecho ();
  cbreak();
  getmaxyx(stdscr, maxheightmenu, maxwidthmenu);
  WINDOW *menuheader = newwin(2,maxwidthmenu-12, maxheightmenu-9,(maxwidthmenu/2)-6.5);
  WINDOW *menuwin = newwin(6,maxwidthmenu-12, maxheightmenu-8, 5);

  refresh ();
  wrefresh (menuwin);

  keypad(menuwin, true);
  std::string choices[2] = {"Yes", "No"};
  int choice;
  int highlight = 0;
  mvwprintw(menuheader,0,0,"Try Again???");
  wrefresh(menuheader);
  box(menuwin,0,0);

  while(1){
    wrefresh (menuwin);
    for (int i = 0; i < 2; i++){
      if (i == highlight)
        wattron(menuwin, A_REVERSE);
      mvwprintw(menuwin, i+1, 1, choices[i].c_str());
      wattroff(menuwin, A_REVERSE);
    }
    choice = wgetch(menuwin);
    switch(choice){
      case KEY_UP:
        highlight--;
        if(highlight == -1)
          highlight = 0;
        break;

      case KEY_DOWN:
        highlight++;
        if(highlight == 3)
          highlight = 2;
        break;
      default: break;
    }

    if (choice == 10)
      break;
  }
  keypad(menuwin, false);
  clear ();
  endwin ();
  return *choices[highlight].c_str();
}




void Engine::play (){

while(1){


  int counter;
  printprevsocre ();

  player.setmovex(get_curx());
  player.setmovey(get_cury());
  gnome.setmovex(getgnomex());
  gnome.setmovey(getgnomey());
  troll.setmovex(gettrollx());
  troll.setmovey(gettrolly());

  fisrtFlag = TRUE;

	while(fisrtFlag && num_gems < 10){
    usleep(100000);
    display_name(player.getname (), player.getsize());
    player.move(get_curx(), get_cury());
    display_hero(player.getmovex(), player.getmovey());
    troll.movetroll(gettrollx(), gettrolly(), player.getmovex(), player.getmovey());
    display_troll(troll.getmovex(), troll.getmovey());
    gnome.movegnome(getgnomex(), getgnomey(), player.getmovex(), player.getmovey());
    display_gnome(gnome.getmovex(), gnome.getmovey());
    npc_responses ();

    if ((curx == gnomex && cury == gnomey) || (curx == trollx && cury == trolly)){
      lost ();
      fisrtFlag = FALSE;
    }
    takegem();
    printscore();
    refresh ();
	}
  move(posgem_y, posgem_x);
  addch(' ');
  gems('p');
  if (fisrtFlag == TRUE){
    Flag = TRUE;
  }
  else{
    Flag = FALSE;
  }
  while(Flag){
    usleep(100000);
    if ((curx == gnomex && cury == gnomey) || (curx == trollx && cury == trolly)){
      lost ();
      Flag = FALSE;
    }

    display_name(player.getname (), player.getsize());
    player.move(get_curx(), get_cury());
    display_hero(player.getmovex(), player.getmovey());
    troll.movetroll(gettrollx(), gettrolly(),player.getmovex(), player.getmovey());
    display_troll(troll.getmovex(), troll.getmovey());
	  gnome.movegnome(getgnomex(), getgnomey(),player.getmovex(), player.getmovey());
    display_gnome(gnome.getmovex(), gnome.getmovey());
    npc_responses ();

    if ((curx == gnomex && cury == gnomey) || (curx == trollx && cury == trolly)){
      lost ();
      Flag = FALSE;
    }
    if(takepapyrus()){
      printscore();
      Flag = FALSE;
    }
  }

  player.setplayerscore (getscore());
  sleep (1);
  break;
  }
  endwin();
}
