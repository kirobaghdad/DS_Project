#include "UI.h"
#include<Windows.h>


UI::UI()
{
	cout << "Press I for Interactive Mode or S for Step-By-Step Mode" << endl;
	cin >> mode;
	
}

UI::~UI()
{
	
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void UI::printNow(Time t , Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv , LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv)
{
	cout << "Current Time(Day:Hour) :" << t.getDay() << ":" << t.getHour()<<endl; 
	//Waiting Cargos :
	int sum = cs.GetCount() + cv.GetCount() + cn.getcurrentsize();
	SetConsoleTextAttribute(hConsole, 1);
	cout << sum << " Waiting Cargos:["; cn.print(); cout << "]  ("; cs.print(); cout << ")   {"; cv.print();cout<< "}" << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 4);
	sum = Tcn.GetCount() + Tcs.GetCount() + Tcv.GetCount();
	cout << sum << " Empty Trucks:  ["; Tcn.print(); cout << "] , ("; Tcs.print(); cout << ") , {"; Tcv.print(); cout << "}" << endl;;
	SetConsoleTextAttribute(hConsole, 3);
	cout << "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 10);
	sum = Mcs.GetCount() + Mcv.GetCount() + Mcn.GetCount();
	cout << sum << " Moving Cargos::["; Mcn.print(); cout << "]  ("; Mcs.print(); cout << ")   {"; Mcv.print(); cout << "}" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	sum = Dcs.GetCount() + Dcv.GetCount() + Dcn.GetCount();
	cout << sum << " Delivered Cargos::["; Dcn.print(); cout << "]  ("; Dcs.print(); cout << ")   {"; Dcv.print(); cout << "}" << endl;
	SetConsoleTextAttribute(hConsole, 8);

}


void UI::print(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv)
{
	switch (mode)
	{

	case'I':
		std::cin.ignore();
		printNow(t, cn, cs, cv, Tcn, Tcs, Tcv, Mcn, Mcs, Mcv, Dcn, Dcs, Dcv);
		break;
	case 'S':
		Sleep(1000);
		printNow(t, cn, cs, cv, Tcn, Tcs, Tcv, Mcn, Mcs, Mcv, Dcn, Dcs, Dcv);
		break;

	}
}

               





