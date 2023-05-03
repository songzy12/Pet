#include<iostream>
#include "Pet.h"
#include "Farm.h"



int main()
{
	Pet pet("Poochie");
	cout<<"My critter's name is "<<pet.GetName ()<<endl;

	cout<<"\nCreating pet farm.\n";
	Farm myFarm(3);

	cout<<"\nAdding three pets to the farm.\n";
	myFarm.Add (Pet("Moe"));
	myFarm.Add (Pet("Larry"));
	myFarm.Add (Pet("Curly"));

	cout<<"\nCalling Roll...\n";
	myFarm.RollCall ();

	pet.Talk ();

	int choice;
	do
	{
		cout<<"\nPet Caretaker\n\n";
		cout<<"0 - Quit\n";
		cout<<"1 - Listen to your pet\n";
		cout<<"2 - Feed your pet\n";
		cout<<"3 - Play with your pet\n\n";

		cout<<"Choice: ";
		cin>>choice;

		switch(choice)
		{
		case 0:
			cout<<"Good-bye.\n";
			break;
		case 1:
			pet.Talk ();
			break;
		case 2:
			pet.Eat();
			break;
		case 3:
			pet.Play ();
			break;
		default:
			cout<<"\nSorry, but "<<choice<<"is not a valid choice.\n";
		}
	}while(choice != 0);

	return 0;
}