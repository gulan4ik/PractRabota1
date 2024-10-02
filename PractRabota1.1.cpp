#include <iostream>
using namespace std;

void Int()
{
    float checkIsNotInt;
    int number;
    cout << "Введите число" << "\n";
    cin >> checkIsNotInt;
    while (true)
    {
        number = checkIsNotInt;
        if (number != checkIsNotInt)
        {
            cout << "Ошибка, введите целое число" << "\n";
            cin >> checkIsNotInt;
        }
        else
            break;
    }
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i)

    {

        cout << ((number >> i) & 1); // бинарный сдвиг вправо и умножение на 1 для получения побитового представления числа

        if (i == sizeof(int) * 8 - 1)

            cout << ' ';

    }

    cout << endl;
}
void Reverse()
{
    float checkIsNotInt;
    int number;
    bool isEven = false;
    bool isNegative;
    cout << "Введите число" << "\n";
    cin >> checkIsNotInt;
    while (true)
    {
        number = checkIsNotInt;
        if (number != checkIsNotInt)
        {
            cout << "Ошибка, введите целое число" << "\n";
            cin >> checkIsNotInt;
        }
        else
            break;
    }
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i)

    {
            isNegative = (number >> sizeof(int) * 8 - 1) & 1; // узнаём отрицательное или положительное
            if (i == sizeof(int) * 8 - 1)
            cout << ((number >> i) & 1) << " ";
            i--;
            if (isEven)
            {
                cout << ((!isNegative) ^ ((number >> i) & 1)); // замена на 0
                isEven = false;
            }
            else
            {
                cout << ((isNegative) ^ ((number >> i) & 1)); // замена на 1
                isEven = true;
            }

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
    cout << "Введите число" << "\n";
    cin >> number;
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)

    {

        cout << ((num >> i) & 1);

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
    cout << "Введите число" << "\n";
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
    cout << "\nВыберите тип данных:" << "\n" << "1. Integer" << "\n" << "2. Float" << "\n" << "3. Double" << "\n" << "4. ИДЗ" "\n";
    cin >> typeOfOperation;
    while (true)
    {
        switch (typeOfOperation)
        {
        case 1:
        {
            Int();
            break;
        }
        case 2:
        {
            Float();
            break;
        }
        case 3:
        {
            Double();
            break;
        }
        case 4:
        {
            Reverse();
            break;
        }
        }
        cout << "\nВыберите тип данных:" << "\n" << "1. Integer" << "\n" << "2. Float" << "\n" << "3. Double" << "\n" << "4. ИДЗ" "\n";
        cin >> typeOfOperation;
    }
}
