#pragma once

#include "iostream"
#include "fstream"

const int weightofman=75;

using namespace std;
//Test vetky
class transport
{
public:
	// иденитфикация, порождение и ввод объекта из потока
	static transport* Transport_Input(ifstream &ifst);				//Для ввода последующих эл-ов
	virtual bool Input(ifstream &ifst);					// ввод с учетом типа объекта
	virtual void Output(ofstream &ofst);		// вывод с учетом типа объекта
	virtual float ProcessRatationPower() = 0 ;
	int Past_power();
	virtual void Out_Truck(ofstream &ofst);
	bool Compare(transport *other);
private:
	int power;
	float fuel_consumption;
protected:
	transport() {/**/ };
	//transport *next;
};


class container
{
	struct Node
	{
		transport *transport;
		Node *next;
	};
private:
	Node *head;
	size_t sizeoflist;			//кол-во элементов
	void Clear();				//очистка контейнера
public:

	//transport *current;	//указатель на текущий элемент
	void Out_Truck(ofstream &ofst);
	void sort();
	void In(ifstream &ifst);	//ввод матриц
	void Out(ofstream &ofst);	//вывод матриц
	
	container();				//инициализация контейнера
	~container() { Clear(); };
};


class truck : public transport {
private:
	int tonnage;
public:
	// переопределяем интерфейс класса
	bool Input(ifstream &ifst); // ввод
	void Output(ofstream &ofst); // вывод
	void Out_Truck(ofstream &ofst);

	float ProcessRatationPower();
	truck() {} // создание без инициализации.
};

class bus : public transport {
private:
	int passengercapacity;
public:
	// переопределяем интерфейс класса
	bool Input(ifstream &ifst); // ввод
	void Output(ofstream &ofst); // вывод
	float ProcessRatationPower();
	bus() {} // создание без инициализации.
};

class passenger_car : public transport
{
private:
	short int max_speed;
public:
	bool Input(ifstream &ifst); // ввод
	void Output(ofstream &ofst); // вывод
	float ProcessRatationPower();
	passenger_car() {} // создание без инициализации.

};
