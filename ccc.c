#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct																					//密码管理员信息结构体
{
    char name[10];
    char code[20];
}ADMIN;
typedef struct passwordinfo																		//密码结构体
{
    char place[10];
    char username[10];
    char password[20];
}CODE;
void menu(void);																				//主菜单显示
void menuLook(void);																			//查看密码菜单
void menuAdm(void);																				//管理密码菜单
void log_reg(void);																				//登录注册菜单
void login(void);																				//登录函数
void registration(void);																		//注册函数
void Look(int n);																				//查看密码函数
void sortletter(CODE *p,int m,int n);															//按字母排序函数
void sortlength(CODE *p,int m, int n);															//按密码长度排序函数
void lookfor(CODE *p,int m);																	//查找函数
void add(void);																					//添加密码函数
void del(void);																					//删除密码函数
void change(void);																				//更改密码函数
int main()
{
    log_reg();
    menu();
}

void menu()  																					//第一层界面显示//
{
    int n;                                  													//判断操作
    printf("\n");
    printf("\t\t      欢迎使用密码管理系统\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.查看密码\n");
    printf("\t\t\t2.管理密码\n");
    printf("\t\t\t3.退出\n");
    printf("\t\t******************************\n");
    printf("\t\t\t请输入数字并执行操作:_\b");
    scanf("%d",&n);
    switch(n)
    {
        case 1: system("cls"); menuLook();break;
        case 2: system("cls"); menuAdm();break;
        case 3: exit(0);
    }

}
void menuLook()
{
    int n;                                 														// 判断操作
    printf("\t\t\t查看密码\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.金融\n");
    printf("\t\t\t2.社交\n");
    printf("\t\t\t3.其他\n");
    printf("\t\t\t4.返回上一层\n");
    printf("\t\t\t5.退出\n");
    printf("\t\t******************************\n");
    printf("\t\t\t请输入数字并执行操作:_\b");
    fflush(stdin);
    scanf("%d",&n);
    Look(n);
}

void Look(int n)
{
    FILE *fp;
    CODE passwordLook[100];                                         							//读取文件中储存的密码
    int i, m=0;																					// i控制变量，m存储密码个数
    CODE *p = passwordLook;																		//p指向密码结构体
    system("cls");
    switch(n){
        case 1: printf("\t\t\t金融类密码查看\n"); fp = fopen("codeeco.txt","a+"); break;
		case 2: printf("\t\t\t社交类密码查看\n"); fp = fopen("codeim.txt","a+"); break;
		case 3: printf("\t\t\t其他类密码查看\n"); fp = fopen("codeoth.txt","a+"); break;
		case 4: menu(); break;
	}
    if(fp==NULL){
        printf("file opened error!");
        exit(0);
    }
    for(i=0; fscanf(fp,"%s %s %s\n",passwordLook[i].place,passwordLook[i].username,passwordLook[i].password)!=EOF; i++)  m++;
    fclose(fp);
    printf("\t\t******************************\n");
	for(i=0; i<m; i++)
        printf("\t\t\t%s %s %s\n",passwordLook[i].place,passwordLook[i].username,passwordLook[i].password);
    printf("\t\t******************************\n");
    printf("\n\n");
    printf("\t\t\t  选择功能:\n");
    printf("\t\t\t1.按用户名字母升序查看\n");
    printf("\t\t\t2.按用户名字母降序查看\n");
    printf("\t\t\t3.按密码长度升序查看\n");
    printf("\t\t\t4.按密码长度降序查看\n");
    printf("\t\t\t5.查找\n");
    printf("\t\t\t6.返回上一层\n");
    printf("\t\t\t输入数字选择\n");
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
        case 1:;
        case 2:sortletter(p,m,n);break;
        case 3:;
        case 4:sortlength(p,m,n); break;
        case 5:lookfor(p,m); break;
        case 6:system("cls"); menuLook();
    }
}

