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

	transport *temporary;	//¬ременные указатели
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

void transport::Output(ofstream & ofst)
{
	ofst << ", power=" << power;
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

void truck::Output(ofstream &ofst)
{
	ofst << "It's truck: tonnage=" << tonnage;
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
