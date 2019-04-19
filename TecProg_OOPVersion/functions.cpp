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
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		temporary = new truck; break;
	case 2:
		temporary = new bus; break;
	case 3:
		temporary = new passenger_car; break;
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
	ifst >> tonnage;
	if (!transport::Input(ifst))
	{
		return false;
	}
	return true;
}

bool  passenger_car::Input(ifstream &ifst)
{
	ifst >> max_speed;
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

void passenger_car::Output(ofstream &ofst)
{
	ofst << "It's passenger car: the biggest speed=" << max_speed;
	transport::Output(ofst);
}


int truck::ProcessRatationPower()
{
	
	return (tonnage/Past_power());
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

int bus::ProcessRatationPower()
{
	return (weightofman*passengercapacity)/Past_power();
}
void container::sort()
{
	if (sizeoflist < 2)
	{
		return;
	}

	Node* current = head;

	for (int i = 0; i < sizeoflist - 1; i++)
	{
		for (int k = 0; k < sizeoflist - 1; k++)
		{
			if (current->transport->Compare(current->next->transport))
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