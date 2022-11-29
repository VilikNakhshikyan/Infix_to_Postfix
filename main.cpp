#include <vector>
#include <string>
#include <iostream>

int priority(char my_operator)
{
    if (my_operator == '^')
        return 3;
    else if (my_operator == '/' || my_operator == '*')
        return 2;
    else if (my_operator == '+' || my_operator == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(std::string s)
{
    std::vector<char> answer;
    std::string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            answer.push_back('(');

        else if (c == ')')
        {
            while (answer[answer.size() - 1] != '(')
            {
                result += answer[answer.size() - 1];
                answer.pop_back();
            }
            answer.pop_back();
        }

        else
        {
            while (!answer.empty() && priority(s[i]) <= priority(answer[answer.size() - 1]))
            {
                result += answer[answer.size() - 1];
                answer.pop_back();
            }
            answer.push_back(c);
        }
    }

    while (!answer.empty())
    {
        result += answer[answer.size() - 1];
        answer.pop_back();
    }

    std::cout << result << std::endl;
}

int main()
{
    std::string exp = "a-b/(c-d^e)*(f^g-h/i)+j/k^(l-m*n/o)+p";
    infixToPostfix(exp);
    return 0;
}
