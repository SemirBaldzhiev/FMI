#include <iostream>
#include <cstring>


// Bonus 2
char* removeRedundantSymbols(char* str, char* res, int index)
{
	if (*str == '\0')
	{
		res[index] = '\0';
		return res;
	}

	if (*str != '1' && *str != '0' && *str != '=' && *str != '&' && *str != '|')
	{
		removeRedundantSymbols(str + 1, res, index);
	}
	else
	{
		res[index] = *str;
		index++;
		res[index] = ' ';
		
		removeRedundantSymbols(str + 1, res, index + 1);
	}
}

void modifyExpression(char*& str)
{
	int removed = 0;
	int len = strlen(str);
	bool flag = true;

	int i;
	for (i = 0; i < len; i++)
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '=' && str[i] != '&' && str[i] != '|')
		{
			for (int j = i; j < len - 1; j++)
			{
				if (str[j] == '1' || str[j] == '0' || str[j] == '=' || str[j] == '&' || str[j] == '|')
				{
					flag = false;
				}

				str[j] = str[j + 1];
			}


			removed++;

			if (flag)
			{
				removed = 0;

				break;
			}
			
			i--;
		}

		flag = true;
	}

	str[i - removed] = '\0';
}

// Bonus 1
bool isValidWithDoubleOperators(const char* expression)
{
	int length = strlen(expression);

	if (expression[length - 2] != '=')
	{
		return false;
	}

	if (expression[length - 1] != '1' && expression[length - 1] != '0')
	{
		return false;
	}

	for (int i = 0; expression[i] != '='; i++) 
	{
		if ((expression[i] == '&' || expression[i] == '|'))
		{
			if ((expression[i + 1] != '&' && expression[i+1] != '|'))
			{
				return false;
			}
			i++;
		}
		else if (expression[i] != '1' && expression[i] != '0')
		{
			return false;
		}

	}

	return true;
}

bool isValidExpression(const char* expression)
{

	int length = strlen(expression);

	if (expression[length - 2] != '=')
	{
		return false;
	}

	if (expression[length - 1] != '1' && expression[length - 1] != '0')
	{
		return false;
	}

	for (int i = 0; expression[i] != '='; i++)
	{

		if (i % 2 == 0 && (expression[i] != '1' && expression[i] != '0'))
		{
			return false;
		}

		if (i % 2 != 0 && (expression[i] != '&' && expression[i] != '|'))
		{
			return false;
		}


	}

	return true;
}


int main()
{
	int n = 100;
	char* expression = new char[n];

	std::cin >> expression;

	modifyExpression(expression);

	if (isValidExpression(expression))
	{
		std::cout << "Boolean expression " << expression << " is valid!" << std::endl;
	}
	else
	{
		std::cout << "Boolean expression " << expression << " is NOT valid!" << std::endl;
	}

	std::cout << "Bonus 1 result: " << std::endl;
	if (isValidWithDoubleOperators(expression))
	{
		std::cout << "Boolean expression " << expression << " is valid!" << std::endl;
	}
	else
	{
		std::cout << "Boolean expression " << expression << " is NOT valid!" << std::endl;
	}

	char* res = new char[n];

	char* result = removeRedundantSymbols(expression, res, 0);

	std::cout << "Bonus 2 result: " << std::endl;
	std::cout << result << std::endl;

	delete[] expression;
	delete[] res;

	return 0;
}