void sortletter(CODE *p,int m,int n)
{
	CODE *head[100],*temp;																			//指针数组head指向密码结构体
	int i,j,k;
	for(i=0;i<m;i++)
		head[i]=&p[i];
	if(n==1){																						//冒泡排序
		for(i=1; i<m; i++)
			for(j=0; j<m-i; j++)
				if(strcmp(p[j].username,p[j+1].username)>0){
					temp = head[j];
					head[j] = head[j+1];
					head[j+1] = temp;
				}
	}
	else
		for(i=1; i<m; i++)
			for(j=0; j<m-i; j++)
				if(strcmp(p[j].username,p[j+1].username)<0){
					temp = head[j];
					head[j] = head[j+1];
					head[j+1] = temp;
				}
	for(i=0; i<m; i++)
        printf("%s %s %s\n",head[i]->place,head[i]->username,head[i]->password);
}

void sortlength(CODE *p,int m, int n)
{
	CODE *head[100],*temp;
	int length[100];
	int i,j,k;
	for(i=0;i<m;i++)
		head[i]=&p[i];
	for(i=0; i<m; i++)
		length[i] = strlen(head[i]->password);
	if(n==3)																							//选择排序
		for(i=0; i<m; i++){
			k=i;
			for(j=i+1; j<m; j++)
				if(length[j]<length[k])
					k = j;
			if(i!=k){
				temp = head[i];
				head[i] = head[k];
				head[k] = temp;
			}
		}
	else
		for(i=0; i<m; i++){
			k=i;
			for(j=i+1; j<m; j++)
				if(length[j]>length[k])
					k = j;
			if(i!=k){
				temp = head[i];
				head[i] = head[k];
				head[k] = temp;
			}
		}
	for(i=0; i<m; i++)
        printf("%s %s %s\n",head[i]->place,head[i]->username,head[i]->password);
}
void lookfor(CODE *p,int m)
{
    int i,k,flag =0;
    char placeFind[20];																					//存储所要查找的密码
    printf("\t\t\t查找\n");
    printf("\t\t******************************\n");
    printf("\t\t\t输入你要查找的密码账户(QQ/淘宝/知乎...)");
    fflush(stdin);
    gets(placeFind);
    for(i=0; i<m; i++)
        if(strcmp(placeFind,p[i].place)==0){
            flag=1;
            i=k;
            break;
        }
    if(flag == 1)
        printf("%s %s %s\n",p[k].place,p[k].username,p[k].password);
    else
        printf("Not found!");
}
void menuAdm()
{
    int n;                                                     										 //判断用户选择
    printf("\t\t\t管理密码\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.添加密码\n");
    printf("\t\t\t2.删除密码\n");
    printf("\t\t\t3.更改密码\n");
    printf("\t\t\t4.返回上一层\n");
    printf("\t\t\t5.退出\n");
    printf("\t\t******************************\n");
    printf("\t\t\t请输入数字并执行操作:_\b");
	scanf("%d",&n);
    switch(n)
    {
        case 1: system("cls"); add(); break;
        case 2: system("cls"); del(); break;
        case 3: system("cls"); change(); break;
        case 4: system("cls"); menu();break;
        case 5: exit(0);
    }
}

void add(void)
{
    FILE *fp;
    CODE codeAdd;																						//用户所添加的密码
    int n;																								//判断选择
    char judge;																							//判断是否要添加
    printf("\t\t\t添加密码\n");
    printf("\t\t******************************\n");
    printf("\t\t\t密码类别：\n");
    printf("\t\t\t1.金融\n");
    printf("\t\t\t2.社交\n");
    printf("\t\t\t3.其他\n");
    printf("\t\t\t4.返回上一层\n");
    printf("\t\t\t输入数字选择类型：\n");
    printf("\t\t******************************\n");
    printf("\t\t\t");
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
        case 1: fp = fopen("codeeco.txt","a+"); break;
		case 2: fp = fopen("codeim.txt","a+"); break;
		case 3: fp = fopen("codeoth.txt","a+"); break;
		case 4: system("cls"); menuAdm(); break;
	}
	if(fp==NULL){
		printf("file opening error.");
	 	exit(0);
	}
	fflush(stdin);
    printf("\t\t\t密码场合(QQ/百度...)");
    gets(codeAdd.place);
    printf("\t\t\t用户名");
    gets(codeAdd.username);
    printf("\t\t\t密码");
    gets(codeAdd.password);
    if(fprintf(fp,"%s %s %s\n",codeAdd.place,codeAdd.username,codeAdd.password)!=-1)
	    printf("\t\t\t成功\n");
	else
        printf("\t\t\t失败,请重新写入");
        fclose(fp);
    printf("\t\t\t继续添加(y/n)?");
    fflush(stdin);
    judge=getchar();
    if(judge=='y' || judge=='Y'){
        system("cls");
        add();
    }
    else
        exit(0);
}

