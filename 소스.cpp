#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Node {
	char name[MAX];
	char phone_num[MAX];
	char car_name[MAX];
	char car_num[MAX];
	struct Node* link;
}Node;


Node* p = NULL;
Node* prev = NULL;
Node* head = NULL;
Node* next = NULL;

char buffer[MAX];

FILE* fp = NULL;


void menu();
void Add();
void Del();
void Search();
void PrintAll();
void Change();

int main()
{
	menu();
}
void menu()
{
	printf("��Ʈī ���� ���α׷�\n");
	printf("===================\n");
	printf("1. ��Ʈ ���� �߰�\n");
	printf("2. ��Ʈ ���� ����Ʈ ��ü ���\n");
	printf("3. �� ���� ã��\n");
	printf("4. �� ���� ����\n");
	printf("5. ��Ʈ ���� �ݳ�\n");
	printf("6. ����\n");
	printf("====================\n");
	printf("�޴��� �Է��ϼ���: ");
	int num;
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		Add();
		break;
	case 2:
		PrintAll();
		break;
	case 3:
		Search();
		break;
	case 4:
		Change();
		break;
	case 5:
		Del();
		break;
	case 6:
		exit(0);
		break;
	
	}
}

void Add()
{
	getchar();
	p = (Node*)malloc(sizeof(Node));
	p->link = NULL;
	printf("�� �̸�: ");
	gets_s(buffer, MAX);
	strcpy(p->name, buffer);
	printf("�� ��ȭ��ȣ: ");
	gets_s(buffer, MAX);
	strcpy(p->phone_num, buffer);
	printf("����: ");
	gets_s(buffer, MAX);
	strcpy(p->car_name, buffer);
	printf("���� ��ȣ: ");
	gets_s(buffer, MAX);
	strcpy(p->car_num, buffer);
	printf("��Ʈī ������ ���������� �߰� �Ǿ����ϴ�.\n");
	
	fp = fopen("data.txt", "a+");
	fputs(p->name , fp);
	fputs("\t", fp);
	fputs(p->phone_num , fp);
	fputs("\t", fp);
	fputs(p->car_name , fp);
	fputs("\t", fp);
	fputs(p->car_num , fp);
	fputs("\n", fp);
	fclose(fp);

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		prev->link = p;
	}
	prev = p;
	menu();
}

void Search()
{
	printf("������ ã���� ������ �̸��� �Է����ּ���: ");
	getchar();
	gets_s(buffer, MAX);
	p = head;
	while (1)
	{
		if (p == NULL)
		{
			printf("��ϵ��� ���� ������Դϴ�.\n");
			break;
		}
		if (strcmp(buffer, p->name) != 0)
		{
			p = p->link;
		}
		else
		{
			printf("���� ����: %s\n", p->name);
			printf("���� ��ȭ��ȣ: %s\n", p->phone_num);
			printf("����: %s\n", p->car_name);
			printf("���� ��ȣ: %s\n", p->car_num);
			break;
		}
	}
	menu();
}

void PrintAll()
{
	p = head;
	if (head == NULL)
	{
		printf("������ �����ϴ�.\n");
	}
	while (1)
	{
		if (p == NULL)
			break;
		printf("�� �̸�: %s\n", p->name);
		printf("�� ��ȭ��ȣ: %s\n", p->phone_num);
		printf("����: %s\n", p->car_name);
		printf("���� ��ȣ: %s\n\n", p->car_num);
		p = p->link;

	}
	menu();
}

void Del()
{
	char line[MAX];
	printf("������ �ݳ��Ͻ� ������ �̸��� �Է��ϼ���: ");
	getchar();
	gets_s(buffer, MAX);
	p = head;
	while (1) 
	{
		if (p == NULL)
		{
			printf("���������� ������ �ݳ��Ǿ����ϴ�.\n");
			break;
		}
		if (strcmp(buffer, p->link->name) != 0)
		{
			p = p->link;
		}
		else
		{
			p->link = p->link->link;
			break;
		}
	}
	//fp = fopen("data.txt", "a+");
	//while (fgets(line, sizeof(line), fp) != NULL)
	//{
	//	char* ptr = strtok(line, " ");
	//	if (strcmp(ptr, buffer) != 0)
	//	{
	//		printf("%s\n", line);
	//	}
	//}
	//fclose(fp);
	//
	menu();
}


void Change()
{
	printf("������ �����Ͻ� ������ �̸��� �Է��ϼ���: ");
	getchar();
	gets_s(buffer, MAX);
	p = head;

	while (1)
	{
		if (p == NULL)
		{
			printf("��ġ�ϴ� ������ ������ �����ϴ�,\n");
			break;
		}
		if (strcmp(buffer, p->name) != 0)
		{
			p = p->link;
		}
		else
		{
			printf("������ ��ȭ��ȣ�� �����ϼ���: ");
			gets_s(buffer, MAX);
			strcpy(p->phone_num, buffer);
			printf("���������� ������ ������ ����Ǿ����ϴ�,\n");
			break;
		}
		
	}
	menu();
}