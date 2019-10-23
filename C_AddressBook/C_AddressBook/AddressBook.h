#pragma once
#include<stdio.h>
#include <assert.h>
#define MAX_SIZE 100

enum SEX  //枚举定义性别
{
	MAN,
	WOMAN
};


typedef struct AddressInfo //个人信息
{
	char _name[20];
	char _tel[20];
	int _age;
	enum SEX _sex;
}AddressInfo;


typedef struct AddressBook//通讯录
{
	AddressInfo _AIArray[MAX_SIZE];
	size_t _size;
}AddressBook;

void AddressBookInit(AddressBook *pBook);//初始化通讯录
void AddressBookAdd(AddressBook *pBook, AddressInfo *pInfo);//增加通讯录成员
void AddressBookDelete(AddressBook *pBook,char *pName);//删除通讯录成员
AddressInfo* AddressBookFind(AddressBook *pBook, char *pName);//查找通讯录成员