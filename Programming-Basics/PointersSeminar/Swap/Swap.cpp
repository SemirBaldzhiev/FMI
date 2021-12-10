#include <iostream>

void swap(int* firstNum, int* secondNum)
{
	int temp = *firstNum;
	*firstNum = *secondNum;
	*secondNum = temp;
}

double* calculateHeight(double height, double age) 
{
	double arr[2] = { height, age };

	arr[0] += 0.05;
	arr[1] += 5;

	return arr;
}


int main()
{

	double height = 1.65;
	double age = 15;

	double* arr = calculateHeight(height, age);

	for (int i = 0; i < 2; i++)
	{
		std::cout << arr[i] << std::endl;
	}


	/*int a, b;

	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;

	swap(&a, &b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;*/

	return 0;
}