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

void UI::printNow(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck*> Tcn, LinkedQueue<Truck*> Tcs, LinkedQueue<Truck*> Tcv, PriorityQueue<Cargo> totalMoving, LinkedQueue<Cargo> totalDeliveredCargo, PriorityQueue<Truck*> assignedTrucks, LinkedQueue<Truck*> In_Checkup_N_Trucks, LinkedQueue<Truck*> In_Checkup_S_Trucks, LinkedQueue<Truck*> In_Checkup_VIP_Trucks,PriorityQueue<Truck*> MovingTrucks)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout << "Current Time(Day:Hour) " << t.getDay() << ":" << t.getHour() << endl;
	int sum;
	Truck* tempT;
	Cargo tempC;

	sum = cs.GetCount() + cv.GetCount() + cn.getcurrentsize();
	SetConsoleTextAttribute(hConsole, 2);
	cout << sum << " Waiting Cargos:  ["; cn.print(); cout << "]  ("; cs.print(); cout << ")   {"; cv.print(); cout << "}" << endl;
	SetConsoleTextAttribute(hConsole, 1);
	cout << "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 2);
	sum = assignedTrucks.GetCount();
	cout << sum << " Loading Trucks:  ";
	while (assignedTrucks.dequeue(tempT))
	{
		cout << tempT->GetID();
		switch (tempT->getType())
		{
		case'N':
			cout << "[";
			tempT->getCargosQueue().print();
			cout << "] ";
			break;
		case'S':
			cout << "(";
			tempT->getCargosQueue().print();
			cout << ") ";
			break;
		case'V':
			cout << "{";
			tempT->getCargosQueue().print();
			cout << "} ";
			break;
		default:
			break;
		}
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 1);
	cout << "---------------------------------------------------------------------------" << endl;

	SetConsoleTextAttribute(hConsole, 2);
	sum = Tcn.GetCount() + Tcs.GetCount() + Tcv.GetCount();
	cout << sum << " Empty Trucks:  [";
	while (Tcn.dequeue(tempT))
	{
		cout << tempT->GetID();
		if (!Tcn.isEmpty())
			cout << ",";
	}
	cout << "] , (";
	while (Tcs.dequeue(tempT))
	{
		cout << tempT->GetID();
		if (!Tcs.isEmpty())
			cout << ",";
	}
	cout << ") , {";
	while (Tcv.dequeue(tempT))
	{
		cout << tempT->GetID();
		if (!Tcv.isEmpty())
			cout << ",";
	}
	cout << "}" << endl;
	SetConsoleTextAttribute(hConsole, 1);
	cout << "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 2);
	sum = MovingTrucks.GetCount();
	cout << sum << " Moving Trucks:  ";
	while (MovingTrucks.dequeue(tempT))
	{
		cout << tempT->GetID();
		switch (tempT->getType())
		{
		case'N':
			cout << "[";
			tempT->getCargosQueue().print();
			cout << "] ";
			break;
		case'S':
			cout << "(";
			tempT->getCargosQueue().print();
			cout << ") ";
			break;
		case'V':
			cout << "{";
			tempT->getCargosQueue().print();
			cout << "} ";
			break;
		default:
			break;
		}
	}
	SetConsoleTextAttribute(hConsole, 1);
	cout <<endl<< "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 2);
	sum = In_Checkup_N_Trucks.GetCount() + In_Checkup_S_Trucks.GetCount() + In_Checkup_VIP_Trucks.GetCount();
	cout << sum << " In_Checkup Trucks:  [";
	while (In_Checkup_N_Trucks.dequeue(tempT))
	{
		cout << tempT->GetID();
		if (!In_Checkup_N_Trucks.isEmpty())
			cout << ",";
	}
	cout << "]  (";
	while (In_Checkup_S_Trucks.dequeue(tempT))
	{
		cout << tempT->GetID();
		if (!In_Checkup_S_Trucks.isEmpty())
			cout << ",";
	}
	cout << ")   {";
	while (In_Checkup_VIP_Trucks.dequeue(tempT))
	{
		cout << tempT->GetID();
		if (!In_Checkup_VIP_Trucks.isEmpty())
			cout << ",";
	}	
	cout << "}" << endl;
	SetConsoleTextAttribute(hConsole, 1);
	cout << "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 2);
	sum = totalDeliveredCargo.GetCount();
	cout << sum << " Delivered Cargos:  "; 
	while (totalDeliveredCargo.dequeue(tempC))
	{
		switch (tempC.getCargoType())
		{
		case'N':
			cout << "[" << tempC.getID() << "] ";
			break;
		case'S':
			cout << "(" << tempC.getID() << ") ";
			break;
		case'V':
			cout << "{" << tempC.getID() << "} ";
			break;
		default:
			break;
		}
	}
	cout << endl<<endl;
}




void UI::print(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck*>& Tcn, LinkedQueue<Truck*>& Tcs, LinkedQueue<Truck*>& Tcv, PriorityQueue<Cargo>& totalMoving, LinkedQueue<Cargo>& totalDeliveredCargo, PriorityQueue<Truck*>& assignedTrucks, LinkedQueue<Truck*>& In_Checkup_N_Trucks, LinkedQueue<Truck*>& In_Checkup_S_Trucks, LinkedQueue<Truck*>& In_Checkup_VIP_Trucks, PriorityQueue<Truck*> MovingTrucks)
{
	switch (mode)
	{
	case'I':
		std::cin.ignore();
		printNow(t, cn, cs, cv, Tcn, Tcs, Tcv, totalMoving, totalDeliveredCargo, assignedTrucks, In_Checkup_N_Trucks, In_Checkup_S_Trucks, In_Checkup_VIP_Trucks, MovingTrucks);
		break;
	case 'B':
		Sleep(1);
		printNow(t, cn, cs, cv, Tcn, Tcs, Tcv, totalMoving, totalDeliveredCargo, assignedTrucks, In_Checkup_N_Trucks, In_Checkup_S_Trucks, In_Checkup_VIP_Trucks, MovingTrucks);
		break;
	}
}

void UI::printSilentMode(char x)
{
	if (mode == 'S')
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






