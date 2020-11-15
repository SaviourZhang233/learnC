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
		cout << "输入第" << i + 1 << "位学生姓名:";
		cin >> name[i];
		cout << "分别输入" << N << "门课程的成绩:";
		for (int j = 0; j < N; j++) {
			cin >> score[i][j];
		}
	}
}

void Student::Stu_Score_Output() {
	cout << "\t\t" << "姓名";
	for (int i = 0; i < N; i++)
	{
		cout << "\t" << "课程" << i + 1;
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
	cout << "输入你要查询的学生姓名：" << endl;
	cin >> Find_name;
	for (int i = 0; i < M; i++) {
		if (strcmp(Find_name, name[i]) == 0) {
			cout << "查询结果：" << endl;
			cout << "\t\t" << "姓名";
			for (int i = 0; i < N; i++)
			{
				cout << "\t" << "课程" << i + 1;
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
			cout << "查询无果" << "\t" << endl;
	}
}

void Student::Stu_Score_Sort() {
	int n = 0;
	cout << "请输入需要排名的成绩（课程n->n）：" << endl;
	cin >> n;
	int k[100];
	cout << "课程" << n << "的分数排序为:";
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
	cout << "共有" << M << "位同学," << N << "门课程" << endl;
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