#include<stdio.h>
#include<stdlib.h>
int again;
int total=0;
float gst,cgst,sgst;
int bfrate[7][2]={  {0,30},
                    {1,35},
                    {2,40},
                    {3,20},
                    {4,15},
                    {5,20},
                    {6,30}
                };
int lunchrate[7][2]={{0,80},
                {1,120},
                {2,20},
                {3,120},
                {4,150},
                {5,160},
                {6,30}};
int dinner_rate[7][2]={{0,65},
                {1,50},
                {2,70},
                {3,80},
                {4,65},
                {5,110},
                {6,50}};
int purchased[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
int temp[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
void bfast(char bfmenu[][100]);
void lunch( char lunchmenu[][100]);
void dinner(char dinnermenu[][100]);
void main_menu();
void display();
void lunch_menucard();
void dinner_menu();
void display_bf_bill(char bfmenu[][100]);
void display_lunch_bill(char lunchmenu[][100]);
void display_dinner_bill(char dinnermenu[][100]);
void display_bfmenu();
void repeatbf(char bfmenu[][100]);
void repeatlunch(char lunchmenu[][100]);
void repeatdinner(char dinnermenu[][100]);
void display_total_words();

void main()
{
	system("color 4a");             /////
    char bfmenu[][100]={"Tea","Coffee","Dosa","Poha","Samosa","Toast","Juice"};
    char lunchmenu[][100]={"Tandori Roti","Butter Roti meal","Dal Fry","Mix Veg","Paneer Chilly","Palak Paneer","GulabJamun"};
    char dinnermenu[][100]={"Butter Nan","Missi Roti","Rajma","Dal Makhani","Handi Paneer","Veg Thali","Delux Thali"};
    char choice;
    do
    {
        enter:
        display();
        printf("\t\tEnter your choice here : ");
        scanf("%c", &choice);
        getchar();
        system("cls");              //////
        switch(choice)
        {
        	case 'A':
            case 'a':system("color 1b");
				     printf("\nBreakfast\n");
                     bfast(bfmenu);
                     break;
            case 'B':
            case 'b':system("color 1b");
					 printf("\nLunch\n");
                     lunch(lunchmenu);
                     break;
            case 'C':
            case 'c':system("color 1b");
			         printf("\nDinner\n");
                     dinner(dinnermenu);
                     break;
           default:  printf("\n !!!! Wrong choice !!!! \n Please Enter the valid choice!!\n\n");
                     goto enter;
        }
    }while(choice!='d');
}

void display()
{
	printf("\n");
	printf("\t\t             +--------------------------------+        \n");
    printf("\t\t             |   WELCOME TO HUNGER JUNCTION   |        \n");
    printf("\t\t             +--------------------------------+         \n\n");
    printf("\t         Enter the type of meal you would like to have \n\n");
    printf("\t\t      [A] Breakfast\n");
    printf("\t\t      [B] Lunch\n");
    printf("\t\t      [C] Dinner\n\n");
}

void display_bfmenu()
{
	printf("\n");
    printf("\t\t             +--------------------------------+        \n");
    printf("\t\t             |   WELCOME TO HUNGER JUNCTION   |        \n");
    printf("\t\t             +--------------------------------+         \n\n");
    printf("\t\t                  !! Breakfast Menu  !! \n\n");
    printf("\t\t  Select Your Order :  \n\n");
    printf("\t\t  Code Items       Price\n\n");
    printf("\t\t   [0] Tea      - Rs 15.00\n");
    printf("\t\t   [1] Coffee   - Rs 20.00\n");
    printf("\t\t   [2] Dosa     - Rs 50.00\n");
    printf("\t\t   [3] Poha     - Rs 35.00\n");
    printf("\t\t   [4] Samosa   - Rs 10.00\n");
    printf("\t\t   [5] Toast    - Rs 25.00\n");
    printf("\t\t   [6] Juice    - Rs 30.00\n");
}

void bfast(char bfmenu[][100]) //Breakfast Menu Screen
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    display_bfmenu();
    printf("\n\tEnter Code :: ");
    scanf("%d", &code);
    getchar();
 //   printf("\tTotal  :: %d\n\n",total);
    if(code>=0&&code<=6)
    {
        printf("\n\tEnter Quantity :: ");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*bfrate[code][1]; /*purchased[code][1]+ (quantity*bfrate[code][1]);*/
        total+=purchased[code][ 1];
        printf("\tTotal :: %d\n\n", total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        bfast(bfmenu);
    }
    repeatbf(bfmenu);
}

void repeatbf(char bfmenu[][100])
{
    printf("\n\tWould you like to buy anything else ? \n \t[1] Yes , [2] No "); // Allows user to choose whether to check-out or buy anything else.
    printf("\n\tEnter Your choice : ");
	scanf("%d",&again);
    if (again == 1)
    {
    	printf("\n\n\n");
        bfast(bfmenu);
	}
    else if (again == 2 )
    {
        display_bf_bill(bfmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered !!! \n");
        repeatbf(bfmenu);
    }
}

// DISPLAING THE BILLS
void display_bf_bill(char bfmenu[][100])
{
	system("color 4a");
	system("cls");
    int i;
	printf("\n");
    printf("\t\t         +--------------------------------+        \n");
    printf("\t\t         |         HUNGER JUNCTION        |        \n");
    printf("\t\t         +--------------------------------+         \n\n");
    printf("\t\t                   BILLING INFORMATION                \n");
    printf("\t\t                   ===================       \n\n");
    printf("\t\t\t    ITEMS    Price(in Rs.)\n\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t\t   %s ",bfmenu[i]);
            printf(" = %d\n",purchased[i][1]); /*purchased[i][1]);*/
        }
    }
    printf("\n\t\t\t   GST   = Rs.%0.2f\n",gst);
    printf("\t\t\t   C-GST = Rs.%0.2f\n",cgst);
    printf("\t\t\t   S-GST = Rs.%0.2f\n",sgst);
    
    printf("\n\t\t\t GRAND TOTAL => Rs.%d\n",total);
    display_total_words();
    printf("\n\n\t  +------------------------- THANK YOU ------------------------- +          \n\n");

}

void display_lunch_bill(char lunchmenu[][100])
{
	system("color 4a");
	system("cls");
    int i;
	printf("\n");
    printf("\t\t         +--------------------------------+        \n");
    printf("\t\t         |         HUNGER JUNCTION        |        \n");
    printf("\t\t         +--------------------------------+         \n\n");
    printf("\t\t                   BILLING INFORMATION                \n");
    printf("\t\t                   ===================       \n\n");
    printf("\t\t\t    ITEMS    Price(in Rs.)\n\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t\t   %s ",lunchmenu[i]);
            printf(" = %d\n",purchased[i][1]);
        }
    }
    printf("\n\t\t\t   GST   = Rs.%0.2f\n",gst);
    printf("\t\t\t   C-GST = Rs.%0.2f\n",cgst);
    printf("\t\t\t   S-GST = Rs.%0.2f\n",sgst);
    
    printf("\n\t\t\t GRAND TOTAL => Rs.%d\n",total);
    display_total_words();
      printf("\n\n\t  +------------------------- THANK YOU ------------------------- +          \n\n");
}

