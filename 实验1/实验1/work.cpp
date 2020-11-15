#include<iostream>
#include<string.h>
using namespace std;

const int M = 3;
const int N = 4;
char name[M][20] = { "\0" };
int score[M][N] = { 0 };

class Student
{
public:
	void Stu_Score_Input();
	void Stu_Score_Output();
	void Stu_Score_Search();
	void Stu_Score_Sort();
private:
	char name[M][20];
	int score[M][N];
};

void Student::Stu_Score_Input() {
	for (int i = 0; i < M; i++) {
		cout << "�����" << i + 1 << "λѧ������:";
		cin >> name[i];
		cout << "�ֱ�����" << N << "�ſγ̵ĳɼ�:";
		for (int j = 0; j < N; j++) {
			cin >> score[i][j];
		}
	}
}

void Student::Stu_Score_Output() {
	cout << "\t\t" << "����";
	for (int i = 0; i < N; i++)
	{
		cout << "\t" << "�γ�" << i + 1;
	}
	cout << endl;
	for (int i = 0; i < M; i++) {
		cout << "\t\t" << name[i] << "\t";
		for (int j = 0; j < N; j++) {
			cout << score[i][j] << "\t";
		}
		cout << "\n" << endl;
	}
}

void Student::Stu_Score_Search() {
	char Find_name[20] = { 0 };
	cout << "������Ҫ��ѯ��ѧ��������" << endl;
	cin >> Find_name;
	for (int i = 0; i < M; i++) {
		if (strcmp(Find_name, name[i]) == 0) {
			cout << "��ѯ�����" << endl;
			cout << "\t\t" << "����";
			for (int i = 0; i < N; i++)
			{
				cout << "\t" << "�γ�" << i + 1;
			}
			cout << endl;
			for (int j = 0; j < N; j++) {
				if (j == 0) {
					cout << "\t\t" << name[i] << "\t" << score[i][j] << "\t";
				}
				else {
					cout << score[i][j] << "\t";
				}
			}
			cout << "\n" << endl;
			break;
		}
		if (i == (M - 1))
			cout << "��ѯ�޹�" << "\t" << endl;
	}
}

void Student::Stu_Score_Sort() {
	int n = 0;
	cout << "��������Ҫ�����ĳɼ����γ�n->n����" << endl;
	cin >> n;
	int k[100];
	cout << "�γ�" << n << "�ķ�������Ϊ:";
	for (int i = 0; i < M; i++) {
		k[i] = score[i][n - 1];
	}
	if (n <= N) {
		for (int i = 0; i < M; i++) {
			for (int j = i; j < M; j++) {
				if (k[i] > k[j]) {
					int a = k[i];
					k[i] = k[j];
					k[j] = a;
				}
			}
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				if (score[j][n - 1] == k[i]) {
					cout << name[j] << ":" << k[i] << "  ";
					break;
				}
			}
		}
	}
	else
		cout << "error" << endl;
}

int main(void) {
	Student stu;
	cout << "����" << M << "λͬѧ," << N << "�ſγ�" << endl;
	stu.Stu_Score_Input();
	cout << endl;
	stu.Stu_Score_Output();
	cout << endl;
	stu.Stu_Score_Search();
	cout << endl;
	stu.Stu_Score_Sort();
	system("pause");
	return 0;
}