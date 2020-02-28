#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>

 FILE*pass;
  FILE*name;
  int i;
  int input;
    char user_name[30],password[30];      //variables for login........................
    char user_file[30],password_file[30];



 void main_menu(); //

int i;
//function for auto increment customer & supplier Id.
int getcust_id();
int getsupp_id();

//function for bill slip
void bill();
//function for about menu
void about();

//function for medicine menu
void medicine();
void medi_sale();
void stock();
void update_stock();
void medi_entry();
void medi_search();
void remainnder();
//function for customer menu
void customer();
void cust_entry();
void cust_list();
void cust_update();


//function for report menu
void report_menu();
void report();
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();

//function for supplier menu
void supplier();
void supp_entry();
void supp_list();
void sup_update();
void search();
void search_id();
void search_name();
struct supplier
{
	int supp_id;
	char supp_name[25];
	char city[20];
	char mob_no[15];
	char email[30];

};
struct supplier temp1;


struct bill     //for bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;
FILE *ptrbill;


struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
 };

struct medical temp;
struct medical x[20];
FILE *ptr;

char a[10];
struct customer
{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[15];
	char email[50];

};
struct customer temp_c;
FILE *ptr1;

struct sales_report
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;
FILE *ptrs_r;

struct purchase_report
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

struct profit_report
{
	char medi_id[6];
	char medir_name[20];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float unit;
	float profit;
};
struct profit_report pr_r;
FILE *ptrpr_r;


check()
{
    user_file[30]=0;
    password_file[30]=0;

    name=fopen("name.txt","r");           //File open.............
    pass=fopen("password.txt","r");       //File open.............

    fscanf(name,"%s",user_file);
    fscanf(pass,"%s",password_file);

    fclose(name);                         //File close............
    fclose(pass);                         //File close............

    if(strcmp(user_name,user_file)==0 && strcmp(password,password_file)==0)
    {
        welcome();
    }
    else
    {
        system("cls");
        MessageBoxW(NULL,L"User name or Password is Incorrect!\n\t   Try again.",L"Error!",MB_OK);
        ask();
    }
}
login_design()
{
 printf("\n\n\n\t\t\t\t\t::::::::::::::::::::::::::::::::::\n");
 printf("\t\t\t\t\t:::::::::::LOG IN:::::::::::::::::\n");
 printf("\t\t\t\t\t::::::::::::::::::::::::::::::::::\n\n\n");
}
ask()
{
    int ch=0,i=0;
    user_name[30]=0;
    password[30]=0;

    login_design();

    printf("\t\t\t\t\t\tEnter User Name: ");
    scanf("%s",user_name);
    printf("\t\t\t\t\t\tEnter Password: ");

    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            password[i]='\0';
            break;
        }
        else
        {
            password[i]=ch;
            printf("*");
            i++;
        }
    }
    check();
}





int main()
{



    system("cls");
    char un[30],p[30],new_name[30],new_pass[30];
    name=fopen("name.txt","r");           //File open.............
    pass=fopen("password.txt","r");       //File open.............

    fscanf(name,"%s",un);
    fscanf(pass,"%s",p);

    fclose(name);                         //File close............
    fclose(pass);                         //File close............

    if(strcmp(un,"\0")==0 || strcmp(p,"\0")==0)
    {
        printf("\n\n\n::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t:::::::::::LOG IN:::::::::::::::::\n");
        printf("\n\n::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\n\t\t\t\t\t\tSet User Name: ");
    scanf("%s",&new_name);
    printf("\t\t\t\t\t\tSet Password: ");
    scanf("%s",&new_pass);

    name=fopen("name.txt","w");           //File open.............
    pass=fopen("password.txt","w");       //File open.............

    fprintf(name,"%s",new_name);
    fprintf(pass,"%s",new_pass);

    fclose(name);                         //File Close............
    fclose(pass);
    system("cls");                         //File Close............

    welcome();
    }
    ask();
    system("cls");

     main_menu();


}
//=========================getsupp_id =======================
int getsupp_id()
{

 FILE *fp;
	 fp=fopen("supplier.dat","r");
	 if(fp==NULL)
	 {

		printf("\nData not Found.....");
		getch();
	 }
	 else
	 {
		temp1.supp_id=100;
		rewind(fp);
		while(fscanf(fp,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.city, temp1.mob_no,temp1.email)!=EOF)
		{
		}
	 }
	 fclose(fp);
	 return temp1.supp_id+1;
}


int t(void)
{


    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );


	//printf("\t\t\t\t\t\t\t\t\t\t\t\t\tDate: %d-%d-%d\n",now->tm_mday,now->tm_mon,now->tm_year);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tTime: %d:%d:%d\n\n",now->tm_hour, now->tm_min,now->tm_sec);
	return 0;
}

void ventry(char t[],int code)
{
  int i=0;
	if(code==0)
	{
		while((t[i]=getch())!='\r' && i<30)
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==1)
	{
		while((t[i]=getch())!='\r' && i<10 )
		if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==2)
	{
		while((t[i]=getch())!='\r' && i<30 )
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}

	t[i]='\0';
}



