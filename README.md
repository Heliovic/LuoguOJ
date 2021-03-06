# LuoguOJ
洛谷 OJ 题解

## P1000 超级玛丽游戏

[Problem description](https://www.luogu.org/problem/P1000)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1000/main.cpp)

## P1001 A+B Problem

[Problem description](https://www.luogu.org/problem/P1001)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1001/main.cpp)

## P1002 过河卒

[Problem description](https://www.luogu.org/problem/P1002)

[C++ (100/100) - DFS](https://github.com/Heliovic/LuoguOJ/blob/master/P1002/main.cpp)

[C++ (100/100) - DP](https://github.com/Heliovic/LuoguOJ/blob/master/P1002/main-dp.cpp)

### 解题思路

* DFS：遍历所有可以到达的路径，注意若访问过某个点 (x, y)，则保存从该点出发的可及路径的个数，下次再访问该点时，result += ans[x][y]。事实上，这是一种递推。

* 递推/动态规划：状态转移方程：dp[x][y] = dp[x + 1][y] + dp[x][y + 1]。注意边界上任意一点出发的路径条数或为 0，或为 1。

## P1003 铺地毯

[Problem description](https://www.luogu.org/problem/P1003)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1003/main.cpp)

### 解题思路

数据量太大，不适合打表，直接遍历判断点是否在矩形框内即可。

## P1004 方格取数

[Problem description](https://www.luogu.org/problem/P1004)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1004/main.cpp)

### 解题思路

动态规划。dp[s][t][u][v] 表示第一次在 (s, t) 和第二次在点 (u, v) 处所能取得的最大。dp[s][t][u][v] = mat[s][t] + mat[u][v] + max(dp[s - 1][t][u - 1][v], dp[s - 1][t][u][v - 1], dp[s][t - 1][u - 1][v], dp[s][t - 1][u][v - 1])。

若两个点是同一点，应只加一个 mat[s][t]，表示第一次取得 mat[s][t] 后，第二次到达 mat[s][t] 只能取 0。

注意，两次分开求最大相加并不能得出总体得到的是最大。[错误示范 C++ (80/100)]((https://github.com/Heliovic/LuoguOJ/blob/master/P1004/main-80.cpp))

## P1006 传纸条

[Problem description](https://www.luogu.org/problem/P1006)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1006/main.cpp)

### 解题思路

动态规划，同 P1004。

这里通过记录步数只需使用三维数组。

## P1007 独木桥

[Problem description](https://www.luogu.org/problem/P1007)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1007/main.cpp)

### 解题思路

两个士兵相遇时，实际上相当于互相穿越，不需要模拟转向。

## P1008 三连击

[Problem description](https://www.luogu.org/problem/P1008)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1008/main.cpp)

### 解题思路

简单DFS + 剪枝。

## P1009 阶乘之和

[Problem description](https://www.luogu.org/problem/P1009)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1009/main.cpp)

[Java (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1009/Main.java)

### 解题思路

大数运算。

## P1010 幂次方

[Problem description](https://www.luogu.org/problem/P1010)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1010/main.cpp)

### 解题思路

递归分治。

## P1011 车站

[Problem description](https://www.luogu.org/problem/P1011)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1011/main.cpp)

### 解题思路

找规律递推。

## P1012 拼数

[Problem description](https://www.luogu.org/problem/P1012)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1012/main.cpp)

### 解题思路

贪心排序。

## P1014 Cantor表

[Problem description](https://www.luogu.org/problem/P1014)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1014/main.cpp)

### 解题思路

二分，找规律。

## P1015 回文数

[Problem description](https://www.luogu.org/problem/P1015)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1015/main.cpp)

### 解题思路

大数加法。

对于读取非规则数据，最好先从输入流整行读取后再进行内部处理。

## P1016 旅行家的预算

[Problem description](https://www.luogu.org/problem/P1016)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1016/main.cpp)

### 解题思路

模拟+贪心。

## P1017 进制转换

[Problem description](https://www.luogu.org/problem/P1017)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1017/main.cpp)

### 解题思路

负进制。同正进制一样，取模、升阶，不同的是，当取模结果为负数时，对取模结果减去该负进制，变为正数，并从剩余数中加上该负进制。

https://github.com/Heliovic/LuoguOJ/blob/master/P1017/main.cpp#L19

## P1018 乘积最大

[Problem description](https://www.luogu.org/problem/P1018)

[C++ (90/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1018/main.cpp)

### 解题思路

方法一、DFS + 大数乘法。#7 TLE。
方法二、DP。

## P1025 数的划分

[Problem description](https://www.luogu.org/problem/P1025)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1025/main.cpp)

### 解题思路

方法一、DFS + 剪枝。注意在 for 循环就剪枝，不要再次进入下一层搜索。
方法二、DP。

## P1030 求先序排列

[Problem description](https://www.luogu.org/problem/P1030)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1030/main.cpp)

### 解题思路

根据中序遍历和先序遍历或后序遍历重建二叉树。

## P1032 字串变换

[Problem description](https://www.luogu.org/problem/P1032)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1032/main.cpp)

### 解题思路

DFS 搜索。用 map<string, vector<string>> 保存所有变换。对于一个字符串，施加一次所有可行的变换，进入下一层 DFS。

注意如下优化：

1. 若层数已经大于等于已搜索到的层数，则可以直接返回。[优化 1](https://github.com/Heliovic/LuoguOJ/blob/master/P1032/main.cpp#L23)

2. 若进入某一层时，对应的个 str 已经被搜索过，则无需搜索（用set保存，记忆化搜索）。[优化 2](https://github.com/Heliovic/LuoguOJ/blob/master/P1032/main.cpp#L20)

## P1036 选数

[Problem description](https://www.luogu.org/problem/P1036)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1036/main.cpp)

### 解题思路

子集产生 + 素数判断。

## P1037 产生数

[Problem description](https://www.luogu.org/problem/P1037)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1037/main.cpp)

### 解题思路

对于每一位，进行DFS，确定其能使用的数的数目。之后大数乘法获得答案。

## P1045 麦森数

[Problem description](https://www.luogu.org/problem/P1045)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1045/main.cpp)

### 解题思路

大数乘法、大数加法。快速幂。

由于题目中超过 500 位的不用算，因此只需单独将位数算出。

设结果的位数为 t，则有：

t = p * log10(2)。

## P2142 高精度减法

[Problem description](https://www.luogu.org/problem/P2142)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P2142/main.cpp)

### 解题思路

大数减法。注意输入方式，先将一行数据输入到buf中，再使用strlen进行读取。
