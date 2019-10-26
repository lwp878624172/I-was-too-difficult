void backUpFromPc()
{
	char source[MAX_SIZE],end[MAX_SIZE]; 
	FILE *sourceFile=NULL, *endFile=NULL; 
	char ch;

	printf("请输入源通讯录文件路径包含文件名【形如：C:/111.txt】->");
	scanf("%s",source); sourceFile=fopen(source,"r"); printf("\n");
	while(sourceFile==NULL){
		printf("\n 打不开【%s】通讯录文件，请重新输入路径包含文件名【形如：C:/111.txt】->",source);
		scanf("%s",source); sourceFile=fopen(source,"r"); printf("\n");
	}
	printf("请输入目的通讯录文件路径包含文件名【形如：C:/111.txt】->");
	scanf("%s",end); endFile=fopen(end,"w"); printf("\n");
	while(endFile==NULL){
		printf("\n 打不开【%s】通讯录文件，请重新输入路径包含文件名【形如：C:/111.txt】->",end);
		scanf("%s",end); endFile=fopen(end,"w"); printf("\n");
	}

	for(ch=fgetc(sourceFile);ch!=EOF;ch=fgetc(sourceFile)){ 
		fputc(ch,endFile);
	}
	fclose(sourceFile); fclose(endFile);
	printf("\n 成功备份通讯录文件!从【%s】到【%s】!\n",source,end);
}
