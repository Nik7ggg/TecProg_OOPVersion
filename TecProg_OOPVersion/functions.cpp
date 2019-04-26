#include "header.h"
#include <string>
#include <fstream>

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
		else//порядок элементов будет отличаться, от процедурного
		{
			temp->next = head;
			tail->next = temp;                    //Запись данных в следующее за последним элементом поле
			tail = temp;                          //Последний активный элемент=только что созданный.
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

		}
		current = current->next;
	}
}

void container::Clear()
{
	while (sizeoflist != 0)                        //Пока размерность списка не станет нулевой
	{
		Node *temp = head->next;
		delete head;                           //Освобождаем память от активного элемента
		head = temp;                           //Смена адреса начала на адрес следующего элемента
		sizeoflist--;                                //Один элемент освобожден. корректируем число элементов
	}

}

container::container()
{
	head = NULL;
	sizeoflist = 0;
}

transport* transport::Transport_Input(ifstream &ifst)// в контейнеровском файле, как в процедурном стиле
{

	transport *temporary;	//временные указатели
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
		temporary = new truck; break;
	case 2:
		temporary = new bus; break;
	case 3:
		temporary = new passenger_car; break;
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

bool transport::Input(ifstream & ifst)
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

int transport::Past_power()
{
	return power;
}

void transport::Out_Truck(ofstream & ofst)
{
	ofst << endl;
}

bool transport::Compare(transport * other)
{
	return ProcessRatationPower()>other->ProcessRatationPower();
}

void transport::Output(ofstream & ofst)
{
	ofst << ", power=" << power;
	ofst << ", fuel consumtion=" << fuel_consumption << endl;
	ofst << ", ratation power=" << ProcessRatationPower()<<endl;
}


bool  truck::Input(ifstream &ifst)
{
	if (!transport::Input(ifst))
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

bool  passenger_car::Input(ifstream &ifst)
{
	if (!transport::Input(ifst))
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

void passenger_car::Output(ofstream &ofst)
{
	ofst << "It's passenger car: the biggest speed=" << max_speed;
	transport::Output(ofst);
}

float passenger_car::ProcessRatationPower()
{
	return (float)(weightofman * 5) / (float)Past_power();
	//return (weightofman * 5) / Past_power();
	
}


float truck::ProcessRatationPower()
{
	return ((float)tonnage / (float)Past_power());
	//return (tonnage/Past_power());
}


bool bus::Input(ifstream &ifst)
{
	if (!transport::Input(ifst))
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

void bus::Output(ofstream &ofst)
{
	ofst << "It's bus: passengercapacity=" << passengercapacity;
	transport::Output(ofst);
}

float bus::ProcessRatationPower()
{
	return (float)(weightofman*passengercapacity)/(float)Past_power();
	//return (weightofman*passengercapacity) / Past_power();
}
void container::sort()
{
	if (sizeoflist < 2)
	{
		return;
	}

	Node* current = head;

	for (int i = 0; i < sizeoflist-1; i++)
	{
		for (int k = 0; k < sizeoflist-1; k++)
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