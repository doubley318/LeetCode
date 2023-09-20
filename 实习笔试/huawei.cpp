#include <iostream>
#include <map>
using namespace std;

int ans = 0;

// 字符串S作为输入，从l的位置开始检查
bool del(string s, int l)
{
    // 如果l等于s的长度，说明刚刚好结束，因此就是正确的
    if (l == s.size())
        return true;
    // 如果l大于s的长度，说明不正确
    if (l > s.size())
        return false;
    int tmp = 0;
    int i = l;
    // 循环每个字符，如果这个字符是数字的话，就进入循环，不是数字直接返回错误。
    while (i < s.size() && s[i] <= '9' && s[i] >= '0')
    {
        // 把数字加上去
        tmp = tmp * 10 + s[i] - '0';
        // 对字符串s进行检查，这时候开始的位置应该为 tmp+i+1
        // 比如 s=109jskskwkxi，这时候l=0，i=0，tmp=1，
        // 意思先看1是否能继续，因此这时候起始位置变为 2，然后进行判断
        if (del(s, tmp + i + 1))
        {
            // 如果判断没问题，说明是可以解释的明白的，但是并不能判断是否具有二义性
            // 比如s=109jskskwkxi在最开始的时候是可以判断没问题，但是当时的判断是1 0 9 jskskwkxi这样子的
            // 但是起始还有可能是10 9jskskwkxi，所以我们继续往后走一位，也就是 tmp_tmp=10
            int tmp_i = i + 1;
            if (tmp_i < s.size() && s[tmp_i] <= '9' && s[i] >= '0')
            {
                int tmp_tmp = tmp * 10 + s[tmp_i] - '0';
                // 这时候再次判断 10 9jskskwkxi可不可以
                if (del(s, tmp_tmp + tmp_i + 1))
                {
                    // 发现 10 9jskskwkxi也是可以的，说明出现了二义性，因此标记一下，记为ans++
                    ans++;
                }
            }
            return true;
        }
        i++;
    }
    return false;
}

int main()
{
    string s;
    // 9abshwjxns
    // 109jskskwkxi
    // 1sjw
    cin >> s;
    // del表示这个字符串是否可以解释的通
    if (del(s, 0))
    {
        // 解释通，这时候看ans是否为0，如果为0，则没有二义性
        if (ans == 0)
            cout << "yes" << endl;
        // 不为0 说明第39行执行了，说明就是具有二义性
        else
            cout << "two" << endl;
    }
    // 都解释不通，肯定就是不行了。
    else
        cout << "no" << endl;
    return 0;
}