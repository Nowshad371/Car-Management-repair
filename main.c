
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

int option, element, placefound;
char Name[30];
void invoice();
void input();
void menu();
void view_record();
void insertion();
void Servicenormal();
void Serviceurgent();
void display();
typedef struct tm tm;time_t currentTime;/*tm *myTime = localtime(&currentTime),time(&currentTime),;*/

struct node
{
	int data;

    char name[30];
	struct node* next;
}*newnode, * START = NULL,*head=NULL,* prev, * temp, * tmpdisplay;


struct customer{

    char c_name[100];
    char car_reg_no[15];
    int service_no;
    char service_type[10];


}c;struct customer *r = &c;

void gotoxy(int x, int y){

    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);



}

int main()
{

    int choice = 0;
    char ch;
    while(choice != 6){
    system("cls");
    gotoxy(50,2);printf("WELCOME TO FAST TRACK CAR MANAGEMENT SYSTEM");
    gotoxy(40,4);printf("-----------------------------------------------------------------");
    gotoxy(40,6);printf("-----------------------------------------------------------------");
    gotoxy(44,8);printf("\t\t1.PRESS 1 TO SEE MENU\n");
    gotoxy(44,10);printf("\t\t2.PRESS 2 TO SELECT SERVICE\n");
    gotoxy(44,12);printf("\t\t3.press 3 TO TO SEE CURRENT SERVICE\n");
    gotoxy(44,14);printf("\t\t4.PRESS 4 TO QUEUE CUT URGENT SERVICE\n");
    gotoxy(44,16);printf("\t\t5.PRESS 5 TO VIEW WHOLE RECORD\n");
    gotoxy(44,18);printf("\t\t6.PRESS 6 TO EXIT\n");
    gotoxy(44,20);printf("\t\tENTER YOUR OPTION: ");
    scanf("%d",&choice);


    if (choice == 1){
        menu();
    }
    else if (choice ==2){


        input();
        }

    else if(choice ==3){
        display();

        }
    else if(choice==4){
         Serviceurgent();
        }
    else if(choice==5){
        view_record();
        }
    else{
    gotoxy(44,30);printf("\t\tTHANK YOU FOR COMING");
    gets(ch);}







}


}
void menu(){
    system("cls");
    char ch;





    gotoxy(60,2);printf("welcome to car service");
    gotoxy(40,4);printf("-----------------------------------------------------------");
    gotoxy(30,8);printf("service number \t\tservice type\t\tTime Needed(minutes)\tService fee");
    gotoxy(30,10);printf("\t\t\t\t\t\t\t\t\t\t\\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tNormal\t\tUrgent");

    gotoxy(30,14);printf("\t1\t\tRepair punctured car tyre/piece\t\t10min\t\tRM5\t\tRM6");
    gotoxy(30,16);printf("\t2\t\tCar tyre change / piece\t\t\t15min\t\tRM150\t\tRM160");
    gotoxy(30,18);printf("\t3\t\tMineral Oil Change\t\t\t20min\t\tRM80\t\tRM90");
    gotoxy(30,20);printf("\t4\t\tSynthetic Oil Change\t\t\t20min\t\tRM130\t\tRM140");
    gotoxy(30,22);printf("\t5\t\tBattery Change\t\t\t\t5min\t\tRM200\t\tRM210");
    gotoxy(30,24);printf("\t6\t\tHead light bulb change / piece\t\t5min\t\tRM6\t\tRM8");
    gotoxy(30,26);printf("\t7\t\tTaillight bulb change / piece \t\t5min\t\tRM6\t\tRM8");
    gotoxy(30,28);printf("\t8\t\tcar wash \t\t\t\t10min\t\tRM10\t\tRM12");
    gotoxy(60,32);printf("press any key to continue");

    scanf("%c",&ch);
    getch();


}



