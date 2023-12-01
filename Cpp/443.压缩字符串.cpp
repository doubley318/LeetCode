/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size();
        int l = 0;
        int sum = 1;
        char pre = chars[0];
        for (int i = 1; i < n; i++) {
            if (chars[l] == chars[i]) {
                sum++;
            } else if (chars[l] != chars[i]) {
                if (sum != 1) {
                    int tmp = 1;
                    while (sum > 0) {
                        chars[l + tmp] = '0' + (sum % 10);
                        sum /= 10;
                        tmp++;
                    }
                    reverse(chars.begin() + l + 1, chars.begin() + l + tmp);
                    sum = tmp;
                }
                l = l + sum;
                pre = chars[i];
                chars[l] = pre;
                sum = 1;
            }
        }
        if (sum != 1) {
            int tmp = 1;
            while (sum > 0) {
                chars[l + tmp] = '0' + (sum % 10);
                sum /= 10;
                tmp++;
            }
            reverse(chars.begin() + l + 1, chars.begin() + l + tmp);
            sum = tmp;
        }
        l = l + sum;
        return l;
    }
};
// @lc code=end
