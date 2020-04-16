#include "bonus.h"
#include <cstring>


bool* is_prime; // global pointer for PrimeSieve

void PrimeSieve(size_t N)
{
    is_prime = new bool[N];
    BIG* prime = new BIG[N];
    memset(is_prime, 1, sizeof(bool) * N);
    memset(prime, 0, sizeof(BIG) * N);

    for (BIG i = 2; i <= N; i++)
    {
        if (is_prime[i]) prime[++prime[0]] = i;
        for (BIG j = 1; j <= prime[0] && i * prime[j] <= N; j++) 
        {
            is_prime[i * prime[j]] = 0; 
            if (i % prime[j] == 0) break; // 防止多次去除
        }
    }
    delete[] prime;
    return;
}

bool InputCheck()
{
    if (cin.fail()) // Input error handling
    {
        cin.clear(), cin.sync();
        while (cin.get() != '\n'); // Clear this line
        return false;
    }
    else
        return true;
}

BIG* ListGenerator(BIG* input_list, size_t num)
{
    for (size_t i = 0; i < num; i++)
    {
        input_list[i] = (BIG)(rand() % 1000000) * 2;
        // cout << input_list[i] << '\t';    // 删除注释可显示生成的随机数
        // if (!((i + 1) % 5)) cout << '\n';
    }
    cout << " Automatically generating numbers... " << endl;
    cout << " Range: from 0 to 2000000..." << endl;
    cout << " Generated " << num << " random numbers..." << endl;
    cout << " 去除 main.cpp 中 ListGenerator 内的注释，以输出生成的随机数。 " << endl;
    cout << endl;
    return input_list;
}
