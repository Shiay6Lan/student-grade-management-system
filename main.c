#include"all.h"
struct NODE* listhead = NULL;
void menu()
{
	printf("\t\t\t************************【学生成绩管理系统】************************\n");
	printf("\t\t\t*\t\t    0.【返回上一级菜单(退出)】\t\t\t   *\n");
	printf("\t\t\t*\t\t    1.【   按学生姓名排序   】\t\t\t   *\n");
	printf("\t\t\t*\t\t    2.【 按学生平均成绩排序 】\t\t\t   *\n");
	printf("\t\t\t*\t\t    3.【   按学院查找学生   】\t\t\t   *\n");
	printf("\t\t\t*\t\t    4.【  添加学生及其信息  】\t\t\t   *\n");
	printf("\t\t\t*\t\t    5.【  修改学生成绩信息  】\t\t\t   *\n");
	printf("\t\t\t*\t\t    6.【   按姓名查找学生   】\t\t\t   *\n");
	printf("\t\t\t*\t\t    7.【    删除学生信息    】\t\t\t   *\n");
	printf("\t\t\t*\t\t    8.【    修改系统密码    】\t\t\t   *\n");
	printf("\t\t\t*\t\t    9.【  查找挂科学生信息  】\t\t\t   *\n");
	printf("\t\t\t********************************************************************\n");
	printf("\t\t\t请输入0-9:");
}
int key()
{
	int down, down2;
	struct student tempdata;
	scanf("%d", &down);
	switch (down)
	{
		case 0:
			exit(0);
			break;
		case 1:
			printf("\t\t\t\t\t      【   按学生姓名排序   】\n");
			break;
		case 2:
			printf("\t\t\t\t\t      【 按学生平均成绩排序 】\n");
			break;
		case 3:
			printf("\t\t\t\t\t      【   按学院查找学生   】\n");
			break;
		case 4:
			printf("\t\t\t\t\t      【  添加学生及其信息  】\n");
			printf("请输入学生学号、姓名、学院代码、性别代码(M为男，F为女)、C语言成绩、数学成绩、英语成绩、体育成绩:\n");
			scanf("%s%s%s%s%d%d%d%d", tempdata.num, tempdata.name, tempdata.instnum, &tempdata.sex, &tempdata.score.cscore, &tempdata.score.mscore, &tempdata.score.escore, &tempdata.score.pscore);
			insertnode(listhead, tempdata);
			printf("\t\t\t添加成功！\n");
			savefile("Stu_Info.txt", listhead);
			break;
		case 5:
			printf("\t\t\t\t\t      【  修改学生成绩信息  】\n");
			printf("\t\t\t请输入要修改学生信息的学生学号:");
			scanf("%s", tempdata.num);
			if (searchnodebynum(listhead, tempdata.num) == NULL) printf("\t\t\t未查找到相关学生信息！\n");
			else
			{
				struct NODE* node = searchnodebynum(listhead, tempdata.num);
				printf("\t\t\t请输入要修改的学生信息(0-返回菜单,1-学生所有信息,2-学生成绩信息):");
				scanf("%d", &down2);
				switch (down2)
				{
				case 0:
					break;
				case 1:
					printf("\t\t\t请输入新的学生信息(学号、姓名、学院代码、性别代码(M为男，F为女)、C语言成绩、数学成绩、英语成绩、");
					printf("\t\t\t\t体育成绩):");
					scanf("%s%s%s%s%d%d%d%d", node->data.num, node->data.name, node->data.instnum, &node->data.sex, &node->data.score.cscore, &node->data.score.mscore, &node->data.score.escore, &node->data.score.pscore);
					printf("\t\t\t修改成功！\n");
					savefile("Stu_Info.txt", listhead);
					break;
				case 2:
					printf("\t\t\t请输入新的学生成绩信息(C语言成绩、数学成绩、英语成绩、体育成绩):");
					scanf("%d%d%d%d", &node->data.score.cscore, &node->data.score.mscore, &node->data.score.escore, &node->data.score.pscore);
					printf("\t\t\t修改成功！\n");
					savefile("Stu_Info.txt", listhead);
					break;
				}
			}
			break;
		case 6:
			printf("\t\t\t\t\t      【   按姓名查找学生   】\n");
			printf("\t\t\t请输入学生姓名:");
			scanf("%s", tempdata.name);
			if (searchnodebyname(listhead, tempdata.name) == NULL) printf("\t\t\t未查找到相关学生信息！\n");
			else printnode(searchnodebyname(listhead, tempdata.name));
			break;
		case 7:
			printf("\t\t\t\t\t      【    删除学生信息    】\n");
			printf("\t\t\t请输入要删除学生信息的学号:");
			scanf("%s", tempdata.num);
			deletenode(listhead, tempdata.num);
			savefile("Stu_Info.txt", listhead);
			break;
		case 8:
			printf("\t\t\t\t\t      【    修改系统密码    】\n");
			break;
		case 9:
			printf("\t\t\t\t\t      【  查找挂科学生信息  】\n");
			break;
	}
}
int main()
{
	listhead = creatlist();

	readfile("Stu_Info.txt", listhead);
	while (1)
	{
		menu();
		key();
		system("pause");
		system("cls");
	}

	return 0;
}
