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

	ifstream ifst("input.txt");  // ����� ��� ����� � ������
	ofstream ofst("output.txt"); // � ���� ���� ������� ��������

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
	Container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.Out(ofst);
	ofst << endl;

	c.MultyMethod(ofst);

	ofst << "Empty container. " << endl;
	c.~Container();
	c.Out(ofst);
	cout << "Stop" << endl;

	return 0;
}
