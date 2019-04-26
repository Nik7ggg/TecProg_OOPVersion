#pragma once

#include "iostream"
#include "fstream"

using namespace std;
//Test vetky
class transport
{
public:
	// �������������, ���������� � ���� ������� �� ������
	static transport* Transport_Input(ifstream &ifst);				//��� ����� ����������� ��-��
	virtual bool Input(ifstream &ifst);					// ���� � ������ ���� �������
	virtual void Output(ofstream &ofst);		// ����� � ������ ���� �������
	int Past_power();
	virtual void Out_Truck(ofstream &ofst);
	virtual void MultiMethod(transport *other, ofstream &ofst) = 0;
	virtual void MMTruck(ofstream &ofst) = 0;
	virtual void MMBus(ofstream &ofst) = 0;
private:
	int power;
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
	void In(ifstream &ifst);	//���� ������
	void Out(ofstream &ofst);	//����� ������
	void MultiMethod(ofstream &ofst);
	
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
	void MultiMethod(transport *other, ofstream &ofst);
	void MMTruck(ofstream &ofst);
	void MMBus(ofstream &ofst);
	truck() {} // �������� ��� �������������.
};

class bus : public transport {
private:
	int passengercapacity;
public:
	// �������������� ��������� ������
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	void MultiMethod(transport *other, ofstream &ofst);
	void MMTruck(ofstream &ofst);
	void MMBus(ofstream &ofst);
	bus() {} // �������� ��� �������������.
};
