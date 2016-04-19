#include <iostream>
#include <fstream>

int main()
{
	std::ofstream outputFileStream{"log.txt"};

	int numberOfTimesPerformingTest{ 0 };

	std::cout << "테스트 수행 회수 입력 : ";
	std::cin >> numberOfTimesPerformingTest;
	std::cout << std::endl;

	const float originX{ 100.0f };
	const float originZ{ 100.0f };
	const float radius{ 50.0f };
	const float angleLimit{ 360.0f };

	const float PI{ 3.141592f };
	const float degreeToRadian{ PI / 180.0f };

	float accumulatedAngle{0.0f};
	float angularSpeedPerSec{ 15.0f };

	for (int count = 0; count < numberOfTimesPerformingTest; count++)
	{
		accumulatedAngle += angularSpeedPerSec;

		if (accumulatedAngle >= angleLimit)
		{
			accumulatedAngle -= angleLimit;
		}

		const float revolvedX = cos(accumulatedAngle * degreeToRadian) * radius + originX;
		const float revolvedZ = sin(accumulatedAngle * degreeToRadian) * radius + originZ;

		std::cout << "Angle : " << accumulatedAngle << " Pos : ( X : " << revolvedX << ", Z : " << revolvedZ << " )" << std::endl;
		outputFileStream << "Angle : " << accumulatedAngle << " Pos : ( X : " << revolvedX << ", Z : " << revolvedZ << " )" << std::endl;
	}
}