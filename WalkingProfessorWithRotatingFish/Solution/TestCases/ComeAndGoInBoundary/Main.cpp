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

	float positionZ{ 0.0f };
	int walkingDirectionZ{ 1 };

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
		}

		else
		{
			positionZ += walkingDirectionZ * WALKING_SPEED_METER_PER_SECOND * ELAPSED_TIME_SINCE_LAST_FRAME;
		}

		std::cout << positionZ << std::endl;
		outFileStream << positionZ << " ";
	}
}