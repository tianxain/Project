#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#define MAX_SIZE 100
#define NAME_LEN 20
#define TEL_LEN 20

enum SEX  //ö�ٶ����Ա�
{
	MAN,
	WOMAN
};


typedef struct AddressInfo //������Ϣ
{
	char _name[NAME_LEN];
	char _tel[TEL_LEN];
	int _age;
	enum SEX _sex;
}AddressInfo;


typedef struct AddressBook//ͨѶ¼
{
	AddressInfo _AIArray[MAX_SIZE];
	size_t _size;
}AddressBook;


void AddressBookInit(AddressBook *pBook);//��ʼ��ͨѶ¼
void PrintAddressBook(AddressBook *pBook);//��ӡͨѶ¼
void InputInfo(AddressInfo *pInfo);//����һ����ϵ����Ϣ
void PrintAddressInfo(AddressBook *pBook,AddressInfo *pInfo, size_t num);//��ӡ������Ϣ
void AddressBookAdd(AddressBook *pBook, AddressInfo *pInfo);//����ͨѶ¼��ϵ��
void AddressBookDelete(AddressBook *pBook,char *pDelInfo);//ɾ��ͨѶ¼��ϵ��
AddressInfo* AddressBookFind(AddressBook *pBook,char *pFinInfo);//����ͨѶ¼��ϵ��
AddressInfo* AddressBookModify(AddressBook *pBook, char *pName);//�޸�ͨѶ¼��ϵ����Ϣ