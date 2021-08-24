#include "Troll.h"



Troll::~Troll (){
	delete msgview;
}



const char* Troll::warcry (){
	msgview = "@@!@#@#%^&@!!!";
	return msgview;
}
