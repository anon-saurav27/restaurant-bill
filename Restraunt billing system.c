#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void admin();
void reg();
void sys();
void insert_menu();
void add_menu();
void display_menu();
void edit_menu();
void del_menu();
void gen_bill();
void gen_billheader(char name[50],char date[30]);
void gen_billbody(int qty);
void gen_billfooter(float tot);


struct menu
{
	int item_no;
	char item_name[40];
	int item_price;
	
}m[1000];

struct item
{
	char item_uname[40];
	float price1;
}un[100];

int i,nmenu;

int main()
{
	int n,z;
	while (z!=3)
	{
	sys();
	printf("Select Who you are?:\n");
	printf("1. LogIn as Admin.\n");
	printf("2. Exit.\n\n");
	printf("Enter Choice: ");
	
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			admin();
			break;
		case 2:
			return(0);
			break;
		default:
			printf("             Please Select Following Choice only.            \n");
	}
	
	printf("\n                Press any key to continue \n");
	getch();
	}
}

void admin()
{
	int a,y,p;
	sys();
	printf("               Welcome To Admin LogIn Page                      \n");
	printf("              ------------------------------                    \n\n");
	char username[20],password[20];
	char uname[20],pass[20];
	char ch;
	FILE*fp;
	fp=fopen("login.txt","r+");
	if (fp==NULL)
	{
		printf("             Register As Admin                     \n");
		printf("           ---------------------               \n\n");
		reg();
		return;
	}
	fscanf(fp,"%s %s",username,password);
	printf("UserName:");
	scanf("%s",uname);
	printf("Password:");
	while(1)
	{
		ch=getch();
		if(ch==13)
		{
			pass[i]='\0';
			break;
		}
		else if(ch==8)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			pass[i]=ch;
			printf("*");
			i++;
		}
	}
	if (strcmp(username,uname)==0&&strcmp(password,pass)==0)
	{
		printf("\n\t\t......Logged In SuccessFull......");
		while(y!=8)
	{
	sys();
	printf("                        Welcome To Admin Page                      \n");
	printf("                       -----------------------                    \n\n");
	printf("Please Select The Following:\n");
	printf("____________________________\n");
	printf("1. Insert New Menu.\n");
	printf("2. Add Items on Menu.\n");
	printf("3. Display Menu.\n");
	printf("4. Edit Menu.\n");
	printf("5. Delete Menu.\n");
	printf("6. Genereate Bill.\n");
	printf("7. LogOut.\n\n");
	printf("Enter Choice: ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			sys();
			printf("                            Insert Menu                      \n");
			printf("                          ----------------                   \n\n");
			insert_menu();
			break;
		case 2:
			sys();
			printf("                           Add Items on Menu\n");
			printf("                          -------------------\n\n");
			add_menu();
		case 3:
		    sys();
			printf("                            Display Menu                      \n");
			printf("                          ----------------                   \n\n");
			display_menu();
			break;
		case 4:
			sys();
			printf("                           Edit Menu                 \n");
			printf("                         -------------                   \n\n");
			edit_menu();
			break;
		case 5:
			sys();
			printf("            		    	Delete Menu                      \n");
			printf("                           ---------------                  \n\n");
			del_menu();
			break;
		case 6:
			sys();
			printf("                          Generate Bill									\n");
			printf("                          ---------------                                   ");
			gen_bill();
			break;
		case 7:
			return;
			break;
		default:
			printf("                  Please Select The FOllowing Choices Only           \n");
			
	}
	printf("\n\n                     Press any key to continue      \n");
	getch();
	}//end of 2nd whil
	getch();
		
	}
	else
	{
		printf("\n\tEnter Valid username and password....\n");
		getch();
		return;
	}


	
}

void reg()
{
	sys();
		printf("             Register As Admin                     \n");
		printf("           ---------------------               \n\n");
	char uuname[40],pww[40],repww[40];
	FILE*fu;
	fu=fopen("login.txt","w+");
	fflush(stdin);
	printf("Enter UserName      : ");
	gets(uuname);
	fflush(stdin);
	printf("Enter NewPassword   : ");
	gets(pww);
	fflush(stdin);
	printf("ReEnter NewPassword : ");
	gets(repww);
	if (strcmp(pww,repww)==0)
	{
		fprintf(fu,"%s %s",uuname,pww);
		printf("\n  \t  ***Account Registered Successfully***\n");
	}
	else
	{
		printf("   \n\t.....Please Enter Same Password.....\n");
	}
	fclose(fu);
	
}



void sys()
{
	system("cls");
	printf("----------------------------------------------------------------\n");
	printf("                       Restaurant Billing System         \n");
	printf("----------------------------------------------------------------\n");
}

