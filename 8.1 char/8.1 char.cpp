#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* s) // s = вхідний рядок
{
	int k = 0,
		pos = 0; // pos = позиція початку наступного пошуку "abc"
	char* t;
	while (t = strstr(s + pos, "abc")) // t = підстрока "abc"
	{
		pos = t - s + 1; //pos = позиція початку наступного "abc"
		k++;
	}
	return k;
}

char* Change(char* s) //  s = вхідний рядок
{
	char* t = new char[strlen(s) * 2];
	char* p;
	int pos1 = 0, // pos1 = позиція початку наступного пошуку "abc"
		pos2 = 0;
	*t = 0;
	while (p = strstr(s + pos1, "abc")) // p = підстрока "abc"
	{
		pos2 = p - s + 3; // // pos2 = позиція початку наступної частини після "abc"
		strncat_s(t, strlen(s) * 2, s + pos1, pos2 - pos1 - 3);
		strcat_s(t, strlen(s) * 2, "**");
		pos1 = pos2;
	}
	strcat_s(t, strlen(s) * 2, s + pos1);
	strcpy_s(s, strlen(s) * 2, t);
	return t;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of 'abc'" << endl;
	char* dest = new char[201];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}