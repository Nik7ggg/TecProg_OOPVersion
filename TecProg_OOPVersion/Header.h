#pragma once

#include "iostream"
#include "fstream"

const int weightofman=75;

using namespace std;

class Transport
{

public:
	static Transport* TransportInput(ifstream &ifst);//��� ����� ����������� ��-��
	virtual bool Input(ifstream &ifst);// ���� � ������ ���� �������
	virtual void Output(ofstream &ofst);// ����� � ������ ���� �������
	virtual float ProcessRatationPower() = 0 ;
	int GetPower();
	virtual void OutTruck(ofstream &ofst);
	bool Compare(Transport *other);

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
	size_t size_of_list;//���-�� ���������
	void Clear();//������� ����������

public:

	void OutTruck(ofstream &ofst);
	void Sort();
	void In(ifstream &ifst);//���� ������
	void Out(ofstream &ofst);//����� ������
	
	Container();				//������������� ����������
	~Container() { Clear(); };
};


class Truck : public Transport {

private:
	int tonnage;

public:
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	void OutTruck(ofstream &ofst);

	float ProcessRatationPower();
	Truck() {} // �������� ��� �������������.
};

class Bus : public Transport {

private:
	int passengercapacity;

public:
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	float ProcessRatationPower();
	Bus() {} // �������� ��� �������������.
};

class PassengerCar : public Transport
{

private:
	short int max_speed;

public:
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	float ProcessRatationPower();
	PassengerCar() {} // �������� ��� �������������.

};
