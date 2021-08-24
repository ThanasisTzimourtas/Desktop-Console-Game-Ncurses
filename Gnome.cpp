#include "Gnome.h"

Gnome::Gnome (){

}

Gnome::~Gnome (){
	delete msgview;
}

const char* Gnome::see_at_x (){
	msgview = "I can see you running away!!!";
	return msgview;
}

const char* Gnome::see_at_y (){
	msgview = "You cant escape me!!";
	return msgview;
}

const char* Gnome::gnomeandtroll (){
	msgview = "We are two and you are alone you will lose!!";
	return msgview;
}
