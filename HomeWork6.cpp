#include <iostream>

using namespace std;

//=====Exercise 1======================================================================================

int GetInt() { 
    while (true)
    {
        cout << " Enter number: ";
        int var;
        cin >> var;

        if (cin.fail() || cin.get() != '\n') // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Input is invalid.  Please try again.\n";
        }
        else
        {       
            return var;
        }
    }
}

//=====Exercise 2======================================================================================

ostream& endll(ostream& stream)
{
    stream << "\n\n";
    stream.flush();
    return stream;
}

//=====================================================================================================

int main()
{
    cout << " Ex 1" << endl;
    int i = GetInt();
    cout << " " << i << endll;
    
    //=================================================================================================

    cout << " Ex 2" << endl;
    cout << " Hello world!" << endll;

    return 0;
}

