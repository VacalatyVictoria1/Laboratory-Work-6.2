#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
Ввести некоторе количество символов латинского алфавита 
и записать их в бинарный файл. Переписать бинарный файл так, 
чтобы все символы были записаны заглавными буквами.
*/


int main()
{
    char stroka1[255], stroka2[255]; 
    int i, n, x;
    ofstream file("C:\\Пользователи\\Users\\Рабочий стол\\2.txt", ios::binary | ios::out);
    cout << "Enter the string: " << endl;
    cin.getline(stroka1, 255);
    file.write((char*)&stroka1, sizeof stroka1);
    file.close();
    ifstream  file2("C:\\Пользователи\\Users\\Рабочий стол\\2.txt", ios::binary | ios::in);
    cout << "Converted string: " << endl;
    i = 0; n = 0; x = strlen(stroka1);
    while (i < x)
    {
        if (islower(stroka1[i]))
        {
            n = stroka1[i];
            n -= ' ';
            stroka2[i] = n;
        }
        else if (isupper(stroka1[i]))
            stroka2[i] = stroka1[i];
        else
            stroka2[i] = 32;
        i++;
    }
    stroka2[i] = '\0';
    cout << stroka2;
    file2.close();
    ofstream file3("C:\\Пользователи\\Users\\Рабочий стол\\2.txt", ios::binary | ios::out);
    file3.write((char*)&stroka2, sizeof stroka2);
    file3.close();
    cout << endl;
    system("pause");
    return 0;
}