void del(void)
{
	FILE *fp;
	CODE passdel[100];																					//存储读入的密码
	char placedel[10];																					//所要更改密码的使用场合
	int i, n;
	int flag, m=0;																						//flag判断是否找到密码
	char judge;
	printf("\t\t\t选择你想更改密码类别：\n");
	printf("\t\t\t密码类别：\n");
    printf("\t\t\t1.金融\n");
    printf("\t\t\t2.社交\n");
    printf("\t\t\t3.其他\n");
    printf("\t\t\t4.返回上一层\n");
    printf("\t\t\t输入数字选择类型：");
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
        case 1: fp = fopen("codeeco.txt","a+"); break;
		case 2: fp = fopen("codeim.txt","a+"); break;
		case 3: fp = fopen("codeoth.txt","a+"); break;
		case 4: system("cls"); menuAdm(); break;
	}
	if(fp==NULL){
		printf("file opening error.");
	 	exit(0);
	}
	for(i=0; fscanf(fp,"%s %s %s",passdel[i].place,passdel[i].username,passdel[i].password)!=EOF; i++)	  m++;
	fclose(fp);
	printf("\t\t\t请输入你想删除的密码(QQ/淘宝...)");
    fflush(stdin);
	scanf("%s",placedel);
	for(i=0; i<m; i++)
		if(strcmp(passdel[i].place,placedel)==0){
			flag=1;
			break;
		}
	if(flag==1)
	{
		printf("\t\t\t已找到，确认删除？(y/n)");
		fflush(stdin);
		judge = getchar();
		if(judge=='y' || judge=='Y')
		{
			switch(n)
		    {
		        case 1: fp = fopen("codeeco.txt","w"); break;
				case 2: fp = fopen("codeim.txt","w"); break;
				case 3: fp = fopen("codeoth.txt","w"); break;
				case 4: system("cls"); menuAdm(); break;
			}
			if(fp==NULL){
				printf("file opening error.");
			 	exit(0);
			}
			for(; i<m; i++)
				passdel[i] = passdel[i+1];
			for(i=0; i<m-1; i++)
				fprintf(fp,"%s %s %s\n",passdel[i].place,passdel[i].username,passdel[i].password);
			fclose(fp);
			printf("\t\t\t删除成功！");
		}
	}
	else
		printf("Not found!");
}

