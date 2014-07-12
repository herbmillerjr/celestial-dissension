/****\
|  File Name: Intro.cpp
|  Description: Defines the introduction scene class
\****/

/*// includes //*/
#include "Intro.hpp"
#include "CD.hpp"
/*// end includes //*/

/*// define static members //*/
Intro *Intro::instance=NULL;
/*// end define static members //*/


/****\
|  Member Function Name: getInstance
|  Description: Returns the scene's instance, creating one if needed.
\****/
Intro* Intro::getInstance()
{
	if(!instance) {instance=new Intro();}
	return instance;
}
/*** end member function getInstance ***/

/****\
|  Member Function Name: Intro
|  Description: Constructor initializing scene
\****/
Intro::Intro()
{
	
}
/*** end member function Intro ***/