int getcust_id()
{
 FILE *fp;
	 fp=fopen("customer.dat","r");
	 if(fp==NULL)
	 {

		printf("\nData not Found.....\n");
		getch();
	 }
	 else
	 {
		temp_c.cust_id=100;
		rewind(fp);
		while(fscanf(fp,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
		{
		}
	 }
	 fclose(fp);
	 return temp_c.cust_id+1;
}

void welcome()
{
     printf("\n\n\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
             		printf("\t\t\t\t:::::::::::Welcome To THE BEST Medical Store::::::::::::::::::\n");
             		printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n\n");
}

void main_menu()
{



  char ch;

	do
	{

		system("cls");


             t();
                    printf("\n\n\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
             		printf("\t\t\t\t:::::::::::Welcome To THE BEST Medical Store::::::::::::\n");
             		printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n\n");

		printf("\tS. Supplier \n");

		printf("\tC. Customer \n");

        printf("\tM. Medicine\n");

        printf("\tB. Bill\n");
       // printf("\tR.  Report \n");

		printf("\tA. About\n");

		printf("\tE. Exit\n\n");








		printf("\n\n\n\tpress First Character for further Menu :::   ");

		ch=toupper(getche());
		switch(ch)
		{
			case 'S':supplier();
				 break;
			case 'C':customer();
				 break;
			case 'M':medicine();
				 break;
				// case'R':
               // report_menu();
				// break;

			case 'B':bill();
				 break;
			case 'A':about();
				 break;
			case 'E':

			printf("\n\n\tDo you want to exit now? Y/N :");
			Sleep(100);
			ch=(getche());
			ch=toupper(ch);
			if(ch=='Y')
			{

				system("cls");

				printf(" \n\n\n\n\n\t\t\t\tPlease wait.....\n\n\t\t\t");
				Sleep(2000);
				exit(0);
			}
			else
			{
				main_menu();
			}

			default:

			printf("\nPlese Enter right character ONLY (S,C,M,R,B,A).");
			getch();
		}
	}while(ch!='E');
}
  //customer list
void customer()
{
	char ch;
	do
	{
	  system("cls");
	  t();


	  printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== CUSTOMER MENU ======\n");
	   printf("\t\t\t===========================================\n\n\n");


	  printf("E.  Add New Customer\n");


	  //printf("U.  Update Customer\n");


	  printf("L.  List of Existing Customer\n");

	  printf("M.  Main Menu\n\n");

	  printf("Press First Character for further Operations :  ");


	  ch=toupper(getche());
	  switch(ch)
	  {
		case 'E':
			 cust_entry();
			 break;
		//case 'U':
			// cust_update();
			// break;
		case 'L':
			 cust_list();
			 break;

		case 'M':main_menu();
			 break;
		default:

			printf("Plese Enter right character ONLY (E,L,U,M).");
			getch();
	  }
	}while(ch!='M');

}

void cust_entry()
{
 char ch;
 int id;
 FILE *fp;
 system("cls");
	   fp=fopen("customer.dat","a");
	   if(fp==NULL)
	   {
		printf("\n Can not open file!!");
		exit(0);
	   }
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {
		system("cls");


		printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== CUSTOMER ENTRY ======\n");
	   printf("\t\t\t===========================================\n\n\n");
;

		//flushall();
		temp_c.cust_id=getcust_id();
		printf("\nCUSTOMER ID :%d\n",temp_c.cust_id);


		printf("CUSTOMER NAME : ");
		scanf("%s",&temp_c.cust_name);

		printf("CITY        : ");
		scanf("%s",&temp_c.city);

		printf("CONTACT NO.   : ");
		scanf("%s",&temp_c.mob_no);

		printf("EMAIL ID    : ");
		scanf("%s",&temp_c.email);



		printf("\n\n(save or cancel)Press First charecter for the operation : ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
			fprintf(fp,"\n");
			fflush(stdin);
			system("cls");

			printf("\n\n\t\t\tCustomer Added Successfully!!!!!\n\n");


			printf("\t\t\tMore entries  [y/n] ");
			ch=getche();

		}
	   }
	   fclose(fp);
}

void cust_update()
{
  int i;
  char ch;
  int cid;
  FILE *ft;
  system("cls");

	   ptr1=fopen("customer.dat","rb+");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open file!! ");
		exit(0);
	   }

	   printf(" \n\t\t\tModifying customer \n");

	   printf("Enter the CUSTOMER ID : ");
	   scanf("%d",&cid);


		ft=fopen("temp.txt","w");
		if(ft==NULL)
		{
			printf("\n Can not open file");
			exit(0);
		}
		else
		{

			while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
			{
				if(temp_c.cust_id==cid)
				{

					printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== EXISTING RECORD ======\n");
	   printf("\t\t\t===========================================\n\n\n");


					printf("%d\t %s \t%s \t%s \t%s",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);

					printf("\nEnter New Name         : ");
					scanf("%s",&temp_c.cust_name);

					printf("\nEnter New mobile no    : ");

					scanf("%s",&temp_c.mob_no);

					printf("\nEnter New City         : ");

					scanf("%s",&temp_c.city);

					printf("\nEnter New email        : ");

					scanf("%s",&temp_c.email);








					printf("\n(update or cancel)Press First charecter for the operation : ");
					ch=getche();
					if(ch=='u' || ch=='U')
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
				       //	fprintf(ft,"\n");
					fflush(stdin);

					printf("\nCustomer updated successfully...");
					remove("customer.dat");
					rename("temp.txt","customer.dat");
					}					}
					else
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
					fflush(stdin);
					}
				  }


	   fclose(ft);
	   fclose(ptr1);
      }

}

//=========FOR CUSTOMER DISPLAY LIST ==========
void cust_list()
{
 char ch;
 system("cls");
	   ptr1=fopen("customer.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");


	   printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== CUSTOMER LIST ======\n");
	   printf("\t\t\t===========================================\n\n\n");



	   printf("     ID.            CUSTOMER NAME.             CITY.            MOBILE.NO.              EMAIL\n");

	   printf("=======================================================================================================================\n");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {

		printf("\t%d\t\t",temp_c.cust_id);

		printf(" %s\t\t",temp_c.cust_name);

		printf("       %s\t\t",temp_c.city);

		printf(" %s\t\t",temp_c.mob_no);

		printf(" %s\n\n",temp_c.email);

	   }
	   printf("\n\nPress Enter For Customer Menu......");
	   getche();
}

void medicine()
{
	char ch;
	do
	{
	  system("cls");


	  printf("\n\t\t\t\t:::::::::::::::::::::::::::::::::::::\n");

	  printf("\t\t\t\t::::::::::Medicine Menu.::::::::::::::\n");

	  printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::\n\n\n\n");


	  printf("\tP.  Purchase New Medicine\n");

       printf("\tS.  Sale Medicine\n");

	  printf("\tC.  Stock\n");

	  printf("\tA.  Search medicine\n");

	  printf("\tM.  Main Menu\n\n");


	 printf("\tPress First Character for further Operations  ");


	  ch=toupper(getche());
	  switch(ch)
	  {
		case 'P':medi_entry();
			 break;
		case 'S':medi_sale();
			 break;
		case 'C':stock();
			 break;
		case 'A':medi_search();
			 break;
		case 'M':main_menu();
			 break;
		default:

			printf("Please Enter right character ONLY (P,S,C,M).");
			getch();
	  }
	}while(ch!='M');

}
FILE*ptrpr_r;

void medi_entry()
{
  char ch,id[6];

    time_t t = time(0);
    struct tm * now = localtime( & t );
  int f;
  FILE *fp;
  system("cls");


	 ptrpr_r=fopen("purreport.dat","a");
	  ch='Y';
	  while(ch=='Y')
	  {
		system("cls");

		printf("\n\n\t\t\t\t:::::::::::::::::::::::::::::::::::::\n");

	  printf("\t\t\t\t::::::::::MEDICINE PURCHASE.::::::::::::::\n");

	  printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::\n\n\n\n");
		{

			printf("\nMEDICINE ID    : ");

           ventry(temp.id,1);
			strcpy(id,temp.id);

			fp=fopen("medical.dat","r");
			while((fread(&temp,sizeof(temp),1,fp))==1)
			{

			if(strcmp(id,temp.id)==0)
			{
				f=1;
				break;
			}
			}
			fclose(fp);
			if(f==1)
			{

				printf("\n***ID Allready Exists\n");
				getche();
				system("cls");
				medi_entry();
			}
			else
			{
			ptr=fopen("medical.dat","a+b");
			strcpy(temp.id,id);
			strcpy(p_r.medi_id,temp.id);
			}

            printf("\nMEDICINE NAME  : ");
            scanf("%s",&temp.medi_name);
			strcpy(p_r.medir_name,temp.medi_name);


			printf("\nENTER RACK NO  : ");
			scanf("%s",&a);
			temp.rack= atoi(a);//atoi() used for convert str to int.


			printf("\nCABNIT NO      : ");
			scanf("%s",&temp.cabnit);


			printf("\nCOMPANY NAME   : ");
			scanf("%s",&temp.comp_name);


			printf("\nSUPPLIER NAME  : ");
			ventry(temp.supp_name,0);
			strcpy(p_r.supp_name,temp.supp_name);



			printf("\nUNIT COST   tk.:  ");
				ventry(a,1);
			temp.unit= atof(a);


			printf("\nSALE COST   tk.: ");
			p_r.rate=temp.unit;

			ventry(a,1);
			temp.sale= atof(a);



			printf("\nQUANTITY       :  ");
			ventry(a,1);
			temp.quantity= atoi(a);
			p_r.qty=temp.quantity;


			printf("\nMFG.DATE(dd-mm-yyyy): ");
			//flushall();
			ventry(temp.manu_date,1);


			printf("\nEXP.DATE(dd-mm-yyyy): ");
			ventry(temp.exp_date,1);




			printf("\n=================================================================================");
			temp.total=temp.quantity*temp.sale;

			//textcolor(10);

			printf("\nTOTAL SALE COST = Tk. %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);

			printf("\nTOTAL UNIT COST = tk. %.2f",temp.cost);
			p_r.total=temp.cost;
			p_r.sDay=now->tm_mday;
			p_r.sMonth=now->tm_mon;
			p_r.sYear=now->tm_year;
		 }



		printf("\n(Save or Cancel)");

		printf("Press First charecter for the operation : ");


		ch=toupper(getche());

		if(ch=='S'  || ch=='s')
		{
			fwrite(&temp,sizeof(temp),1,ptr);
			fflush(stdin);
			//textcolor(10);
			fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
			system("cls");

			printf("\n\n\nMedicine Added sucessfully!!!!!!");

			printf("\n\n\nMore entries  [y/n]");
			ch=toupper(getche());

		}

	   }
	   fclose(ptr);
	   fclose(ptrp_r);
}

//===========FOR MEDICINE SALE=========================
void medi_sale()
{
  struct bill bil;

  time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
  int j,n,i,a,billno;
  int d1,m,y;
  float b,total,rate;
  char tar[30],ch,mediname[30],c_name[30],cname[30];
  FILE *fp,*fpc;
  int count=0;

  d1=now->tm_mday;
  m=now->tm_mon;
  y=now->tm_year;
	   ch='y';
	   while(ch=='y')
	   {
		fp = fopen("dbbill.dat","a");
		ptr1 = fopen("customer.dat","r");
		ptr = fopen("medical.dat","r");
		ptrs_r=fopen("saleRpt.dat","a");
		ptrpr_r=fopen("profitRpt.dat","a");
		system("cls");

		for(i=3;i<=45;i++)      //This 'FOR' loop will print asteriks 'I'
		{                       //vertically till the 3th row is reached.

		//printf("%c",219);
		}

           printf("\n\n\t\t------------------------------------\n");
		printf("\t\tCust_ID   &      Cust_Name\n");
		printf("\t\t------------------------------------\n\n");
		//flushall();
		while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
		{

			printf("\t\t%d\t\t",temp_c.cust_id);

			printf("%s\n",temp_c.cust_name);

		}
		printf("\n\n\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\t\t\t::::::::Sale Medicine To The Customer::::::::::::::::\n");
		printf("\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");


		printf("\nENTER MEDICINE Name TO BE SOLD  : ");

		scanf("%s",&tar);
		j=0;
		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{
			if((strcmp(temp.medi_name,tar)<0) || (strcmp(temp.medi_name,tar)>0))
			{
				x[j] = temp;
				j++;
			}
			else if((strcmp(temp.medi_name,tar)==0))
			{


				printf("\n Medicine Name        : %s\n",temp.medi_name);

				printf("\n Quantity in stock    : %d\n",temp.quantity);

				printf(" \nSales price          : %.2f\n",temp.sale);

				printf("\nEnter bill number     : ");

				ventry(bil.billno,1);


				printf("\nEnter customer Name   : ");

				ventry(c_name,0);


				printf("\nQuantity want to sale : ");

				scanf("%d",&a);

				pr_r.profit=(temp.sale-temp.unit)*a;
				x[j]=temp;
				x[j].quantity=(x[j].quantity-a);
				x[j].total=(x[j].quantity*temp.sale);
				x[j].cost=(x[j].quantity*temp.unit);
				x[j].bye=(x[j].sale*a);
				b=x[j].bye;
				x[j].qty=a;
				j++;
				count++;
				strcpy(bil.cname,c_name);
				strcpy(s_r.cust_name,c_name);
				strcpy(bil.mediname,temp.medi_name);
				bil.medi_qty=a;
				bil.medi_rate=temp.sale;
				bil.total=temp.sale*a;

				bil.day=d1;
				bil.month=m;
				bil.year=y;

				fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);
				fflush(stdin);

				fclose(fp);

				s_r.sDay=d1;
				s_r.sMonth=m;
				s_r.sYear=y;
				strcpy(s_r.medi_id,tar);
				strcpy(s_r.medir_name,temp.medi_name);
				s_r.qty=a;
				s_r.rate=temp.sale;
				s_r.total=temp.sale*a;

				//sale report
				fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
				fflush(stdin);
				fclose(ptrs_r);
				//profit report

				pr_r.sDay=d1;
				pr_r.sMonth=m;
				pr_r.sYear=y;
				strcpy(pr_r.medi_id,tar);
				strcpy(pr_r.medir_name,temp.medi_name);
				pr_r.qty=a;
				pr_r.rate=temp.sale;
				pr_r.unit=temp.unit;
				fprintf(ptrpr_r,"%s %s %d %d %d %d %.2f %.2f  %.2f\n",pr_r.medi_id,pr_r.medir_name,d1,pr_r.sMonth,pr_r.sYear,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
				fflush(stdin);
				fclose(ptrpr_r);

			}
		}
		if (count==0)
		{
			system("cls");

			printf("\nNot in stock!!!!!");
			getch();
			return;
		}
		fclose(ptr1);
		fclose(ptr);
		n = j;
		system("cls");
		ptr=fopen("medical.dat","wb");
		for(i=0; i<n; i++)
		fwrite(&x[i],sizeof(x[i]),1,ptr);
		fclose(ptr);
		system("cls");

		printf("\n\n* Price paid by customer = %.2f",b);

		printf("\n\n* Quantity sold          = %d",a);
		getch();

		printf("\nmore enteries=(y/n) :");
		ch=getche();
	   }

}


//===========================MEDICINE STOCK=====================================
void stock()
{
  char ch;
  int i,c;
	   do
	   {
		system("cls");
		ptr1=fopen("medical.dat","r");
		if(ptr1==NULL)
		{
			printf("\n\t Can not open File! ");
			exit(1);
		}
		system("cls");

		printf("\n\t\t\t\t:::::::::::::::::::::::::::::::::::::\n");

	  printf("\t\t\t\t::::::::::Medicine Stock::::::::::::::\n");

	  printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::\n\n\n\n");
		i=14;

		printf(" ID.\t\tMEDICINE NAME.\t\t QUANTITY\t\tSupplier Name\t\tExp.Date\n");

		printf("================================================================================================================\n");

		while((fread(&temp,sizeof(temp),1,ptr1))==1)
		{

			printf(" %s\t\t",temp.id);

			printf(" %s\t\t      ",temp.medi_name);

			printf(" %d\t\t",temp.quantity);

			printf(" %s\t\t",temp.supp_name);

			printf("       %s\n",temp.exp_date);
			i++;
		}

		printf("\n\n\nPress [1] for Update Medicine Stock  & [0] for main menu ");
		c = (getche());
		switch (c)
		{
			case '0':
				 main_menu();
				 break;
			case '1':update_stock();
				 break;
		}

	   }while(c != '1');
	   getche();
}

//============================ FOR MEDICINE UPDATE =====================
void update_stock()
{
  char mid[6];
  int j,a,count=0,n;
  system("cls");
	   ptr=fopen("medical.dat","rb");
	   if(ptr==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");

	    printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== UPDATE MEDICINE QUANTITY ======\n");
	   printf("\t\t\t===========================================\n\n\n");





	   printf("\t\tEnter medicine Name to be update qty: ");
	   scanf("%s",&mid);
	   j=0;

	   while((fread(&temp,sizeof(temp),1,ptr))==1)
	   {
		if((strcmp(temp.medi_name,mid)<0) || (strcmp(temp.medi_name,mid)>0))
		{
			x[j] = temp;
			j++;
		}
		else
		{

			printf("\n\n\t\tMedicine Name     : %s",temp.medi_name);

			printf("\n\t\tQuantity in stock : %d",temp.quantity);

			printf("\n\t\tQuantity want to update : ");
			scanf("%d",&a);
			x[j]=temp;
			x[j].quantity=(x[j].quantity+a);
			x[j].total=(x[j].quantity*temp.sale);
			x[j].cost=(x[j].quantity*temp.unit);
			x[j].bye=(x[j].sale*a);
			x[j].qty=a;
			j++;
			count++;
		}
	   }
	   if (count==0)
	   {
		 system("cls");

		 printf("\nNot in stock!!!!!!");
		 getch();
		 return;
	   }
	   fclose(ptr);
	   n = j;
	   system("cls");
	   printf("\n\n\n\n\t\t\tQuantity of the medicine Added Successfully..!!!!\n\n");
	   printf("\t\t\tPress Enter For Medicine Menu......");
	   ptr=fopen("medical.dat","wb");
	   for(i=0; i<n; i++)
	   fwrite(&x[i],sizeof(x[i]),1,ptr);
	   fclose(ptr);
}
   //=============================== FOR MEDICINE SEARCH ====================
void medi_search()
{
  char mid[6];
  char mnm[15];
  int i,c;
  system("cls");
	   ptr1=fopen("medical.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   printf("\n\t\t\t\t:::::::::::::::::::::::::::::::::::::\n");

	  printf("\t\t\t\t:::::::::: Medicine Search ::::::::::::::\n");

	  printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::\n\n\n\n");

	   printf("\nEnter Medicine Name or Id to be searched : ");
	   scanf("%s",&mnm);
	   system("cls");

	      printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== MEDICINE Description ======\n");
	   printf("\t\t\t===========================================\n\n\n");




	   i=14;

	   printf("\n   ID.\t\tMEDICINE NAME.\t\tQTY\t\tSupplier Name\t\tExp.Date\n");

	   printf("====================================================================================================\n");
	   while((fread(&temp,sizeof(temp),1,ptr1))==1)
	   {
		if(strcmp(mnm,temp.medi_name)==0 || strcmp(mnm,temp.id)==0)
		{

			printf(" %s\t\t",temp.id);

			printf(" %s\t\t         ",temp.medi_name);

			printf(" %d\t\t",temp.quantity);

			printf(" %s\t\t     ",temp.supp_name);

			printf(" %s\n",temp.exp_date);
			i++;
			break;
		}

	   }
	   printf("\npress Enter for goto medicine menu::::;\n");

	  if(strcmp(mnm,temp.medi_name)!=0 )
	   {

		printf("\n\nNot in Stock.....:-(");
	   }
	   getche();

}

//======================Remainder for medicine stock ===============
void remainnder()
{
	ptr1=fopen("medical.dat","r");

	while((fread(&temp,sizeof(temp),1,ptr1))==1)
	{
		if(temp.quantity<10)
		{


			printf("\n%s : ",temp.medi_name);
			printf("\nQuantity of this medicine is less then 10");
		}
	}
}

//===========for supplier=========================
void supplier()
{
  char ch;
	do
	{
	  system("cls");

	  printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== SUPPLIER MENU ======\n");
	   printf("\t\t\t===========================================\n\n\n");

	   printf("\n\n\n\t\t\t======Press First Character for further Operation=======\n\n ");

	  printf("\n\n\t\tA -- Add New Supplier");

	  //printf("\nU**Update Supplier\n");

	  printf("\n\t\tL -- List of Existing Supplier\n");

	  printf("\t\tM -- Main Menu\n\n\n");




	  ch=toupper(getche());
	  switch(ch)
	  {
		case 'A':
			 supp_entry();
			 break;
		//case 'U':
			// sup_update();
			// break;
		case 'L':
			 supp_list();
			 break;

		case 'M':main_menu();
			 break;
		default:

			printf("\n\t\tPlese Enter right character ONLY (A,L,U,M).");
			getch();
	  }
	}while(ch!='M');

}

//========FOR SUPPLIERS ENTRY=================
void supp_entry()
{
 int id;
 char ch;
 FILE *fp;
 system("cls");

	   fp=fopen("supplier.dat","a");
	   if(fp==NULL)
	   {
		printf("\n Can not open file!!");
		exit(0);
	   }
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {
		system("cls");

		 printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== SUPPLIER ENTRY ======\n");
	   printf("\t\t\t===========================================\n\n\n");

		temp1.supp_id=getsupp_id();
		printf("\nSUPPLIER ID : %d \n",temp1.supp_id);
		//ventry(temp1.supp_id,1);


		printf("\nSUPPLIER NAME : ");
		ventry(temp1.supp_name,0);

		printf("\nCITY        : ");
			ventry(temp1.city,0);

		printf("\nCONTACT NO.   : ");
		ventry(temp1.mob_no,1);

		printf("\nEMAIL ID    : ");
		scanf("%s",&temp1.email);

        printf("\n\n\n(Save or ");

		 printf("Cancel)");

		printf("Press First charecter for the operation : ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n\n",temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email);
			fprintf(fp,"\n");

			system("cls");

			printf("\nSupplier Added successfully!!!!!");

			printf("\nMore entries  [y/n]");
			ch=getche();
		}
	   }
	   fclose(fp);

}
//=========FOR SUPPLIER DISPLAY LIST ==========
void supp_list()
{
 char ch;
 int j;
 system("cls");
	   ptr1=fopen("supplier.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }

	   t();


       printf("\n\n\t\t\t===========================================");
	   printf("\n\t\t\t\t====== SUPPLIER LIST ======\n");
	   printf("\t\t\t===========================================\n\n\n");

	   printf("\n  ID.\t\tSUPPLIER NAME.\t\tPH.NO.\t\t\tCITY.\t\tEMAIL\n");

	   i=14;
	   printf("=========================================================================================================\n");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.city,temp1.mob_no,temp1.email)!=EOF)
	   {

		printf(" %d \t     ",temp1.supp_id);

		printf(" %s \t \t   ",temp1.supp_name);

		printf(" %s \t\t     ",temp1.city);

		printf(" %s \t      ",temp1.mob_no);

		printf(" %s\n",temp1.email);
		i=i+2;
	   }
	   printf("\n\n\t\tPress Enter for Supplier Menu.......");
	   getche();
}

//============supp update=================
void sup_update()
{
  int i;
  char ch;
  int sid;
  FILE *ft;
  system("cls");

	   ptr1=fopen("supplier.dat","rb+");
	   if(ptr1==NULL )
	   {
		printf("\n\t Can not open file!! ");
		exit(0);
	   }

	   printf(" \n\n\t\t\t********Modifying Supplier *********\n\n");

	   printf("\nEnter supplier ID :  ");

	   scanf("%d",&sid);


		ft=fopen("temp.dat","w");
		if(ft==NULL)
		{
			printf("\n Can not open file");
			exit(1);
		}
		else
		{
			while(fscanf(ptr1,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no, temp1.city,temp1.email)!=EOF)
			{
				if(temp1.supp_id==sid)
				{

					printf(" \n\nExisting Record\n  ");

					printf("\n\n\n%d\t %s \t%s \t%s \t%s",temp1.supp_id,temp1.supp_name,temp1.mob_no, temp1.city,temp1.email);

					printf("\nEnter New Name       : ");

					ventry(temp1.supp_name,0);

					printf("\nEnter New mobile no  : ");

					ventry(temp1.mob_no,1);

					printf("\nEnter New City       : ");

					ventry(temp1.city,0);

					printf("\nEnter New email      : ");

					ventry(temp1.email,2);


					printf("\n\n(Update or ");

					printf("Cancel)");

					printf("Press First character for the operation : ");
					ch=getch();
					if(ch=='u' || ch=='U')
					{
					    fprintf(ft,"%d %s %s %s %s\n",temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email);


					    printf("Supplier updated successfully...");
					    remove("supplier.dat");
					    rename("temp.dat","supplier.dat");

					}
				}
			else
			{
				fprintf(ft,"%d %s %s %s %s\n",temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email);
				fflush(stdin);
			}
		}

	   fclose(ft);
	   fclose(ptr1);
	   }
}


void bill()
{

    time_t td = time(0);   // get time now
    struct tm * now = localtime( & td );
    t();

	   FILE *ptrbill;
	   char id[6];
	   int j=1,d1,m,y,k;
	   float netamt=0.0;
	   //getdate(&d);
	   d1=now->tm_mday;
	   m=now->tm_mon;
	   y=now->tm_year;
	   system("cls");
	   ptrbill=fopen("dbbill.dat","r");

	   printf("\n\n\n\t\tEnter bill no : ");
	   scanf("%s",&id);
	   system("cls");

	    printf("\n\n\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n");
             		printf("\t\t\t\t::::::::::: BEST Medical Store::::::::::::::::::\n");
             		printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n\n");

	   printf("\n\t\tBill No: ");
	   printf(" %s",id);



	   printf("\n\t\tDate : ");
	   printf("%d-%d-%d",d1,m,y);

	   printf("\n\n\n   \t\tSr.No          Medicine Name               Qty           Rate           Total\n ");

	   printf("\t\t----------------------------------------------------------------------------------------\n\n");

	   i=15;
	   while(fscanf(ptrbill," %s %s %s %d %f %f %d %d %d",bil.billno,bil.cname,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total,&bil.day,&bil.month,&bil.year)!=EOF)
	   {

		       do
		       {
			if(strcmp(id,bil.billno)==0)
			{

				printf("    \t\t  %d           ",j);

				printf(" %s                    ",bil.mediname);
				printf(" %d            ",bil.medi_qty);
				printf(" %.2f          ",bil.medi_rate);
                printf(" %.2f\n",bil.total);

				netamt=netamt+bil.total;
				i++;
				j++;



			}


		}while(feof(ptrbill));

	   }



	   printf(" \n \t\t----------------------------------------------------------------------------------------\n\n");
           printf(" \t\tCustomer name:  %s\n\n",bil.cname);
	   printf("\t\t\t\t\t\t\t\tNet Amount (Taka) : %.2f /-\n\n\n\n",netamt);
	   printf("\t\t\t\tThanks for shopping from us :-) See You Again..!!!!\n\n");

	   fclose(ptrbill);
	   getch();
}

void report_menu()
{
	char ch;
	do
	{
	  system("cls");

	  printf("\t\t\t\t-----------------------------------\n");

	  printf("\t\t\t\t**********Report Menu*************\n");

	  printf("----------------------------------------------\n\n");
	   printf(":::::Press First Character for further Operations::::::::  \n\n");

	 printf("P* Purchase Report\n");

	  printf("S* Sale Report\n");

	   printf("O* Profit Report\n");

	  printf("A* Daily Sale Report\n");


	  printf("D* Daily Purchase Report\n");

	  printf("M* Main Menu\n\n");



      ch=toupper(getche());
	  switch(ch)
	  {
		case 'P':pur_rpt();
			 break;
		case 'S':sale_rpt();
			 break;
		case 'A':sale_rpt_daily();
			 break;
		case 'O':profit_rpt();
			 break;
		case 'D':pur_rpt_daily();
			 break;
		case 'M':main_menu();
			 break;
		default:

			printf("\nPlese Enter right character ONLY (P,S,A,O,M).\n");
			getch();
	  }
	}while(ch!='M');

}

//======================= VIEW PURCHASE REPORT ===========================
void pur_rpt()
{
  char ch;
  int j;
  system("cls");
  t();

	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }



	   printf("\n\t\t************Purchase Report****************\n\n");

	   printf("ID. Medicine Name.       Supplier Name.       Qty.     Rate.  Total.   Date\n");

	   printf("====================================================================================================\n");
	   j=14;
	   while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {

		printf("  %s         ",p_r.medi_id);

		printf("%s        ",p_r.medir_name);

		printf("%s          ",p_r.supp_name);

		printf("%d          ",p_r.qty);

		printf("%.2f        ",p_r.rate);

		printf("%.2f         ",p_r.total);

		printf("%d-%d-%d\n",p_r.sDay,p_r.sMonth,p_r.sYear);
		j+=2;
	   }
	   fclose(ptrp_r);
	   getche();
}
//===================== view report =============================/
void sale_rpt()
{
  char ch;
  int j;
  system("cls");
	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");

	   printf("\n\t\t\t********Sales Report***********\n\n");

	   printf("ID. Medicine Name.\t\tCustomer Name.\t\tQty. \t\tRate.\t\tTotal.\t\tDate\n");

	   printf("==============================================================================================================\n");
	   j=14;
	   while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {

		printf("%s\t\t",s_r.medi_id);

		printf("%s\t\t",s_r.medir_name);

		printf("%s\t\t",s_r.cust_name);

		printf("%d\t\t",s_r.qty);

		printf("%.2f\t\t",s_r.rate);

		printf("%.2f\t\t",s_r.total);

		printf("%d-%d-%d\n",s_r.sDay,s_r.sMonth,s_r.sYear);
		j=j+2;
	   }
	   getche();
}

void sale_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;
  system("cls");
	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");

	   printf("\nEnter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");



	   printf("/n\t\t\t\t*****Sales Report******/n");

	   j=14;
	   printf("  ID.    Medicine Name.     Customer Name.   Qty.    Rate.    Total.     Date\n");

	   printf("=============================================================================================================\n");

	   while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {
		if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
		{

		printf("%s   ",s_r.medi_id);

		printf("%s    ",s_r.medir_name);

		printf("%s    ",s_r.cust_name);

		printf("%d    ",s_r.qty);

		printf("%.2f   ",s_r.rate);

		printf("%.2f     ",s_r.total);

		printf("%d-%d-%d    \n",s_r.sDay,s_r.sMonth,s_r.sYear);

		total=total+s_r.total;
		}
	   }

	   printf("\n-------------------------------------------------------------------------------------------------\n");

	   printf("\t\t\t\t\tTotal:        %.2f",total);
	   getche();
}

