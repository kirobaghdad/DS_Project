#include "UI.h"
#include<Windows.h>


UI::UI()
{
	cout << "Press I for Interactive Mode or B for Step-By-Step Mode or S for Silent Mode" << endl;
	cin >> mode;
	
}

UI::~UI()
{
	
}

void UI::printNow(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv , LinkedQueue<Truck> assignedTrucks, LinkedQueue<Truck>& In_Checkup_N_Trucks, LinkedQueue<Truck>& In_Checkup_S_Trucks, LinkedQueue<Truck>& In_Checkup_VIP_Trucks)
{


	cout << "Current Time(Day:Hour) " << t.getDay() << ":" << t.getHour() << endl;
	int sum;
	Truck tempT;

	sum = cs.GetCount() + cv.GetCount() + cn.getcurrentsize();
	cout << sum << " Waiting Cargos:  ["; cn.print(); cout << "]  ("; cs.print(); cout << ")   {"; cv.print(); cout << "}" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = assignedTrucks.GetCount();
	cout << sum << " Loading Trucks:  ";
	while (assignedTrucks.dequeue(tempT))
	{
		cout << tempT.GetID();
		switch (tempT.getType())
		{
		case'N':
			cout << "[";
			tempT.getCargosQueue().print();
			cout << "] ";
		case'S':
			cout << "(";
			tempT.getCargosQueue().print();
			cout << ") ";
		case'V':
			cout << "{";
			tempT.getCargosQueue().print();
			cout << "} ";
		default:
			break;
		}
	}
	cout << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = Tcn.GetCount() + Tcs.GetCount() + Tcv.GetCount();
	cout << sum << " Empty Trucks:  ["; Tcn.print(); cout << "] , ("; Tcs.print(); cout << ") , {"; Tcv.print(); cout << "}" << endl;;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = Mcs.GetCount() + Mcv.GetCount() + Mcn.GetCount();
	cout << sum << " Moving Cargos:  ["; Mcn.print(); cout << "]  ("; Mcs.print(); cout << ")   {";  Mcv.print(); cout << "}" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = In_Checkup_N_Trucks.GetCount() + In_Checkup_S_Trucks.GetCount() + In_Checkup_VIP_Trucks.GetCount();
	cout << sum << " In_Checkup Trucks:  ["; In_Checkup_N_Trucks.print(); cout << "]  ("; In_Checkup_S_Trucks.print(); cout << ")   {";  In_Checkup_VIP_Trucks.print(); cout << "}" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	sum = Dcs.GetCount() + Dcv.GetCount() + Dcn.GetCount();
	cout << sum << " Delivered Cargos:  ["; Dcn.print(); cout << "]  ("; Dcs.print(); cout << ")   {"; Dcv.print(); cout << "}" << endl;
	cout << endl;
}




void UI::print(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv , LinkedQueue<Truck>& assignedTrucks, LinkedQueue<Truck>& In_Checkup_N_Trucks, LinkedQueue<Truck>& In_Checkup_S_Trucks, LinkedQueue<Truck>& In_Checkup_VIP_Trucks)
{
	switch (mode)
	{
	case'I':
		std::cin.ignore();
		printNow(t, cn, cs, cv, Tcn, Tcs, Tcv, Mcn, Mcs, Mcv, Dcn, Dcs, Dcv, assignedTrucks,In_Checkup_N_Trucks, In_Checkup_S_Trucks, In_Checkup_VIP_Trucks);
		break;
	case 'B':
		Sleep(1);
		printNow(t, cn, cs, cv, Tcn, Tcs, Tcv, Mcn, Mcs, Mcv, Dcn, Dcs, Dcv, assignedTrucks,In_Checkup_N_Trucks, In_Checkup_S_Trucks, In_Checkup_VIP_Trucks);
		break;
	}
}

void UI::printSilentMode(char x)
{
	if (mode=='S')
	{
		switch (x)
		{
		case's':
			cout << "Silent Mode" << endl << "Simulation Starts..." << endl;
			break;
		case'e':
			cout << "Simulation ends, Output file created";
			break;
		default:
			break;
		}
	}
}
        