void insert_menu()
{
	FILE*fmenu,*fnmenu;
	fmenu=fopen("menu.txt","w+");
	if(fmenu==NULL)
	{
		printf("                 Menu File NOt Found...");
		return;
	}
	fnmenu=fopen("nmenu.txt","w+");
	if(fnmenu==NULL)
	{
		printf("                 No. of items in the menu NOt Found...");
		return;
	}
	printf("						Previous Menu:\n\n");
	display_menu();
	printf("\n                 Insert New Menu         \n");
	printf("Enter How many Items To Insert             :");
	scanf("%d",&nmenu);
	fprintf(fnmenu,"%d",nmenu);
	for(i=0;i<nmenu;i++)
	{
		fflush(stdin);
		printf("Enter The Name of Item No.%d                : ",i+1);
		gets(m[i].item_name);
		printf("Enter The Price of Item No.%d               : ",i+1);
		scanf("%d",&m[i].item_price);
		fwrite(&m[i],sizeof(m[i]),1,fmenu);
	}
	printf("\n\t\t....Menu Inserted Successfully.....\n");
	getch();
	fclose(fmenu);
	fclose(fnmenu);
	display_menu();
}

void add_menu()
{
	int mmenu,p;
	FILE*fmenu,*fnmenu;
	fmenu=fopen("menu.txt","a+");
	if(fmenu==NULL)
	{
		printf("                 Menu File NOt Found...");
		return;
	}
	printf("						Previous Menu:\n\n");
	display_menu();
	printf("\n                 Add Menu Items         \n");
	printf("                  ----------------\n\n");
	printf("Enter How many Items To Add                : ");
	scanf("%d",&mmenu);
	
	
	fnmenu=fopen("nmenu.txt","w+");
	if(fnmenu==NULL)
	{
		printf("                 No. of items in the menu NOt Found...");
		return;
	}
	
	for(i=0;i<mmenu;i++)
	{
		fflush(stdin);
		printf("Enter The Name of Item No.%d                : ",i+1);
		gets(m[i].item_name);
		printf("Enter The Price of Item No.%d               : ",i+1);
		scanf("%d",&m[i].item_price);
		fwrite(&m[i],sizeof(m[i]),1,fmenu);
	}

	printf("\n\t\t....Item Added Successfully.....\n");
	fprintf(fnmenu,"%d",nmenu+mmenu);
	getch();
	
	fclose(fmenu);
	fclose(fnmenu);
	display_menu();
}void display_menu()
{
	int menunum, itn=1;
    sys();
	FILE*fmenu,*fnmenu;
	fmenu=fopen("menu.txt","r+");
	if(fmenu==NULL)
	{
		printf("Menu FIle Not Found.");
		return ;
	}
	fnmenu=fopen("nmenu.txt","r+");
	if(fnmenu==NULL)
	{
		printf("                 No. of items in the menu NOt Found...");
		return;
	}
	fscanf(fnmenu,"%d",&menunum);
	printf("Our Restaurant Menu:\n\n");
	printf("Item No\t\tItem Name\tPrice\n");
    
    while(fread(&m[i],sizeof(m[i]),1,fmenu)==1)
	{
		printf("%d\t\t%s\t\tRs.%d\n",itn,m[i].item_name,m[i].item_price);
		itn++;
	}
	fclose(fnmenu);
	fclose(fmenu);
}//end of display menu function.............

void edit_menu()//starting of edit menu function..........
{
	int flag=0,itn=1;
	char item_nam[40];
	FILE*fmenu;
	fmenu=fopen("menu.txt","r+");
	if(fmenu==NULL)
	{
		printf("Menu File Not Found.");
		return;
	}
	printf("	                  	Our Menu		\n");
	printf("                       -----------\n\n");
	display_menu();
	printf("\nEnter Item Name. Which you want to Edit                 :");
	fflush(stdin);
	gets(item_nam);
	printf("\nPreviously Stored Record of Item %s is: \n",item_nam);
	printf("\t\t--------------------------------------------\n\n");
	while(fread(&m[0],sizeof(m[0]),1,fmenu)>0&&flag==0)
	{
	if(strcmp(m[0].item_name,item_nam)==0)
	{
			flag=1;
			printf("\n\t\tTo Edit Menu\n");
  			printf("\t\t-----------\n");
			printf("\t\tItem Name\tPrice\n");
			printf("\t\t%s\t\tRs.%d\t\t\n",m[0].item_name, m[0].item_price);
			itn++;
  			
			fflush(stdin);
			printf("\nEnter Item Name to Update                    : ");
			gets(m[0].item_name);
			printf("ENter Item Price to Update                   : ");
			scanf("%d",&m[0].item_price);
			fseek(fmenu,-(long)sizeof(m[0]),1);
			fwrite(&m[0],sizeof(m[0]),1,fmenu);
			printf("\t......Menu Updated Successfully.......");
			getch();
			fclose(fmenu);
	}	
	else
	{
		printf("\t\t******No Such Item No Found******");
	}
	display_menu();
	}
}//end of Edit menu......

