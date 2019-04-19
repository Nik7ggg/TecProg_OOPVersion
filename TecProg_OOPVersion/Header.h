#pragma once

#include "iostream"
#include "fstream"

const int weightofman=75;

using namespace std;
//Test vetky
class transport
{
public:
	// �������������, ���������� � ���� ������� �� ������
	static transport* Transport_Input(ifstream &ifst);				//��� ����� ����������� ��-��
	virtual bool Input(ifstream &ifst);					// ���� � ������ ���� �������
	virtual void Output(ofstream &ofst);		// ����� � ������ ���� �������
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
	size_t sizeoflist;			//���-�� ���������
	void Clear();				//������� ����������
public:

	//transport *current;	//��������� �� ������� �������
	void Out_Truck(ofstream &ofst);
	void sort();
	void In(ifstream &ifst);	//���� ������
	void Out(ofstream &ofst);	//����� ������
	
	container();				//������������� ����������
	~container() { Clear(); };
};


class truck : public transport {
private:
	int tonnage;
public:
	// �������������� ��������� ������
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	void Out_Truck(ofstream &ofst);

	float ProcessRatationPower();
	truck() {} // �������� ��� �������������.
};

class bus : public transport {
private:
	int passengercapacity;
public:
	// �������������� ��������� ������
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	float ProcessRatationPower();
	bus() {} // �������� ��� �������������.
};

class passenger_car : public transport
{
private:
	short int max_speed;
public:
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	float ProcessRatationPower();
	passenger_car() {} // �������� ��� �������������.

};
