#include "Moving.h"


Moving::Moving (){

}


int Moving::getmovex () {return this->movex;}
int Moving::getmovey () {return this->movey;}
void Moving::setmovex (int x) {this->movex = x;}
void Moving::setmovey (int y) {this->movex = y;}



void Moving::move (int x, int y){

  movex = x;
  movey = y;
	keypad (stdscr, TRUE);
  ch = getch ();

  if (ch == KEY_UP){
		this->movey--;
    refresh ();
	}
	else if (ch == KEY_DOWN){
    this->movey++;
    refresh ();
	}
	else if (ch == KEY_LEFT){
    this->movex--;
    refresh ();

	}
	else if (ch == KEY_RIGHT){
    this->movex++;
    refresh ();

  }

}

void Moving::movegnome (int x, int y, int hx, int hy){
  movex = x;
  movey = y;
  herox = hx;
  heroy = hy;

  if ((herox > movex) && (heroy == movey)){
    movex++;
  }
  else if((herox < movex) && (heroy == movey)){
    movex--;
  }
  else if((herox == movex) && (heroy < movey)){
    movey--;
  }
  else if((herox == movex) && (heroy > movey)){
    movey++;
  }
  else{
    rx =  rand()%3+(-1);
    ry =  rand()%3+(-1);
    if (rx == 1 || rx == -1 || ry == 1|| ry == -1){
      movex += rx;
      movey += ry;
    }

  }

}


void Moving::movetroll (int x, int y, int hx, int hy){
  movex = x;
  movey = y;
  herox = hx;
  heroy = hy;

    if ((herox > movex) && (heroy == movey)){
      movex++;
    }
    else if((herox < movex) && (heroy == movey)){
      movex--;
    }
    else if((herox == movex) && (heroy < movey)){
      movey--;
      }
    else if((herox == movex) && (heroy > movey)){
      movey++;
    }
    else{
      rx =  rand()%3+(-1);
      ry =  rand()%3+(-1);
      if (rx == 1 || rx == -1 || ry == 1|| ry == -1){
        movex += rx;
        movey += ry;
      }

    }

}
