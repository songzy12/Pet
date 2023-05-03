#ifndef Farm_H_
#define Farm_H_
#include<iostream>
#include<string>
#include<vector>
#include "Pet.h"

class Farm
{
public:
	Farm(int spaces=1);//create a farm with one space
	void Add(const Pet& aPet);//add a new Pet to the farm
	void RollCall() const;//to give the name of the pets in the farm one by one.
private:
	vector<Pet> m_Pets;// use a vector to store all the pets
};

#endif