void input(){

    system("cls");
    char ch;
    time(&currentTime);
    tm *myTime = localtime(&currentTime);


    newnode = (struct node*) malloc(sizeof(struct node));


    printf("No\tservice type\t\t\t\tTime Needed(minutes)\tService fee");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tNormal\t\tUrgent");

    printf("\n 1. Repair punctured car tyre/piece \t\t10min\t\t \tRM5 \t\tRM6");
    printf("\n 2. Car tyre change / piece \t\t\t15min \t\t\tRM150 \t\tRM160");
    printf("\n 3. Mineral oil change \t\t\t\t20min \t\t\tRM80 \t\tRM90");
    printf("\n 4. Synthetic oil change \t\t\t20min \t\t\tRM130 \t\tRM140");
    printf("\n 5. Battery change \t\t\t\t5min \t\t\tRM200\t\tRM210");
    printf("\n 6. Head light bulb change/ piece \t\t5min\t\t\tRM6\t\tRM8");
    printf("\n 7. Taillight bulb change/ piece \t\t5min \t\t\tRM6 \t\tRM8");
    printf("\n 8. Car Wash \t\t\t\t\t10min\t\t\tRM10\t\tRM12\n\n");

    FILE *fp =fopen("SERVICE.text","a");

    printf("Enter your Name: ");
    scanf("%s",r->c_name);
    printf("Enter car_registration no: ");
    scanf("%s",r->car_reg_no);
    int normal[9] ={0,5,150,80,130,200,6,6,10};
    int urgent[9]={0,6,160,90,140,210,8,8,12};
    printf("Enter service type(urgent/normal): ");
    scanf("%s",r->service_type);
    char str1[] = "normal";
    int d = strcmp(str1,r->service_type);

    if (d==0)

        {
        printf("Enter service number: ");
        scanf("%d",&r->service_no);
        printf("Enter ID Number:");
        scanf("%d", &element);
        printf("Enter Last Name:");
        scanf("%s", &Name);
        newnode->data = element;
        strcpy(newnode->name,Name);


        if (START == NULL) {
            START = newnode;
            START->next = NULL;
        }
        else {
            temp = START;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            temp->next->next = NULL;
        }
        static int a = 1;

        fprintf(fp,"\ninvoice number: %d",a);



        gotoxy(62,28);printf("\t\t  INVOICE");
        gotoxy(62,30);printf("FAST TRACK CAR SERVICE MAGAEMENT SYSTEM");
        gotoxy(26,32);printf("--------------------------------------------------------------------------------------------------------------------------");
        gotoxy(26,34);printf("invoice number\tcustomer_Name\tservice number\tregistration_NO\t\tservice type\tservice date(m/d/y)\tService fee");
        gotoxy(26,36);printf("--------------------------------------------------------------------------------------------------------------------------");
        gotoxy(26,38);printf("\t%d\t\t%s\t\t\t%d\t%s\t\t\t%s\t\t%i/%i/%i\t\tRM%d",a,r->c_name,r->service_no,r->car_reg_no,r->service_type,myTime->tm_mon +1,myTime->tm_yday,myTime->tm_year + 1900,normal[r->service_no]);


        fprintf(fp,"\nname: %s\nservice_Date(mm/day/yyyy): %i/%i/%i\ncar_registration number: %s\nservice type: %s\nservice number: %d\nservice fee %d\n\n",r->c_name,myTime->tm_mon +1,myTime->tm_yday,myTime->tm_year + 1900,r->car_reg_no,r->service_type,r->service_no,normal[r->service_no]);
        a++;

        }
    else {
        printf("Enter Service Number: ");
        scanf("%d",&r->service_no);
        printf("Enter ID Number:");
        scanf("%d", &element);
        printf("Enter Last Name:");
        scanf("%s", &Name);
        newnode->data = element;
        strcpy(newnode->name,Name);


        if (head == NULL) {
            head = newnode;
            head->next = NULL;
        }
        else {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            temp->next->next = NULL;
        }

        static int b = 1;
        fprintf(fp,"\ninvoice number %d",b);
        gotoxy(62,28);printf("\t\t  INVOICE");
        gotoxy(62,30);printf("FAST TRACK CAR SERVICE MAGAEMENT SYSTEM");
        gotoxy(26,32);printf("--------------------------------------------------------------------------------------------------------------------------");
        gotoxy(26,34);printf("invoice number\tcustomer_Name\tservice number\tregistration_NO\t\tservice type\tservice date(m/d/y)\tService fee");
        gotoxy(26,36);printf("--------------------------------------------------------------------------------------------------------------------------");
        gotoxy(26,38);printf("\t%d\t\t%s\t\t\t%d\t%s\t\t\t%s\t\t%i/%i/%i\t\tRM%d",b,r->c_name,r->service_no,r->car_reg_no,r->service_type,myTime->tm_mon +1,myTime->tm_yday,myTime->tm_year + 1900,urgent[r->service_no]);


        b++;


        fprintf(fp,"\nname: %s\nservice_Date(mm/day/yyyy): %i/%i/%i\ncar_registration number: %s\nservice type: %s\nservice number: %d\nservice fee %d\n",r->c_name,myTime->tm_mon +1,myTime->tm_yday,myTime->tm_year + 1900,r->car_reg_no,r->service_type,r->service_no,urgent[r->service_no]);

    }









    gotoxy(62,46);printf("\t\tTHANK YOU FOR COMING");
    gotoxy(62,48);printf("\t\tPRESS ANY KEY TO CONTINUE");
    gotoxy(62,50);printf("------------------------------------------");
    fclose(fp);

    scanf("%c",&ch);

    getch();


}

