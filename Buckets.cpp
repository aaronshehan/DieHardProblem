#include "Buckets.h"

/*
 * Default constructor
 */
Buckets::Buckets()
{
	bucket_A.current_capacity = 0;
	bucket_A.max_capacity = 0;
	bucket_B.current_capacity = 0;
	bucket_B.max_capacity = 0;
	target = 0;
}

/*
 * Overloaded constructor
 */
Buckets::Buckets(int maxCapA, int maxCapB, int goal)
{
	bucket_A.max_capacity = maxCapA;
	bucket_A.current_capacity = 0;
	bucket_B.max_capacity = maxCapB;
	bucket_B.current_capacity = 0;
	target = goal;
}

/*
 * Fills bucket A to max capacity
 */
void Buckets::fillBucketA()
{
	bucket_A.current_capacity = bucket_A.max_capacity;
}

/*
 * Fills bucket B to max capacity
 */
void Buckets::fillBucketB()
{
	bucket_B.current_capacity = bucket_B.max_capacity;
}

/*
 * Empties bucket A
 */
void Buckets::emptyBucketA()
{
	bucket_A.current_capacity = 0;
}

/*
 * Empties bucket B
 */
void Buckets::emptyBucketB()
{
	bucket_B.current_capacity = 0;
}

/*
 * Return current capacity for Bucket A
 */
int Buckets::getBucketALevel()
{
	return bucket_A.current_capacity;
}

/*
 * Return current capacity for Bucket B
 */
int Buckets::getBucketBLevel()
{
	return bucket_B.current_capacity;
}

/*
 * Return max capacity for Bucket A
 */
int Buckets::getBucketAMaxCap()
{
	return bucket_A.max_capacity;
}

/*
 * Return max capacity for Bucket B
 */
int Buckets::getBucketBMaxCap()
{
	return bucket_B.max_capacity;
}

/*
 * Return target
 */
int Buckets::getTarget()
{
	return target;
}

/*
 * Dump contents of Bucket A into Bucket B
 */
void Buckets::Dump_A_Into_B()
{
	if (bucket_A.current_capacity + bucket_B.current_capacity > bucket_B.max_capacity)
	{
		int temp = bucket_B.current_capacity;
		bucket_B.current_capacity = bucket_B.max_capacity;
		bucket_A.current_capacity -= bucket_B.max_capacity - temp;
	}

	else
	{
		bucket_B.current_capacity += bucket_A.current_capacity;
		bucket_A.current_capacity = 0;
	}
}