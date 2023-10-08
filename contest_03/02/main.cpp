#include <iostream>
#include <stack>
#include <string>

bool checkBalanced(const std::string& text) 
{
    std::stack<char> bracketsStack;

    for (char c : text) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            bracketsStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (bracketsStack.empty()) 
            {
                return false;
            }

            char top = bracketsStack.top();
            bracketsStack.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return bracketsStack.empty();
}

int main() 
{
    std::string text;
    std::getline(std::cin, text, '!');

    if (checkBalanced(text)) 
    {
        std::cout << "YES" << std::endl;
    }
    else 
    {
        std::cout << "NO" << std::endl;
    }
}
