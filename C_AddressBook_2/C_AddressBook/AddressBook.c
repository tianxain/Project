#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"

void AddressBookInit(AddressBook *pBook)//初始化通讯录
{
	assert(pBook);
	pBook->_size = 0;
	pBook->_capacity = 2;
	pBook->_AIArray= (AddressInfo*)malloc(sizeof(AddressInfo) * 2);
	assert(pBook->_AIArray);
}

void InputInfo(AddressInfo *pInfo)//输入一个联系人信息
{
	printf("Information:\n");
	printf("**************************************************\n");
	printf("Please input the Name:");
	scanf("%s", pInfo->_name);
	printf("Please input the Tel:");
	scanf("%s", pInfo->_tel);
	printf("Please input the Age:");
	do
	{
		scanf("%d", &pInfo->_age);
		if (pInfo->_age < 0)
		{
			printf("  Input errors, please input again:");
		}
	} while (pInfo->_age < 0);
	printf("Please input the Sex:");
	do
	{
		scanf("%d", &pInfo->_sex);
		if (pInfo->_sex != 0 && pInfo->_sex != 1)
		{
			printf("  Input errors, please input again:");
		}
	} while (pInfo->_sex != 0 && pInfo->_sex != 1);
	printf("**************************************************\n");
}

void PrintAddressInfo(AddressBook *pBook,AddressInfo *pInfo, size_t num)//打印个人信息
{
	assert(pBook);
	assert(pInfo);

	if (num <= pBook->_size)
	{
		
		printf("CONTACT%d：\n", num + 1);
		printf("NAME：%s\n", pBook->_AIArray[num]._name);
		printf("TELE：%s\n", pBook->_AIArray[num]._tel);
		printf("AGE：%d\n", pBook->_AIArray[num]._age);
		if (pBook->_AIArray[num]._sex == 0)
		{
			printf("SEX：%s\n", "MAN");
		}
		else {
			printf("SEX：%s\n", "WOMAN");
		}
		printf("\n");
	}
	else {
		printf("error!\n");
	}
	
}

void PrintAddressBook(AddressBook *pBook)//打印通讯录
{
	assert(pBook);
	if (pBook->_size == 0)
	{
		printf("AddressBook is empty!\n");
		printf("**************************************************\n");
	}

	size_t i = 0;
	for (i = 0; i < pBook->_size; i++)
	{
		PrintAddressInfo(pBook, &pBook->_AIArray[i], i);
	}
}

void AddressBookAdd(AddressBook *pBook, AddressInfo *pInfo)//增加通讯录成员
{
	assert(pBook);
	assert(pInfo);

	if (pBook->_capacity == pBook->_size)
	{
		// 空间满了，进行扩容
		pBook->_AIArray = realloc(pBook->_AIArray,pBook->_capacity*2*sizeof(AddressInfo));
		pBook->_capacity *= 2;
	}
		strcpy(pBook->_AIArray[pBook->_size]._name, pInfo->_name);
		strcpy(pBook->_AIArray[pBook->_size]._tel, pInfo->_tel);
		pBook->_AIArray[pBook->_size]._age = pInfo->_age;
		pBook->_AIArray[pBook->_size]._sex = pInfo->_sex;
		pBook->_size++;
		//printf("\nSuccsessfully added!\n");
		//printf("**************************************************\n");
}


AddressInfo* AddressBookFind(AddressBook *pBook, char *pFinInfo)//查找通讯录联系人
{
	assert(pBook);
	assert(pFinInfo);

	size_t i = 0;
	size_t j = 0;

	int ret_Name = 2;//名字查找结果
	int ret_Tel = 2;//电话号码查找结果

	for (i = 0; i < pBook->_size; i++)
	{
		ret_Name = strcmp(pBook->_AIArray[i]._name, pFinInfo);
		if (0 == ret_Name)
		{
			printf("\nSuccsessfully found!\n");
			printf("**************************************************\n");
			PrintAddressInfo(pBook, &pBook->_AIArray[i], i);
			return &pBook->_AIArray[i];
		}
		ret_Tel = strcmp(pBook->_AIArray[i]._tel, pFinInfo);
		if (0 == ret_Tel)
		{
			printf("\nSuccsessfully found!\n");
			printf("**************************************************\n");
			PrintAddressInfo(pBook, &pBook->_AIArray[i], i);
			return &pBook->_AIArray[i];
		}
	}
	return NULL;
}

