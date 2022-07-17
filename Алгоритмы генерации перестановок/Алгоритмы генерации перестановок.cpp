#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int* mn;
    int CountOfElements, i, j, Temp_i, newtemp;
    cout << "Введите количество элементов: ";
    cin >> CountOfElements;
    mn = new int[CountOfElements];
    CountOfElements--;
    for (i = 0; i <= CountOfElements; i++) { 
        mn[i] = i + 1;
        cout << mn[i]; 
    }
    cout << endl;
    for (i = CountOfElements; i > 0; i--)
    {
        if (mn[i] > mn[i - 1])
        {
            Temp_i = i;
            for (i = CountOfElements; i >= Temp_i; i--)
            {
                if (mn[i] > mn[Temp_i - 1])
                {
                    swap(mn[Temp_i - 1], mn[i]);
                    for (j = CountOfElements, i = Temp_i; j > i; j--, i++)
                    {
                        swap(mn[i], mn[j]);
                    }
                    for (i = 0; i <= CountOfElements; i++) cout << mn[i] << " ";
                    cout << endl;
                    break;
                }
            }
        }
    }
    cout << "Антилексикографический порядок 3-х элементов {1,2,3}:\n123 213 132 312 231 321";
    return 0;
}
