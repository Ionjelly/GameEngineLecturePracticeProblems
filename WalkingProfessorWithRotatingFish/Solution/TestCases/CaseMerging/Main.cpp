#include <iostream>
#include <fstream>

int main()
{
	std::ofstream outFileStream("log.txt");

	/*associated with walking professor*/
	const float ELAPSED_TIME_SINCE_LAST_FRAME{ 1.0f / 60.0f };
	const float WALKING_SPEED_METER_PER_SECOND{ 10.0f };
	const float MIN_BOUNDARY_Z{ -250.0f };
	const float MAX_BOUNDARY_Z{ 250.0f };
	const float RADIUS_OF_BOUNDARY{ 250.0f };
	const float ANGULAR_SPEED_DEGREE_PER_SECOND{ 30.0f };

	/*associated with turning around professor*/
	float professorPositionX{ 0.0f };
	float professorPositionZ{ 0.0f };
	int professorWalkingDirectionZ{ 1 };
	bool onTurnAround{ false };
	float professorAccumulatedAngleInDegree{ 0.0f };

	/*associated with revolving fish*/
	const float FISH_REVOLUTION_RADIUS{ 50.0f };
	const float FISH_ANGULAR_SPEED_DEGREE_PER_SEC{ 15.0f };
	const float PI{ 3.141592f };
	const float DEGREE_TO_RADIAN{ PI / 180.0f };
	float fishAccumulatedAngleInDegree{ 0.0f };

	int numberOfTimesPerformingTest{ 0 };
	std::cout << "테스트 수행 회수 입력 : ";
	std::cin >> numberOfTimesPerformingTest;
	std::cout << std::endl;

	for (int count = 0; count < numberOfTimesPerformingTest; count++)
	{
		const bool hasReachedEndOfBoundary = (professorPositionZ > MAX_BOUNDARY_Z) || (professorPositionZ < MIN_BOUNDARY_Z);

		if (hasReachedEndOfBoundary)
		{
			professorPositionZ = RADIUS_OF_BOUNDARY * professorWalkingDirectionZ;
			professorWalkingDirectionZ *= -1;

			onTurnAround = true;
		}

		else if (onTurnAround)
		{
			const bool isTurningAroundCompleted = professorAccumulatedAngleInDegree >= 180.0f;

			if (isTurningAroundCompleted)
			{
				professorAccumulatedAngleInDegree = 0.0f;
				onTurnAround = false;
			}

			else
			{
				professorAccumulatedAngleInDegree += ANGULAR_SPEED_DEGREE_PER_SECOND * ELAPSED_TIME_SINCE_LAST_FRAME;

				professorPositionX = cos(professorAccumulatedAngleInDegree * DEGREE_TO_RADIAN);
				professorPositionZ = sin(professorAccumulatedAngleInDegree * DEGREE_TO_RADIAN);
			}
		}

		else
		{
			professorPositionZ += professorWalkingDirectionZ * WALKING_SPEED_METER_PER_SECOND * ELAPSED_TIME_SINCE_LAST_FRAME;
		}

		fishAccumulatedAngleInDegree += FISH_ANGULAR_SPEED_DEGREE_PER_SEC;

		if (fishAccumulatedAngleInDegree >= 360.0f)
		{
			fishAccumulatedAngleInDegree -= 360.0f;
		}

		const float fishRevolvedX = cos(fishAccumulatedAngleInDegree * DEGREE_TO_RADIAN) * FISH_REVOLUTION_RADIUS + 0.0f;
		const float fishRevolvedZ = sin(fishAccumulatedAngleInDegree * DEGREE_TO_RADIAN) * FISH_REVOLUTION_RADIUS + professorPositionZ;

		std::cout << "Professor : ( Z : " << professorPositionZ << " )" << std::endl;
		std::cout << "Fish : ( X : " << fishRevolvedX << ", Z : " << fishRevolvedZ << " )" << std::endl;

		outFileStream << "Professor : ( Z : " << professorPositionZ << " )" << "   ";
		outFileStream << "Fish : ( X : " << fishRevolvedX << ", Z : " << fishRevolvedZ << " )" << std::endl;
	}
}