void del_menu()//starting of delete menu function......
{
	char item_nam[40];
    int flag=0;
	FILE*fmenu,*fdmenu;
	fmenu=fopen("menu.txt","r+");
	{
		if(fmenu==NULL)
		printf("\n\t\t******Error: cannot find menu file!!!******");
	}
	printf("\n\t---Previous Stored Menu---");
	display_menu();
	printf("\n\nEnter Item Name which you want do delete                    :");
	scanf("%s",&item_nam);
	fdmenu=fopen("menu1.txt","a+");
	while(fread(&m[0],sizeof(m[0]),1,fmenu)==1)
	{
		if(strcmp(m[0].item_name,item_nam)!=0)
		{
			fwrite(&m[0],sizeof(m[0]),1,fdmenu);
		}
		else
		flag=1;
	}
	if(flag==0)
	{
		printf("\n\n\t\t******No such Record Found!!!******");
	}
	fclose(fmenu);
	fclose(fdmenu);
	remove("menu.txt");
	rename("menu1.txt","menu.txt");
	printf("\n\t\t******Record Delete sucessfully******\n");
	getch();
	display_menu();
}
void gen_bill()
{
	time_t currentTime;
    struct tm *localTime;
    char date[100];
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    strftime(date, sizeof(date), "%Y-%m-%d", localTime);
    
	char ch;
	int flag=0;
	int num,item_quantity[100],total=0,price[100],item_total[100];
	char name[40];
	display_menu();
	fflush(stdin);
	printf("---------------------------------------------------------------");
	printf("\nENter Name of Customer                          : ");
	gets(name);
	printf("\nENter How many Items You Want to Order          : ");
	scanf("%d",&num);
	printf("\n\t\tEnter Order\n");
	printf("\t\t------------\n\n");
	for(i=0;i<num;i++)
	{
	printf("\nEnter Item name                               : ");
	scanf("%s",&un[i].item_uname);
	printf("Enter How many quantity You want To Order       : ");
	scanf("%d",&item_quantity[i]); 
	}
	FILE*fmenu;
	fmenu=fopen("menu.txt","r+");
	if(fmenu==NULL)
	{
		printf("\n\t\t******Error: Cannot Open the file!!!******");
		return;
	}

	while(fread(&m[0],sizeof(m[0]),1,fmenu)>0)
	{
	
	for(i=0;i<num;i++)
	{
		if(strcmp(un[i].item_uname,m[0].item_name)==0)
		{
			//req item name= menu item name
			un[i].price1=m[0].item_price;
			price[i]=m[0].item_price;
			total=total+(price[i]*item_quantity[i]);
			
		}	
   	} 	
    }
    if (flag==1)
		{
			printf("\t\t******Item No Not Found******");	
		}
	sys();
	
	gen_billheader(name,date);
    for( i=0;i<num;i++)
	{
        gen_billbody(item_quantity[i]);
    }
    gen_billfooter(total);
	fclose(fmenu);
}

void gen_billheader(char name[50],char date[30])
{
    printf("\n\n");
        printf("\t              Restaurant Name    ");
        printf("\n\t           -----------------");
        printf("\n\nDate:%s",date);
        printf("\nBill To: %s",name);
        printf("\n");
        printf("----------------------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t");
        printf("Price\t\t");
        printf("Total\t\t");
        printf("\n----------------------------------------------------");
        printf("\n\n");
}

void gen_billbody(int qty)
{
    printf("%s\t\t",un[i].item_uname); 
        printf("%d\t",qty); 
        printf("Rs.%.2f\t",un[i].price1);
        printf("Rs.%0.2f\t\t",qty*un[i].price1); 
        printf("\n");
}

void gen_billfooter(float tot)
{
    printf("\n");
    float dis = 0.1*tot;
    float netTotal=tot-dis;
    float vat=0.13*netTotal,grandTotal=netTotal + vat;//netTotal + vat
    printf("---------------------------------------------------\n");
    printf("Sub Total\t\t\t\tRs.%.2f",tot);
    printf("\nDiscount @10%s\t\t\t\tRs.%.2f","%",dis);
    printf("\n\t\t\t\t\t----------");
    printf("\nNet Total\t\t\t\tRs.%.2f",netTotal);
    printf("\nVAT @13%s\t\t\t\tRs.%.2f","%",vat);
    printf("\n---------------------------------------------------");
    printf("\nGrand Total\t\t\t\tRs.%.2f",grandTotal);
    printf("\n---------------------------------------------------\n");
}



