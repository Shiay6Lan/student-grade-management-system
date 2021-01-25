#include<stdio.h>
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
	scanf("%d", &down);
	switch (down)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
	}
}
int main()
{
	menu();
	key();

	return 0;
}