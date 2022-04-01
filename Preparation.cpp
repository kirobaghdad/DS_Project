#include "Preparation.h"
#include "Cargo.h"

Preparation::Preparation(Time T, int lu, int d, int c,char Type):Event(T,lu,d,c)
{
	TYP = Type;
}

void Preparation::Execute()
{
	//should create a new cargo and add it to the appropriate list
 
	switch (TYP)
	{
	case 'N':

		break;
	case 'S':

		break;
	case 'V':

		break;

	default:
      

		break;
	}



}
