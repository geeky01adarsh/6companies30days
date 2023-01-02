// https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Using Recursion

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string t = tokens.back();
        tokens.pop_back();
        if(t != "+" && t != "-" && t != "*" && t != "/") return stoi(t);
        else{
            long long b = evalRPN(tokens);
            long long a = evalRPN(tokens);
            if(t == "+") return a + b;
            else if(t == "-") return a - b;
            else if(t == "*") return a * b;
            else return a / b;
        }
    }
};

// Using Stacks

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto i : tokens)
        {
            if (i != "+" && i != "-" && i != "*" && i != "/")
                st.push(stoi(i));
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans;
                if (i == "+")
                    ans = a + b;
                else if (i == "-")
                    ans = b - a;
                else if (i == "*")
                    ans = a * b;
                else
                    ans = b / a;
                st.push(ans);
            }
        }
        return st.top();
    }
};