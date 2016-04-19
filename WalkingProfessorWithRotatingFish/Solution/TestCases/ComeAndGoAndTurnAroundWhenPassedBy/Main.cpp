#include <iostream>
#include <fstream>

int main()
{
	std::ofstream outFileStream("log.txt");

	const float ELAPSED_TIME_SINCE_LAST_FRAME{ 1.0f / 60.0f };
	const float WALKING_SPEED_METER_PER_SECOND{ 10.0f };
	const float MIN_BOUNDARY_Z{ -250.0f };
	const float MAX_BOUNDARY_Z{ 250.0f };
	const float RADIUS_OF_BOUNDARY{ 250.0f };
	const float ANGULAR_SPEED_DEGREE_PER_SECOND{ 30.0f };

	float positionX{ 0.0f };
	float positionZ{ 0.0f };
	int walkingDirectionZ{ 1 };
	bool onTurnAround{ false };
	float accumulatedAngleInDegree{ 0.0f };
	int numberOfTimesPerformingTest{ 0 };

	std::cout << "테스트 수행 회수 입력 : ";
	std::cin >> numberOfTimesPerformingTest;
	std::cout << std::endl;

	for (int count = 0; count < numberOfTimesPerformingTest; count++)
	{
		const bool hasReachedEndOfBoundary = (positionZ > MAX_BOUNDARY_Z) || (positionZ < MIN_BOUNDARY_Z);

		if (hasReachedEndOfBoundary)
		{
			positionZ = RADIUS_OF_BOUNDARY * walkingDirectionZ;
			walkingDirectionZ *= -1;

			onTurnAround = true;
		}

		else if (onTurnAround)
		{
			const bool isTurningAroundCompleted = accumulatedAngleInDegree >= 180.0f;

			if (isTurningAroundCompleted)
			{
				accumulatedAngleInDegree = 0.0f;
				onTurnAround = false;
			}

			else
			{
				accumulatedAngleInDegree += ANGULAR_SPEED_DEGREE_PER_SECOND * ELAPSED_TIME_SINCE_LAST_FRAME;
			
				const float PI = 3.141592f;
				const float DegreeToRad = PI / 180.0f;
				positionX = cos(accumulatedAngleInDegree * DegreeToRad);
				positionZ = sin(accumulatedAngleInDegree * DegreeToRad);
			}
		}

		else
		{
			positionZ += walkingDirectionZ * WALKING_SPEED_METER_PER_SECOND * ELAPSED_TIME_SINCE_LAST_FRAME;
		}

		std::cout << "( X : " << positionX << ", Z : " << positionZ << " )" << std::endl;
		outFileStream << "( X : " << positionX << ", Z : " << positionZ << " )" << " ";
	}
}