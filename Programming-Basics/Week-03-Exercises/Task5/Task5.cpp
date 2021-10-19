#include <iostream>

int main()
{
    int score;

    std::cin >> score;

	double bonusScore = 0;

	if (score <= 100)
	{
		bonusScore += 5;
	}
	else if (score > 100) 
	{
		bonusScore += score * 0.2;
	}
	else if (score > 1000) 
	{
		bonusScore += score * 0.1;
	}

	if (score % 2 == 0) 
	{
		bonusScore += 1;
	}

	if (score % 10 == 5) 
	{
		bonusScore += 2;
	}

	std::cout << bonusScore << " " << score + bonusScore << std::endl;

	return 0;
}
