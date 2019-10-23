#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"

void AddressBookInit(AddressBook *pBook)//初始化通讯录
{
	assert(pBook);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		strcpy(pBook->_AIArray[i]._name,"XXX");
		strcpy(pBook->_AIArray[i]._tel,"000");
		pBook->_AIArray[i]._sex=MAN;
		pBook->_AIArray[i]._age=0;
	}
	pBook->_size = 0;
}
void AddressBookAdd(AddressBook *pBook, AddressInfo *pInfo)//增加通讯录成员
{
	assert(pBook);
	assert(pInfo);

	if (100 == pBook->_size)
	{
		printf("AddressBook if full!");
	}
	else
	{
		strcpy(pBook->_AIArray[pBook->_size]._name, pInfo->_name);
		strcpy(pBook->_AIArray[pBook->_size]._tel, pInfo->_tel);
		pBook->_AIArray[pBook->_size]._age = pInfo->_age;
		pBook->_AIArray[pBook->_size]._sex = pInfo->_sex;
		pBook->_size++;
	}

}

void AddressBookDelete(AddressBook *pAddressBook, char *pName);//删除通讯录成员
AddressInfo* AddressBookFind(AddressBook *pAddressBook, char *pName);//查找通讯录成员