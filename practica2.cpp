#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int day, month, year;

    cout << "Введіть день: ";
    cin >> day;

    cout << "Введіть місяць: ";
    cin >> month;

    cout << "Введіть рік: ";
    cin >> year;

    if (month < 3)
    {
        month += 12;
        year--;
    }

    int K = year % 100;
    int J = year / 100;

    int h = (day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    string days[] =
    {
        "субота",
        "неділя",
        "понеділок",
        "вівторок",
        "середа",
        "четвер",
        "п'ятниця"
    };

    cout << "\nДень тижня: " << days[h] << endl;

    system("pause");
    return 0;
}