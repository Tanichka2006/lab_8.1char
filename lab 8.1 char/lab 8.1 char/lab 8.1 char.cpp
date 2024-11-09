#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������� ��� ����������� ������� �������� � ���� ������
int FindFourthDotFromEnd(char* s) {
    int dotCount = 0; // ˳������� ������
    int length = strlen(s); // ������� �����

    // ��������� ����� � ����
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] == '.') {
            dotCount++;
            if (dotCount == 4) {
                return i; // ��������� ������ �������� ������
            }
        }
    }
    return -1; // ��������� -1, ���� ����� �� 4 ������
}

// ������� ��� ����� ����� ������ �� "**"
char* ReplaceDots(char* s) {
    int length = strlen(s);
    char* result = new char[length * 2]; // ������������ ����� � �������
    int j = 0; // ������ ��� ������ �����

    for (int i = 0; i < length; i++) {
        if (s[i] == '.') {
            result[j++] = '*';
            result[j++] = '*';
        }
        else {
            result[j++] = s[i];
        }
    }
    result[j] = '\0'; // ������ ������ ���� �����
    strcpy(s, result); // ������� ��������� � �������� �����
    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // ��������� �������� ������ � ����
    int fourthDotIndex = FindFourthDotFromEnd(str);
    if (fourthDotIndex != -1) {
        cout << "Index of fourth dot from the end: " << fourthDotIndex << endl;
    }
    else {
        cout << "Less than four dots in the string" << endl;
    }

    // �������� ����� ������ �� "**"
    char* modifiedStr = ReplaceDots(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr; // ��������� �������� ���'���
    return 0;
}
