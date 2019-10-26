userDefined.h     //自定义头文件(放宏定义、结构体和所有函数的声明)
#ifndef USERDEFINED_H
#define USERDEFINED_H
#define MAX_SIZE  200      //宏定义

struct student   //班级通讯录结构体
{      char number[MAX_SIZE];        //学号
       char name[MAX_SIZE];          //姓名
       char sex[MAX_SIZE];           //性别
       char phone[MAX_SIZE];         //手机号码
       char qq[MAX_SIZE];            //QQ 号码
       char dorm[MAX_SIZE];          //宿舍号
       char email[MAX_SIZE];         //电子邮箱
       char address[MAX_SIZE];       //家庭地址
       struct student *next;
}; //以下是程序所有函数的声明，在各个函数的源文件已经有详细说明了
void tiShi1();
void yanZhengOk();
void tiShi2();
void findHelp();
struct student *insertBack(struct student *head,int *count);
void backUpFromPc();
void changeNode(struct student *head,char number[MAX_SIZE]);
struct student *create(int *count); s
truct student *delNode(struct student *head,char number[MAX_SIZE], int *count);
struct student *searchByNumber(struct student *head, char number[MAX_SIZE]);
void printLianBiao(struct student *head,int *count);
struct student *readFromPcOk(int *sum);
void saveToPc(struct student *head, int *count);
int uniqueOk(struct student *head, char number[MAX_SIZE]);
int uniqueYes(struct student *head, struct student *p);
#endif
