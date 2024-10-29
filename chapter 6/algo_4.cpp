#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string expression)
{
    string postfix = "";
    stack<char> operatorStack;

    for (char &c : expression)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); 
        }
        else
        {
            while (!operatorStack.empty() && precedence(c) <= precedence(operatorStack.top()))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();

    
        operatorStack.pop();
    }
    return postfix;
}

int main()
{
    string infixExpression;
    cout << "Enter infix expression: ";

    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
