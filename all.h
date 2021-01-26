#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct inst
{
	char instnum[20];
	char instname[20];
};
struct SCORE
{
	int cscore;
	int mscore;
	int escore;
	int pscore;
};
struct student
{
	char num[20];
	char name[20];
	char instnum[20];
	char sex;
	struct SCORE score;
};
struct NODE
{
	struct student data;
	struct NODE* next;
};
struct NODE* creatlist()
{
	struct NODE* listhead = (struct NODE*)malloc(sizeof(struct NODE));
	if (listhead != NULL) listhead->next = NULL;
	return listhead;
}
struct NODE* creatnode(struct student data)
{
	struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
	}
	return node;
}
void insertnode(struct NODE* headnode, struct student data)
{
	struct NODE* node = creatnode(data);
	node->next = headnode->next;
	headnode->next = node;
}
