// ������ 2018203055

#include <iostream>
#include "MyDoubleVector.h"
#include <Windows.h>
using namespace std;
void gotoxy(int x, int y) {
	COORD pos = { x,y }; //x, y ��ǥ ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ�� ����
}
int main()
{
	MyDoubleVector vec1;
	MyDoubleVector vec2;

	double d = 0.0;
	int k = 10;
	double input = 0.0;

	int num = 0;

	cout << "vector1�� vector2�� ���� �Ǿ� �ֽ��ϴ�." << endl << endl;
	cout << "Unary" << endl << endl;
	cout << "vector1 push_back = 11    vector2 push_back = 21" << endl;
	cout << "vector1 pop_back  = 12    vector2 pop_back  = 22" << endl;
	cout << "vector1 empty     = 13    vector2 empty     = 23" << endl;
	cout << "vector1 clear     = 14    vector2 clear     = 24" << endl;
	cout << "vector1 -         = 15    vector2 -         = 25" << endl;
	cout << "vector1 ()        = 16    vector2 ()        = 26" << endl << endl;
	cout << "Binary" << endl << endl;
	cout << "vector 1 +  vector 2 = 30" << endl;
	cout << "vector 1 -  vector 2 = 31" << endl;
	cout << "vector 1 *  vector 2 = 32" << endl;
	cout << "vector 1 =  vector 2 = 33" << endl;
	cout << "vector 1 += vector 2 = 34" << endl;
	cout << "vector 2 += vector 1 = 35" << endl;
	cout << "vector 1 == vector 2 = 36" << endl;
	cout << endl;
	cout << "���� ǥ�� ���� ���ϴ� ����� �ڵ带 �Է��Ͻʽÿ�" << endl;

	while (1)
	{
		gotoxy(0, 22);
		cout << "                                                " << endl;
		gotoxy(0, 22);
		cin >> num;
		switch (num)
		{
		case 11:
		{
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 25);
			cout << "�߰��� �Ǽ��� �Է��Ͻʽÿ�" << endl;
			cin >> input;
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;
			vec1.push_back(input);
			cout << "after vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			input = 0.0;

			break;
		}
		case 12:
		{
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;
			vec1.pop_back();
			cout << "after vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;
			break;
		}
		case 13:
		{
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			if (vec1.empty()) {
				cout << "��� �ֽ��ϴ�." << endl;
			}
			else {
				cout << "��� ���� �ʽ��ϴ�." << endl;
			}
			break;
		}
		case 14:
		{
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;
			vec1.clear();
			cout << "after vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;
			break;
		}
		case 15:
		{
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;
			cout << "after vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << -vec1[i] << " ";
			cout << "]";
			cout << endl;
			break;
		}
		case 16:
		{
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 25);
			cout << "���� �Է��Ͻʽÿ�" << endl;
			cin >> input;
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			vec1(input);
			cout << "after vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			input = 0.0;
			break;
		}
		case 21:
		{
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 25);
			cout << "�߰��� �Ǽ��� �Է��Ͻʽÿ�" << endl;
			cin >> input;
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;
			vec2.push_back(input);
			cout << "after vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			input = 0.0;

			break;
			break;
		}
		case 22:
		{	
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;
			vec2.pop_back();
			cout << "after vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;
			break;
		}
		case 23:
		{
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			if (vec2.empty()) {
				cout << "��� �ֽ��ϴ�." << endl;
			}
			else {
				cout << "��� ���� �ʽ��ϴ�." << endl;
			}
			break;
		}
		case 24:
		{
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;
			vec2.clear();
			cout << "after vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;
			break;
		}
		case 25:
		{
			for (int i = 0; i < 5; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 27);
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			cout << "after vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << -vec2[i] << " ";
			cout << "]";
			cout << endl;
			break;
		}
		case 26:
		{
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 25);
			cout << "���� �Է��Ͻʽÿ�" << endl;
			cin >> input;
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "before vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			vec1(input);
			cout << "after vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			input = 0.0;
			break;
		}
		case 30:
		{
			MyDoubleVector vec = vec1 + vec2;
			for (int i = 0; i < 4; i++) {
				cout << "                                                " << endl;
			}
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			cout << "vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			cout << "���� ��� : ";
			for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
			cout << endl;

			break;
		}
		case 31:
		{
			MyDoubleVector vec = vec1 - vec2;
			for (int i = 0; i < 4; i++) {
				cout << "                                                " << endl;
			}
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			cout << "vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			cout << "���� ��� : ";
			for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
			cout << endl;

			break;
		}
		case 32:
		{
			for (int i = 0; i < 4; i++) {
				cout << "                                                " << endl;
			}
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			cout << "vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			cout << "���� ��� : ";
			cout << vec1 * vec2 << endl;
			cout << endl;

			break;
		}
		case 33:
		{
			for (int i = 0; i < 4; i++) {
				cout << "                                                " << endl;
			}
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			vec1 = vec2;
			cout << "vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			cout << "���Ե� vector1 = ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << endl;
			break;
		}
		case 34:
		{
			for (int i = 0; i < 4; i++) {
				cout << "                                                " << endl;
			}
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			vec1 += vec2;
			cout << "vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			cout << "[ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]" << endl;

			break;
		}
		case 35:
		{
			for (int i = 0; i < 4; i++) {
				cout << "                                                " << endl;
			}
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			cout << "vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;


			cout << "vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;
			vec2 += vec1;

			cout << "[ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			break;
		}
		case 36:
		{
			for (int i = 0; i < 4; i++) {
				cout << "                                                " << endl;
			}
			cout << "���------------------------------------------" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "                                                " << endl;
			}
			gotoxy(0, 28);
			k = (vec1 == vec2);
			cout << "vector1 = [ ";
			for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
			cout << "]";
			cout << endl;

			cout << "vector2 = [ ";
			for (int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
			cout << "]";
			cout << endl;

			if (k == 1)
			{
				cout << "�� ���ʹ� �����մϴ�." << endl;
			}
			else
				cout << "�� ���ʹ� �������� �ʽ��ϴ�." << endl;
			break;
		}
		
		}
	}
	int i = 0;
	return 0;
}