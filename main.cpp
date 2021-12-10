#include <iostream>
#include "my_lib.h"
using namespace std;

int main() {
	//���������� ������� ����
	setlocale(LC_ALL, "rus");
	//��������� ������ ��� ����
	int size = 3;
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	//��������� ���� ���������
	init_field(field, size);
	//�������� ������� ����
	while (true) {
		// ��� ���������
		player_turn(field, size);
		//������ ����
		print_field(field, size);
		// ���� ������� ���������, �� ������� ��������� � �������� ����
		if (check_win(field, size, 'x')) {
			cout << "�������� ��������!" << endl;
			break;
		}
		// ���� �����, �� ������� ��������� � �������� ����
		if (check_draw(field, size)) {
			cout << "�����(((" << endl;
			break;
		}
		// ��� �������
		player_turn(field, size);
		// ������ ����
		print_field(field, size);
		// ���� ������� �������, �� �������� ����
		if (check_win(field, size, 'o')) {
			cout << "�������� ������!" << endl;
			break;
		}
		// ���� �����, �� �������� ����
		if (check_draw(field, size)) {
			cout << "�����(((" << endl;
			break;
		}
	}
	return 0;
}

