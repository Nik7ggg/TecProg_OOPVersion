#include "header.h"
#include <string>
#include <fstream>

void Container::OutTruck(ofstream & ofst)
{
	Node *current = head;
	ofst << "Container contains " << size_of_list << " elements." << endl;

	for (size_t i = 0; i < size_of_list; i++)
	{
		ofst << i + 1 << ": ";
		if (current->transport == NULL)
		{
			ofst << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			current->transport->OutTruck(ofst);
		}
		current = current->next;
	}
}

void Container::In(ifstream &ifst)
{
	Node *temp;
	Node *tail = NULL;
	while (!ifst.eof())
	{
		temp = new Node;
		temp->transport = Transport::TransportInput(ifst);
		++size_of_list;

		if (head == NULL)
		{
			temp->next = temp;
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			tail->next = temp;//Запись данных в следующее за последним элементом поле
			tail = temp;//Последний активный элемент=только что созданный.
		}
	}
}

void Container::Out(ofstream &ofst)
{
	Node *current = head;
	ofst << "Container contains " << size_of_list << " elements." << endl;

	for (size_t i = 0; i < size_of_list; i++)
	{
		ofst << i + 1 << ": ";
		if (current->transport == NULL)
		{
			ofst << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			current->transport->Output(ofst);

		}
		current = current->next;
	}
}

void Container::Clear()
{
	while (size_of_list != 0)                        //Пока размерность списка не станет нулевой
	{
		Node *temp = head->next;
		delete head;                           //Освобождаем память от активного элемента
		head = temp;                           //Смена адреса начала на адрес следующего элемента
		size_of_list--;                                //Один элемент освобожден. корректируем число элементов
	}

}

Container::Container()
{
	head = NULL;
	size_of_list = 0;
}

Transport* Transport::TransportInput(ifstream &ifst)// в контейнеровском файле, как в процедурном стиле
{
	Transport *temporary;	//временные указатели
	string temp;
	ifst >> temp;

	if (temp == "\0")
	{
		return NULL;
	}

	if (temp.length()  > 1)
	{
		ifst.get();
		getline(ifst, temp, '\n');
		return NULL;
	}

	if (!isdigit(int(unsigned char(temp.front()))))
	{
		ifst.get();
		getline(ifst, temp, '\n');
		return NULL;
	}

	int state = stoul(temp);

	switch (state) {
	case 1:
		temporary = new Truck; break;

	case 2:
		temporary = new Bus; break;

	case 3:
		temporary = new PassengerCar; break;

	default:
		ifst.get();
		getline(ifst, temp, '\n');
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

bool Transport::Input(ifstream & ifst)
{
	string temp;
	ifst >> temp;

	if (temp == "\0")
	{
		return false;
	}

	if (temp.length() >= 4)
	{
		getline(ifst, temp, '\n');
		return false;
	}

	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			getline(ifst, temp, '\n');
			return false;
		}
	}

	power = stoul(temp);

	ifst >> temp;
	if (temp == "\0")
	{
		return false;
	}

	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			getline(ifst, temp, '\n');
			return false;
		}
	}

	if (temp.length() >= 4)
	{
		getline(ifst, temp, '\n');
		return false;
	}

	fuel_consumption = stoul(temp);

	return true;
}

int Transport::GetPower()
{
	return power;
}

void Transport::OutTruck(ofstream & ofst)
{
	ofst << endl;
}

bool Transport::Compare(Transport * other)
{
	if (this == NULL && other != NULL)
	{
		return true;
	}

	if (this != NULL && other == NULL)
	{
		return false;
	}

	if (this == NULL && other == NULL)
	{
		return false;
	}

	return ProcessRatationPower()>other->ProcessRatationPower();
}

void Transport::Output(ofstream & ofst)
{
	ofst << ", power=" << power;
	ofst << ", fuel consumtion=" << fuel_consumption;
	ofst << ", ratation power=" << ProcessRatationPower()<<endl;
}


bool  Truck::Input(ifstream &ifst)
{
	if (!Transport::Input(ifst))
	{
		return false;
	}

	string temp;
	ifst >> temp;

	if (temp == "\0")
	{
		return false;
	}

	if (!isdigit(int(unsigned char(temp.front()))))
	{
		getline(ifst, temp, '\n');
		return false;
	}

	tonnage = stoul(temp);

	return true;
}

bool  PassengerCar::Input(ifstream &ifst)
{
	if (!Transport::Input(ifst))
	{
		return false;
	}

	string temp;
	ifst >> temp;

	if (temp == "\0")
	{
		return false;
	}

	if (temp.length() >= 4)
	{
		getline(ifst, temp, '\n');
		return false;
	}

	if (!isdigit(int(unsigned char(temp.front()))))
	{
		getline(ifst, temp, '\n');
		return false;
	}

	max_speed = stoul(temp);

	return true;
}

void Truck::Output(ofstream &ofst)
{
	ofst << "It's truck: tonnage=" << tonnage;
	Transport::Output(ofst);
}

void Truck::OutTruck(ofstream & ofst)
{
	ofst << "It's truck: tonnage=" << tonnage;
	Transport::Output(ofst);
}

void PassengerCar::Output(ofstream &ofst)
{
	ofst << "It's passenger car: the biggest speed=" << max_speed;
	Transport::Output(ofst);
}

float PassengerCar::ProcessRatationPower()
{
	if (GetPower() != 0)
	{
		return (float)(weightofman * 5) / (float)GetPower();
	}
	else
	{
		return -1;
	}
}


float Truck::ProcessRatationPower()
{
	if (GetPower() != 0)
	{
		return ((float)tonnage / (float)GetPower());
	}
	else
	{
		return -1;
	}
}


bool Bus::Input(ifstream &ifst)
{
	if (!Transport::Input(ifst))
	{
		return false;
	}

	string temp;
	ifst >> temp;

	if (temp == "\0")
	{
		return false;
	}

	if (temp.length() >= 4)
	{
		getline(ifst, temp, '\n');
		return false;
	}

	if (!isdigit(int(unsigned char(temp.front()))))
	{
		getline(ifst, temp, '\n');
		return false;
	}

	passengercapacity = stoul(temp);

	return true;
}

void Bus::Output(ofstream &ofst)
{
	ofst << "It's bus: passengercapacity=" << passengercapacity;
	Transport::Output(ofst);
}

float Bus::ProcessRatationPower()
{
	if (GetPower() != 0)
	{
		return (float)(weightofman*passengercapacity) / (float)GetPower();
	}
	else
	{
		return -1;
	}
}
void Container::Sort()
{
	if (size_of_list < 2)
	{
		return;
	}

	Node* current = head;

	for (int i = 0; i < size_of_list -1; i++)
	{
		for (int k = 0; k < size_of_list -1; k++)
		{
			if (head->transport->Compare(head->next->transport))
			{
				Node *previously = head;

				while (previously->next != head)
					previously = previously->next;

				Node *next1 = head->next;
				Node *next2 = head->next->next;

				head->next->next = head;
				head->next = next2;
				previously->next = next1;
				head = next1;
			}
			head = head->next;
		}
		head = head->next;
	}
}