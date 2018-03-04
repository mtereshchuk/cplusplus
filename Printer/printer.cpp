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
    
public:
    Printer()
    {
        for (int i = 0; i < 8; ++i)
        {
            expression[i] = "";
        }
    }
    void putChar(char c)
    {
        assert(c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
            || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'
            || c == '+' || c == '-' || c == '(' || c == ')');
        putInExpression(getAsciiArt(c));
    }
    void putInt(int number)
    {
        int reverseNumber = 0;
        int cntNumber = 0;
        int cntReverseNumber = 0;
        if (number < 0)
        {
            putChar('-');
            number *= -1;
        }
        while (number)
        {
            reverseNumber = reverseNumber * 10 + number % 10;
            ++cntNumber;
            number /= 10;
        }
        while (reverseNumber)
        {
            putChar(reverseNumber % 10 + '0');
            ++cntReverseNumber;
            reverseNumber /= 10;
        }
        if (cntNumber != cntReverseNumber)
        {
            for (int i = 0; i < cntNumber - cntReverseNumber; ++i)
            {
                putChar('0');
            }
        }
    }
    void print()
    {
        for (int i = 0; i < 8; ++i)
        {
            cout << expression[i] << endl;
        }
    }
};

int main()
{
    Printer a;
    a.putInt(2);
    a.putChar('+');
    a.putInt(2);
    a.putChar('-');
    a.putInt(2);
    a.print();
    return 0;
}
