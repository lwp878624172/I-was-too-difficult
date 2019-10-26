void printLianBiao(struct student *head,int *count) { 
	struct student *p=NULL;  
	printf("\n\n★-☆-★-☆-★- 北京信息科技大学 --- 大数据  1801班--- 班 级 通 讯 录 -★-☆-★-☆-★\n");  
	printf("\n 【总共有 %d 条记录】\n",*count); 
	p=head; 
	printf("====================================\n");
	printf("学号  姓名  性别  手机号码 QQ 号码  宿舍号 电子邮箱 家庭地址\n"); 
	printf("====================================\n");
	while(p!=NULL){
		 printf("%-16s%-10s%-8s%-15s%-13s%-15s%-25s%-28s\n",p->number,p->name,p>sex,p->phone,p->qq,p->dorm,p->email,p->address);
		 printf("——————————————————————————————\n"); 
		 p=p->next;
	}
}
