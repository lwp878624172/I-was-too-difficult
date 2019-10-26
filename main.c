#include<stdio.h>      //标准输入输出头文件 eg:printf(); scanf(); FILE 结构体
#include<string.h>     //关于字符数组的函数定义的头文件 eg:strcmp();
#include<stdlib.h>     //标准库头文件 eg:malloc(); free();
//自定义头文件(放宏定义、结构体和所有函数的声明) //就相当于一个“接口”，当编译的时候，userDefined.h 文件里的内容会全部显示在这里
#include"userDefined.h"
void main(void)//主函数
{
    int    sum=0 ;                           //记录通讯录的条数
    struct student *lianBiaoTou=NULL;        //链表头
    struct student *fineResult;
    int    n=600000000;                    //退出到软件关闭前的延迟
    char   changeNumber[MAX_SIZE];      //修改操作时的学号
    char   delNumber[MAX_SIZE];         //删除操作时的学号
    char   findNumber[MAX_SIZE];        //查询操作时的学号
    char   firstInput;                      //操作选择
    tiShi1();           //软件的功能介绍
    yanZhengOk();     //验证信息，在调试的时候，可以把这个注释了
    tiShi2();          //操作提示
    printf("请选择操作【班级通讯录管理系统】的方式!\n");
    printf("温馨提示：第一次进入本系统，可选择“手动创建通讯录”或“调入已有的通讯录”，\n");
    printf("但是切记不能选择“调入已有的通讯录”后，再选择“手动创建通讯录”!!\n\n");
    printf("请选择操作种类->");
    while(1)   //程序一直运行着，直到用户选择“Q”退出程序
    {
        scanf("%c",&firstInput);     //接受用户的操作选择
        if(firstInput == 'Q')          //如果用户选择“Q”则退出软件
        {
            printf("\n\n      欢迎光临【班级通讯录管理系统】^_^\n\n\n");
            while(n--);       //延时关闭
            break;
        }
        else if(firstInput == '\n')     //回车键处理：不打印任何东西
        {
            printf("");
        }
        else
        {
            switch(firstInput)       //用 swith 分支处理用户的操作选择
            {
            case 'A':
                printf("\n 创建【通讯录】^_^\n");
                lianBiaoTou=create(&sum);
                printf("\n 创建班级通讯录成功!!!^_^\n");
                printf("\n 你刚才输入的通讯录是：\n");
                printLianBiao(lianBiaoTou,&sum);     //显示创建后的通讯录
                break;
            case 'B':
                printf("\n 调入【通讯录】^_^!\n\n");
                lianBiaoTou=readFromPcOk(&sum);
                printf("\n");
                break;
            case 'C':
                printf("\n 添加【通讯录】^_^!\n");
                printf("\n 请输入一条通讯录的相关信息!\n");
                lianBiaoTou=insertBack(lianBiaoTou,&sum);
                printf("\n 添加一条通讯录后的全部通讯录信息为：\n");
                printLianBiao(lianBiaoTou,&sum);     //显示添加后的通讯录
                break;
            case 'D':
                printf("\n 修改【通讯录】^_^!\n");
                printf("\n 请输入想要修改的通讯录的学生学号：");
                scanf("%s",changeNumber);
                changeNode(lianBiaoTou,changeNumber);
                break;
            case 'E':
                printf("\n 删除【通讯录】^_^!\n");
                printf("\n 请输入想删除的通讯录的学生学号：");
                scanf("%s",delNumber);
                lianBiaoTou=delNode(lianBiaoTou,delNumber,&sum);
                break;
            case 'F':
                printf("\n 查询【通讯录】^_^!\n");
                findHelp();
                printf("\n 本程序仅提供【1】的查询方式\n");
                printf("\n 请输入要查询的通讯录的学生学号->");
                scanf("%s",findNumber);
                fineResult=searchByNumber(lianBiaoTou,findNumber);
                break;
            case 'G':
                printf("\n 最新的全部【通讯录】信息^_^!\n");
                printLianBiao(lianBiaoTou,&sum);      //显示通讯录
                break;
            case 'H':
                printf("\n 保存【通讯录】为 txt 文件^_^!\n\n");
                saveToPc(lianBiaoTou,&sum);
                break;
            case 'I':
                printf("\n 备份【通讯录】^_^!\n\n");
                backUpFromPc();
                break;
            default :   //如果用户选择的都不是上面的功能，则提示操作选择有误
                printf("\n 你选择的操作种类有误，请重新选择!!");
                break;
            }
            tiShi2();       //操作提示
            printf("请选择操作【班级通讯录管理系统】的方式!\n");
            printf("温馨提示：第一次进入本系统，可选择“手动创建通讯录”或“调入已有的通讯录”， \n");
            printf("但是切记不能选择“调入已有的通讯录”后，再选择“手动创建通讯录”!!\n\n");
            printf("请选择操作种类->");
        }
    }
}
