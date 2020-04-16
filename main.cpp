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
	cout << "��sample input��:" << endl;
	for (int x = 0, y = 1; x < 5; x++) cout << (y = y * 10) << endl;
	cout << "��sample output��:" << endl;
	for (int x = 0, y = 1; x < 5; x++) GoldBach((y = y * 10), 1, 1);
	cout << endl;

#endif // _DEBUG


#ifdef _DEBUG
	ListGenerator(input_list, MAX_ARRAY-10);
	counter = MAX_ARRAY-10;
#else
	cout << "���������4��ż�����У����ڽ�β����0��ʾ�˳���" << endl;
	while (true)
	{
		cin >> input_list[counter];
		if (!InputCheck())
		{
			cout << "��������unsigned long long����������("
				<< 4 << '~' << (BIG)0 - 2 << ')' << endl;
			continue;
		}
		if (input_list[counter] == 0)  break;
		counter++;
	}
#endif // _DEBUG

	// menu
	cout << "1. ��ʹ������ɸ + ��ˬģʽ" << endl;
	cout << "2. ��ʹ������ɸ + ��Ұģʽ" << endl;
	cout << "3. ʹ������ɸ + ��ˬģʽ" << endl;
	cout << "4. ʹ������ɸ + ��Ұģʽ" << endl;
	cout << "5. �����������У���������ʱ\n" << endl;

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
				cout << "ģʽ" << i << "��ʱ"
					<< (double)(end - start) / (double)CLOCKS_PER_SEC * 1000 << "ms" << endl;
				cin;
			}
		}
		else
		{
			start = clock();
			GoldBachInitialize(input_list, counter, mode, babble);
			end = clock();
			cout << "ģʽ" << mode << "��ʱ"
				<< (double)(end - start) / (double)CLOCKS_PER_SEC * 1000 << "ms" << endl;
			cin;
		}
	}


#else

	cout << "���ڴ����������������룬��ʹ������ɸ����" << endl;

	while (true) {
		cin >> mode;
		if (!InputCheck() || mode < 1 || mode > 5) cout << "��������ţ�(1~5)" << endl;
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
			cout << "ģʽ" << i << "��ʱ��"
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