#include <iostream>
#include "Company.h"
#include "UI.h"
#include "Truck.h"
#define decode(a,b,c,d)a##b##c##d
#define DS_Project decode (m,a,i,n)
using namespace std;



int Truck::J = 0;

int DS_Project()
{
	Company C;
	C.LoadFile();
	C.Simulator();
	C.Print();
	return 0;
}