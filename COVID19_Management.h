#ifndef BIGHOMEWORKHEAD_H_INCLUDED
#define BIGHOMEWORKHEAD_H_INCLUDED
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Util {
    // 所需头文件  <sstream>  <vector>  <string>
public:
    // 函数以单个char字符作为分隔符对string字符串进行分割， 并将分割结果存入vector中，最终返回vector<string>
    static std::vector<string> split(const std::string &s, char delimiter) { //  n.	定界符，分隔符;
        std::vector<string> tokens; // 存放结果
        std::string token; // 子串
        std::istringstream tokenStream(s); //使用string s初始化输入流, 标准库头文件 <sstream>
        while (std::getline(tokenStream, token,
                            delimiter)) { //  对于输入流，遇到char的delimiter时 就停止 把结果储存在token中, (同时舍弃遇到的这个char), 定义于<string>
            if (!token.empty()) //因为会遇到连续的delimiter的情况，这时候token就是空，这种情况不要放入tokens当中
                tokens.push_back(token);
        }
        return tokens;
    }

    // 函数以string作为分隔符对string字符串进行分割， 并将分割结果存入vector中，最终返回vector<string>
    static std::vector<string> split(const std::string &s, const std::string &delimiter) { //  n.	定界符，分隔符;
        std::vector<string> tokens; // 存放结果
        std::string token; // 子串
        int i = 0, start = 0, sSize = (int) s.size(), dSize = (int) delimiter.size(); // start为字符子串的起始位置
        while (i < sSize) {
            if (isDelimiter2(s, i, delimiter)) {  // 此处也可以使用isDelimiter(s, i, delimiter)  如果遇到了分隔符
                token = s.substr(start, i - start); // 分割字符串
                if (!token.empty()) { // 因为会遇到连续的delimiter的情况，这时候token就是空，这种情况不要放入tokens当中
                    tokens.push_back(token);
                }
                i += dSize; // 跳过分隔符的长度
                start = i; // 更新子串的起始位置
            } else {
                i++;
            }
        }
        token = s.substr(start, i - start); // 分割字符串
        if (!token.empty()) { //因为会遇到连续的delimiter的情况，这时候token就是空，这种情况不要放入tokens当中
            tokens.push_back(token);
        }
        return tokens;
    }

private:
    // 函数判断字符串s从下标i开始的，长为delimiter的字符子串是否和delimiter全等
    static bool isDelimiter(const std::string &s, int i, const std::string &delimiter) {
        int j = 0, sSize = (int) s.size(), dSize = (int) delimiter.size();
        while (i < sSize && j < dSize) {
            if (s[i] != delimiter[j]) {
                return false;
            } else {
                j++;
                i++;
            }
        }
        return j == dSize;
    }

    // 函数判断字符串s从下标i开始的，长为delimiter的字符子串是否和delimiter全等
    static bool isDelimiter2(const std::string &s, int i, const std::string &delimiter) {

        return s.substr(i, delimiter.size()) == delimiter;
    }

};

struct time{//存放时间
int hour=0;
int day=0;
int month=0;
int year=0;
};



struct Hesuan{//存储核酸结果和日期
string hesuan="无";
time hesuantime;
};



struct Dormitary{
int DormitaryNumber=0;
int StudentQuantity=0;
string ManagerName="未知";
string DormitarySection="(未知)区";
bool fengkong=false;
time starttime;
time endtime;
};



struct STUDENT{
string Name="未知";//字符串
long long int StudentNumber=0;//12位数
long long int Telephone=0;//11位数
string Academy="未知";//字符串
string Class="未知";//字符串
int dormitarynumber=0;
Hesuan Hesuan[10];//可存放10次核酸情况。
int hesuancishu=0;
};

struct Date{//申请日期
int day=0;
int month=0;
int year=0;
};

struct StudentT{//学生申请结构体
long StudentNumber=0;
string Name="空";
string Area="未知校区";
string Reason="未知原因";
string Academy="未知学院";
Date Enter;
Date Out;
int Condition=0;
};



void Input_dormitaryinformation(Dormitary*dormitary);//输入宿舍信息
void Input_Hesuaninformation(STUDENT*student);//输入核酸信息
void Input_studentinformation(STUDENT*student);//输入学生信息
int StudentInput(STUDENT*student,Dormitary*dormitary);//综合输入



void StudentInformation(STUDENT*student);
void CommuteManagement(STUDENT*student);



//宿舍管理函数声明
void DormitaryManagement(STUDENT*student,Dormitary*dormitary);//总体
void revise(Dormitary *a,time Today);
bool range1(time a, time b);//比较时间
time datechange(time a,int b);//增加时间
void help1();//一部分共通提示的输出
void help2();//一部分共通提示的输出
void help3();//一部分共通提示的输出
void fresh();
void check2(Dormitary *b);
void check1(Dormitary*dormitary,STUDENT*Student);

#endif // BIGHOMEWORKHEAD_H_INCLUDED
