#include "header.h"

void container::Out_Truck(ofstream & ofst)

{
	Node *current = head;
	ofst << "Container contains " << sizeoflist << " elements." << endl;

	for (size_t i = 0; i < sizeoflist; i++)
	{
		ofst << i + 1 << ": ";
		if (current->transport == NULL)
		{
			ofst << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			current->transport->Out_Truck(ofst);
			//ofst << "The number of years that have passed since the year the language was created = "
			//<< current->transport->Past_power << endl;
		}
		current = current->next;
	}
}

void container::In(ifstream &ifst)
{
	Node *temp;
	Node *tail = NULL;
	while (!ifst.eof())
	{
		temp = new Node;
		temp->transport = transport::Transport_Input(ifst);
		++sizeoflist;

		if (head == NULL)//
		{
			temp->next = temp;
			head = temp;
			tail = temp;
		}
		else//������� ��������� ����� ����������, �� ������������
		{
			temp->next = head;
			tail->next = temp;                    //������ ������ � ��������� �� ��������� ��������� ����
			tail = temp;                          //��������� �������� �������=������ ��� ���������.
		}
	}
}

void container::Out(ofstream &ofst)
{
	Node *current = head;
	ofst << "Container contains " << sizeoflist << " elements." << endl;

	for (size_t i = 0; i < sizeoflist; i++)
	{
		ofst << i + 1 << ": ";
		if (current->transport == NULL)
		{
			ofst << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			current->transport->Output(ofst);
			//ofst << "The number of years that have passed since the year the language was created = "
				//<< current->transport->Past_power << endl;
		}
		current = current->next;
	}
}

void container::Clear()
{
	while (sizeoflist != 0)                        //���� ����������� ������ �� ������ �������
	{
		Node *temp = head->next;
		delete head;                           //����������� ������ �� ��������� ��������
		head = temp;                           //����� ������ ������ �� ����� ���������� ��������
		sizeoflist--;                                //���� ������� ����������. ������������ ����� ���������
	}

}

container::container()
{
	head = NULL;
	sizeoflist = 0;
}

transport* transport::Transport_Input(ifstream &ifst)// � ��������������� �����, ��� � ����������� �����
{

	transport *temporary;	//��������� ���������
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		temporary = new truck; break;
	case 2:
		temporary = new bus; break;
	default:
		return 0;
	}
	if (!temporary->Input(ifst))
	{
		return NULL;
	}
	else
	{
		return temporary;
	}
}

bool transport::Input(ifstream & ifst)
{
	ifst >> power;
	ifst >> fuel_consumption;
	if (power > 0)
		return true;
	else
		return false;
}

int transport::Past_power()
{
	return power;
}

void transport::Out_Truck(ofstream & ofst)
{
	ofst << endl;
}

void transport::Output(ofstream & ofst)
{
	ofst << ", power=" << power;
	ofst << ", fuel consumption=" << fuel_consumption << endl;
}


bool  truck::Input(ifstream &ifst)
{
	ifst >> tonnage;
	if (!transport::Input(ifst))
	{
		return false;
	}

	return true;
}

void truck::Output(ofstream &ofst)
{
	ofst << "It's truck: tonnage=" << tonnage;
	transport::Output(ofst);
}

void truck::Out_Truck(ofstream & ofst)
{
	ofst << "It's truck: tonnage=" << tonnage;
	transport::Output(ofst);
}


bool bus::Input(ifstream &ifst)
{
	ifst >> passengercapacity;
	if (!transport::Input(ifst))
	{
		return false;
	}

	return true;
}

void bus::Output(ofstream &ofst)
{
	ofst << "It's bus: passengercapacity=" << passengercapacity;
	transport::Output(ofst);
}
