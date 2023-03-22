// Вариант 3

#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>

using namespace std;

struct Date {
    short day;
    short month;
    short year;
};

struct TableData {
    char lastname[20];
    char namebook[20];
    short year;
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

struct Date getMinDate(struct TableData* lines) {
    unsigned short minMonth = lines[0].date.month;
    unsigned short minDay = lines[0].date.day;
    unsigned short minyear = lines[0].date.year;
    for (int i = 0; i < 3; i++) {
        if (lines[i].date.month < minMonth) {
            minMonth = lines[i].date.month;
            minDay = lines[i].date.day;
            minyear = lines[i].date.year;
        }
    }
    struct Date minDate = { minDay, minMonth, minyear };
    return minDate;
}
struct Date getMaxDate(struct TableData* lines) {
    unsigned short maxMonth = lines[0].date.month;
    unsigned short maxDay = lines[0].date.day;
    unsigned short maxyear = lines[0].date.year;
    for (int i = 0; i < 3; i++) {
        if (lines[i].date.month > maxMonth) {
            maxMonth = lines[i].date.month;
            maxDay = lines[i].date.day;
            maxyear = lines[i].date.year;
        }
    }
    struct Date maxDate = { maxDay ,maxMonth, maxyear };
    return maxDate;
}

int findI(struct TableData* lines, const struct Date date) {
    int ind = -1;
    for (int i = 0; i < 3; i++) {
        if (lines[i].date.year == date.year and lines[i].date.month == date.month and lines[i].date.day == date.day)
            ind = i;
    }
    return ind;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct TableData lines[10];

    lines[0] = { " Сенкевич ", " Потоп ", 1978, 'X', {11,11,2020} };
    lines[1] = { " Ландау ", " Механика ", 1989, 'Y', {11,11,2020} };
    lines[2] = { " Дойль ", " Сумчатые ", 1990, 'C', {12,12,2010} };
    Draw(lines);


    TableData* A;
    int n = 3;
    A = (TableData*)malloc(n * sizeof(TableData));
    for (int i = 0; i < n; i++) {
        strcpy_s(A[i].lastname, lines[i].lastname);
        strcpy_s(A[i].namebook, lines[i].namebook);
        A[i].year = lines[i].year;
        A[i].group = lines[i].group;
    }
    A = (TableData*)realloc(A, 10 * sizeof(TableData));
    TableData** B;
    B = (TableData**) new TableData * [10];
    for (int i = 0; i < 10; i++) {
        B[i] = (TableData*) new TableData;
        *(B[i]) = A[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << endl << "адрес A[i] " << &A[i] << " A[i]->lastname " << A[i].lastname;
        cout << endl << "адрес B[i] " << &B[i] << " B[i]->lastname " << B[i]->lastname;
        cout << endl << "адрес A[i] " << &A[i] << " A[i]->namebook " << A[i].namebook;
        cout << endl << "адрес B[i] " << &B[i] << " B[i]->namebook " << B[i]->namebook;
        if (i != 2) {
            cout << endl << "адрес A[i] " << &A[i] << " A[i]->year " << A[i].year;
            cout << endl << "адрес B[i] " << &B[i] << " B[i]->year " << B[i]->year;
            cout << endl << "адрес A[i] " << &A[i] << " A[i]->group " << A[i].group;
            cout << endl << "адрес B[i] " << &B[i] << " B[i]->group " << B[i]->group;
        }
    }
    delete[]B;
    free(A);
}
