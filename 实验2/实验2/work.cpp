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
//		cout << "栏杆造价为:" << (Ra + Rb) * 2 * PI * 35 << endl;
//		cout << "过道造价为:" << ((Ra + Rb) * (Ra + Rb) - Ra * Ra) * PI * 20;
//	}
//};
//
//int main(void) {
//	double a, b = 3;
//	Pool obj;
//	cout << "请输入泳池半径:";
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
	cout << "请输入姓名,准考证号及个人成绩" << endl;
	for (int i = 0; i < 3; i++){
		cout << "第" << i + 1 << "个学生姓名：" << endl;
		cin >> stu_name[i];
		cout << "第" << i + 1 << "个学生准考证号：" << endl;
		cin >> exam_number[i];
		cout << "第" << i + 1 << "个学生个人成绩：" << endl;
		cin >> stu_grade[i];
	}

	cout << "请输入团队成绩：" << endl;
	cin >> team_grade;
	cout << "\n" << endl;
}

void Student::PrintStuInfo(){
	for (int i = 0; i < 3; i++){
		cout << "姓名:" << stu_name[i] << "\t" << "准考证号:" << exam_number[i] << endl;
	}
	cout << "团队成绩：" << team_grade << "\n" << endl;
}

int main(void){
	Student stu;
	stu.ScanStuInfo();
	stu.PrintStuInfo();
	system("pause");
	return 0;
}