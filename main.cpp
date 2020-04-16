#include "prime_judge.h"
#include "bonus.h"
#include <iostream>
#include <random>
#include "time.h"

using namespace std;

/* simplifies coding */
typedef unsigned long long BIG;

/* define the max volume of the arry */
const size_t MAX_ARRAY = 1000;


int main(void)
{
	srand(time((size_t)NULL));

	//PrimeSieve(10000000);
	BIG input_list[MAX_ARRAY];
	size_t counter = 0, mode = 0;
	clock_t start, end;
	bool babble = 1;

	// welcome
	cout << "**************GOLD BACH CONJECTURE**************\n" << endl;

#ifdef _DEBUG

	cout << "****************DEBUG MODE**********************\n" << endl;

#else

	// sample
	cout << "【sample input】:" << endl;
	for (int x = 0, y = 1; x < 5; x++) cout << (y = y * 10) << endl;
	cout << "【sample output】:" << endl;
	for (int x = 0, y = 1; x < 5; x++) GoldBach((y = y * 10), 1, 1);
	cout << endl;

#endif // _DEBUG


#ifdef _DEBUG
	ListGenerator(input_list, MAX_ARRAY-10);
	counter = MAX_ARRAY-10;
#else
	cout << "请输入大于4的偶数序列，并在结尾输入0表示退出：" << endl;
	while (true)
	{
		cin >> input_list[counter];
		if (!InputCheck())
		{
			cout << "仅能输入unsigned long long类型整数！("
				<< 4 << '~' << (BIG)0 - 2 << ')' << endl;
			continue;
		}
		if (input_list[counter] == 0)  break;
		counter++;
	}
#endif // _DEBUG

	// menu
	cout << "1. 不使用质数筛 + 清爽模式" << endl;
	cout << "2. 不使用质数筛 + 狂野模式" << endl;
	cout << "3. 使用质数筛 + 清爽模式" << endl;
	cout << "4. 使用质数筛 + 狂野模式" << endl;
	cout << "5. 运行以上所有，仅返回用时\n" << endl;

#ifdef _DEBUG

	while (true)
	{
		cout << "mode:";
		cin >> mode;
		if (mode == 5)
		{
			babble = 0;
			for (size_t i = 1; i <= 4; i++)
			{
				start = clock();
				GoldBachInitialize(input_list, counter, i, babble);
				end = clock();
				cout << "模式" << i << "用时"
					<< (double)(end - start) / (double)CLOCKS_PER_SEC * 1000 << "ms" << endl;
				cin;
			}
		}
		else
		{
			start = clock();
			GoldBachInitialize(input_list, counter, mode, babble);
			end = clock();
			cout << "模式" << mode << "用时"
				<< (double)(end - start) / (double)CLOCKS_PER_SEC * 1000 << "ms" << endl;
			cin;
		}
	}


#else

	cout << "对于大量近似数量级输入，请使用质数筛！！" << endl;

	while (true) {
		cin >> mode;
		if (!InputCheck() || mode < 1 || mode > 5) cout << "请输入序号！(1~5)" << endl;
		else break;
	}

	if (mode == 5)
	{
		babble = 0;
		for (size_t i = 1; i <= 4; i++)
		{
			start = clock();
			GoldBachInitialize(input_list, counter, i, babble);
			end = clock();
			cout << "模式" << i << "用时："
				<< ((double)end - (double)start) / (double)CLOCKS_PER_SEC * 1000 << "ms" << endl;
			cin;
		}
	}
	else
	{
		GoldBachInitialize(input_list, counter, mode, babble);
	}


#endif // _DEBUG
	system("pause");
	return 0;
} 