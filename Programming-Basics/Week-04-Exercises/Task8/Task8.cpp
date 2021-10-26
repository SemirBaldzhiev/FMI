#include <iostream>

int main()
{
    int n;
    std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (i == k)
			{
				std::cout << '0';
			}
			else if (i < k) 
			{
				std::cout << '+';
			}
			else 
			{
				std::cout << '-';
			}
			
		}

		std::cout << std::endl;
	}

	return 0;
}