void AddressBookDelete(AddressBook *pBook, char *pDelInfo)//删除通讯录成员
{
	assert(pBook);
	assert(pDelInfo);

	size_t i = 0;
	size_t j = 0;
	int flag = pBook->_size;
	int ret_Name = 2;//名字查找结果
	int ret_Tel = 2;//电话号码查找结果

	for (i = 0; i < pBook->_size; i++)
	{
		ret_Name = strcmp(pBook->_AIArray[i]._name, pDelInfo);
		ret_Tel = strcmp(pBook->_AIArray[i]._tel, pDelInfo);
		if (0 == ret_Name|| 0 == ret_Tel)
		{
			for (j = i; j < pBook->_size - 1; j++)
			{
				memmove(&pBook->_AIArray[j], &pBook->_AIArray[j + 1], sizeof(AddressInfo));
			}
			pBook->_size--;
			i--;
			printf("\nSuccsessfully delete!\n\n");
			printf("**************************************************\n");
		}
	}
	if (flag == pBook->_size)
	{
		printf("\nNo such contact！\n\n");
	}
}

AddressInfo* AddressBookModify(AddressBook *pBook, char *pModInfo)//修改通讯录成员信息
{
	AddressInfo *findResult = AddressBookFind(pBook, pModInfo);
	if (NULL == findResult)
	{
		printf("\nNo such contact！\n\n");
		return NULL;
	}
	else {
			int i_modify = 0;
			char newName[NAME_LEN] = "XXX";
			char newTel[TEL_LEN] = "000";
			int newAge = 0;
			enum SEX newSex = MAN;
			do 
			{		
				printf("\nWhat are you need to modify?\n");
				printf("**************************************************\n");
				printf("*1.Name               ");
				printf("2.Telephone                *\n");
				printf("*3.age                ");
				printf("4.sex                      *\n"); 
				printf("*0.exit                                          *\n");
				printf("**************************************************\n");
				printf("Please input your choose:");
				scanf("%d", &i_modify);
				switch (i_modify)
				{
				case 0:
					break;
				case 1:
					printf("Please input the newName:");
					scanf("%s", newName);
					strcpy(findResult->_name, newName);
					break;
				case 2:
					printf("Please input the newTel:");
					scanf("%s", newTel);
					strcpy(findResult->_tel, newTel);
					break;
				case 3:
					printf("Please input the newAge:");
					do
					{
						scanf("%d", &newAge);
						if (newAge < 0)
						{
							printf("  Input errors, please input again:");
						}
					} while (newAge < 0);
					findResult->_age = newAge;				
					break;
				case 4:
					printf("Please input the newSex（0:M/1:W）:");
					do
					{
						scanf("%d", &newSex);
						if (newSex != 0 && newSex != 1)
						{
							printf("  Input errors, please input again:");
						}
					} while (newSex != 0 && newSex != 1);
					findResult->_sex = newSex;
				case 5:
					return findResult;
				default:
					break;
				}
			} while (i_modify);		
	}
	return findResult;
}

void AddressBookSave(AddressBook* pBook, const char* filename)//将通讯录写入文件
{
	assert(pBook);

	FILE *pFile = fopen(filename,"w");
	for (size_t i = 0; i < pBook->_size; i++)
	{
		fprintf(pFile, "%s\n%s\n%d\n%d\n",pBook->_AIArray[i]._name, pBook->_AIArray[i]._tel, pBook->_AIArray[i]._age, pBook->_AIArray[i]._sex);
	}
	AddressInfo endInfo = { "XXX","000",-1,MAN };
	fprintf(pFile, "%s\n%s\n%d\n%d", endInfo._name, endInfo._tel, endInfo._age, endInfo._sex);
	fclose(pFile);
}

void AddressBookLoad(AddressBook* pBook, const char* filename)//从文件读出联系人
{
	assert(pBook);

	FILE *pFile = fopen(filename, "r");
	AddressInfo tempInfo;
	int count = 0;
	while (1)
	{
		fscanf(pFile,&tempInfo,sizeof(AddressInfo),1,pFile);
		fscanf(pFile, "%s %s %d %d", tempInfo._name, tempInfo._tel, &tempInfo._age, &tempInfo._sex);
		if (tempInfo._age == -1)
		{
			fclose(pFile);
			break;
		}
		else {
			AddressBookAdd(pBook,&tempInfo);
			count++;
		}
	}
	printf("%d contacts was succsessfully exported!\n",count);
	printf("**************************************************\n\n");
}
