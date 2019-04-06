#include "Library.h"

/*
 * Get input from user
 */
Buckets getInput(Buckets buckets)
{
	int Bucket_A_Max;	//Bucket A max capacity
	int Bucket_B_Max;	//Bucket B max capacity
	int target;		//target
	bool inputIsGood = false;

	do
	{
		std::cout << "Enter the Max Capacity for Bucket A: ";
		std::cin >> Bucket_A_Max;

		if (Bucket_A_Max <= 0)
		{
			std::cout << "The number entered is not positive." << std::endl;
		}

		else
		{
			inputIsGood = true;
		}
	} while (!inputIsGood); 	//loop repeats if input is not valid

	inputIsGood = false;

	do
	{
		std::cout << "Enter the Max Capacity for Bucket B: ";
		std::cin >> Bucket_B_Max;

		if (Bucket_B_Max <= 0)
		{
			std::cout << "The number entered is not positive." << std::endl;
		}

		else
		{
			inputIsGood = true;
		}
	} while (!inputIsGood);		//loop repeats if input is not valid

	inputIsGood = false;

	do
	{
		std::cout << "Enter the desired water level: ";
		std::cin >> target;
		if (target <= 0)
		{
			std::cout << "The number entered is not positive non-zero." << std::endl;
		}

		else if (target > Bucket_A_Max + Bucket_B_Max)
		{
			std::cout << "The number entered is greater than the sum of both capacities of the buckets." << std::endl;
		}

		else
		{
			inputIsGood = true;
		}
	} while (!inputIsGood);		//loop repeats if input is not valid
	

	Buckets tempBuckets(Bucket_A_Max, Bucket_B_Max, target);	//store input in object
	
	return tempBuckets;
}

/*
 * Prints water level for both Bucket A and Bucket B
 */
void print(Buckets buckets)
{
	std::cout << "(" << buckets.getBucketALevel() << "," << buckets.getBucketBLevel() << ")" << std::endl;
}


/*
 * Find all possible water levels between Bucket A and Bucket B
 * until both buckets are full, at which point the target 
 * cannot be fulfilled.
 */
void findWaterLevels(Buckets buckets)
{
	bool isPossible = true;
	std::cout << "A(" << buckets.getBucketAMaxCap() << ")\tB(" << buckets.getBucketBMaxCap() << ")" << std::endl;
	std::cout << "Requested Amount: " << buckets.getTarget() << std::endl;

	print(buckets);

	while (isPossible)
	{
		if (buckets.getBucketALevel() == buckets.getBucketAMaxCap() && buckets.getBucketBLevel() == buckets.getBucketBMaxCap())	//when both buckets are full, return
		{
			std::cout << "This is not possible." << std::endl;
			return;
		}

		if (buckets.getBucketALevel() == buckets.getBucketAMaxCap() && buckets.getBucketBLevel() != buckets.getBucketBMaxCap())	//If Bucket A current capacity equals Bucket A max capacity and Bucket B current capacity does not equal Bucket B max capacity, Dump A into B
		{
			buckets.Dump_A_Into_B();
			print(buckets);
		}

		else if (buckets.getBucketALevel() == 0)	//if Bucket A current capacity equals zero, fill A
		{
			buckets.fillBucketA();
			print(buckets);
		}

		else if (buckets.getBucketBLevel() == buckets.getBucketBMaxCap())	//if Bucket B current capacity equals Bucket B max capacity, empty B

		{
			buckets.emptyBucketB();
			print(buckets);
		}

		else if (buckets.getBucketBLevel() < buckets.getBucketBMaxCap()) 	//if Bucket B current capacity less than Bucket B max capacity, dump A into B
		{
			buckets.Dump_A_Into_B();
			print(buckets);
		}

		if (buckets.getBucketALevel() + buckets.getBucketBLevel() == buckets.getTarget()) //if target met, return
		{
			return;
		}
	}
}