void display_dinner_bill(char dinnermenu[][100])
{
	system("color 4a");
	system("cls");
    int i;
	printf("\n");
    printf("\t\t         +--------------------------------+        \n");
    printf("\t\t         |         HUNGER JUNCTION        |        \n");
    printf("\t\t         +--------------------------------+         \n\n");
    printf("\t\t                   BILLING INFORMATION                \n");
    printf("\t\t                   ===================       \n\n");
    printf("\t\t\t    ITEMS    Price(in Rs.)\n\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t\t   %s ",dinnermenu[i]);
            printf(" = %d\n",purchased[i][1]);
        }

    }
    printf("\n\t\t\t   GST   = Rs.%0.2f\n",gst);
    printf("\t\t\t   C-GST = Rs.%0.2f\n",cgst);
    printf("\t\t\t   S-GST = Rs.%0.2f\n",sgst);
    
    printf("\n\t\t\t GRAND TOTAL => Rs.%d\n",total);
    display_total_words();
      printf("\n\n\t  +------------------------- THANK YOU ------------------------- +          \n\n");
}


void lunch(char lunchmenu[][100]) // Lunch Screen Menu
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    lunch_menucard();
    printf("\n\tEnter Code :: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\n\tEnter Quantity :: ");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*lunchrate[code][1]);
        purchased[code][1]= quantity*lunchrate[code][1];
         total+=purchased[code][ 1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
         lunch(lunchmenu);
    }
    repeatlunch(lunchmenu);
}

