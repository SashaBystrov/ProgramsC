// Вариант 3

#include <iostream>
#include <windows.h>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct TableData {
	char lastname[20];
	char namebook[20];
	unsigned short year;
	char group;
	struct Date date;
};

void printDate(unsigned short day, unsigned short month, unsigned short year, int wl) {
    int w = 10;
    int delta = (wl - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    if (day > 9) {
        cout << day;
    }
    else {
        cout << "0" << day;
    }
    cout << ".";
    if (month > 9) {
        cout << month;
    }
    else {
        cout << "0" << month;
    }
    cout << ".";
    cout << year;
    cout.width(delta); cout << " ";
}

void Draw(struct TableData* lines) {
    int width = 87;
    cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(width);  cout << left << "|Каталог библиотеки"; cout << "|" << endl;
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');
    cout << left << "|     Автор книги    ";
    cout << left << "|     Название   ";
    cout << left << "| Год выпуска";
    cout << left << "| Группа";
    cout << left << " | Дата подписания рукописи ";
    cout << "|" << endl;
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');
    for (int i = 0; i < 3; i++) {
        cout << left << "|"; cout.width(20); cout << left << lines[i].lastname;
        cout << left << "|"; cout.width(16); cout << left << lines[i].namebook;
        cout << left << "|"; cout.width(12); cout << left << lines[i].year;
        cout << left << "|"; cout.width(8); cout << left << lines[i].group;
        cout << left << "|";
        printDate(lines[i].date.day, lines[i].date.month, lines[i].date.year, 28);
        cout << "|" << endl;
    }
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Х – худож. лит-ра; У - учебная лит-ра; С - справочная лит-ра. "; cout << "|" << endl;
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct TableData lines[3];

	lines[0] = { " Сенкевич ", " Потоп ", 1978, 'X', {11,11,2020} };
	lines[1] = { " Ландау ", " Механика ", 1989, 'Y', {11,11,2020} };
	lines[2] = { " Дойль ", " Сумчатые ", 1990, 'C', {12,12,2010} };

	Draw(lines);
}

