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
	ofst << ", power=" << power << endl;
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

void container::MultiMethod(ofstream &fout)
{
	Node *current_first = head;
	Node *current_second = current_first->next;

	fout << "Multimethod." << endl;
	for (size_t i = 0; i < sizeoflist - 1; i++)
	{
		for (size_t j = i + 1; j < sizeoflist; j++)
		{
			current_first->transport->MultiMethod(current_second->transport, fout);
			current_first->transport->Output(fout);
			current_second->transport->Output(fout);
			current_second = current_second->next;
		}
		current_first = current_first->next;
		current_second = current_first->next;
	}

}
void truck::MultiMethod(transport *other, ofstream &fout)
{
	other->MMTruck(fout);
}

void truck::MMTruck(ofstream &fout)
{
	fout << "Truck and Truck." << endl;
}

void truck::MMBus(ofstream &fout)
{
	fout << "Bus and Truck." << endl;
}

void bus::MultiMethod(transport *other, ofstream &fout)
{
	other->MMBus(fout);
}

void bus::MMTruck(ofstream &fout)
{
	fout << "Truck and Bus." << endl;
}

void bus::MMBus(ofstream &fout)
{
	fout << "Bus and Bus." << endl;
}