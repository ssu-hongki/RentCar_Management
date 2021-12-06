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
	printf("렌트카 관리 프로그램\n");
	printf("===================\n");
	printf("1. 렌트 차량 추가\n");
	printf("2. 렌트 차량 리스트 전체 출력\n");
	printf("3. 고객 정보 찾기\n");
	printf("4. 고객 정보 수정\n");
	printf("5. 렌트 차량 반납\n");
	printf("6. 종료\n");
	printf("====================\n");
	printf("메뉴를 입력하세요: ");
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
	printf("고객 이름: ");
	gets_s(buffer, MAX);
	strcpy(p->name, buffer);
	printf("고객 전화번호: ");
	gets_s(buffer, MAX);
	strcpy(p->phone_num, buffer);
	printf("차종: ");
	gets_s(buffer, MAX);
	strcpy(p->car_name, buffer);
	printf("차량 번호: ");
	gets_s(buffer, MAX);
	strcpy(p->car_num, buffer);
	printf("렌트카 차량이 정상적으로 추가 되었습니다.\n");
	
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
	printf("정보를 찾으실 고객님의 이름을 입력해주세요: ");
	getchar();
	gets_s(buffer, MAX);
	p = head;
	while (1)
	{
		if (p == NULL)
		{
			printf("등록되지 않은 사용자입니다.\n");
			break;
		}
		if (strcmp(buffer, p->name) != 0)
		{
			p = p->link;
		}
		else
		{
			printf("고객님 성함: %s\n", p->name);
			printf("고객님 전화번호: %s\n", p->phone_num);
			printf("차종: %s\n", p->car_name);
			printf("차량 번호: %s\n", p->car_num);
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
		printf("정보가 없습니다.\n");
	}
	while (1)
	{
		if (p == NULL)
			break;
		printf("고객 이름: %s\n", p->name);
		printf("고객 전화번호: %s\n", p->phone_num);
		printf("차종: %s\n", p->car_name);
		printf("차량 번호: %s\n\n", p->car_num);
		p = p->link;

	}
	menu();
}

void Del()
{
	char line[MAX];
	printf("차량을 반납하실 고객님의 이름을 입력하세요: ");
	getchar();
	gets_s(buffer, MAX);
	p = head;
	while (1) 
	{
		if (p == NULL)
		{
			printf("정상적으로 차량이 반납되었습니다.\n");
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
	printf("정보를 변경하실 고객님의 이름을 입력하세요: ");
	getchar();
	gets_s(buffer, MAX);
	p = head;

	while (1)
	{
		if (p == NULL)
		{
			printf("일치하는 고객님의 정보가 없습니다,\n");
			break;
		}
		if (strcmp(buffer, p->name) != 0)
		{
			p = p->link;
		}
		else
		{
			printf("고객님의 전화번호를 변경하세요: ");
			gets_s(buffer, MAX);
			strcpy(p->phone_num, buffer);
			printf("정상적으로 고객님의 정보가 변경되었습니다,\n");
			break;
		}
		
	}
	menu();
}