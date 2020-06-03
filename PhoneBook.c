#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct person
{
	char name[35];
	char address[50];
	char father_name[35];
	char mother_name[35];
	long int mble_no;
	char sex[8];
	char mail[100];
	char citizion_no[20];
};

void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();

int main()
{
	system("color 0f");
	start();
	return 0;
}

void back()
{
	start();
}

void start()
{
	menu();
}

void menu()
{
	system("cls");
	printf("\t\t*****Welcome To PhoneBook*****");
	printf("\n\n\t\t\t MENU \t\t\n\n");
	printf("\t1.Add New	\t2.List	\t3.Exit	\n\t4.Modify	\t5.Search\t6.Delete");

	switch (_getch())
	{
	case '1':
		addrecord();
		break;
	case '2':
		listrecord();
		break;
	case '3':
		exit(0);
		break;
	case '4':
		modifyrecord();
		break;
	case '5':
		searchrecord();
		break;
	case '6':
		deleterecord();
		break;
	default:
		system("cls");
		printf("\nEnter 1 to 6 only");
		printf("\n Enter any key");
		_getch();
		menu();
	}
}

void addrecord()
{
	system("cls");
	FILE* fp;
	struct person p;
	fp = fopen("Project", "a+b");

	printf("\nEnter name: ");
	got(p.name);
	printf("\nEnter the address: ");
	got(p.address);
	printf("\nEnter father name: ");
	got(p.father_name);
	printf("\nEnter mother name: ");
	got(p.mother_name);
	printf("\nEnter phone no.:");
	scanf("%ld", &p.mble_no);
	printf("Enter sex:");
	got(p.sex);
	printf("\nEnter e-mail:");
	got(p.mail);
	printf("\nEnter citizen no:");
	got(p.citizion_no);
	fwrite(&p, sizeof(p), 1, fp);
	fflush(stdin);
	printf("\nRecord Saved");

	fclose(fp);

	printf("\nEnter any key");
	_getch();
	system("cls");
	menu();
}

void listrecord()
{
	struct person p;
	FILE* fp;
	fp = fopen("Project", "rb");
	if (fp == NULL)
	{
		printf("\nFile opening error in listing");
		exit(1);
	}
	
	while (fread(&p, sizeof(p), 1, fp) == 1)
	{
		printf("\n\n\n Your Record Is \n\n");
		printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizen no=%s", p.name, p.address, p.father_name, p.mother_name, p.mble_no, p.sex, p.mail, p.citizion_no);
		_getch();
		system("cls");
	}

	fclose(fp);
	printf("\nEnter Any Key");
	_getch();
	system("cls");
	menu();
}

void searchrecord()
{
	struct person p;
	FILE* fp;
	char name[100];
	fp = fopen("Project", "rb");
	if (fp == NULL)
	{
		printf("\n Error in Opening \n\n\n");
		exit(1);
	}
	printf("\nEnter name of person to search\n");
	got(name);
	while (fread(&p, sizeof(p), 1, fp) == 1)
	{
		if (strcmp(p.name, name) == 0)
		{
			printf("\n\t Detail Information About %s", name);
			printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitision no:%s", p.name, p.address, p.father_name, p.mother_name, p.mble_no, p.sex, p.mail, p.citizion_no);
		}
		else
		{
			printf("File Not Found");
		}
	}
	fclose(fp);
	printf("\nEnter Any Key");
	_getch();
	system("cls");
	menu();
}


void deleterecord()
{
	struct person p;
	FILE* fp, * ft;
	int flag;
	char name[100];
	fp = fopen("Project", "rb");
	if (fp == NULL)
	{
		printf("\nContact's data not added yet\r\n");
	}
	else
	{
		ft = fopen("temp", "wb+");
		if (ft == NULL)
		{
			printf("File opening error");
		}
		else
		{
			printf("\nEnter Contact's name: ");
			got(name);
			fflush(stdin);
			while (fread(&p, sizeof(p), 1, fp) == 1)
			{
				if (strcmp(p.name, name) != 0)
				{
					fwrite(&p, sizeof(p), 1, ft);
				}
				if (strcmp(p.name, name) == 0)
				{
					flag = 1;
				}
			}
			fclose(fp);
			fclose(ft);
			if (flag != 1)
			{
				printf("\nNo Contact's Record To Delete\r\n");
				remove("temp.txt");
			}
			else
			{
				remove("Project");
				rename("temp.txt", "Project");
				printf("\nRecord Deleted Successfully\r\n");
			}
		}
	}
	printf("\nEnter any key");
	_getch();
	system("cls");
	menu();
}

void modifyrecord()
{
	int c;
	FILE* fp;
	int flag = 0;
	struct person p, s;
	char name[50];
	fp = fopen("Project", "rb+");
	if (fp == NULL)
	{
		printf("\nContact's data not added yet\r\n");
		exit(1);
	}
	else
	{
		system("cls");
		printf("\nEnter Contact's name to modify:\n");
		got(name);
		while (fread(&p, sizeof(p), 1, fp) == 1)
		{
			if (strcmp(name, p.name) == 0)
			{
				printf("\n Enter name:");
				got(s.name);
				printf("\nEnter the address:");
				got(s.address);
				printf("\nEnter father name:");
				got(s.father_name);
				printf("\nEnter mother name:");
				got(s.mother_name);
				printf("\nEnter phone no:");
				scanf("%ld", &s.mble_no);
				printf("\nEnter sex:");
				got(s.sex);
				printf("\nEnter e-mail:");
				got(s.mail);
				printf("\nEnter citizen no\n");
				got(s.citizion_no);
				fseek(fp, sizeof(p), SEEK_CUR);
				fwrite(&s, sizeof(p), 1, fp);
				flag = 1;
				break;
			}
			fflush(stdin);
		}
		if (flag == 1)
		{
			printf("\n Your data is modified");
		}
		else
		{
			printf("\n Data is not found");
		}
		fclose(fp);
	}
	printf("\nEnter any key");
	_getch();
	system("cls");
	menu();
}

void got(char* name)
{
	int i = 0, j;
	char c, ch;
	do
	{
		c = _getch();
		if (c != 8 && c != 13)
		{
			*(name + i) = c;
			_putch(c);
			i++;
		}
		if (c == 8)
		{
			if (i > 0)
			{
				i--;
			}
			system("cls");
			for (j = 0; j < i; j++)
			{
				ch = *(name + j);
				_putch(ch);
			}
		}
	} while (c != 13);
	*(name + i) = '\0';
}