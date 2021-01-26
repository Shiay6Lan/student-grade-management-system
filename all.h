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
void insertnode(struct NODE* headnode, struct student data)       //插入节点
{
	struct NODE* node = creatnode(data);
	node->next = headnode->next;
	headnode->next = node;
}
