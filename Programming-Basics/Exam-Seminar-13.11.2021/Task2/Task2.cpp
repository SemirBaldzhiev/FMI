#include <iostream>

int main()
{
	int firstNum;
	int secondNum;

	std::cin >> firstNum >> secondNum;

	for (int i = firstNum; i <= secondNum; i++)
	{
		int currentNum = i;


		while (currentNum != 0) //1, 4, 6, 8, 12, 20  - 13  4 - Fire 6 - Earth 8 - Air 20 - Water  12 - Universe  1 - Plasma
		{
			if (currentNum >= 20)
			{
				currentNum -= 20;
				std::cout << "Water";
			}
			else if (currentNum >= 12) 
			{
				currentNum -= 12;
				std::cout << "Universe";
			}
			else if (currentNum >= 8)
			{
				currentNum -= 8;
				std::cout << "Air";
			}
			else if (currentNum >= 6)
			{
				currentNum -= 6;
				std::cout << "Earth";
			}
			else if (currentNum >= 4)
			{
				currentNum -= 4;
				std::cout << "Fire";
			}
			else if (currentNum >= 1)
			{
				currentNum -= 1;
				std::cout << "Plasma";
			}
		}

		std::cout << std::endl;
	}

    return 0;
}