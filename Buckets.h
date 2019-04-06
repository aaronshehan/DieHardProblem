#pragma once

#include <iostream>

struct Bucket
{
	int max_capacity;
	int current_capacity;
};

class Buckets
{
private:
	Bucket bucket_A;
	Bucket bucket_B;
	int target;
public:
	Buckets();			//default constructor
	Buckets(int, int, int);		//overloaded constructor
	void fillBucketB();		//fill Bucket B to max capacity
	void fillBucketA();		//fill Bucket A to max capacity
	void emptyBucketA();		//empty Bucket A
	void emptyBucketB();		//empty Bucket B
	int getBucketALevel();		//return Bucket A current capacity
	int getBucketBLevel();		//return Bucket B current capacity
	int getBucketBMaxCap();		//return Bucket A max capacity
	int getBucketAMaxCap();		//return Bucket B max capacity
	int getTarget();		//return target
	void Dump_A_Into_B();		//dumps water from A into B
};