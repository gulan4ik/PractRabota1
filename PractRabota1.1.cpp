#include <iostream>
using namespace std;

void Int()
{
    int number;
    cin >> number;
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i)

    {

        cout << ((number >> i) & 1);

        if (i == sizeof(int) * 8 - 1)

            cout << ' ';

    }

    cout << endl;
}
void Float()
{
    union
    {
        float number;
        int num;
    };
    cin >> number;
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)

    {

        cout << ((num >> i) & 1);

        if (i == sizeof(int) * 8 - 1)

            cout << ' ';
        if (i == sizeof(int) * 8 - 1.2)

            cout << ' ';
        if ((i == sizeof(unsigned long int) * 8 - 1) || (i == sizeof(unsigned long int) * 8 - 9))

            cout << ' ';

    }

    cout << endl;
}

void Double()
{
    union 
    { 
        double number; 
        unsigned long int doubArray[2]; 
    };
    cin >> number;
    for (int i = 1; i >= 0; i--)
    {
        for (int j = sizeof(unsigned long int) * 8 - 1; j >= 0; j--)
        {
            cout << ((doubArray[i] >> j) & 1);

            if ((i == 1) && ((j == sizeof(unsigned long int) * 8 - 1) || (j == sizeof(unsigned long int) * 8 - 12)))

            cout << ' ';
        }
    }
}
int main()
{
    setlocale(0, "");
    cout << "int: " << sizeof(int) << "\nshort int: " << sizeof(short int) << "\nlong int: " << sizeof(long int) << "\nfloat: " << sizeof(float) << "\ndouble: "
        << sizeof(double) << "\nlong double: " << sizeof(long double) << "\nchar: " << sizeof(char) << "\nbool: " << sizeof(bool) << "\n";
    int typeOfOperation;
    cout << "Выберите тип данных:" << "\n" << "1. Integer" << "\n" << "2. Float" << "\n" << "3. Double" << "\n";
    cin >> typeOfOperation;
    while (true)
    {
        if (typeOfOperation == 1)
        {
            Int();
            break;
        }
        else if (typeOfOperation == 2)
        {
            Float();
            break;
        }
        else if (typeOfOperation == 3)
        {
            Double();
            break;
        }
        else
        {
            cout << "Ошибка, введите 1, 2 или 3." << "\n";
            cin >> typeOfOperation;
        }
    }
}
