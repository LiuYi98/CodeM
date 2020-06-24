#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct																					//�������Ա��Ϣ�ṹ��
{
    char name[10];
    char code[20];
}ADMIN;
typedef struct passwordinfo																		//����ṹ��
{
    char place[10];
    char username[10];
    char password[20];
}CODE;
void menu(void);																				//���˵���ʾ
void menuLook(void);																			//�鿴����˵�
void menuAdm(void);																				//��������˵�
void log_reg(void);																				//��¼ע��˵�
void login(void);																				//��¼����
void registration(void);																		//ע�ắ��
void Look(int n);																				//�鿴���뺯��
void sortletter(CODE *p,int m,int n);															//����ĸ������
void sortlength(CODE *p,int m, int n);															//�����볤��������
void lookfor(CODE *p,int m);																	//���Һ���
void add(void);																					//������뺯��
void del(void);																					//ɾ�����뺯��
void change(void);																				//�������뺯��
int main()
{
    log_reg();
    menu();
}

void menu()  																					//��һ�������ʾ//
{
    int n;                                  													//�жϲ���
    printf("\n");
    printf("\t\t      ��ӭʹ���������ϵͳ\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.�鿴����\n");
    printf("\t\t\t2.��������\n");
    printf("\t\t\t3.�˳�\n");
    printf("\t\t******************************\n");
    printf("\t\t\t���������ֲ�ִ�в���:_\b");
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
    int n;                                 														// �жϲ���
    printf("\t\t\t�鿴����\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.����\n");
    printf("\t\t\t2.�罻\n");
    printf("\t\t\t3.����\n");
    printf("\t\t\t4.������һ��\n");
    printf("\t\t\t5.�˳�\n");
    printf("\t\t******************************\n");
    printf("\t\t\t���������ֲ�ִ�в���:_\b");
    fflush(stdin);
    scanf("%d",&n);
    Look(n);
}

