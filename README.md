程序设计语言--作业2：验证哥德巴赫猜想
================================================


# 程序特点

1. 实现了超长类型整数的运算(支持4 ~ unsigned long long 类型)，且速度不慢。
2. 优化了判断素数的算法，跳过了大量不必要的运算（剪枝？）
3. 使用欧拉筛法。优先将用户给定数表范围内的质数全部求出后再运算，对于大量需验证数据更加友好。
4. 实现了对所有素数组合的输出，提供5种模式：
   
```c++
cout << "1. 不使用质数筛 + 清爽模式" << endl;
cout << "2. 不使用质数筛 + 狂野模式" << endl;
cout << "3. 使用质数筛 + 清爽模式" << endl;
cout << "4. 使用质数筛 + 狂野模式" << endl;
cout << "5. 依次完成以上所有过程，仅返回运行时长" << endl;
```

清爽模式对每个数都仅输出一行，狂野模式对每个数都输出所有组合。时间差异如下（debug模式下）

| 时间 (ms) | 不使用质数筛 | 使用质数筛 |
| --------- | ------------ | ---------- |
| 清爽模式 | 1            | 1          |
| 狂野模式 | 2257         | 160        |

当然，质数筛导致了内存占用较高，属于空间换时间，因此不使用素数筛可以达到unsigned long long长度的数字验证，而使用素数筛仅能验证约200,000,000以内的数，且占用较大内存。

与此同时，注意到cout函数兼容等其他因素，导致输出效率较低，反而使得在狂野模式下影响输出效率的是cout函数而非算法本身。因此不建议超大数使用狂野模式。

文件版本
----------------------------------

文件分为Debug版本与Release版本，
### Debug
Debug版本在运行时生成一定量的随机数（990个，INT_MAX以内的偶数，可自定义），用户选择输出的模式，返回运行结果。

### Release
Release版本是作业版本，用户输入需要验证的数。

# 文件说明

```
GOLDBACH\
│  bonus.cpp
│  bonus.h
│  main.cpp
│  prime_judge.cpp
│  prime_judge.h
│  README.md
```

- bonus.cpp, bonus.h // 负责素数筛的实现和补充函数。
- main.cpp // 入口，处理用户输入
- prime_judge.cpp, prime_judge.h // 所有初始化、运算函数

素数判断方法
------------------------
对于任一质数$p\ge5$，我们有：
$$
\begin{aligned}
    p = & 6i-1 , or\\
    =& 6i+1.\\
\end{aligned}
$$
故对于任意一个大于4的数a，我们首先可以通过验证其是否满足
$$a = 5(mod6) || a = 1 (mod 6)$$
若不满足，一定非质数。
随后判断时，也可以进行简单的筛选：
1. 任何合数都是由素数组成
2. 判断是否为素数需要用小于它的素数相除

因此只需要尝试所有小于$\sqrt{a}$的**素数**是否为$a$的因子即可，程序中采用所有 $6i+1$ & $6i-1$代替。

## 快速线性筛选（欧拉筛法）

传统的埃氏筛法存在一定的问题，给定一个上界$N$，通过循环赋值
```
对于所有 prime[i] * k <= N ：
is_prime[prime[i] * k] = 0
```
去除所有合数。

然而存在较多重复，例如5\*6和2\*15，因此选用欧拉筛。具体实现方式可见代码。