//========================= report of profit ===========================
void profit_rpt()
{
  char ch;
  int j;
  system("cls");
  t();

	   ptrpr_r=fopen("profitRpt.dat","r");
	   if(ptrpr_r==NULL)
	   {
		printf("\n\t Can not open File! ");
	       //	exit(0);
	   }

	   printf("Press Enter to go to REPORT MENU ...........");

	   printf("Profit Report");

	   printf("ID. Medicine Name.   Date        Qty.  Unit Price  Sale Price. Profit. ");

	   printf("===================================================================");
	   j=14;
	   while(fscanf(ptrpr_r,"%s %s %d %d %d %d %f %f %f \n",pr_r.medi_id,pr_r.medir_name,&pr_r.sDay,&pr_r.sMonth,&pr_r.sYear,&pr_r.qty,&pr_r.unit,&pr_r.rate,&pr_r.profit)!=EOF)
	   {

		printf("%s  ",pr_r.medi_id);

		printf("%s   ",pr_r.medir_name);

		printf("%d-%d-%d  ",pr_r.sDay,pr_r.sMonth,pr_r.sYear);

		printf("%d  ",pr_r.qty);

		printf("%.2f  ",pr_r.unit);

		printf("%.2f  ",pr_r.rate);

		printf("%.2f   \n",pr_r.profit);



	   }
	   getche();
}

