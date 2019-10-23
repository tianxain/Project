#pragma once
#include<stdio.h>
#include <assert.h>
#define MAX_SIZE 100

enum SEX  //ö�ٶ����Ա�
{
	MAN,
	WOMAN
};


typedef struct AddressInfo //������Ϣ
{
	char _name[20];
	char _tel[20];
	int _age;
	enum SEX _sex;
}AddressInfo;


typedef struct AddressBook//ͨѶ¼
{
	AddressInfo _AIArray[MAX_SIZE];
	size_t _size;
}AddressBook;

void AddressBookInit(AddressBook *pBook);//��ʼ��ͨѶ¼
void AddressBookAdd(AddressBook *pBook, AddressInfo *pInfo);//����ͨѶ¼��Ա
void AddressBookDelete(AddressBook *pBook,char *pName);//ɾ��ͨѶ¼��Ա
AddressInfo* AddressBookFind(AddressBook *pBook, char *pName);//����ͨѶ¼��Ա