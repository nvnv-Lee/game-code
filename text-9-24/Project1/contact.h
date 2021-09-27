#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SZ 1000
#define MAX 1000

#define NAME_MAX 30
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
//����һ����ϵ�˵Ļ�����Ϣ
struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};
//����һ��ͨѶ¼
struct Contact
{
	struct PeoInfo* data;//�����ϵ�˵Ļ�����Ϣ
	int sz;//��ǰͨѶ¼������ϵ�˵ĸ���
	int capacity;//ͨѶ¼�ĵ�ǰ�������
};
//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);
//������ϵ��
void AddContact(struct Contact* pc);
//ɾ����ϵ��
void DelContact(struct Contact* pc);
//��ѯָ����ϵ��
void SearchContact(struct Contact* pc);
//�޸���ϵ����Ϣ
void ModifyContact(struct Contact* pc);
//��ʾ���е���ϵ����Ϣ
void ShowContact(struct Contact* pc);
