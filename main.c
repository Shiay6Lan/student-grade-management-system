#include"all.h"
struct NODE* listhead = NULL;
void menu()
{
	printf("************************【学生管理系统】************************\n");
	printf("*\t\t  0.【返回上一级菜单(退出)】\t\t       *\n");
	printf("*\t\t  1.【   按学生姓名排序   】\t\t       *\n");
	printf("*\t\t  2.【 按学生平均成绩排序 】\t\t       *\n");
	printf("*\t\t  3.【   按学院查找学生   】\t\t       *\n");
	printf("*\t\t  4.【  添加学生及其信息  】\t\t       *\n");
	printf("*\t\t  5.【  修改学生成绩信息  】\t\t       *\n");
	printf("*\t\t  6.【   按姓名查找学生   】\t\t       *\n");
	printf("*\t\t  7.【    删除学生信息    】\t\t       *\n");
	printf("*\t\t  8.【    修改系统密码    】\t\t       *\n");
	printf("*\t\t  9.【  查找挂科学生信息  】\t\t       *\n");
	printf("****************************************************************\n");
	printf("请输入0-9:\n");
}
int key()
{
	int down;
	struct student tempdata;
	scanf("%d", &down);
	switch (down)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			printf("\t\t    【  添加学生及其信息  】\n");
			printf("请输入学生学号、姓名、学院代码、性别代码(M为男，F为女)、C语言成绩、数学成绩、英语成绩、体育成绩:\n");
			scanf("%s%s%s%c%d%d%d%d", tempdata.num, tempdata.name, tempdata.instnum, &tempdata.sex, &tempdata.score.cscore, &tempdata.score.mscore, &tempdata.score.escore, &tempdata.score.pscore);
			insertnode(listhead, tempdata);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
	}
}
int main()
{
	listhead = creatlist();

	while (1)
	{
		menu();
		key();
		system("pause");
		system("cls");
	}

	return 0;
}
