/*
********PRGRAMMING ASSIGNMENT***********
       Name                            ID
Abdinaf Tufa...................... ETS0001/10
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<fstream>
using namespace std;
char ch;//for all choices
bool sign,sign_arrival;//for admin access
int i=1;//admin id number
float tax,serv;//serv means service charge
//function accessible variables within a class
class  product
{
		public :
		bool new_pro;
		bool notice;
		char  name[30];
        int Quantity;
        int item_type;
        int pro_no;
        float price ;


} data[1000];

void login();
void wifile(product data[]);//storing the value of i
void rifile(product data[]);//reading the value of i
void wfile(product data[]);//storing product informations
void rfile(product data[]);//reading product informations
void notf(product data[]);//notification
void place_order(product data[]);//costumer care service //Asdenaki
void input(product data[]);//entering new files          //
void display(product data[]);//displaying all services
void deleete(product data[]);//helps to delete any item from item list
void sort(product data[]);//sorting out the items according to the user demand
void Edit(product data[]);//formating item components
void loading();//format for transition(processing) time gap
void admin_menu();//it contains administrative purpose functions
void statstics(product data[]);//for total capital
void help();//support center for the user
int main()

{
	rifile(data);// starting file reading
	rfile(data);
    notf(data);
	char choice;
	system("color 20");
	system("cls");
	cout<<"\t\t\t\t\t************************************\n";
	cout<<"\t\t\t\t\t|      GO-GREEN SUPER MARKET       |\n";
    cout<<"\t\t\t\t\t|  eat healthy for a better life!  |";
	cout<<"\n\t\t\t\t\t************************************";

  	cout<<endl<<endl;
  	//main menu
  	cout<<"\n\n\t\t 1. CLIENT OPTION \t\t\t\t 3. ADMINSTRATOR NOTIFICATION\n\n\n\t\t 2. ADMINISTRATOR LOGIN"<<"\t\t\t         4. USER MANUAL\n\n\n\t\t\t\t\t       5. EXIT\n\n";
  	cout<<"Option : ";
	cin>>choice;
		if(choice=='1')
			{
	  			place_order(data);
	  			getch();
	  			system("cls");
	  			main();
	 		}
	  	else if(choice=='2')
	 		{
	  			login();
	  			admin_menu();
			}
		else if(choice=='3')
			{
				sign=true;//if sign is false the function Notf runs inthe back groung
				notf(data);
			}

		else if(choice =='4')
			{
				help();
			 }
		else if(choice=='5')
		{
		exit(0);
		}
		else
		{
			cout<<"Invalid input \n";
			system("pause");
			main();
		}
return 0;
}
void admin_menu()
{
	notf(data);
	char ch;
	system("cls");
	cout<<"\t\t* 1. ADD PRODUCTS \n";
	cout<<"\t\t* 2. DISPLAY PRODUCTS \n";
	cout<<"\t\t* 3. SORT LIST\n";
	cout<<"\t\t* 4. DELETE\n";
	cout<<"\t\t* 5. SEARCH AND EDIT\n";
	cout<<"\t\t* 6. SHOW STATISTICS \n";
	cout<<"\t\t* 7. MAIN MENU \n Choice :";
	here:cin>>ch;
		if(ch=='1')
			{
				input(data);
 				loading();
 				display(data);
				cout<<"\n\t Press any key to continue...\n";
  				getch();
  				admin_menu();
			}
		else if(ch=='2')
			{
				display(data);
 				cout<<"\n\t Press any key to continue...\n";
  				getch();
  				admin_menu();
			}
	else if(ch=='3')
			{
				sort(data);
				loading();
				system("cls");
				cout<<"\n\n\t\tYou data is successfully sorted !!!\n";
				cout<<"\t\tPress any key to continue...\n>";
				getch();
				display(data);
				cout<<"Press any key to continue...\n> ";
				getch();
				admin_menu();
			}
	else if(ch=='4')
			{
				display(data);
				deleete(data);
				getch();
			 	admin_menu();
		    }
    else if(ch=='5')
			{
				Edit(data);
		  	}

	else if(ch=='6')
			{
				statstics(data);
			}
	else if(ch=='7')
			{
			main();// back to the main menu
			}
    else
            {cout<<"\n\t\t\tWrong input.";
    goto here;}
}

void loading()
{
	for(int j=0;j<3;j++)
{
	system("cls");
	cout<<"\nLoading";
	for(int c=0;c<5;c++)
	{

		cout<<".";
		Sleep(100);
	}

}
system("cls");
}

void input(product data[300])
{
    rifile(data);
    rfile(data);
         do
			{
				cin.get();
		      	system("cls");
		    	cout<<endl<<endl<<"\t\t";
		      	cout<<"Product name["<<i<<"]  :";
			  	gets(data[i].name);
			  	cout<<endl<<endl<<"\t\t";
			  	cout<<"Product number["<<i<<"]  :";
			  	cin>>data[i].pro_no;
			  	cout<<endl<<endl<<"\t\t";
			  	cout<<"Product price ["<<i<<"]  :";
			  	cin>>data[i].price;
				if(data[i].price <=0)//validation for the price
					{
						cout<<"\n\t\tError input !!\n";
						cout<<"\n\t\tPlease input positive price \n\n\t\t";
						cin>>data[i].price;
					}
		    	cout<<endl<<endl<<"\t\t";
				cout<<"Quantity["<<i<<"]  : ";
				cin>>data[i].Quantity;
					if(data[i].Quantity <=0)//validation for qoantity
						{
							cout<<"\n\n\t\tError input !!\n";
							cout<<"\n\n\t\tPlease input positive Quantity \n\n\n\t\t";
							cin>>data[i].Quantity;
							cout<<endl<<endl<<"\t\t";
						}
			item:
					cout<<endl<<endl<<"\t\t";
					cout<<"Item type ["<<i<<"]  : ";
					cout<<"1.Vegetables\n\t\t\t\t2.Fruits\n\t\t\t\t3.Other eatables\n\n\t\t\t\t\tchoice: ";
					cin>>data[i].item_type;
					if(data[i].item_type>3||data[i].item_type<1)
						{
							cout<<endl<<endl<<"\t\t";
							cout<<"Please input correct item-type\n ";
			goto item;
				 		}
					i++;
					cout<<"Is there another item ?\n >";
					cin>>ch;
		}
		while(ch == 'Y'|| ch == 'y');

		wifile(data);
		wfile(data);
}
void display(product data[300])
{
	rifile(data);
    rfile(data);
	char ch;
	system("cls");
		for(int j=1;j<i;j++)
			{
				for(int k=0;k<20;k++)
					data[j].name[k]=toupper(data[j].name[k]);// to capitalize input name
			}
		cout<<endl<<endl;
		cout<<left<<setw(10)<<"NO"<<left<<setw(20)<<"PRODUCT NAME"<<left<<setw(20)<<"PRODUCT NO"<<setw(15)<<"PRICE"<<left<<setw(10)<<"QUANTITY";
		cout<<"\n--------------------------------------------------------------------------\n";
		cout<<"\t\t#########VEGETABLES#########\n\n";

		cout<<"---------------------------------------------------------------------------\n";
			for(int j=1;j<i;j++)
				{
					if(data[j].item_type==1)
						{
							Sleep(50);
							cout<<left<<setw(10)<<j<<left<<setw(20)<<data[j].name<<left<<setw(20)<<data[j].pro_no<<left<<setw(6)<<data[j].price<<left<<setw(12)<<"Br"<<left<<setw(15)<<data[j].Quantity<<"\n";
							cout<<"---------------------------------------------------------------------------\n";
						}
				}
		cout<<"\t\t########FRUITS########\n\n";
		cout<<"---------------------------------------------------------------------------\n";
			for(int j=1;j<i;j++)
				{
					if(data[j].item_type==2)
						{
							Sleep(50);
							cout<<left<<setw(10)<<j<<left<<setw(20)<<data[j].name<<left<<setw(20)<<data[j].pro_no<<left<<setw(6)<<data[j].price<<left<<setw(12)<<"Br"<<left<<setw(15)<<data[j].Quantity<<"\n";
							cout<<"---------------------------------------------------------------------------\n";
						}
				}

		cout<<"\t\t#########OTHER EATABLES#########\n\n";
		cout<<"--------------------------------------------------------------------------\n";
			for(int j=1;j<i;j++)
				{
					if(data[j].item_type!=2&&data[j].item_type!=1)
						{
							Sleep(50);
							cout<<left<<setw(10)<<j<<left<<setw(20)<<data[j].name<<left<<setw(20)<<data[j].pro_no<<left<<setw(6)<<data[j].price<<left<<setw(12)<<"Br"<<left<<setw(15)<<data[j].Quantity<<"\n";
			 				cout<<"------------------------------------------------------------------------\n";
						}
				}
		cout<<endl<<endl<<endl<<endl;
					if(i==1)
						{
							cout<<"Sorry you have empty file !!!\n";
							cout<<"Press any key to continue...\n";
							getch();
							system("cls");
							main();
						}
	wifile(data);
	wfile(data);
}
void place_order(product data[300])
{
	system("cls");
	rifile(data);
	rfile(data);
	int order_item[50], quan[50], c=1;// c for counter
	float amount=0,total=0;
	float discount=100;
	bool flag=false;//flag to check if the item number is found
		if(i==1)
			{
				cout<<"Sorry you have empty stock !!!\n";
				cout<<"Press any key to continue...\n";
				getch();
				system("cls");
				main();
			}
	cout<<"\n======================="<<"  PLACE YOUR ORDER "<<"=======================";
		do
			{
		order:display(data);
				cout<<"\n\n Press '0' to terminate \n";

				cout<<"\n\nEnter the Product No. of The Product: ";
				cin>>order_item[c];
				if(order_item[c]==0)
					{
						cout<<"\nPress any key to continue... ";
						getch();
						main();
						break;
		 			}
		 		for(int j=1;j<i;j++)//i is stred value or the last item number
		 			{
		 				if(data[j].pro_no==order_item[c])
		 					{
		 						flag=true;
		 						order_item[c]=j;
			 				}
		 			}
		 		if(flag==false)
		 			{
		 				cout<<"The pro-no not found\n";
		goto order;
					}
				cout<<"Product name : ";
				cout<<data[order_item[c]].name;
		quan:
				cout<<"\nQuantity in Number: ";
				cin>>quan[c];
				if(data[order_item[c]].Quantity==0)
					{
						cout<<"You have no enough amount of product \n";
						cout<<"Do you want to continue ? ('y'/'n')\n>";
						cin>>ch;
						if(ch=='y'||ch=='Y')
								{
									continue;
								}
						else
								{
									break;
								}
					}
				else if(data[order_item[c]].Quantity<quan[c])
					{
						cout<<"\n out of range\n";
						cout<<"Please insert correct quantity\n";
		goto quan;
					}
				cout<<"Discount value (%): ";
				cin>>discount;
				data[order_item[c]].Quantity=data[order_item[c]].Quantity-quan[c];
				c++;
				wifile(data);
            	wfile(data);
				cout<<"\n Do You Want To Order Another Product (y/n)?";
			cin>>ch;

		}
		while(ch=='Y'||ch=='y');
    	system("cls");
		cout<<"\n\n Thank You For Placing Your Order\n\n\n";
		cout<<"\n******************** INVOICE ************************\n\n";
 		cout<<left<<setw(12)<<"PR.NO"<<left<<setw(12)<<"PR.NAME"<<left<<setw(12)<<"QUANTITY"<<left<<setw(10)<<"PRICE"<<left<<setw(12)<<"AMOUNT\n";
		for(int x=1; x<c; x++)
			{
				if(data[order_item[x]].price>200||data[order_item[x]].price<=500)
					{
						tax=0.07;
						serv=0.05;//service charge
					}
				else if(data[order_item[x]].price>500)
						{
							tax=0.15;
							serv=0.05;
						}
				amount=data[order_item[x]].price*quan[x]-(data[order_item[x]].price*quan[x])*(discount/100); // calculate amount of single item
				cout<<"\n"<<left<<setw(12)<<data[order_item[x]].pro_no<<left<<setw(12)<<data[order_item[x]].name<<left<<setw(12)<<quan[x]<<left<<setw(10)<<data[order_item[x]].price<<left<<setw(12)<<amount;
				amount=data[order_item[x]].price*quan[x]-(data[order_item[x]].price*quan[x])*(discount/100)+(data[order_item[x]].price*quan[x])*tax+(data[order_item[x]].price*quan[x])*serv;// calculate with vat,service and discount
		        total+=amount; // total amount
		    }
		cout<<"\n\n\t\t\t\t\tTax = "<<tax*100<<" % ";
		cout<<"\n\t\t\t\t\tService charge = "<<serv*100<<" % ";
		cout<<"\n\t\t\t\t\tTotal = "<<total<<" birr\n";
int p;
		char o;
	me:
		cout<<" Does the costumer wishes to pay in cash or credit?"<<endl;
		cout<<" Input _____$______ for cash"<<endl;
		cout<<"Input  _____C______  for credit"<<endl;
		cout<<">> ";
		cin>>o;
		if(o=='$')
		{
		cout<<"Thanks for shopping with us"<<endl;
		getch(); main();
		}
		else if(o=='c')
		{
		cout<<"What is your credit card number?"<<endl;
		cin>>p;
		getch(); main();}
	else
	{
	cout<<"Invalid input"<<endl;
	goto me;
	 }}
void deleete(product data[300])
{
	char ch;
	int del_item[30];
	int k=1;
	rifile(data);
    rfile(data);
		do
			{
        insert:
			display(data);
			cout<<"Enter delete items\n>";
			cin>>del_item[k];
			if(del_item[k]>i-1||del_item[k]<1)
				{
					cout<<"Sorry please insert correct id\n";
					goto insert;
				}
			cout<<"Are you sure ?\n";
			cin>>ch;
			if(ch!='y'||ch!='y')
				{
					cout<<"You are terminated the process successfully \n";
					cout<<"Do you want to delete another item ? (yes or no)";
					cin>>ch;
					if(ch=='y'||ch=='Y')
						{
		goto insert;
						}
					else
						admin_menu();
				}
			for(int j=del_item[k];j<i;j++)
				{
					data[j]=data[j+1];
				}
			i--;
			wifile(data);
    		wfile(data);
			cout<<"Do you want to delete another item ?\n>";
			cin>>ch;
		}
		while(ch=='Y'||ch=='y');
		loading();
		system("cls");
		cout<<"\n\n\t\tYou successfully deleted the data !!!\n";
		cout<<"\n\t\tPress any key to continue...\n\n\t\t > ";
}
void sort(product data[])
{
	rifile(data);
	rfile(data);
	char sort_choice;
	system("cls");
	cout<<"> 1. SORT by name\n";
	cout<<"> 2. SORT by price\n";
	cout<<"> 3. Exit\n";
	cout<<"Option : ";
	cin>>ch;
	if(ch=='1')
		{
			system("cls");
			cout<<"> 1. Ascending order\n";
			cout<<"> 2. Descending order\n";
			cout<<"> 3. Exit\n> ";
			cin>>sort_choice;
			if(sort_choice=='1')
				{
					for(int k=1;k<i;k++)
						{
							for(int j=k+1;j<i;j++)
								{
									if(strcmp(data[k].name,data[j].name)>0)
	 									swap(data[k],data[j]);
	   							}
  						}
				}
			else if(sort_choice=='2')
				{
					for(int k=1;k<i;k++)
						{
							for(int j=k+1;j<i;j++)
								{
									if(strcmp(data[k].name,data[j].name)<0)
	 								swap(data[k],data[j]);
	   							}
  						}
				}
			else
				{
					main();
				}
		}
	else if(ch=='2')
		{
			system("cls");
			cout<<"> 1. Ascending order\n";
			cout<<"> 2. Descending order\n";
			cout<<"> 3. Exit\n> ";
			cin>>sort_choice;
			if(sort_choice=='1')
				{
					for(int k=1;k<i;k++)
						{
							for(int j=k+1;j<i;j++)
						{
							if(data[k].price>data[j].price)
	 						swap(data[k],data[j]);
	   					}
  						}
				}
			else if(sort_choice=='2')
				{
					for(int k=1;k<i;k++)
						{
							for(int j=k+1;j<i;j++)
								{
									if(data[k].price<data[j].price)
	 									swap(data[k],data[j]);
	   							}
  						}
				}
			else
				{
					admin_menu();
				}
			}
		else
			{
				admin_menu();
			}
	wifile(data);
	wfile(data);
}
void Edit(product data[300])
{
	rifile(data);
    rfile(data);
	char edit_choice;
	int edit_item[30];
	int k=1;//item number
edit:
	display(data);
	cout<<"\t\tPlease insert Edit item number  : ";
	cin>>edit_item[k];
	if(edit_item[k]>=i||edit_item[k]<1)
		{
			cout<<"\t\tSorry out of range!!!\n";
			goto edit;
		}
	system("cls");
	cout<<"\n===================="<<" SEARCH & EDIT ITEM "<<"====================\n\n";
	cout<<"\t\t"<<"PRODUCT NAME :  ";
	cout<<data[edit_item[k]].name;
	cout<<"\n\t\tPRO-NO  : ";
	cout<<data[edit_item[k]].pro_no;
	cout<<"\n\t\t"<<"PRICE :  ";
	cout<<data[edit_item[k]].price;
	cout<<"\n\t\t"<<"QUANTITY :  ";
	cout<<data[edit_item[k]].Quantity;
	cout<<"\n\t\tITEM-TYPE : ";
	cout<<data[edit_item[k]].item_type<<endl<<endl;
	cout<<"\t\t > 1. QUANTITY\n";
	cout<<"\t\t > 2. PRICE\n";
	cout<<"\t\t > 3. NAME\n";
	cout<<"\t\t > 4. PRO-NO\n";
	cout<<"\t\t > 5. ITEM-TYPE\n";
	cout<<"\t\t > 6. BACK TO DISPLAY\n> ";
	cin>>edit_choice;
	switch(edit_choice)
		{
			case '1':
				cout<<"\n\t\t"<<"Quantity :  ";
				cin>>data[edit_item[k]].Quantity;
				if(data[edit_item[k]].Quantity<1||data[edit_item[k]].Quantity>1000)
					{
						cout<<"Sorry out of range\n> ";
						cin>>data[edit_item[k]].Quantity;
					}
			break;
			case '2':
					cout<<"\n\t\t"<<"PRICE :  ";
					cin>>data[edit_item[k]].price;
					if(data[edit_item[k]].price<=0||data[edit_item[k]].price>1000)
						{
							cout<<"Sorry out of range\n> ";
							cin>>data[edit_item[k]].price;
						}
			break;
			case '3':
					cout<<"\t\t"<<"Product name :  ";
			   		cin.get();
					gets(data[edit_item[k]].name);
			break;
			case '4':
pro_no:
					cout<<"\t\tPRO-NO : ";
					cin>>data[edit_item[k]].pro_no;
					for(int j=0;j<i;j++)
						{
							if(data[edit_item[k]].pro_no==data[j].pro_no)
								{
									cout<<"please insert correct pro-no";
									goto pro_no;
								}
						}
			break;
			case '5' :
item:
					cout<<"\t\t"<<"ITEM TYPE : ";
					cin>>data[edit_item[k]].item_type;
					if(data[edit_item[k]].item_type>3||data[edit_item[k]].item_type<1)
				{
					cout<<endl<<endl<<"\t\t";
					cout<<"Please input correct item-type\n ";
					goto item;
				 }
			break;
			default:
					display(data);
		}
k++;
wifile(data);
wfile(data);
validation:
	cout<<"Do you want to continue \n";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		{
			goto edit;
		}
	else if(ch=='n'||ch=='N')
		{
			loading();
			system("cls");
			cout<<"\n\n\t\tYou are successfully edited your file !!!\n";
			cout<<"\t\tPress any key to continue...    ";
			getch();
			admin_menu();
		}
	else
	{
	goto validation;
	}

}
void wfile(product data[300])
{
	ofstream txt;
	txt.open("file.txt");
	for(int j=1;j<i;j++)
	{
		txt<<data[j].name<<"\t";
		txt<<data[j].Quantity<<"\t";
		txt<<data[j].price<<"\t";
		txt<<data[j].pro_no<<"\t";
		txt<<data[j].new_pro<<"\t";
		txt<<data[j].notice<<"\t";
		txt<<data[j].item_type<<endl;
	}
	txt.close();
}
void rfile(product data[300])
{
	ifstream txt;
	txt.open("file.txt");
	for(int j=1;j<i;j++)
	{
		txt>>data[j].name;
		txt>>data[j].Quantity;
		txt>>data[j].price;
		txt>>data[j].pro_no;
		txt>>data[j].new_pro;
		txt>>data[j].notice;
		txt>>data[j].item_type;
	}
	txt.close();
}
void wifile(product data[300])
{
	ofstream id;
	id.open("ifile.txt");
	id<<i;
	id.close();
}
void rifile(product data[300])
{
	ifstream id;
	id.open("ifile.txt");
	id>>i;
	id.close();
}
void login()
{
char username[30]={"green"};
	char usrname[30];
	char password[30]={"1234"};
	char pass[30];
	int try_counter=0;
here:
	 system("cls");
	 cout<<"\t\t\n\n\n USER NAME : ";
	 cin>>usrname;
	 cout<<"\t\t\n\n PASSWORD : ";
	 cin>>pass;
	 try_counter++;
	 if(strcmp(username,usrname)==0&&strcmp(pass,password)==0)
		{
	 		admin_menu();
	 	}
	 else if(try_counter<=3)
	 	{
	 		cout<<"\t\t\n\nInvalid username or password \n";
	 		cout<<"Please try again\n";
	 		getch();
	 		goto here;
	 	}
	 else
	 	{
	 		cout<<"Sorry your chance is over\n\n\n\n";
	 		exit(0);

		}
}
 void notf(product data[300])
 {

 	rfile(data);
 	rifile(data);
	 system("cls");
 	for(int j=1;j<i;j++)
 		{
 			if(data[j].Quantity<11&&data[j].notice!=true)
 					{
 						data[j].notice=true;

	 				}
 		}
 	for(int j=1;j<i;j++)
 		{
 			if(data[j].Quantity>=11)
 				{
 					data[j].notice=false;
				 }
 		}
	if(sign==true)
		 {
	 		cout<<"\t\t\n\nYOU ARE ALMOST FINISHING THESE ITEMS :  \n\n";
 			for(int j=1;j<i;j++)
 				{
 					if(data[j].notice==true)
 					cout<<" >  "<<data[j].name<<endl;
 				}
	 		sign=false;
		 	cout<<"Press any key to continue\n";
	        getch();
	        main();
		}
wfile(data);
}

 void statstics(product data[300])
{
	int total_capital=0;
	rifile(data);
	rfile(data);
	for(int j=1;j<i;j++)
		{
			total_capital+=(data[j].Quantity*data[j].price);
		}
	system ("cls");
	cout<<"TOTAL CAPITAL ="<<total_capital<<" Birr";
	total_capital=0;
	getch();
	admin_menu();
}
void help()
{
	system("cls");
	cout<<"===========Go-Green SuperMarket Help Center============\n"<<endl;
	cout<<"If YoU Have Difficulties Understanding the Program This Will Help You Out\n"<<endl;
	cout<<"\t#1.Customer Service----Helps The Customer To Buy The Products He wants and Displays The Receipt\n"<<"\t#2.Administrative-----Helps Staff Members To add,edit,delete and other things Easily\n";
	cout<<"\t#3.Notification----This Tabs Helps Us to Get Notified When We have Finished Products\n"<<endl<<"If you Selected The Administrator Service You Will be asked To enter username and password Because It's Only For Authorized Person\n\n\n";
	cout<<"In The Administrative Tab You Will Find\n"<<"\t# ADD---TO enter Products\n"<<"\t# Display---Show All the Products That we have\n"<<"\t# Sort list----To Make Order of the Products either in NAME OR PRICE\n";
	cout<<"\t# Delete---To Erase data from the Products\n"<<"\t# Search and Edit-----To Find products easily and modify them\n\n\n";
	cout<<"OR You Can Contact US through: \n"<<"\t--go-green234@GMAIL.com\n\t--#+251913616046 / #+251941924816\n\t--OR You Can visit Our Website gogreensuper.org\n\n\n";
	cout<<":) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :)\n Thanks For Using Our Software\n  ";
	getch();
	main();
}

