/*
 * Aaron Shehan
 * ats0109
 * aaronshehan@my.unt.edu
 * CSCE 2100 Project 1
 */

#include "Buckets.h"
#include "Library.h"

int main()
{
	Buckets buckets;			//initial object with private data members set to zero
	buckets = getInput(buckets);		//get input from user to populate object
	findWaterLevels(buckets);		//finds all possible water levels

	return 0;
}