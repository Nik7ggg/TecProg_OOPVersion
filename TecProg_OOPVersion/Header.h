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
	virtual int ProcessRatationPower() = 0 ;
	int Past_power();
	bool Compare(transport *other);
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
	int ProcessRatationPower();
	truck() {} // �������� ��� �������������.
};

class bus : public transport {
private:
	int passengercapacity;
public:
	// �������������� ��������� ������
	bool Input(ifstream &ifst); // ����
	void Output(ofstream &ofst); // �����
	int ProcessRatationPower();
	bus() {} // �������� ��� �������������.
};
