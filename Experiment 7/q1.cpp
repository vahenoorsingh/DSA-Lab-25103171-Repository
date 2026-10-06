#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int longest_valid_parentheses(const string &s)
{
    stack<int> st;
    st.push(-1);

    int best = 0;
    string max_valid = "";

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                if (len > best)
                {
                    best = len;
                    max_valid = s.substr(st.top() + 1, len);
                }
            }
        }
    }

    cout << "Max Valid Parenthesis: " << max_valid << endl;
    return best;
}

int main()
{
    string s = "()(()()";
    int l = longest_valid_parentheses(s);
    cout << "Longest Valid Parenthesis: " << l << endl;
}