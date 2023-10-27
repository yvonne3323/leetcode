#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start
// 一个朴素的做法是遍历 [1,i]，若当前数值 i 满足要求，则将 i×i 累加到答案中。
// 问题关键转为：如何判定 i×i 是否能够分割成多个整数，使其累加值为 i。
// 简单做法是通过递归来做：每次从当前值的低位开始截取，通过「取余」和「地板除」操作，得到截取部分和剩余部分，再继续递归处理。

class Solution {
public:
    bool check(int t, int x) 
    {
        if (t == x) //第一种可能：本身的平方等于自己（只有 1 和 0）
            return true;
        int d = 10;
        while (t >= d && t % d <= x) 
        //t>=d:保证可以拆分 t%d<=x:保证个位数没有超过原来的数
        //如果这两个条件满足，那么意味着我们可以尝试将 t 拆分成两个部分，一个部分是 t / d，另一个部分是 t % d。
        {
            if (check(t / d, x - (t % d))) //继续拆分
            //将 t / d 作为新的 t，将 x - (t % d) 作为新的 x，继续尝试拆分。这是递归的关键部分
            //
                return true;
            d *= 10;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++)//遍历 [1,i]
        {
            if (check(i * i, i)) ans += i * i;
        }
        return ans;
    }
};

