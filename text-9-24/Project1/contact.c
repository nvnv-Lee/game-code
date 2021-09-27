#define _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"

// 初始化通讯录
void InitContact(struct Contact* pc)
{

	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ *sizeof(struct PeoInfo));
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
}
//增加联系人
void AddContact(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增加容量
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			return;
		}
	}
	//录入新增人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%s",&( pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加成功\n");

}
//删减联系人
void DelContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除联系人的姓名:>");
	scanf("%s",name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("查无此人");
	}
	else
	{
		int j = 0;
		for (j = pos; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("删除成功");
	}
}
//通讯录中的联系人是否有所输入的联系人，若有，是通讯录中的第几个联系人
int FindContactByName(const struct Contact* pc, const char*name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	//找不到联系人
			return -1;
}
//查询指定联系人
void SearchContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要查询的联系人姓名:>");
	scanf("%s",name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("查无此人");
	}
	else
	{
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age, 
			pc->data[pos].sex, 
			pc->data[pos].tele, 
			pc->data[pos].addr);
	}
}
//修改联系人信息
void ModifyContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的联系人姓名:>");
	scanf("%s",name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入要修改的名字:>");
		scanf("%s",pc->data[pos].name);
		printf("请输入要修改的年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入要修改的性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入要修改的电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入要修改的地址:>");
		scanf("%s", pc->data[pos].addr);
	}
}
//显示所有的联系人信息
void ShowContact(struct Contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}