void view_record(){


    system("cls");
    char ch;


    FILE *fp =fopen("SERVICE.text","r");
    if(fp ==NULL){
        printf("file does not exit");


    }
    else{
        printf("FILE IS OPENED\n");
        while(!feof(fp)){

        ch = fgetc(fp);
        printf("%c",ch);

        }

        fclose(fp);


    }


    scanf("%c",&ch);

    getch();


}

void Serviceurgent()
{
	if (head == NULL)
		printf("NO SERVICE IN THE LIST");
	else{
		temp = START;
		head = head->next;
		free(temp);
	}

}
void display()
{

    system("cls");
    char ch;
    printf("\n\n\nENTER SERVICE TYPE(normal/urgent): ");
    scanf("%s",r->service_type);
    char str1[] = "normal";
    int d = strcmp(str1,r->service_type);

    if (d==0){
	if (START == NULL){
		printf("\n\nNO SERVICE HAS BEEN INCLUDED");

	}
	else
	{
		tmpdisplay = START;
		printf("\nCURRRENT SERVICE NUMBER\n");
		while (tmpdisplay != NULL)
		{
			printf("\nID is: %d\t", tmpdisplay->data);
			printf("Last Name is: %s\n", tmpdisplay->name);

			tmpdisplay = tmpdisplay->next;
		}
	}
	scanf("%c",&ch);
    getch();
    }
	else{
        if (head == NULL){
		printf("\n\nNO SERVICE HAS BEEN INCLUDED");}
        else
        {
		tmpdisplay = head;
		printf("\nCURRRENT SERVICE NUMBER\n");
		while (tmpdisplay != NULL)
		{
			printf("\nID is: %d\t", tmpdisplay->data);
			printf("Last Name is: %s\n\n", tmpdisplay->name);

			tmpdisplay = tmpdisplay->next;
		}


        }

    }
    printf("\t\t\n\n-------------------------------");
    printf("\t\t\t\t\nTHANK YOU FOR COMING");
    printf("\t\t\t\nPRESS ANY KEY TO CONTINUE");
    printf("\t\t\n-------------------------------");
	scanf("%c",&ch);
    getch();

}



