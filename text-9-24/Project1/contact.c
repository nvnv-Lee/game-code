#define _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"

// ��ʼ��ͨѶ¼
void InitContact(struct Contact* pc)
{

	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ *sizeof(struct PeoInfo));
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
}
//������ϵ��
void AddContact(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//��������
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			return;
		}
	}
	//¼�������˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%s",&( pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("���ӳɹ�\n");

}
//ɾ����ϵ��
void DelContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ����ϵ�˵�����:>");
	scanf("%s",name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("���޴���");
	}
	else
	{
		int j = 0;
		for (j = pos; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�");
	}
}
//ͨѶ¼�е���ϵ���Ƿ������������ϵ�ˣ����У���ͨѶ¼�еĵڼ�����ϵ��
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
	//�Ҳ�����ϵ��
			return -1;
}
//��ѯָ����ϵ��
void SearchContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ��ѯ����ϵ������:>");
	scanf("%s",name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("���޴���");
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
//�޸���ϵ����Ϣ
void ModifyContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s",name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("������Ҫ�޸ĵ�����:>");
		scanf("%s",pc->data[pos].name);
		printf("������Ҫ�޸ĵ�����:>");
		scanf("%d", &(pc->data[pos].age));
		printf("������Ҫ�޸ĵ��Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("������Ҫ�޸ĵĵ绰:>");
		scanf("%s", pc->data[pos].tele);
		printf("������Ҫ�޸ĵĵ�ַ:>");
		scanf("%s", pc->data[pos].addr);
	}
}
//��ʾ���е���ϵ����Ϣ
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