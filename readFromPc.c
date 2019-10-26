//头文件与 main.c 一样，限于篇幅在此省略 
//此函数的功能：从磁盘文件中读取数据到内存(即实现了调入已有通讯录信息的功能)
//参数：节点的总个数 
//返回值：链表的头节点 
struct student *readFromPcOk(int *sum) 
{     
FILE *sourceFile=NULL;    //声明 sourceFile 为指向要读取数据的源文件的文件型指针变量
char source[MAX_SIZE];    //接受源文件的文件名     
struct student *p=NULL,*q=NULL,*head=NULL,*k=NULL;     
int i;                    //for 循环计数变量  
//下面声明的各个字符型数组用来存读入的相应信息   
  char biaoti[MAX_SIZE];   
      char tongji[MAX_SIZE];   
	   int count;   
	    char tiaojilu[MAX_SIZE];   
		char shangtiao[MAX_SIZE];   
		char xueHao[MAX_SIZE],xingMing[MAX_SIZE],xingBie[MAX_SIZE],shouJiHao[MAX_SIZE],qqHa o[MAX_SIZE],suSheHao[MAX_SIZE],youXiang[MAX_SIZE],jiaTing[MAX_SIZE];  
		char zhongtiao[MAX_SIZE]; 
		 char xiatiao[MAX_SIZE];     
		 printf("请输入你想调入的通讯录文件路径包含文件名【形如：C:/111.txt】->"); 
		  scanf("%s",source);  
		  sourceFile=fopen(source,"r");   //用“只读”方式打开改文件，并用 sourceFile 指向打开的文件  while(sourceFile==NULL) 
		     //如果文件打开失败，则重新输入路径  
			 {   
			 printf("\n 打不开【%s】通讯录文件,请重新输入路径包含文件名【形如：C:/111.txt】 ->",source); 
			   scanf("%s",source);   
			    sourceFile=fopen(source,"r"); 
				 }     
				 printf("\n 调入【通讯录】成功!\n\n"); 
				  printf("文件【%s】中的内容是：\n\n\n",source);     //fscanf 函数与 scanf 函数作用相仿，只是他的读对象不是终端也是磁盘文件， 
				   //函数原型：fscanf(文件指针，格式字符串，输入表列);
				     fscanf(sourceFile,"%s",biaoti);         
					 fscanf(sourceFile,"%s",tongji);      
					 fscanf(sourceFile,"%d",&count);       
					 fscanf(sourceFile,"%s",tiaojilu); 
					  fscanf(sourceFile,"%s",shangtiao);   
					    fscanf(sourceFile,"%s",xueHao);   
						   fscanf(sourceFile,"%s",xingMing); 
						       fscanf(sourceFile,"%s",xingBie);   
							      fscanf(sourceFile,"%s",shouJiHao);  
								    fscanf(sourceFile,"%s",qqHao); 
     fscanf(sourceFile,"%s",suSheHao);  
	   fscanf(sourceFile,"%s",youXiang);  
	   fscanf(sourceFile,"%s",jiaTing);      
	    fscanf(sourceFile,"%s",zhongtiao);  
		*sum=count;  for(i=0;i<=count-1;i++)
		  {   
		  p=(struct student *)malloc(sizeof(struct student));  
		   p->next=NULL;  
		    fscanf(sourceFile,"%s",p->number); 
		     fscanf(sourceFile,"%s",p->name);  
			  fscanf(sourceFile,"%s",p->sex);      
			   fscanf(sourceFile,"%s",p->phone); 
			     fscanf(sourceFile,"%s",p->qq);    
				     fscanf(sourceFile,"%s",p->dorm);  
					  fscanf(sourceFile,"%s",p->email);  
					     fscanf(sourceFile,"%s",p->address); 
						   fscanf(sourceFile,"%s",xiatiao);   
						   if(head == NULL)  
						    {          
							 head=p;   q=p;  
							  }   
							  else   
							  {   //下面两句就是把节点依次连接起来  
							    q->next=p;    q=p;   } 
								 }    //以下的代码就是把上面接收到的数据，打印出来。
								   printf("          %s\n\n\n",biaoti);    printf(" %s",tongji);     
								    printf(" %d ",count);    
									printf("%s\n",tiaojilu); 
									 printf("%s\n",shangtiao); 
									  printf("%-16s%-10s%-8s%-15s%-13s%-15s%-25s%-28s\n",xueHao,xingMing,xingBie,sh ouJiHao,qqHao,suSheHao,youXiang,jiaTing);  
									   printf("%s\n",zhongtiao);     
									    k=head;     
										while(k!=NULL) 
										 {  
										 printf("%-16s%-10s%-8s%-15s%-13s%-15s%-25s%-28s\n",k->number,k->name,k>sex,k->phone,k->qq,k->dorm,k->email,k->address); 
										  printf("%s\n",xiatiao);   
										   k=k->next; 
										          }       
												  fclose(sourceFile);    //切记要关闭文件，否则会有内存读取错误的问题。     
												   return head; 
												   }
