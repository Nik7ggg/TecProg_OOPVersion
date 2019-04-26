#pragma once

#include "iostream"
#include "fstream"

const int weightofman=75;

using namespace std;

class Transport
{

public:
	static Transport* TransportInput(ifstream &ifst);//Для ввода последующих эл-ов
	virtual bool Input(ifstream &ifst);// ввод с учетом типа объекта
	virtual void Output(ofstream &ofst);// вывод с учетом типа объекта
	virtual float ProcessRatationPower() = 0 ;
	int GetPower();
	virtual void OutTruck(ofstream &ofst);
	bool Compare(Transport *other);
	virtual void MultyMethod(Transport *other,ofstream &ofst) = 0;
	virtual void MMTruck(ofstream &ofst) = 0;
	virtual void MMBus(ofstream &ofst) = 0;
	virtual void MMPassengerCar(ofstream &ofst) = 0;
private:
	int power;
	float fuel_consumption;

protected:
	Transport() {/**/ };
};


class Container
{
	struct Node
	{
		Transport *transport;
		Node *next;
	};

private:
	Node *head;
	size_t size_of_list;//кол-во элементов
	void Clear();//очистка контейнера

public:

	void OutTruck(ofstream &ofst);
	void Sort();
	void In(ifstream &ifst);//ввод матриц
	void Out(ofstream &ofst);//вывод матриц
	void MultyMethod(ofstream &ofst);
	Container();				//инициализация контейнера
	~Container() { Clear(); };
};


class Truck : public Transport {

private:
	int tonnage;

public:
	bool Input(ifstream &ifst); // ввод
	void Output(ofstream &ofst); // вывод
	void OutTruck(ofstream &ofst);
	void MultyMethod(Transport *other, ofstream &ofst);
	void MMTruck(ofstream &ofst);
	void MMBus(ofstream &ofst);
	void MMPassengerCar(ofstream &ofst);
	float ProcessRatationPower();
	Truck() {} // создание без инициализации.
};

class Bus : public Transport {

private:
	int passengercapacity;

public:
	bool Input(ifstream &ifst); // ввод
	void Output(ofstream &ofst); // вывод
	float ProcessRatationPower();
	void MultyMethod(Transport *other, ofstream &ofst);
	void MMTruck(ofstream &ofst);
	void MMBus(ofstream &ofst);
	void MMPassengerCar(ofstream &ofst);
	Bus() {} // создание без инициализации.
};

class PassengerCar : public Transport
{

private:
	short int max_speed;

public:
	bool Input(ifstream &ifst); // ввод
	void Output(ofstream &ofst); // вывод
	float ProcessRatationPower();
	void MultyMethod(Transport *other, ofstream &ofst);
	void MMTruck(ofstream &ofst);
	void MMBus(ofstream &ofst);
	void MMPassengerCar(ofstream &ofst);
	PassengerCar() {} // создание без инициализации.

};
