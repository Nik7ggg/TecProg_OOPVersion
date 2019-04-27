#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "functions.cpp"
#include "main.cpp"
#include "header.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestSort)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outSort.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\inputSort.txt");
			container c;
			c.In(fin);
			c.sort();
			c.Out(fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\corS.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outSort.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompare)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InTruck.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InBus.txt");
			bool expected = false;
			transport * actual = new truck;
			transport * actual2 = new bus;
			actual->Input(fin);
			actual2->Input(fin2);
			bool actualResult = actual->Compare(actual2);
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(RatationPowerTruck)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InTruck.txt");
			float expected = 50;
			transport * actual=new truck;
			actual->Input(fin);
			float actualResult = actual->ProcessRatationPower();
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(RatationPowerBus)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InBus.txt");
			float expected = 3000;
			transport * actual = new bus;
			actual->Input(fin);
			float actualResult = actual->ProcessRatationPower();
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(RatationPowerPassengerCar)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InCar.txt");
			float expected = 187.5;
			transport * actual = new passenger_car;
			actual->Input(fin);
			float actualResult = actual->ProcessRatationPower();
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(GetPower)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InBus.txt");
			int expected = 5;
			bus *actual = new bus;
			actual->Input(fin);
			int actualresult = actual->Past_power();
			Assert::AreEqual(expected, actualresult);
		}
		TEST_METHOD(InputTruck)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InTruck.txt");
			int expected = 200;
			transport * actual = new truck;
			actual->Input(fin);
			int actual_power = actual->Past_power();
			Assert::AreEqual(expected, actual_power);
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\corT.txt");
			ofstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outTruck.txt");
			actual->Out_Truck(fin2);
			actual->Output(fin2);
			fin2.close();
			string expected2;
			ifstream fout("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outTruck.txt");
			getline(fin1, expected2, '\0');
			string actual2;
			getline(fout, actual2, '\0');
			Assert::AreEqual(expected2, actual2);
		}
		TEST_METHOD(InputBus)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InBus.txt");
			int expected = 5;
			transport * actual = new bus;
			actual->Input(fin);
			int actual_power = actual->Past_power();
			Assert::AreEqual(expected, actual_power);
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\corB.txt");
			ofstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outBus.txt");
			actual->Out_Truck(fin2);
			actual->Output(fin2);
			fin2.close();
			string expected2;
			ifstream fout("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outBus.txt");
			getline(fin1, expected2, '\0');
			string actual2;
			getline(fout, actual2, '\0');
			Assert::AreEqual(expected2, actual2);
		}
		TEST_METHOD(InputPassenger_car)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\InCar.txt");
			int expected = 2;
			transport * actual = new passenger_car;
			actual->Input(fin);
			int actual_power = actual->Past_power();
			Assert::AreEqual(expected, actual_power);
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\corC.txt");
			ofstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outCar.txt");
			actual->Out_Truck(fin2);
			actual->Output(fin2);
			fin2.close();
			string expected2;
			ifstream fout("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outCar.txt");
			getline(fin1, expected2, '\0');
			string actual2;
			getline(fout, actual2, '\0');
			Assert::AreEqual(expected2, actual2);
		}
		TEST_METHOD(TestContainerInput)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outContainer.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\input.txt");
			container c;
			c.In(fin);
			c.Out(fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\corContainer.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outContainer.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestTransportInput)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outTransp.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\inTruck.txt");
			transport *c=new truck;
			c->Transport_Input(fin);
			c->Output(fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\corTransp.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outTransp.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		/*TEST_METHOD(TestOutTruck)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outSort.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\inTruck.txt");
			transport *c=new truck;
			c->Input(fin);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\corS.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_OOPVersion\\UnitTest1\\outSort.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		
		
		TEST_METHOD(OutB)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outBus.txt");
			bus bus;
			bus.passengercapacity = 200;
			OutBus(&bus, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corB.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outBus.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TransportOut)
		{
			ofstream fout("outTransp.txt");
			transport transp;
			transp.k = BUS;
			transp.fuel_consumption = 10;
			transp.power = 200;
			ChooseForOut(&transp, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corTransport.txt");
			ifstream fin2("outTransp.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TransportInput)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InTransport.txt");
			transport* actual = NULL;
			actual = In(fin);
			transport expected;
			expected.k = TRUCK;
			expected.power = 200;
			expected.fuel_consumption = 15;
			Assert::AreEqual(int(expected.k), int(actual->k));
			Assert::AreEqual(int(expected.power), int(actual->power));
			Assert::AreEqual(int(expected.fuel_consumption), int(actual->fuel_consumption));
		}
		TEST_METHOD(OutTr)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outTruck.txt");
			truck truck1;
			truck1.tonnage = 10000;
			OutTruck(&truck1, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corT.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outTruck.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OutCar)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outCar.txt");
			passenger_car car;
			car.full_speed = 140;
			OutPassengerCar(&car, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corC.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outCar.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OutList)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outList.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\input.txt");
			container c;
			Init(c);
			In(c, fin);
			Out(c, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corL.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outList.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestSort)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outSort.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\inputSort.txt");
			container c;
			Init(c);
			In(c, fin);
			SortList(c);
			Out(c, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corS.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outSort.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompare)
		{
			transport *car2 = new transport;
			transport car1;
			car1.k = PASSENGER_CAR;
			car1.power = 20;
			car1.next = car2;

			car2->k = PASSENGER_CAR;
			car2->power = 5;
			bool actual = compare(&car1);
			bool expected = false;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestInit)
		{
		container actual;
		Init(actual);
		container expected;
		expected.Head = NULL;
		expected.Tail = NULL;
		expected.len = 0;
		//Assert::AreEqual(int(expected.Head), int(actual.Head));
		//Assert::AreEqual(int(expected.len), int(actual.len));
		Assert::AreEqual(expected.Tail, actual.Tail);
		}
		TEST_METHOD(OutOTruck)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outOnlyTruck.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\input.txt");
			container c;
			Init(c);
			In(c, fin);
			OutOnlyTruck(c, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corOT.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outOnlyTruck.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}*/

	};
}