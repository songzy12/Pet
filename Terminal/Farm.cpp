#include<iostream>
#include<string>
#include<vector>
#include "Farm.h"
#include "Pet.h"

//create a Farm with capacity of spaces
Farm::Farm(int spaces)
{
	m_Pets.reserve(spaces);
}

//add a new pet
void Farm::Add(const Pet& aPet)
{
	m_Pets.push_back(aPet);
}
//call all the pets in the farm one by one
void Farm::RollCall() const
{
	for(vector<Pet>::const_iterator iter=m_Pets.begin();
		iter!=m_Pets.end();++iter)
		cout<<iter->GetName()<<" here.\n";
	cout<<endl;
}