#include "prime_judge.h"

// 根据模式初始化函数指针数组
fp prime[] = { NULL, IsPrime, IsPrime, IsPrimeBonus, IsPrimeBonus };
vp chat[] = { DoNothing, Chatter };

void GoldBachInitialize(BIG* input_list, size_t counter, size_t mode, bool babble)
{
    size_t i = 0;
    
    if (mode > 2) // 使用质数筛
    {
        BIG max = MaxList(input_list, counter);
        if (max > 200000000)
        {
            cout << "无法为范围大于200,000,000的数组使用欧拉筛法！！" << endl;
            return;
        }
        else
            PrimeSieve((unsigned)max);
    }

    if (mode == 5) // 是否输出结果
        babble = 0;

    for (i = 0; i < counter; i++) // 逐个验证
        GoldBach(input_list[i], mode, babble);

    return;
}

void GoldBach(BIG input, size_t mode, bool babble)
{
    if (input > 3 && !(input % 2)) // 符合4以上的偶数条件
    {
        BIG i;
        bool flag = 0;

        if ((flag = prime[mode](input - 2)) || prime[mode](input - 3)) // 判断是否满足input == 2(3) + Y
        {
            chat[babble](input, (BIG)3 - flag);
            // cout << input << '=' << 3 - flag << '+' << input - 3 + flag << endl;
            if (mode % 2) return; // 清爽模式不再继续
        }

        for (i = 5; i <= input / 2; i += 6) // i <= input/2, 保证x<=y
        {
            if (prime[mode](i) & prime[mode](input - i))
            {
                chat[babble](input, i);
                // cout << input << '=' << i << '+' << input - i << endl;
                if (mode % 2) return;
            }
            else if (prime[mode](i + (BIG)2) & prime[mode](input - i - 2))
            {
                chat[babble](input, i + 2);
                // cout << input << '=' << i + 2 << '+' << input - i - 2 << endl;
                if (mode % 2) return;
            }
        }
    }
    else if (0 == input) // 输入0或错误，退出
    {
        return;
    }
    else
    {
        chat[babble](input, 0);
    }

    return ;
}

static BIG MaxList(BIG* input_list, size_t counter)
{
    size_t i = 0;
    BIG max = 0;

    for (i = 0; i < counter; i++) 
        if (input_list[i] > max) 
            max = input_list[i];

    return max;
}

bool IsPrime(BIG input)
{
	BIG i;

	if (input == 2 || input == 3) return 1;
	if (input % 6 != 1 && input % 6 != 5) return 0;

	for (i = 5; i * i <= input; i += 6)
		if (!(input % i) || !(input%(i + 2))) 
            return 0;

	return 1;
}

bool IsPrimeBonus(BIG input)
{
    extern bool* is_prime;
    return is_prime[(size_t)input];
}

void Chatter(BIG input, BIG x)
{
    if (x == 0) // 若输入有误
    {
        if (input % 2) // 输入偶数提示
        {
            cout << input << "是奇数，不能验证" << endl;
        }
        else if (input < 0) // 输入负数提示
        {
            cout << input << "是负数，不能验证" << endl;
        }
        else if (input <= 2)
        {
            cout << input << "是小于等于2的数，不能验证" << endl;
        }
    }

    cout << input << " = " << x << " + " << input - x << endl;
}

void DoNothing(BIG a, BIG b)
{
    return;
}
