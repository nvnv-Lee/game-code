#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SZ 1000
#define MAX 1000

#define NAME_MAX 30
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
//描述一个联系人的基本信息
struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};
//创建一个通讯录
struct Contact
{
	struct PeoInfo* data;//存放联系人的基本信息
	int sz;//当前通讯录所有联系人的个数
	int capacity;//通讯录的当前最大容量
};
//初始化通讯录
void InitContact(struct Contact* pc);
//增加联系人
void AddContact(struct Contact* pc);
//删减联系人
void DelContact(struct Contact* pc);
//查询指定联系人
void SearchContact(struct Contact* pc);
//修改联系人信息
void ModifyContact(struct Contact* pc);
//显示所有的联系人信息
void ShowContact(struct Contact* pc);
