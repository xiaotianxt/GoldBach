/****************************************************
*File:          prime_judge.h
*Interface:		fun: GoldBachInitialize
*Description:	all the functions to testy GoldBach with given input.

*Func list:		GoldBachInitialize	// giving input_list and mode, arrange the way to calculate. 
				GoldBach			// giving an input number, return the result.
				MaxList				// return the maximum of the list.
				IsPrime				// prime judgement with traditional method.
				IsPrimeBonus		// prime judgement with Euler method.
				Chatter				// output
				DoNothing			// Do Nothing ^_^
*Other:         
****************************************************/
#include <iostream>
#include <time.h>
#include <fstream>
#include "bonus.h"

using namespace std;

typedef unsigned long long BIG;
typedef bool (*fp)(BIG);
typedef void (*vp)(BIG, BIG);


/****************************************************
*Func:          GoldBachInitialize
*Description:	the interface of the file, 
*Param:         BIG* input_list // the list of the input to be judged.
				int counter		// the number of the list.
				char mode		// the mode user chose.
				bool babble		// babbling or not.

*Called:		main.cpp -> main
*Calls:			MaxList, PrimeSieve, GoldBach

*Return:        None
*Input:         None
*Output:        None

*Other:         
***************************************************/
void GoldBachInitialize(BIG* input_list, size_t counter, size_t mode, bool babble);

/**************************************************
*Func:          GoldBach
*Description:	
*Param:         BIG input // a number to testify the conjection.
				char mode // the mode user chose.

*Called:
*Calls:

*Return:        None
*Input:         None
*Output:        cout << intput << '=' << X << '+' << Y << endl;

*Other:         None.
***************************************************/
void GoldBach(BIG input, size_t mode, bool babble);

/**************************************************
*Func:          MaxList
*Description:	return the maximum of the list.
*Param:         BIG * input_list // list of input numbers
				size_t counter		// len(input_list)

*Called:		GoldBachInitialize.
*Calls:			

*Return:        BIG maximum of the list.
*Input:         None
*Output:        None

*Other:         None
***************************************************/
static BIG MaxList(BIG* input_list, size_t counter);

/****************************************************
*Func:          IsPrime
*Description:	prime judgement with regular method.
*Param:         BIG input // the number you want to judge

*Called:		GoldBach
*Calls:

*Return:        bool // isprime-->true, notprime-->false
*Input:         None
*Output:        None

*Other:         Only when mode == 1 || mode == 2
****************************************************/
bool IsPrime(BIG input);

/***************************************************
*Func:          IsPrimeBonus
*Description:	prime judgement with Euler sieve.
*Param:         BIG input // the number you want to judge

*Called:		Gold Bach
*Calls:

*Return:        bool // isprime-->true, notprime-->false
*Input:         None
*Output:        None

*Other:         Only when mode == 3 || mode == 4
*****************************************************/
bool IsPrimeBonus(BIG input);

/****************************************************
*Func:          Chatter
*Description:	cout << "input = x + y"
*Param:			BIG input, BIG x

*Called:		Gold Bach
*Calls:			None.

*Return:        None.
*Input:         None.
*Output:        "input = x + y"

*Other:         None.
****************************************************/
void Chatter(BIG input, BIG x);

/****************************************************
*Func:          DoNothing
*Description:	Simply do nothing
*Param:			BIG a, BIG b //useless

*Called:		Gold Bach
*Calls:			None.

*Return:        None.
*Input:         None.
*Output:        None.

*Other:         only work for GoldBach, void printing.
****************************************************/
void DoNothing(BIG a, BIG b);
