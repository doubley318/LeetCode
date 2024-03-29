/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                if(tokens[i]=="+") st.push(num2+num1);
                if(tokens[i]=="-") st.push(num2-num1);
                if(tokens[i]=="*") st.push((long)num2*(long)num1);
                if(tokens[i]=="/") st.push(num2/num1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
// @lc code=end
