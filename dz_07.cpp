#include <iostream>
#include <exception>
#include "IntArray.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "");

	try 
	{
		//IntArray arr(-7);
		//IntArray brr(7);
		//brr[-7];
		//brr[33];
		//brr.insertBefore(6, -1);
		//brr.insertBefore(16, 23);
		//brr.remove(-1);
		//brr.remove(7);



	catch (const bad_length& exc)
	{
		cout << exc.what() << endl;
	}

	catch (const bad_range& exc)
	{
		cout << exc.what() << endl;
	}

	return 0;
}
