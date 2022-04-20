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

void UI::printnow(Time t , Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv , LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv)
{
	cout << "Current Time(Day:Hour) :" << t.getDay() << ":" << t.getHour()<<endl; 
	//Waiting Cargos :
	int sum = cs.GetCount() + cv.GetCount() + cn.getcurrentsize();

	cout << sum << " Waiting Cargos:["; cn.print(); cout << "]  ("; cs.print(); cout << ")   {"; cv.print();cout<< "}" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = Tcn.GetCount() + Tcs.GetCount() + Tcv.GetCount();
	cout << sum << " Empty Trucks:  ["; Tcn.print(); cout << "] , ("; Tcs.print(); cout << ") , {"; Tcv.print(); cout << "}" << endl;;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = Mcs.GetCount() + Mcv.GetCount() + Mcn.GetCount();
	cout << sum << " Moving Cargos::["; Mcn.print(); cout << "]  ("; Mcs.print(); cout << ")   {";  Mcv.print(); cout << "}" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = Dcs.GetCount() + Dcv.GetCount() + Dcn.GetCount();
	cout << sum << " Delivered Cargos::["; Dcn.print(); cout << "]  ("; Dcs.print(); cout << ")   {"; Dcv.print(); cout << "}" << endl;


}


void UI::print(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv)
{
	switch (mode)
	{

	case'I':
		std::cin.ignore();
		printnow(t, cn, cs, cv, Tcn, Tcs, Tcv, Mcn, Mcs, Mcv, Dcn, Dcs, Dcv);
		break;
	case 'S':
		Sleep(1);
		printnow(t, cn, cs, cv, Tcn, Tcs, Tcv, Mcn, Mcs, Mcv, Dcn, Dcs, Dcv);
		break;

	}
}

               





