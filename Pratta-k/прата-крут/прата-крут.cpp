#include <iostream>
using namespace std;


int search(char* string, char* substring)
{
    int  sl, ssl;
    int res = 0;
    sl = strlen(string);
    ssl = strlen(substring);
    if (sl == 0)
        cout << "Неверно задана строка\n";
    else if (ssl == 0)
        cout << "Неверно задана подстрока\n";

    else
    {
        int  i, j = 0, k = -1;
        int* d = new int[1000];
        d[0] = -1;

        while (j < ssl - 1)
        {
            while (k >= 0 && substring[j] != substring[k])
                k = d[k];
            j++;
            k++;
            if (substring[j] == substring[k])
                d[j] = d[k];
            else
                d[j] = k;
        }

        i = 0;
        j = 0;
        while (j < ssl && i < sl)
        {
            while (j >= 0 && string[i] != substring[j])
                j = d[j];
            i++;
            j++;
        }
        delete[] d;
        res = j == ssl ? i - ssl : 0;
    }
    return res;
}

int main()
{
    setlocale(LC_ALL, "ru");

    char str[256] = "fhbgsv dbg shd hd";
    char substr[256] = "a;";
    int pos = search(str, substr);

    if (pos == -1)
        cout << "Подхождение не найдено!" << "\n";
    else
        cout << "Смещение: " << pos << "\n";

    return 0;
}
