#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"

void AddressBookInit(AddressBook *pBook)//��ʼ��ͨѶ¼
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
void AddressBookAdd(AddressBook *pBook, AddressInfo *pInfo)//����ͨѶ¼��Ա
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

void AddressBookDelete(AddressBook *pAddressBook, char *pName);//ɾ��ͨѶ¼��Ա
AddressInfo* AddressBookFind(AddressBook *pAddressBook, char *pName);//����ͨѶ¼��Ա