void dinner(char dinnermenu[][100]) // Dinner Menu Screen
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    dinner_menu();

    printf("\n\tEnter Code :: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\n\tEnter Quantity :: ");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*dinner_rate[code][1]);
        purchased[code][1]= quantity*dinner_rate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        dinner(dinnermenu);
    }
    repeatdinner(dinnermenu);
}

void lunch_menucard()
{
	printf("\n");
    printf("\t\t             +--------------------------------+        \n");
    printf("\t\t             |   WELCOME TO HUNGER JUNCTION   |        \n");
    printf("\t\t             +--------------------------------+         \n\n");
    printf("\t\t                   !!  Lunch Menu  !! \n\n");
    printf("\t\t  Select Your Order  \n\n");
    printf("\t\t  Code Items          Price\n");
    printf("\t\t   [0] Tandori Roti  - Rs 20.00\n");
    printf("\t\t   [1] Butter Roti   - Rs 15.00\n");
    printf("\t\t   [2] Dal Fry       - Rs 40.00\n");
    printf("\t\t   [3] Mix Veg       - Rs 70.00\n");
    printf("\t\t   [4] Paneer Chilly - Rs 120.00\n");
    printf("\t\t   [5] Palak Paneer  - Rs 130.00\n");
    printf("\t\t   [6] Gulabjamun    - Rs 30.00\n");
 //   printf("Enter your choice here : ");
}

void dinner_menu()
{
	printf("\n");
    printf("\t\t             +--------------------------------+        \n");
    printf("\t\t             |   WELCOME TO HUNGER JUNCTION   |        \n");
    printf("\t\t             +--------------------------------+         \n\n");
    printf("\t\t                    !!  Dinner Menu  !! \n\n");
    printf(" \t\t  Select Your Order \n\n");
    printf("\t\t  Code Items         Price\n");
    printf("\t\t   [0] Butter Nan   - Rs 15.00\n");
    printf("\t\t   [1] Missi Roti   - Rs 18.00\n");
    printf("\t\t   [2] Rajma        - Rs 40.00\n");
    printf("\t\t   [3] Dal Makhani  - Rs 45.00\n");
    printf("\t\t   [4] Handi Paneer - Rs 85.00\n");
    printf("\t\t   [5] Veg Thali    - Rs 180.00\n");
    printf("\t\t   [6] Delux Thali  - Rs 220.00\n");
}

void repeatlunch(char lunchmenu[][100])
{
    printf("\n\tWould you like to buy anything else ? \n \t [1] Yes , [2] No  "); // Allows user to choose whether to check-out or buy anything else.
    printf("\n\tEnter Your choice : ");
	scanf("%d",&again);
    if (again == 1)
    {
    	printf("\n\n\n");
    	lunch(lunchmenu);
	}      
    else if (again == 2 )
    {
        display_lunch_bill(lunchmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatlunch(lunchmenu);
    }
}

void repeatdinner(char dinnermenu[][100])
{

    printf("\n\tWould you like to buy anything else ? \n \t [1] Yes , [2] No  "); // Allows user to choose whether to check-out or buy anything else.
    printf("\n\tEnter Your choice : ");
	scanf("%d",&again);
    if (again == 1)
    {
    	printf("\n\n\n");
        dinner(dinnermenu);
    }
    else if (again == 2 )
    {
        display_dinner_bill(dinnermenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatdinner(dinnermenu);
    }
}

void display_total_words()
{
    int num=0,digits=0,temp=0;
    while(total != 0)
    {
        num=(num * 10)+(total % 10);
        total/= 10;
        digits++;
    }
    printf("\n\t\t\t No of digits :: %d",digits);
    printf("\n\t\t\t Total in words  :: ");
    while(num!= 0)
    {
        temp++;
        switch(num%10)
        {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }
        num = num / 10;
    }
    if(num==0&&digits!=temp)
        printf(" Zero ");
    return;
}

