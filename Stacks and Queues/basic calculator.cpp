/*
leetcode 224 - basic calculator
*/

class Solution
{
public:
    long operate(long num1, long num2, char op)
    {
        if (op == '+')
            return num1 + num2;
        else if (op == '-')
            return num1 - num2;
        else if (op == '*')
            return num1 * num2;
        else
            return num1 / num2;
    }

    int calculate(string s)
    {
        if (s[0] == '-')
            s = '0' + s;

        unordered_map<char, int> prec;
        prec['+'] = 1;
        prec['-'] = 1;
        prec['*'] = 2;
        prec['/'] = 2;
        prec['('] = 0;

        stack<long> operand;
        stack<char> operators;

        int i = 0;
        while (i < s.length())
        {
            char c = s[i];
            if (c == ' ')
            {
                i++;
                continue;
            }
            else if (c == '(')
            {
                operators.push('(');
                i++;
                continue;
            }
            else if (c == ')')
            {
                while (operators.top() != '(')
                {
                    long num2 = operand.top();
                    operand.pop();
                    long num1 = operand.top();
                    operand.pop();
                    char op = operators.top();
                    operators.pop();
                    long val = operate(num1, num2, op);
                    operand.push(val);
                }
                operators.pop();
                i++;
            }
            else if (c >= '0' && c <= '9')
            {
                long num = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                operand.push(num);
                continue;
            }
            else
            {
                while (!operators.empty() && prec[operators.top()] <= prec[c])
                {
                    long num2 = operand.top();
                    operand.pop();
                    long num1 = operand.top();
                    operand.pop();
                    char op = operators.top();
                    operators.pop();
                    long val = operate(num1, num2, op);
                    operand.push(val);
                }
                operators.push(c);
                i++;
            }
        }

        while (!operators.empty())
        {
            long num2 = operand.top();
            operand.pop();
            long num1 = operand.top();
            operand.pop();
            char op = operators.top();
            operators.pop();
            long val = operate(num1, num2, op);
            operand.push(val);
        }

        long ans = operand.top();
        return (int)ans;
    }
};