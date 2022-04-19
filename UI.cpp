#include "UI.h"


UI::UI()
{
	cout << "Press I for Interactive Mode or S for Step-By-Step Mode" << endl;
	cin >> mode;
	switch (mode)
	{
	case'I':
	//	printInteractive();
		break;
	case'S':
	//	printStep_By_Step();
		break;
	default:
		break;
	}
}

UI::~UI()
{
	
}

               





