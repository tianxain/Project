#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#define NAME_LEN 20
#define TEL_LEN 20

enum SEX  //枚举定义性别
{
	MAN,
	WOMAN
};


typedef struct AddressInfo //个人信息
{
	char _name[NAME_LEN];
	char _tel[TEL_LEN];
	int _age;
	enum SEX _sex;
}AddressInfo;


typedef struct AddressBook//通讯录
{
	AddressInfo *_AIArray;
	size_t _size;//有效数据个数
	size_t _capacity;//容量
}AddressBook;


void AddressBookInit(AddressBook *pBook);//初始化通讯录
void PrintAddressBook(AddressBook *pBook);//打印通讯录
void InputInfo(AddressInfo *pInfo);//输入一个联系人信息
void PrintAddressInfo(AddressBook *pBook,AddressInfo *pInfo, size_t num);//打印个人信息
void AddressBookAdd(AddressBook *pBook, AddressInfo *pInfo);//增加通讯录联系人
void AddressBookDelete(AddressBook *pBook,char *pDelInfo);//删除通讯录联系人
AddressInfo* AddressBookFind(AddressBook *pBook,char *pFinInfo);//查找通讯录联系人
AddressInfo* AddressBookModify(AddressBook *pBook, char *pName);//修改通讯录联系人信息
void AddressBookSave(AddressBook* pBook, const char* filename);//将通讯录整个写入文件
void AddressBookLoad(AddressBook* pBook, const char* filename);//从文件读出所有联系人