#ifndef COVID19_MANAGEMENT_H_INCLUDED
#define COVID19_MANAGEMENT_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;
struct Hesuan{//存储核酸结果和日期
bool hesuan;
int day;
int month;
int year;
};
struct Dormitary{
int DormitaryNumber;
int StudentQuantity;
char ManagerName[30];
char DormitarySection[10];
};
struct STUDENT{
char Name[20];//字符串
long StudentNumber;//12位数
long Telephone;//11位数
char Academy[10];//字符串
char Class[4];//字符串
int dormitarynumber;
int vaccines;//0或1或2或3
Hesuan hesuan[10];//可存放10次核酸情况。
double BodyTemperature;
};
void Input_dormitaryinformation(STUDENT*student);
void Input_Hesuaninformation(STUDENT*student);
void Input_studentinformation(STUDENT*student);
void prn(STUDENT s);
int StudentInput(STUDENT*student);
void StudentInformation(STUDENT*student);
void CommuteManagement(STUDENT*student);
void DormitaryManagement(STUDENT*student);
#endif
