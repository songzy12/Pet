#include <iostream>
#include "Pet.h"
using namespace std;

Pet::Pet(int hunger, int boredom,const string& name) :m_Hunger(hunger),m_Boredom(boredom),m_Name(name)
{
//	num++;
}
Pet::Pet(const string& name):m_Hunger(0),m_Boredom(0),m_Name(name)
{
//	num++;
}
inline int Pet::GetMood () const
{
	return (m_Hunger+m_Boredom);
}

void Pet::PassTime(int time)
{
	m_Hunger+=time;
	m_Boredom+=time;
}

void Pet::Talk() 
{
	cout<<"I'm a pet and I feel ";
	int mood=GetMood();
	if(mood > 15)
		cout<<"mad.\n";
	else if(mood > 10)
		cout<<"frustrated.\n";
	else if(mood > 5)
		cout<<"okay.\n";
	else
		cout<<"happy.\n";
	PassTime();
}

void Pet::Eat (int food)
{
	cout<<"Brruppp.\n";
	m_Hunger-=food;
	if(m_Hunger<0)
		m_Hunger=0;
	PassTime();
}

void Pet::Play(int fun)
{
	cout<<"Wheee!\n";
	m_Boredom-=fun;
	if(m_Boredom<0)
		m_Boredom=0;
	PassTime();
}

string Pet::GetName() const
{ 
	return m_Name;
}