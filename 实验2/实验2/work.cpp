//#include<iostream>
//#define PI 3.141592535
//using namespace std;
//
//class Pool {
//private:
//	double Ra, Rb;
//public:
//	void setRab(double a, double b) {
//		Ra = a;
//		Rb = b;
//	}
//
//	void display() {
//		cout << "�������Ϊ:" << (Ra + Rb) * 2 * PI * 35 << endl;
//		cout << "�������Ϊ:" << ((Ra + Rb) * (Ra + Rb) - Ra * Ra) * PI * 20;
//	}
//};
//
//int main(void) {
//	double a, b = 3;
//	Pool obj;
//	cout << "������Ӿ�ذ뾶:";
//	cin >> a;
//	obj.setRab(a, 3);
//	obj.display();
//	system("pause");
//	return 0; 
//}

#include<iostream>
#include<string>
using namespace std;

class Student{
private:
	string exam_number[20];
	string stu_name[20];
public:
	float team_grade = 0;
	float stu_grade[20];
public:
	void PrintStuInfo();
	void ScanStuInfo();
};

void Student::ScanStuInfo(){
	cout << "����������,׼��֤�ż����˳ɼ�" << endl;
	for (int i = 0; i < 3; i++){
		cout << "��" << i + 1 << "��ѧ��������" << endl;
		cin >> stu_name[i];
		cout << "��" << i + 1 << "��ѧ��׼��֤�ţ�" << endl;
		cin >> exam_number[i];
		cout << "��" << i + 1 << "��ѧ�����˳ɼ���" << endl;
		cin >> stu_grade[i];
	}

	cout << "�������Ŷӳɼ���" << endl;
	cin >> team_grade;
	cout << "\n" << endl;
}

void Student::PrintStuInfo(){
	for (int i = 0; i < 3; i++){
		cout << "����:" << stu_name[i] << "\t" << "׼��֤��:" << exam_number[i] << endl;
	}
	cout << "�Ŷӳɼ���" << team_grade << "\n" << endl;
}

int main(void){
	Student stu;
	stu.ScanStuInfo();
	stu.PrintStuInfo();
	system("pause");
	return 0;
}