#include<iostream>
using namespace std;

class Solution{
public:
    bool check(int a,int b)//本身和本身的平方
    {
        if(a==b)//=和==
            return true;
        //拆分 不用else
        int d=10;
        while(b>=10 && b%d<=a)//例子：4 16
        {
            if(check(b/d,a-b%d))
                return true;
            d*=10;//d=d*10
        }
        return false;
    }
    int number(int n)
    {
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(check(i,i*i))
                ans+=i*i;
        }
        return ans;
    }
};
int main()
{
    //1.输入
    Solution solution;
    int n;
    cin >> n;
    //2.循环（函数）int类型
    //3.判断（函数）bool类型（循环里套判断）
    //4.输出
    int sum = solution.number(n);
    cout << sum << endl;
    return 0;
}