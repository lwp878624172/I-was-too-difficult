//此函数的功能：创建链表（即实现手动输入来初始化的功能）。 
//参数：整形的指针变量，指向节点总个数。 //返回值：刚创建的链表头节点。 
struct student *create(int *count) {  struct student *head=NULL;      //指向链表头节点  
struct student *p=NULL;          //指向创建的节点  
struct student *tail=NULL;        //指向链表尾节点  
do  {   p=(struct student *)malloc(sizeof(struct student));   //为刚创建的节点申请一个 student 结构体类型大小的内存空间，并用 p指针指向它。  
 p->next = NULL;          //初始化 p 的 next 为空，防止指针乱指发生的错误。   
 printf("\n 请输入学号,学号为“0”即为保存并结束创建!\n"); 
 printf("学号->");     scanf("%s",p->number);
      while(uniqueOk(head, p->number)==0)  //循环判断想要创建的学号是否在链表中已经存在   
        {    printf("\n 学号为 %s 的同学已经存在!\n",p->number);    printf("\n 请重新输入想要创建的学生的信息!\n");   
printf("学号->");    scanf("%s",p->number);  
 }   if(strcmp(p->number,"0")!=0)     //学号不为“0”时   
{    printf("姓名->");        
 scanf("%s",p->name);    
 printf("性别->");  
       scanf("%s",p->sex);  
       printf("手机号码->");   
       scanf("%s",p->phone); 
       printf("QQ 号码->");   
       scanf("%s",p->qq);    
       printf("宿舍号->");   
       scanf("%s",p->dorm);     
       printf("电子邮箱->");   
       scanf("%s",p->email); 
       printf("家庭地址->");  
       scanf("%s",p->address);
       if(head==NULL)      //如果刚创建的这个节点是这个链表的第一个节点，即在创建该 节点之前链表是空的  
            {   //头指针和尾指针都指向该节点     
        head=p; 
           tail=p;    
            }    else                //如果刚创建的这个节点不是这个链表的第一个节点    
        {   //下面两句的执行结果就是把 p 节点从链表的尾部插入链表 
        tail->next=p;
           tail=p;    
           }    
           (*count)++;        //链表的节点数加一，即通讯录的条数加一  
            }   else               //学号为“0”时  
            {    if(head==NULL)    {        
            return head;    
            }    tail->next=NULL; 
               return head;  
                } 
                 }
                 while(1); 
                 } print
