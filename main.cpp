#include <iostream>
#include "Company.h"
#include "UI.h"

#define decode(a,b,c,d)a##b##c##d
#define DS_Project decode (m,a,i,n)
using namespace std;



ostream& operator<<(ostream& os, const Truck& T)
{
	os << T.GetID();
	return os;
}

ostream& operator<<(ostream& os, const Cargo& c)
{
	os << c.getID();
	return os;
}



int DS_Project()
{
	Company C;
	C.Loading();
	C.Simulator();
	C.Print();
	return 0;
}