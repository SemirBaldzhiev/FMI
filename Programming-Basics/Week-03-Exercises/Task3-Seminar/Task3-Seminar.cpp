#include <iostream>
#include <cmath>

int main()
{
	int firstNum;
	int secondNum;
	char symbol;

	int result = 0;

	std::cin >> firstNum >> secondNum >> symbol;

	switch (symbol)
	{
		case '+':
			result = firstNum + secondNum;
			break;
		case '-':
			result = firstNum - secondNum;
			break;
		case '*':
			result = firstNum * secondNum;
			break;
		case '/':
			result = firstNum / secondNum;
			break;
		case '%':
			result = firstNum % secondNum;
			break;
		case '^':
			result = std::pow(firstNum, secondNum);
			break;
		case '=':
			result = (firstNum == secondNum);
			break;
		default:
			std::cout << "Error" << std::endl;
			return 0;
			break;

	}

	if (symbol == '=')
	{
		std::cout << std::boolalpha << (bool)result << std::endl;
	}
	else
	{
		std::cout << result << std::endl;
	}

	return 0;
}

