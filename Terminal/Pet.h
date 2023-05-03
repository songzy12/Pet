#ifndef Pet_H_
#define Pet_H_
#pragma once
#include<iostream>
using namespace std;

class Pet
{
public:
//	static int num;//static type indicates the number of pets
	Pet(int hunger=0, int boredom=0, const string& name="");
	Pet(const string& name);
	void Talk();
	void Eat(int food=4);
	void Play(int fun=4);
	string GetName() const;

	friend istream & operator >> (istream& is, Pet& pet)//overload the operator >>
	{
		cout<<"name: "<<endl;
//		cin >> pet.m_Name;
		cout<<"hunger: "<<endl;
		cin>> pet.m_Hunger;
		cout<<"boredom: "<<endl;
		cin>> pet.m_Boredom;
	}
private:
	int m_Hunger;
	int m_Boredom;
	string m_Name;
	int GetMood() const;
	void PassTime(int time=1);
	//to indicate the time past sofar, the hunger and boredom will increase with PassTime
};
//int Pet::num=0;
#endif