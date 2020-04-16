#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

typedef unsigned long long BIG;


/*
*Func:          PrimeSieve
*Param:         N // the upper bound to generate prime numbers
*Return:        None
*Input:         None
*Output:        [_DEBUG] the list of primes
*Other:         None
*/
void PrimeSieve(size_t N);

/****************************************************
*Func:          InputCheck()
*Param:         None
*Return:        whether the input is right
*Input:         None
*Output:        None
*Other:         only use after cin,
				connot recognize the wrong range.
****************************************************/
bool InputCheck();

/****************************************************
*Func:          ListGenerator
*Description:	list generator
*Param:			BIG* input_list // the list to be filled
				size_t num		// the lenth

*Called:		prime_judge -> GoldBachInitialize
*Calls:			None

*Return:        input_list
*Input:         None
*Output:        None

*Other:         None
****************************************************/
BIG* ListGenerator(BIG* input_list, size_t num);
