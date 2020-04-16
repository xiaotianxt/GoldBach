#include "prime_judge.h"

// ����ģʽ��ʼ������ָ������
fp prime[] = { NULL, IsPrime, IsPrime, IsPrimeBonus, IsPrimeBonus };
vp chat[] = { DoNothing, Chatter };

void GoldBachInitialize(BIG* input_list, size_t counter, size_t mode, bool babble)
{
    size_t i = 0;
    
    if (mode > 2) // ʹ������ɸ
    {
        BIG max = MaxList(input_list, counter);
        if (max > 200000000)
        {
            cout << "�޷�Ϊ��Χ����200,000,000������ʹ��ŷ��ɸ������" << endl;
            return;
        }
        else
            PrimeSieve((unsigned)max);
    }

    if (mode == 5) // �Ƿ�������
        babble = 0;

    for (i = 0; i < counter; i++) // �����֤
        GoldBach(input_list[i], mode, babble);

    return;
}

void GoldBach(BIG input, size_t mode, bool babble)
{
    if (input > 3 && !(input % 2)) // ����4���ϵ�ż������
    {
        BIG i;
        bool flag = 0;

        if ((flag = prime[mode](input - 2)) || prime[mode](input - 3)) // �ж��Ƿ�����input == 2(3) + Y
        {
            chat[babble](input, (BIG)3 - flag);
            // cout << input << '=' << 3 - flag << '+' << input - 3 + flag << endl;
            if (mode % 2) return; // ��ˬģʽ���ټ���
        }

        for (i = 5; i <= input / 2; i += 6) // i <= input/2, ��֤x<=y
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
    else if (0 == input) // ����0������˳�
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
    if (x == 0) // ����������
    {
        if (input % 2) // ����ż����ʾ
        {
            cout << input << "��������������֤" << endl;
        }
        else if (input < 0) // ���븺����ʾ
        {
            cout << input << "�Ǹ�����������֤" << endl;
        }
        else if (input <= 2)
        {
            cout << input << "��С�ڵ���2������������֤" << endl;
        }
    }

    cout << input << " = " << x << " + " << input - x << endl;
}

void DoNothing(BIG a, BIG b)
{
    return;
}
