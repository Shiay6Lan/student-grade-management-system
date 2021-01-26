#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct inst                       //学院
{
	char instnum[20];
	char instname[20];
};
struct SCORE                      //分数
{
	int cscore;
	int mscore;
	int escore;
	int pscore;
};
struct student                     //学生信息
{
	char num[20];
	char name[20];
	char instnum[20];
	char sex;
	struct SCORE score;
};
struct NODE                        //链表结点
{
	struct student data;
	struct NODE* next;
};
struct NODE* creatlist()           //创建链表
{
	struct NODE* listhead = (struct NODE*)malloc(sizeof(struct NODE));
	if (listhead != NULL) listhead->next = NULL;
	return listhead;
}
struct NODE* creatnode(struct student data)        //创建结点
{
	struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
	}
	return node;
}
void printnode(struct NODE* node)               //打印当前结点
{
	printf("\t\t\t    学号\t姓名   学院代码  性别代码  C语言成绩  数学成绩  英语成绩  体育成绩\n");
	printf("\t\t\t%s   %s   %s\t    %c\t      %d\t %d\t   %d\t     %d\n", node->data.num, node->data.name, node->data.instnum, node->data.sex, node->data.score.cscore, node->data.score.mscore, node->data.score.escore, node->data.score.pscore);
}
void insertnode(struct NODE* headnode, struct student data)       //插入结点
{
	struct NODE* node = creatnode(data);
	node->next = headnode->next;
	headnode->next = node;
}
struct NODE* searchnode(struct NODE* headnode, char* name)      //按名字查找结点
{
	struct NODE* pmove = headnode->next;
	if (pmove == NULL) return pmove;
	else
	{
		while (strcmp(pmove->data.name, name))
		{
			pmove = pmove->next;
			if (pmove == NULL) break;
		}
		return pmove;
	}
}
void deletenode(struct NODE* headnode, char* num)             //删除结点
{
	struct NODE* frontnode = headnode;
	struct NODE* posnode = headnode->next;
	if (posnode == NULL)
	{
		printf("\t\t\t未查找到相关学生信息！\n");
		return;
	}
	else
	{
		while (strcmp(posnode->data.num, num))
		{
			frontnode = posnode;
			posnode = frontnode->next;
			if (posnode == NULL)
			{
				printf("\t\t\t未查找到相关学生信息！\n");
				return;
			}
		}
		frontnode->next = posnode->next;
		free(posnode);
		printf("\t\t\t删除成功！\n");
	}
}