void Look(int n)
{
    FILE *fp;
    CODE passwordLook[100];                                         							//��ȡ�ļ��д��������
    int i, m=0;																					// i���Ʊ�����m�洢�������
    CODE *p = passwordLook;																		//pָ������ṹ��
    system("cls");
    switch(n){
        case 1: printf("\t\t\t����������鿴\n"); fp = fopen("codeeco.txt","a+"); break;
		case 2: printf("\t\t\t�罻������鿴\n"); fp = fopen("codeim.txt","a+"); break;
		case 3: printf("\t\t\t����������鿴\n"); fp = fopen("codeoth.txt","a+"); break;
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
    printf("\t\t\t  ѡ����:\n");
    printf("\t\t\t1.���û�����ĸ����鿴\n");
    printf("\t\t\t2.���û�����ĸ����鿴\n");
    printf("\t\t\t3.�����볤������鿴\n");
    printf("\t\t\t4.�����볤�Ƚ���鿴\n");
    printf("\t\t\t5.����\n");
    printf("\t\t\t6.������һ��\n");
    printf("\t\t\t��������ѡ��\n");
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
	CODE *head[100],*temp;																			//ָ������headָ������ṹ��
	int i,j,k;
	for(i=0;i<m;i++)
		head[i]=&p[i];
	if(n==1){																						//ð������
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
	if(n==3)																							//ѡ������
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
    char placeFind[20];																					//�洢��Ҫ���ҵ�����
    printf("\t\t\t����\n");
    printf("\t\t******************************\n");
    printf("\t\t\t������Ҫ���ҵ������˻�(QQ/�Ա�/֪��...)");
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
    int n;                                                     										 //�ж��û�ѡ��
    printf("\t\t\t��������\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.�������\n");
    printf("\t\t\t2.ɾ������\n");
    printf("\t\t\t3.��������\n");
    printf("\t\t\t4.������һ��\n");
    printf("\t\t\t5.�˳�\n");
    printf("\t\t******************************\n");
    printf("\t\t\t���������ֲ�ִ�в���:_\b");
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
    CODE codeAdd;																						//�û�����ӵ�����
    int n;																								//�ж�ѡ��
    char judge;																							//�ж��Ƿ�Ҫ���
    printf("\t\t\t�������\n");
    printf("\t\t******************************\n");
    printf("\t\t\t�������\n");
    printf("\t\t\t1.����\n");
    printf("\t\t\t2.�罻\n");
    printf("\t\t\t3.����\n");
    printf("\t\t\t4.������һ��\n");
    printf("\t\t\t��������ѡ�����ͣ�\n");
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
    printf("\t\t\t���볡��(QQ/�ٶ�...)");
    gets(codeAdd.place);
    printf("\t\t\t�û���");
    gets(codeAdd.username);
    printf("\t\t\t����");
    gets(codeAdd.password);
    if(fprintf(fp,"%s %s %s\n",codeAdd.place,codeAdd.username,codeAdd.password)!=-1)
	    printf("\t\t\t�ɹ�\n");
	else
        printf("\t\t\tʧ��,������д��");
        fclose(fp);
    printf("\t\t\t�������(y/n)?");
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
	CODE passdel[100];																					//�洢���������
	char placedel[10];																					//��Ҫ���������ʹ�ó���
	int i, n;
	int flag, m=0;																						//flag�ж��Ƿ��ҵ�����
	char judge;
	printf("\t\t\tѡ����������������\n");
	printf("\t\t\t�������\n");
    printf("\t\t\t1.����\n");
    printf("\t\t\t2.�罻\n");
    printf("\t\t\t3.����\n");
    printf("\t\t\t4.������һ��\n");
    printf("\t\t\t��������ѡ�����ͣ�");
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
	printf("\t\t\t����������ɾ��������(QQ/�Ա�...)");
    fflush(stdin);
	scanf("%s",placedel);
	for(i=0; i<m; i++)
		if(strcmp(passdel[i].place,placedel)==0){
			flag=1;
			break;
		}
	if(flag==1)
	{
		printf("\t\t\t���ҵ���ȷ��ɾ����(y/n)");
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
			printf("\t\t\tɾ���ɹ���");
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
	printf("\t\t\tѡ����������������\n");
	printf("\t\t\t�������\n");
    printf("\t\t\t1.����\n");
    printf("\t\t\t2.�罻\n");
    printf("\t\t\t3.����\n");
    printf("\t\t\t4.������һ��\n");
    printf("\t\t\t��������ѡ�����ͣ�");
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
	printf("\t\t\t������������ĵ�����(QQ/�Ա�...)");
	scanf("%s",placeChange);
	for(i=0; i<m; i++)
		if(strcmp(passChange[i].place,placeChange)==0)
		{
			flag=1;
			break;
		}
	if(flag==1)
	{
		printf("\t\t\t���ҵ������������û���\n");
		fflush(stdin);
		gets(username);
		printf("\t\t\t������������\n");
		gets(password);
		printf("\t\t\tȷ�ϸ��ģ�(Y/N)");
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
			printf("\t\t\t���ĳɹ���");
			fclose(fp);
		}
	}
	else
		printf("Not found!");
}

void log_reg(void)
{
    int n;
    printf("\t\t    ��ӭʹ���������ϵͳ\n");
    printf("\t\t******************************\n");
    printf("\t\t\t1.��½\n");
    printf("\t\t\t2.ע��\n");
    printf("\t\t******************************\n");
    printf("\t\t\t��������ѡ��(1-2)");
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
    int i,n=0;																				//nͳ���ļ��д�����û���Ŀ
    char name[10],code[20];																	//��¼�û���½���û���������
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
	    printf("\t\t\t   ��½\n");
	    printf("\t\t******************************\n");
	    printf("\t\t\t�����û���\n");
	    printf("\t\t\t");
	    scanf("%s",name);
	    printf("\t\t\t��������\n");
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
		printf("\t\t\t��¼ʧ�ܣ����µ�¼��");
	}
}

void registration(void)
{
    FILE *fp;
    ADMIN info;
    char codeConfirm[20];									//����ȷ��
    system("cls");
    while(1)
    {
        printf("\t\t\t��ȷ�������״�ʹ�ñ�ϵͳ\n");
        printf("\t\t\t��������Ϣ\n");
        printf("\t\t\t�û�����");
        scanf("%s",info.name);
        printf("\t\t\t���룺");
        scanf("%s",info.code);
        printf("\t\t\t��ȷ�����룺");
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
            printf("\t\t\tע��ɹ���");
            break;
        }
        else
        {
            printf("\t\t\t���벻һ�£�������ע��");
            registration();
        }
    }
    system("cls");
}

