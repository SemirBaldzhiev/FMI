#include <iostream>


// Bad way
//int fib(int n)
//{
//	if (n <= 1)
//	{
//		return n;
//	}
//
//	return fib(n - 1) + fib(n - 2);
//}


int fibLinear(int n, int a = 0, int b = 1)
{
	if (n <= 1)
	{
		return b;
	}

	return fibLinear(n - 1, b, a + b);
}

int main()
{
	int n = 9;

	std::cout << fibLinear(n);

    return 0;
}