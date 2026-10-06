#include <iostream>
using namespace std;
string infix_to_postfix(string infix);

int main()
{
    cout << infix_to_postfix("1*(2+3/4)-5") << endl;
}

string infix_to_postfix(string infix)
{
    string num = "";
    string postfix = "";
    stack<char> s;
    for (char &c : infix)
    {
        if (c >= '0' && c <= '9')
        {
            num = num + c;
        }
        else
        {
            postfix = postfix + num;
            num = "";
            if (c == '(')
            {
                s.push('(');
            }
            else if (c == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    postfix = postfix + s.top();
                    s.pop();
                }
                if (!s.empty() && s.top() == '(')
                    s.pop();
            }
            else if (c == '^' || c == '%')
            {
                if (!s.empty() && (s.top() == '^' || s.top() == '%'))
                {
                    s.push(c);
                }
                else
                {
                    while (!s.empty() && s.top() != '(' && (s.top() == '*' || s.top() == '/'))
                    {
                        postfix = postfix + s.top();
                        s.pop();
                    }
                    s.push(c);
                }
            }
            else if (c == '*' || c == '/')
            {
                while (!s.empty() && s.top() != '(' && (s.top() == '*' || s.top() == '/' || s.top() == '^' || s.top() == '%'))
                {
                    postfix = postfix + s.top();
                    s.pop();
                }
                s.push(c);
            }
            else if (c == '+' || c == '-')
            {
                while (!s.empty() && s.top() != '(' && (s.top() == '*' || s.top() == '/' || s.top() == '^' || s.top() == '%' || s.top() == '+' || s.top() == '-'))
                {
                    postfix = postfix + s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }
    if (num.size() > 0)
    {
        postfix = postfix + num;
    }
    while (!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }
    return postfix;
}