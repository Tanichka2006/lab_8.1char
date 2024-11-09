#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція для знаходження індексу четвертої з кінця крапки
int FindFourthDotFromEnd(char* s) {
    int dotCount = 0; // Лічильник крапок
    int length = strlen(s); // Довжина рядка

    // Проходимо рядок з кінця
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] == '.') {
            dotCount++;
            if (dotCount == 4) {
                return i; // Повертаємо індекс четвертої крапки
            }
        }
    }
    return -1; // Повертаємо -1, якщо менше ніж 4 крапки
}

// Функція для заміни кожної крапки на "**"
char* ReplaceDots(char* s) {
    int length = strlen(s);
    char* result = new char[length * 2]; // Результуючий рядок з запасом
    int j = 0; // Індекс для нового рядка

    for (int i = 0; i < length; i++) {
        if (s[i] == '.') {
            result[j++] = '*';
            result[j++] = '*';
        }
        else {
            result[j++] = s[i];
        }
    }
    result[j] = '\0'; // Додаємо символ кінця рядка
    strcpy(s, result); // Копіюємо результат у вихідний рядок
    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Знаходимо четверту крапку з кінця
    int fourthDotIndex = FindFourthDotFromEnd(str);
    if (fourthDotIndex != -1) {
        cout << "Index of fourth dot from the end: " << fourthDotIndex << endl;
    }
    else {
        cout << "Less than four dots in the string" << endl;
    }

    // Замінюємо кожну крапку на "**"
    char* modifiedStr = ReplaceDots(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr; // Видаляємо динамічну пам'ять
    return 0;
}