void change()
{
	FILE *fp;
	int i,n,flag=0,m;
	char judge;
	char type[10],placeChange[10],username[10],password[20];
    CODE passChange[100];
	printf("\t\t\t选择你想更改密码类别：\n");
	printf("\t\t\t密码类别：\n");
    printf("\t\t\t1.金融\n");
    printf("\t\t\t2.社交\n");
    printf("\t\t\t3.其他\n");
    printf("\t\t\t4.返回上一层\n");
    printf("\t\t\t输入数字选择类型：");
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
        case 1: fp = fopen("codeeco.txt","a+"); break;
		case 2: fp = fopen("codeim.txt","a+"); break;
		case 3: fp = fopen("codeoth.txt","a+"); break;
		case 4: system("cls"); menuAdm(); break;
	}
	if(fp==NULL){
		printf("file opening error.");
	 	exit(0);
	}
	for(i=0; fscanf(fp,"%s %s %s",passChange[i].place,passChange[i].username,passChange[i].password)!=EOF; i++)	  m++;
	fclose(fp);
	printf("\t\t\t请输入你想更改的密码(QQ/淘宝...)");
	scanf("%s",placeChange);
	for(i=0; i<m; i++)
		if(strcmp(passChange[i].place,placeChange)==0)
		{
			flag=1;
			break;
		}
	if(flag==1)
	{
		printf("\t\t\t已找到，请输入新用户名\n");
		fflush(stdin);
		gets(username);
		printf("\t\t\t请输入新密码\n");
		gets(password);
		printf("\t\t\t确认更改？(Y/N)");
		fflush(stdin);
		judge = getchar();
		if(judge=='y' || judge=='Y')
		{
			strcpy(passChange[i].username,username);
			strcpy(passChange[i].password,password);
			switch(n)
		    {
		        case 1: fp = fopen("codeeco.txt","w"); break;
				case 2: fp = fopen("codeim.txt","w"); break;
				case 3: fp = fopen("codeoth.txt","w"); break;
			}
			if(fp==NULL){
				printf("file opening error.");
			 	exit(0);
			}
			for(i=0; i<m; i++)
				fprintf(fp,"%s %s %s\n",passChange[i].place,passChange[i].username,passChange[i].password);
			printf("\t\t\t更改成功！");
			fclose(fp);
		}
	}
	else
		printf("Not found!");
}

void log_reg(void)
{
    int n;
    printf("\t\t    欢迎使用密码管理系统\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.登陆\n");
    printf("\t\t\t2.注册\n");
    printf("\t\t******************************\n");
    printf("\t\t\t输入您的选项(1-2)");
    scanf("%d",&n);
    switch(n)
    {
        case 1: login();break;
        case 2: registration(); break;
        default: system("cls"); log_reg(); break;
    }
}

void login(void)
{
    FILE *fp;
    ADMIN info[10];
    int i,n=0;																				//n统计文件中储存的用户数目
    char name[10],code[20];																	//记录用户登陆的用户名和密码
    system("cls");
    fp = fopen("info.txt","r");
    if(fp==NULL)
    {
        printf("\t\t\tfile opening error.");
        exit(0);
    }
    for(i=0;fscanf(fp," %s %s\n",info[i].name,info[i].code)!=EOF;i++)   n++;
    fclose(fp);
    n=i;
    while(1)
    {
	    printf("\t\t\t   登陆\n");
	    printf("\t\t******************************\n");
	    printf("\t\t\t输入用户名\n");
	    printf("\t\t\t");
	    scanf("%s",name);
	    printf("\t\t\t输入密码\n");
	    printf("\t\t\t");
	    scanf("%s",code);
	    for(i=0;i<n;i++)
	    {
	       if(strcmp(info[i].name,name)==0 && strcmp(info[i].code,code)==0)
	       {
			   system("cls");
			   return;
		   }
		}
		printf("\t\t\t登录失败，重新登录。");
	}
}

void registration(void)
{
    FILE *fp;
    ADMIN info;
    char codeConfirm[20];									//密码确认
    system("cls");
    while(1)
    {
        printf("\t\t\t请确保您是首次使用本系统\n");
        printf("\t\t\t请输入信息\n");
        printf("\t\t\t用户名：");
        scanf("%s",info.name);
        printf("\t\t\t密码：");
        scanf("%s",info.code);
        printf("\t\t\t请确认密码：");
        scanf("%s",codeConfirm);
        if(strcmp(info.code,codeConfirm)==0)
        {
            fp = fopen("info.txt","a");
            if(fp==NULL)
            {
                printf("file opening error.");
                exit(0);
            }
            fprintf(fp," %s %s\n",info.name,info.code);
            fclose(fp);
            printf("\t\t\t注册成功！");
            break;
        }
        else
        {
            printf("\t\t\t密码不一致，请重新注册");
            registration();
        }
    }
    system("cls");
}

