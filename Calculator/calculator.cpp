#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Printer
{
private:

    string expression[8];

    vector <string> getAsciiArt(char c)
    {
        vector <string> result(8);
        switch(c)
        {
        case '(':
            result[0] = "  $$$\\  ";
            result[1] = " $$  _| ";
            result[2] = "$$  /   ";
            result[3] = "$$ |    ";
            result[4] = "$$ |    ";
            result[5] = "\\$$\\    ";
            result[6] = " \\$$$\\  ";
            result[7] = "  \\___| ";
            break;
        case ')':
            result[0] = " $$$\\   ";
            result[1] = "  \\$$\\  ";
            result[2] = "   \\$$\ ";
            result[3] = "    $$ |";
            result[4] = "    $$ |";
            result[5] = "   $$  |";
            result[6] = " $$$  / ";
            result[7] = " \\___/  ";
            break;
            case '*':
            result[0] = "             ";
            result[1] = "   $$\\$$\\    ";
            result[2] = "   \\$$$  |   ";
            result[3] = "  $$$$$$$\\   ";
            result[4] = "  \\_$$$ __|  ";
            result[5] = "   $$ $$\\    ";
            result[6] = "   \\__\\__|   ";
            result[7] = "             ";
            break;
            case '/':
            result[0] = "        $$\\   ";
            result[1] = "       $$  |  ";
            result[2] = "      $$  /   ";
            result[3] = "     $$  /    ";
            result[4] = "    $$  /     ";
            result[5] = "   $$  /      ";
            result[6] = "  $$  /       ";
            result[7] = "  \\__/        ";
            break;
            case '+':
            result[0] = "              ";
            result[1] = "     $$\\      ";
            result[2] = "     $$ |     ";
            result[3] = "  $$$$$$$$\\   ";
            result[4] = "  \\__$$  __|  ";
            result[5] = "     $$ |     ";
            result[6] = "     \\__|     ";
            result[7] = "              ";
            break;
            case '-':
            result[0] = "            ";
            result[1] = "            ";
            result[2] = "            ";
            result[3] = "  $$$$$$\\   ";
            result[4] = "  \\______|  ";
            result[5] = "            ";
            result[6] = "            ";
            result[7] = "            ";
            break;
            case '0':
            result[0] = " $$$$$$\\  ";
            result[1] = "$$$ __$$\\ ";
            result[2] = "$$$$\\ $$ |";
            result[3] = "$$\\$$\\$$ |";
            result[4] = "$$ \\$$$$ |";
            result[5] = "$$ |\\$$$ |";
            result[6] = "\\$$$$$$  /";
            result[7] = " \\______/ ";
            break;
            case '1':
            result[0] = "  $$\\   ";
            result[1] = "$$$$ |  ";
            result[2] = "\\_$$ |  ";
            result[3] = "  $$ |  ";
            result[4] = "  $$ |  ";
            result[5] = "  $$ |  ";
            result[6] = "$$$$$$\\ ";
            result[7] = "\\______|";
            break;
            case '2':
            result[0] = " $$$$$$\\  ";
            result[1] = "$$  __$$\\ ";
            result[2] = "\\__/  $$ |";
            result[3] = " $$$$$$  |";
            result[4] = "$$  ____/ ";
            result[5] = "$$ |      ";
            result[6] = "$$$$$$$$\\ ";
            result[7] = "\\________|";
            break;
            case '3':
            result[0] = " $$$$$$\\  ";
            result[1] = "$$ ___$$\\ ";
            result[2] = "\\_/   $$ |";
            result[3] = "  $$$$$ / ";
            result[4] = "  \\___$$\\ ";
            result[5] = "$$\\   $$ |";
            result[6] = "\\$$$$$$  |";
            result[7] = " \\______/ ";
            break;
            case '4':
            result[0] = "$$\\   $$\\ ";
            result[1] = "$$ |  $$ |";
            result[2] = "$$ |  $$ |";
            result[3] = "$$$$$$$$ |";
            result[4] = "\\_____$$ |";
            result[5] = "      $$ |";
            result[6] = "      $$ |";
            result[7] = "      \\__|";
            break;
            case '5':
            result[0] = "$$$$$$$\\  ";
            result[1] = "$$  ____| ";
            result[2] = "$$ |      ";
            result[3] = "$$$$$$$\\  ";
            result[4] = "\\_____$$\\ ";
            result[5] = "$$\\   $$ |";
            result[6] = "\\$$$$$$  |";
            result[7] = " \\______/ ";
            break;
            case '6':
            result[0] = " $$$$$$\\  ";
            result[1] = "$$  __$$\\ ";
            result[2] = "$$ /  \\__|";
            result[3] = "$$$$$$$\\  ";
            result[4] = "$$  __$$\\ ";
            result[5] = "$$ /  $$ |";
            result[6] = " $$$$$$  |";
            result[7] = " \\______/ ";
            break;
            case '7':
            result[0] = "$$$$$$$$\\ ";
            result[1] = "\\____$$  |";
            result[2] = "    $$  / ";
            result[3] = "   $$  /  ";
            result[4] = "  $$  /   ";
            result[5] = " $$  /    ";
            result[6] = "$$  /     ";
            result[7] = "\\__/      ";
            break;
            case '8':
            result[0] = " $$$$$$\\  ";
            result[1] = "$$  __$$\\ ";
            result[2] = "$$ /  $$ |";
            result[3] = " $$$$$$  |";
            result[4] = "$$  __$$< ";
            result[5] = "$$ /  $$ |";
            result[6] = "\\$$$$$$  |";
            result[7] = " \\______/ ";
            break;
            case '9':
            result[0] = " $$$$$$\\  ";
            result[1] = "$$  __$$\\ ";
            result[2] = "$$ /  $$ |";
            result[3] = "\\$$$$$$$ |";
            result[4] = " \\____$$ |";
            result[5] = "$$\\   $$ |";
            result[6] = "\\$$$$$$  |";
            result[7] = " \\______/ ";
            break;

        }
        return result;
    }

    void putInExpression(vector <string> symbol)
    {
        for (int i = 0; i < 8; ++i)
        {
            expression[i] += symbol[i];
        }
    }

    void putChar(char c)
    {
        assert(c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
            || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'
            || c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')');
        putInExpression(getAsciiArt(c));
    }

    void expressionFilling(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            putChar(s[i]);
        }
    }

    int priorityDispute(char s, char c)
    {
        if (s == '(')
        {
            return 3;
        }
        if (s == ')')
        {
            return 4;
        }
        if ((s == '*' || s == '/') && (c == '+' || c == '-'))
        {
            return 0;
        }
        /*if (((s == '+' || s == '-') && (c == '*' || c == '/'))
            || (((s == '+' || s == '-') && (c == '+' || c == '-')) || ((s == '*' || s == '/') && (c == '*' || c == '/'))))
        {*/
            return 1;
        //}
    }

    vector <string> doPostfixNotation(string s)
    {
        vector <string> postfixNotation;
        vector <string> stackOfOperands;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                bool flag = 1;
                string c;
                while (flag)
                {
                    c.push_back(s[i++]);
                    if (s[i] < '0' || s[i] > '9')
                    {
                        postfixNotation.push_back(c);
                        flag = 0;
                    }
                }
            }
            if (stackOfOperands.empty() || stackOfOperands[stackOfOperands.size() - 1][0] == '(')
            {
                string c;
                c.push_back(s[i]);
                stackOfOperands.push_back(c);
                continue;
            }
            switch(priorityDispute(s[i], stackOfOperands[stackOfOperands.size() - 1][0]))
            {
            case 0:
                string a;
                a.push_back(s[i]);
                stackOfOperands.push_back(a);
                break;
            case 1:
                if (s[i] == '*' || s[i] == '/')
                {
                    while (stackOfOperands[stackOfOperands.size() - 1][0] != '('
                        && priorityDispute(s[i], stackOfOperands[stackOfOperands.size() - 1][0]) != 0
                        && !stackOfOperands.empty())
                    {
                        postfixNotation.push_back(stackOfOperands[stackOfOperands.size() - 1]);
                        stackOfOperands.pop_back();
                    }
                    string x;
                    x.push_back(s[i]);
                    stackOfOperands.push_back(x);
                }
                else
                {
                    while (stackOfOperands[stackOfOperands.size() - 1][0] != '('
                        && !stackOfOperands.empty())
                    {
                        postfixNotation.push_back(stackOfOperands[stackOfOperands.size() - 1]);
                        stackOfOperands.pop_back();
                    }
                    string c;
                    c.push_back(s[i]);
                    stackOfOperands.push_back(c);
                }
                break;
            case 3:
                string c;
                c.push_back(s[i]);
                stackOfOperands.push_back(c);
                break;
            case 4:
                while (stackOfOperands[stackOfOperands.size() - 1][0] != '('
                        && !stackOfOperands.empty())
                {
                     postfixNotation.push_back(stackOfOperands[stackOfOperands.size() - 1]);
                     stackOfOperands.pop_back();
                }
            }
        }
    }

public:

    Printer()
    {
        for (int i = 0; i < 8; ++i)
        {
            expression[i] = "";
        }
    }

    void expressionInput(string s)
    {
        expressionFilling(s);
        calculate(doPostfixNotation(s));
    }

    void printResult()
    {
        for (int i = 0; i < 8; ++i)
        {
            cout << expression[i] << endl;
        }
    }
};





