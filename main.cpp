#include <iostream>
#include "Company.h"
#include "UI.h"

#define decode(a,b,c,d)a##b##c##d
#define DS_Project decode (m,a,i,n)
using namespace std;





int DS_Project()
{
	Company C;
	C.Loading();
	C.Simulator();
	C.Print();
	return 0;
}