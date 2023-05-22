#include <iostream>
using namespace std;

int search(char* string, char* substring)
{
    int  sl = 0;
    int ssl = 0;
    int res = -1;

    while (string[sl] != '\0')
        sl++;
    while (substring[ssl] != '\0')
        ssl++;

    if (sl == 0)
        cout << "Некорректная строка!\n";
    else if (ssl == 0 or ssl == 1)
        cout << "Некорректная подстрока!\n";
    else
    {
        int  i, Pos;
        int  BMT[256];
        for (i = 0; i < 256; i++)
            BMT[i] = ssl;

        for (i = ssl - 1; i >= 0; i--)
            if (BMT[(short)(substring[i])] == ssl)
                BMT[(short)(substring[i])] = ssl - i - 1;

        Pos = ssl - 1;
        while (Pos < sl)
            if (substring[ssl - 1] != string[Pos])
                Pos = Pos + BMT[(short)(string[Pos])];
            else
                for (i = ssl - 2; i >= 0; i--)
                {
                    if (substring[i] != string[Pos - ssl + i + 1])
                    {
                        Pos += BMT[(short)(string[Pos - ssl + i + 1])] - 1;
                        break;
                    }
                    else if (i == 0)
                        return Pos - ssl + 1;
                }
    }
    return res;
}

int main()
{
    setlocale(LC_ALL, "ru");

    char str[256] = "gdjksehjl; ag;lkag ;lnjaghl agwkeu4 agkhga";
    char substr[256] = "agwk";
    int pos = search(str, substr);

    if (pos == -1)
        cout << "Подхождение не найдено!" << "\n";
    else
        cout << "Смещение: " << pos << "\n";

    return 0;
}