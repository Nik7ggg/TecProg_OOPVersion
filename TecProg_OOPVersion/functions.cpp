#include "header.h"

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
			//ofst << "The number of years that have passed since the year the language was created = "
				//<< current->transport->Past_power << endl;
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
	if (power > 0)
		return true;
	else
		return false;
}

int transport::Past_power()
{
	return power;
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

void passenger_car::Output(ofstream &ofst)
{
	ofst << "It's passenger car: the biggest speed=" << max_speed;
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
