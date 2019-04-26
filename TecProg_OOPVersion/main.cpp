#include "header.h"


int main(int argc, char* argv[])
{
	/*if (argc != 3)
	{
	cout << "incorrect command line! "
	"Waited: command in_file out_file"
	<< endl;
	exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);*/

	ifstream ifst("input.txt");  // файлы для ввода и вывода
	ofstream ofst("output.txt"); // с ними было удобнее работать
	if (!ifst.is_open())
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	if (!ofst.is_open())
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	cout << "Start" << endl;
	container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.Out(ofst);
	//ofst << "Sorted container:" << endl;
	//c.sort();
	//c.Out(ofst);
	c.~container();//очистка контейнера
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop" << endl;

	return 0;
}
