1.设计目的 
本课程设计的目的就是要通过一次集中的强化训练，使学生能及时巩固已学的知识，补 充未学的但又必要的内容。进行课程设计目的在于加深对程序设计基础中基础理论和基本知 识的理解，促进理论与实践的结合，进一步提高程序设计的能力。具体目的如下： 1．使学生更深入地理解和掌握该课程中的有关基本概念，程序设计思想和方法。 2．培养学生综合运用所学知识独立完成课题的能力。 3．培养学生勇于探索、严谨推理、实事求是、有错必改，用实践来检验理论，全方位 考虑问题等科学技术人员应具有的素质。 4．提高学生对工作认真负责、一丝不苟，对同学团结友爱，协作攻关的基本素质。 5．培养学生从资料文献、科学实验中获得知识的能力，提高学生从别人经验中找到解 决问题的新途径的悟性，初步培养工程意识和创新能力。 6．对学生掌握知识的深度、运用理论去处理问题的能力、实验能力、课程设计能力、 书面及口头表达能力进行考核。 
 
2.设计题目及要求 
【1】设计题目：班级通讯录管理系统 【2】要求 实现如下功能： 1）建立班级通讯录结构体（学号，姓名，性别，手机号码，QQ 号码，宿舍号，电子邮 箱，家庭地址等） 。 2）班级通讯录信息的初始化。 3）班级通讯录信息的添加、修改、删除、查找。 4）班级通讯录信息的显示输出。 5）将通讯录信息保存为文件。 6）备份通讯录信息。 综合应用数组、指针、结构体、文件等，对该设计题目进行设计和实现。课程设计完成 后，提交课程设计报告。 
 
3.设计算法分析 
  3.1 模块调用层次图 
  【1】变量描述 
数组 
char  changeNumber[MAX_SIZE];     
作用：存放待修改的通讯录信息的学生学号。 
char  delNumber[MAX_SIZE];         
作用：存放待删除的通讯录信息的学生学号。 
char  findNumber[MAX_SIZE];       
作用：存放待查询的通讯录信息的学生学号。 
char outName[MAX_SIZE];     
作用：存放保存到本地电脑的.txt 文件的文件名（在 saveToPc 函数中定义）。 
char  source[MAX_SIZE]; 
作用：存放源文件名（在 readFromPcOk 函数和 backUpFromPc 函数中有定义）。 
char  end[MAX_SIZE]; 
作用：存放目标文件名（在 backUpFromPc 函数中有定义）。 
结构体 
班级通讯录结构体： 
struct student    
{ 
    char number[MAX_SIZE];       //学号 
 char name[MAX_SIZE];         //姓名 
 char sex[MAX_SIZE];          //性别 
 char phone[MAX_SIZE];        //手机号码 
    char qq[MAX_SIZE];           //QQ 号码 
 char dorm[MAX_SIZE];         //宿舍号 
 char email[MAX_SIZE];        //电子邮箱 
    char address[MAX_SIZE];      //家庭地址  
 struct  student  *next;      //下一个节点的地址 
}; 
宏定义 
#define    MAX_SIZE    200 
#define    DAXUE      "上海海事大学" 
#define    BANJI      "网络 08" 
#define    MIMA       "2008" 
系统已定义的相关文件函数 
FILE *fp; 
fp = fopen(文件名，使用文件方式)； 
功能：实现打开文件。 
fclose(文件指针) 
功能：实现关闭文件。 
ch=fgetc(文件指针); 
功能：从指定的文件读入一个字符。 
fputc(ch,文件指针)； 
功能：把一个字符写到磁盘文件上去。 
fprintf(文件指针，格式字符串，输出表列) 
功能：fprintf 函数与 printf 函数作用相仿，只是他的写对象不是终端也是磁盘文件。
 
fscanf(文件指针，格式字符串，输入表列);   
功能：fscanf 函数与 scanf 函数作用相仿，只是他的读对象不是终端也是磁盘文件。 
自定义函数 
struct student *create(int *count) 
功能：创建链表（即实现手动输入来初始化的功能）。 
void changeNode(struct student *head,char number[MAX_SIZE]) 
功能：修改节点（即实现修改通讯录的功能）。 
struct student *delNode(struct student *head,char number[MAX_SIZE],int *count) 
功能：删除一个节点（即实现删除通讯录的功能）。 
struct student *searchByNumber(struct student *head, char number[MAX_SIZE]) 
功能：查找节点（即实现查询通讯录的功能）。 
struct student *insertBack(struct student *head,int *count) 
功能：插入一个节点（即实现添加功能） 。 
void printLianBiao(struct student *head,int *count) 
功能：打印链表的所有节点(即实现了显示输出的功能)。 
void saveToPc(struct student *head, int *count) 
功能：把内存中的通讯录信息保存到本地电脑的.txt 文件(即实现了保存的功能)。 
void backUpFromPc() 
功能：复制磁盘文件(即实现了备份的功能)。 
struct student *readFromPcOk(int *sum) 
功能：从磁盘文件中读取数据到内存(即实现了调入已有通讯录信息的功能)。 
int uniqueOk(struct student *head, char number[MAX_SIZE])  
功能：对于整个链表来说，某个学号是否已经存在。 
int uniqueYes(struct student *head, struct student *p)  
功能：对于除了特定节点之外的整个链表来说，某个节点的学号是否已经存在（在修改
节点的时候用） 。 
void yanZhengOk(); 
功能：身份验证。 
void tiShi1() 
功能：一打开此软件的时候提示用户本软件的功能等信息。 
void tiShi2() 
功能：提示用户操作说明。 
void findHelp() 
功能：查询的时候的提示信息。 
   
 
  3.3 系统特点 
【1】特点    （1）、首先，在进入软件时，要进行身份验证。只有验证信息都正确了才可以进入系统， 这保证的系统的安全性。    （2）、进入系统之后，会出现欢迎信息和操作帮助提示，而且每次操作完成后，都会实 时出现操作帮助提示信息，有利于用户进行下一步的操作，体现了本软件的人性化。    （3）、本系统实现了两种方式进行初始化通讯录。如果你原来没有通讯录，可以选择“手 动输入信息来初始化” ，如果你原来已经有保存了一个通讯录，则可以选择“调入已有通 讯录来初始化”，这样就省去了一条一条输入的麻烦，进一步体现了人性化的程序设计思想。
    （4）、在“添加、修改通讯录”时，做到了各种情况的逻辑判断。使得添加或修改的同 学的学号不能为“0”而且通讯录里不存在的，这样才允许添加或修改记录。    （5）、本软件经过精心的输出显示的格式控制，使得用户看得更清晰、明了，方便了用 户的使用和操作。    （6）、本软件在充分完成课题要求的情况下，还附加了“备份”的功能。       【2】分工 我们共同完成的是：通讯录的学生结构体、身份验证、提示信息、操作帮助、信息的显 示等。本人在整个系统的设计过程，主要的任务是：文件的相关操作，即调入已有的通讯录、 通讯录的保存和备份，还有手动输入信息来初始化等模块。 在设计的过程中我们勇于探索、严谨推理、实事求是、有错必改，用实践来检验理论。 认真负责、一丝不苟，协作攻关终于比较完美的完成了此次课程设计。
