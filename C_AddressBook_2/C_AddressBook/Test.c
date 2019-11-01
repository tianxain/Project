#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"
void PrintMenu()//打印菜单
{
	printf("**************************************************\n");
	printf("*               Address Book!                    *\n");
	printf("**************************************************\n");
	printf("*1.Add contact              ");
	printf("*2.Find contact      *\n");
	printf("*3.Delete contact           ");
	printf("*4.Edit contact      *\n");
	printf("*5.Show the address book    ");
	printf("*6.Exports from file *\n");
	printf("*7.Save                     ");
	printf("*8.Clear AddressBook *\n");
	printf("*0.exit                                          *\n");
	printf("**************************************************\n");
	printf("Please input your choose:");
}


int main()
{
	system("color 70");
	int operate = 0;//进行何种操作
	char NameOrTel[NAME_LEN];
	AddressInfo *pInfo;
	AddressInfo info = { "XXX","000",0,MAN };
	pInfo = &info;
	AddressBook addressBook;//声明一个通讯录
	AddressBookInit(&addressBook);//初始化通讯录
  
	do 
	{
		PrintMenu();
		scanf("%d", &operate);
		printf("\n");
		switch (operate)
		{
		case 0:
			break;
		case 1:
			InputInfo(pInfo);
			for (size_t i = 0; i < addressBook._size; i++)
			{
				if (strcmp(addressBook._AIArray[i]._tel, pInfo->_tel) == 0)
				{
					printf("This contact already exists！\n\n");
					
					goto BREAK;
					
				}
			}
			AddressBookAdd(&addressBook,pInfo);
			printf("\nSuccsessfully added!\n");
			printf("**************************************************\n");
			PrintAddressInfo(&addressBook,pInfo, (&addressBook)->_size-1);
			BREAK:break;
		case 2:
			printf("Please input the contact which you need to find:\n");
			scanf("%s", NameOrTel);
			AddressBookFind(&addressBook, NameOrTel);
			break;
		case 3:
			printf("Please input the contact which you need to delete:\n");
			scanf("%s", NameOrTel);
			AddressBookDelete(&addressBook, NameOrTel);
			PrintAddressBook(&addressBook);
			break;
		case 4:
			printf("Please input the contact which you need to  modify:\n");
			scanf("%s", NameOrTel);
			AddressBookModify(&addressBook, NameOrTel);
			break;
		case 5:
			PrintAddressBook(&addressBook);
			break;
		case 6:
			AddressBookLoad(&addressBook, "test.txt");
			break;
		case 7:
			AddressBookSave(&addressBook, "test.txt");
			printf("Succsessfully saved!\n");
			printf("**************************************************\n\n");
			break;
		case 8:
			AddressBookInit(&addressBook);
			printf("Succsessfully cleared!\n");
			printf("**************************************************\n\n");
			break;
		default:
			break;
		}
	} while (operate);
	return 0;
}