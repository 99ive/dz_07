#include <iostream>
#include <exception>
#include "IntArray.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "");

	try 
	{	//Ќиже представлен перечень тестовых значений

		//IntArray arr(-7);
		//IntArray brr(7);
		//brr[-7];
		//brr[33];
		//brr.insertBefore(6, -1);
		//brr.insertBefore(16, 23);
		//brr.remove(-1);
		//brr.remove(7);



	}
	catch (LengthException& lengthException)
	{	
		cout << "Length cannot be less than 0!" << endl;
	}
	catch (IndexException& indexException)
	{	
		cout << "Index cannot be less than 0!" << endl;
	}
	catch (Oversize& oversize)
	{
		cout << "Index cannot be bigger than length of array!" << endl;
	}
	catch (BiggerOrEqual& biggerOrEqual)
	{
		cout << "Index cannot be bigger or equal to length of array!" << endl;
	}

	return 0;
}
