#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"

void test()
{
	AddressBook addressBook;
	AddressBookInit(&addressBook);

	AddressInfo *pInfo;
	AddressInfo info1= { "–°¿Ô","123456789",18,WOMAN };
	pInfo = &info1;
	AddressBookAdd(&addressBook,pInfo);

}
int main()
{
	test();
	return 0;
}