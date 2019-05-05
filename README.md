# LuoguOJ
洛谷 OJ 题解

## P1000 超级玛丽游戏

[Problem description](https://www.luogu.org/problemnew/show/P1000)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1000/main.cpp)

## P1001 A+B Problem

[Problem description](https://www.luogu.org/problemnew/show/P1001)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1001/main.cpp)

## P1002 过河卒

[Problem description](https://www.luogu.org/problemnew/show/P1002)

[C++ (100/100)](https://github.com/Heliovic/LuoguOJ/blob/master/P1002/main.cpp)

### 解题思路

* DFS：遍历所有可以到达的路径，注意若访问过某个点 (x, y)，则保存从该点出发的可及路径的个数，下次再访问该点时，result += ans[x][y]。事实上，这是一种递推。