void pur_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;

	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");

	   printf("\nEnter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");

	   printf("\n********Purchase Report************\n\n");


	   printf("ID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");

	   printf("===================================================================");

	   while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {
		if(d==p_r.sDay &&m== p_r.sMonth && y==p_r.sYear)
		{

		printf("%s     ",p_r.medi_id);

		printf("%s     ",p_r.medir_name);

		printf("%s      ",p_r.supp_name);

		printf("%d      ",p_r.qty);

		printf("%.2f      ",p_r.rate);

		printf("%.2f      ",p_r.total);

		printf("%d-%d-%d      \n",p_r.sDay,p_r.sMonth,p_r.sYear);

		total=total+p_r.total;
		}
	   }

	   printf("-------------------------------------------------------------------\n");

	   printf("\t\t\t\tTotal:        %.2f\n",total);
	   getche();
}
void about()
{  int c;
   system("cls");

   do
   {
       t();

	 printf("\n\n\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n");
             		printf("\t\t\t\t::::::::::: BEST Medical Store::::::::::::::::::\n");
             		printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n\n\n");

	printf("  \t\t=>  This Project Is About Medical Store\n\n");


	printf("  \t\t=>  In This Project we Can Add Medicine ,Customer,Supplier Details\n\n");


	printf("  \t\t=>  We Can Also Search Medicine in the stock by name or id.\n\n");

	printf("  \t\t=>  It's Helpful For Display Stock Of Medicine \n\n\n");
	//printf("\t\tThis project developed by saimun..:)");

	printf("  \t\t<<<<-Press 1 for main menu->>>>");
	c = (getche());

	switch (c)
		{
			case '1':; main_menu();

				puts("<<--ENTER FROM 1 PLEASE-->>");	//This message will only print on INVALID ENTRY and Will ask again for input.
				getch();
		}

}while(c != '1');

}
