#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<process.h>
#include<time.h>
 
void header(int);
int login(int);
void footer();
void menu();
void showtime();
void admin_menu();
int admin_ctrl(int);
int init_all(int);
void logged_off();
char convert(char []);
int new_product_main(int);
void all_product_main(int);	// ALL PRODUCT DATA
int search_product_main(int&);	// SEARCH PRODUCT DATA
int delete_product_main(int);	// DELETE PRODUCT DATA
int edit_product_main(int&);	// EDIT PRODUCT DATA
int billing_main(int);
int parental_ctrl();
int sales_history();
int invoice_history();
 
char username[20];	//
char password[20];	//
int invoice=1;	//
 
 
//<||===========CLASS DEFINITION===========||>
class product
{
private:
void convert(char []);
protected:
public:
float price;
char barcode[20];
char prod_name[50];
int enter_data(int,int);
int enter_data(int,char []);	// FOR JUMPING FROM SEARCH AND EDIT
void show_data();
int edit_data(char[],int,int);
float give_price(int qty=1)
{
return qty*price;
}
int scan(char [],int);
product()
{
strcpy(barcode,"0000");
strcpy(prod_name,"");
price=0.0;
}
};
 
class sales:public product
{
private:
void convert(char []);
public:
struct item_list
{
char item_bc[20];
char item_name[50];
float item_rate;
int qty;
float tot_prc_item;
};
item_list item[150];
int invoice_no;
int new_bill(int);
float total_bill;
void show_item(item_list,int);
int item_ctr;
float discount;
float net_total;
 
};
//<||===========CLASS DEFINITION END===========||>
 
//<||===========CREATE OBJECT===========||>
product prod[500];
product try_prod[500];
sales sale[500];
//<||===========CREATE OBJECT END===========||>
 
int product::enter_data(int i,int times)
{
int flag=0;
char temp_price[10];
do
{
BARCODE:
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag&&times==1)
cout<<"\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(!flag&&times!=1)
cout<<"\t\t\t\t\t\t HIT \'0\' TO SAVE & EXIT <<";
if(flag==1&&times!=1)
cout<<"!!.....|| BARCODE EXISTS ||.....!!\t\t HIT \'0\' TO SAVE & EXIT <<";
if(flag==1&&times==1)
cout<<"!!.....|| BARCODE EXISTS ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==2&&times==1)
cout<<"!!.....|| ENTER THE ITEM BARCODE ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==2&&times!=1)
cout<<"!!.....|| ENTER THE ITEM BARCODE ||.....!!\t HIT \'0\' TO SAVE & EXIT <<";
if(flag==3&&times==1)
cout<<"!!.....|| INVALID BARCODE ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==3&&times!=1)
cout<<"!!.....|| INVALID BARCODE ||.....!!\t\t HIT \'0\' TO SAVE & EXIT <<";
cout<<"\n\n";
cout<<i<<"."<<'\t';
cin.getline(barcode,20);
convert("barcode");	//CONVERT TO CAPITAL
flag=0;
if(!strcmp(barcode,""))
flag=2;
if(flag!=2)
flag=scan("barcode",i);	//CHECKING BARCODE REPTITION
if(strlen(barcode)>15)
flag=3;
if(!strcmp(barcode,"0"))	//EXIT
{
if(times!=1)
{
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n\n";
cout<<" >> SAVING DATA...."<<endl;
for(i=0;i<=700000000;i++);
}
return 0;
}
}while(flag);
PRODUCT:
flag=0;
do
{
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag)
cout<<"\t\t\t\t\t\t HIT \'0\' TO EDIT BARCODE <<";
if(flag==1)
cout<<"!!.....|| ENTER THE PRODUCT NAME ||.....!!\t HIT \'0\' TO EDIT BARCODE <<";
if(flag==2&&flag!=1)
cout<<"!!.....|| ATLEAST 1 ALPHABET REQD. ||.....!!\t HIT \'0\' TO EDIT BARCODE <<";
if(flag==3&&flag!=2&&flag!=1)
cout<<"!!.....|| PRODUCT NAME EXISTS ||.....!!\t\t HIT \'0\' TO EDIT BARCODE <<";
if(flag==4&&flag!=3&&flag!=2&&flag!=1)
cout<<"!!.....|| PRODUCT NAME TOO LONG ||.....!!\t HIT \'0\' TO EDIT BARCODE <<";
flag=0;
cout<<"\n\n";
if(strlen(barcode)>=8)
cout<<i<<"."<<'\t'<<barcode<<"\t\t";
else
cout<<i<<"."<<'\t'<<barcode<<"\t\t\t";
cin.getline(prod_name,50);
if(!strcmp(prod_name,""))
flag=1;
if(strlen(prod_name)>40)
{
flag=4;
}
if(flag!=1&&flag!=4)
flag=scan(prod_name,-1);	//ONLY DIGITS ??
convert("prod_name");	//CONVERT TO CAPITAL
if(i!=1)
{
for(int num=1;num<i;++num)
{
if(!strcmp(prod[num].prod_name,prod[i].prod_name))
{
flag=3;
break;
}
}
}
}while(flag);
flag=0;
if(!strcmp(prod_name,"0"))
goto BARCODE;
do
{
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag)
cout<<"\t\t\t\t\t HIT \'0\' TO EDIT PRODUCT NAME <<";
if(flag==2)
cout<<"!!.....|| ENTER THE PRODUCT PRICE ||.....!! HIT \'0\' TO EDIT PRODUCT NAME <<";
if(flag==1)
cout<<"!.....INVALID PRICE.....!\t\t\tHIT \'0\' TO EDIT PRODUCT NAME <<";
flag=0;
cout<<"\n\n";
if(strlen(barcode)>=8)
{
if(strlen(prod_name)>30)
cout<<i<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<endl<<"\t\t\t\t\t\t\t\t";
else if(strlen(prod_name)>=24)
cout<<i<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t";
else if(strlen(prod_name)>=16)
cout<<i<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t";
else if(strlen(prod_name)>=8)
cout<<i<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t\t";
else
cout<<i<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t\t\t";
}
else
{
if(strlen(prod_name)>30)
cout<<i<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<endl<<"\t\t\t\t\t\t\t\t";
else if(strlen(prod_name)>=24)
cout<<i<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t";
else if(strlen(prod_name)>=16)
cout<<i<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t";
else if(strlen(prod_name)>=8)
cout<<i<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t\t";
else
cout<<i<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t\t\t";
}
cout<<"SR ";
cin.getline(temp_price,10);
flag=scan(temp_price,0);	//CHECKING FOR ALPHABET IN 'PRICE'
convert(temp_price);
if(!strcmp(temp_price,""))
flag=2;
if(!strcmp(temp_price,"0"))
{
goto PRODUCT;
}
}while(flag);
price=atof(temp_price);
return 1;
}
 
int product::enter_data(int sno,char bc[])
{
int flag=0,i=0;
char temp_price[10];
strcpy(barcode,bc);
PRODUCT:
flag=0;
do
{
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag)
cout<<"\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==1)
cout<<"!!.....|| ENTER THE PRODUCT NAME ||.....!!\t HIT \'0\' TO GO BACK <<";
if(flag==2&&flag!=1)
cout<<"!!.....|| ATLEAST 1 ALPHABET REQD. ||.....!!\t HIT \'0\' GO BACK <<";
if(flag==3&&flag!=2&&flag!=1)
cout<<"!!.....|| PRODUCT NAME EXISTS ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==4&&flag!=3&&flag!=2&&flag!=1)
cout<<"!!.....|| PRODUCT NAME TOO LONG ||.....!!\t HIT \'0\' TO GO BACK <<";
flag=0;
cout<<"\n\n";
if(strlen(barcode)>=8)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t";
else
cout<<sno<<"."<<'\t'<<barcode<<"\t\t\t";
cin.getline(prod_name,50);
if(!strcmp(prod_name,""))
flag=1;
if(strlen(prod_name)>40)
{
flag=4;
}
if(flag!=1&&flag!=4)
flag=scan(prod_name,-1);	//ONLY DIGITS ??
convert("prod_name");	//CONVERT TO CAPITAL
if(sno!=1)
{
for(int num=1;num<sno;++num)
{
if(!strcmp(prod[num].prod_name,prod[sno].prod_name))
{
flag=3;
break;
}
}
}
}while(flag);
flag=0;
if(!strcmp(prod_name,"0"))
return 0;
do
{
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag)
cout<<"\t\t\t\t\t HIT \'0\' TO EDIT PRODUCT NAME <<";
if(flag==2)
cout<<"!!.....|| ENTER THE PRODUCT PRICE ||.....!! HIT \'0\' TO EDIT PRODUCT NAME <<";
if(flag==1)
cout<<"!.....INVALID PRICE.....!\t\t\tHIT \'0\' TO EDIT PRODUCT NAME <<";
flag=0;
cout<<"\n\n";
if(strlen(barcode)>=8)
{
if(strlen(prod_name)>30)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<endl<<"\t\t\t\t\t\t\t\t";
else if(strlen(prod_name)>=24)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t";
else if(strlen(prod_name)>=16)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t";
else if(strlen(prod_name)>=8)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t\t";
else
cout<<sno<<"."<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t\t\t";
}
else
{
if(strlen(prod_name)>30)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<endl<<"\t\t\t\t\t\t\t\t";
else if(strlen(prod_name)>=24)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t";
else if(strlen(prod_name)>=16)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t";
else if(strlen(prod_name)>=8)
cout<<sno<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t\t";
else
cout<<sno<<"."<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t\t\t";
}
cout<<"SR ";
cin.getline(temp_price,10);
flag=scan(temp_price,0);	//CHECKING FOR ALPHABET IN 'PRICE'
convert(temp_price);
if(!strcmp(temp_price,""))
flag=2;
if(!strcmp(temp_price,"0"))
{
goto PRODUCT;
}
}while(flag);
price=atof(temp_price);
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n\n";
cout<<" >> SAVING DATA...."<<endl;
for(i=0;i<=700000000;i++);
return 1;
}
 
void product::convert(char check[])
{
int i=0;
if(!strcmp(check,"barcode"))
{
for(i=0;barcode[i]!='\0';++i)
barcode[i]=toupper(barcode[i]);
}
if(!strcmp(check,"prod_name"))
{
for(i=0;prod_name[i]!='\0';++i)
prod_name[i]=toupper(prod_name[i]);
}
}
 
int product::scan(char check[],int num)
{
int i=0,dot=0,alpha=0;
if(!strcmp(check,"barcode"))	//CHECKING BARCODE REPITITION
{
for(i=0;i<num;++i)
{
if(!strcmp(prod[num].barcode,prod[i].barcode))
return 1;
}
}
if(!strcmp(check,"product"))
{
for(i=1;i<num;++i)
{
if(!strcmp(prod[num].prod_name,prod[i].prod_name))
return 3;
}
}
if(num==-1)	//CHECKING PRODUCT NAME IS GENIUNE || !
{
if(!strcmp(check,"0"))
{
return 0;
}
for(i=0;check[i]!='\0';++i)
{
if(isalpha(check[i]))
return 0;
}
return 2;
}
if(strcmp(check,"barcode"))	//CHECKING PRICE IS GENUINE || !
{
for(i=0;check[i]!='\0';++i)
{
if(isalpha(check[i]))
return 1;
if(!isdigit(check[i])&&check[i]!='.')
return 1;
if(check[i]=='.')
++dot;
if(dot>1)
return 1;
}
}
return 0;
}
 
void product::show_data()
{
if(strlen(barcode)>=8)
{
if(strlen(prod_name)>30)
cout<<'\t'<<barcode<<"\t\t"<<prod_name<<endl<<"\t\t\t\t\t\t\t\t"<<price<<" SR";
else if(strlen(prod_name)>=24)
cout<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t"<<price<<" SR";
else if(strlen(prod_name)>=16)
cout<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t"<<price<<" SR";
else if(strlen(prod_name)>=8)
cout<<'\t'<<setw(3)<<barcode<<"\t\t"<<prod_name<<"\t\t\t"<<price<<" SR";
else
cout<<'\t'<<barcode<<"\t\t"<<prod_name<<"\t\t\t\t"<<price<<" SR";
}
else
{
if(strlen(prod_name)>30)
cout<<'\t'<<barcode<<"\t\t\t"<<prod_name<<endl<<"\t\t\t\t\t\t\t\t"<<price<<" SR";
else if(strlen(prod_name)>=24)
cout<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t"<<price<<" SR";
else if(strlen(prod_name)>=16)
cout<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t"<<price<<" SR";
else if(strlen(prod_name)>=8)
cout<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t\t"<<price<<" SR";
else
cout<<'\t'<<barcode<<"\t\t\t"<<prod_name<<"\t\t\t\t"<<price<<" SR";
}	
}
 
int product::edit_data(char choice[],int sno,int post)
{
if(!strcmp(choice,"barcode"))
{
EDIT_BARCODE:
int flag=0,i=0;
char new_barcode[20],choice[5],news[150]="ITEM EDITED";
do
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" -----------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" OLD BARCODE : "<<barcode<<endl;
cout<<" NEW BARCODE : "<<""<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag||flag==2)
cout<<"!!.....|| ENTER NEW BARCODE ||.....!!\t\t\t HIT \'0\' TO GO BACK <<";	
if(flag==1)
cout<<"!!.....|| BARCODE EXISTS ||.....!!\t\t\t HIT \'0\' TO GO BACK <<";
flag=0;
cout<<"\n\n";
cout<<" ";
cin.getline(new_barcode,20);
if(!strcmp(new_barcode,""))
flag=2;
if(!strcmp(new_barcode,"0"))
{
return 0;
}
if(flag!=2)
{
for(i=0;new_barcode[i]!='\0';++i)
new_barcode[i]=toupper(new_barcode[i]);	//CONVERT TO CAPITAL
for(i=0;i<sno;++i)
{
if(i!=post)
if(!strcmp(new_barcode,prod[i].barcode))
flag=1;
}	//CHECKING BARCODE REPTITION
}
}while(flag);
flag=0;
do
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" OLD BARCODE : "<<barcode<<endl;
cout<<" NEW BARCODE : "<<new_barcode<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n\n";
cout<<" Are You SURE To Change The BARCODE Of This Item ? >> Y : YES"<<endl<<endl;
cout<<" >> N : NO"<<endl<<endl;
cout<<" >> G : GO BACK"<<endl;
cout<<"\n";
if(flag==1)
cout<<" !.....ENTER Y / N / G.....!";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
cout<<"\n\n";
flag=0;
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);	
if(!strcmp(choice,""))
flag=1;
if(flag!=1)
if(strcmpi(choice,"Y")&&strcmpi(choice,"N")&&strcmpi(choice,"G"))
flag=2;
}while(flag);
if(!strcmpi(choice,"G"))
{
goto EDIT_BARCODE;
}
if(!strcmpi(choice,"N"))
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| BARCODE NOT CHANGED ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\nHit ENTER To Continue...";
cin.get();
return 0;
}
if(!strcmpi(choice,"Y"))
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
strcpy(barcode,new_barcode);
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" CHANGING BARCODE......"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
for(i=0;i<=700000000;i++);
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| BARCODE CHANGED SUCCESSFULLY ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\nHit ENTER To Continue...";
cin.get();
return 0;
}
}
if(!strcmp(choice,"product"))
{
EDIT_PRODUCT_NAME:
int flag=0,i=0;
char new_name[50],choice[5];
do
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" -----------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" OLD NAME : "<<prod_name<<endl;
cout<<" NEW NAME : "<<""<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag||flag==1)
cout<<"!!.....|| ENTER NEW PRODUCT NAME ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==2&&flag!=1)
cout<<"!!.....|| ATLEAST 1 ALPHABET REQD. ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==3&&flag!=2&&flag!=1)
cout<<"!!.....|| PRODUCT NAME EXISTS ||.....!!\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==4&&flag!=3&&flag!=2&&flag!=1)
cout<<"!!.....|| PRODUCT NAME TOO LONG ||.....!!\t HIT \'0\' TO EDIT BARCODE <<";
flag=0;
cout<<"\n\n";
cout<<" ";
cin.getline(new_name,50);
if(!strcmp(new_name,""))
flag=1;
if(!strcmp(new_name,"0"))
{
return 0;
}
if(strlen(new_name)>40)
{
flag=4;
}
for(i=0;new_name[i]!='\0';++i)
new_name[i]=toupper(new_name[i]);	//CONVERT TO CAPITAL
if(flag!=1&&flag!=4)
flag=scan(new_name,-1);
for(i=1;i<sno;++i)
{
if(i!=post)
if(!strcmp(new_name,prod[i].prod_name))
{
flag=3;
break;
}
}
}while(flag);
flag=0;
do
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" OLD NAME : "<<prod_name<<endl;
cout<<" NEW NAME : "<<new_name<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n\n";
cout<<" Are You SURE To Change The NAME Of This Item ? >> Y : YES"<<endl<<endl;
cout<<" >> N : NO"<<endl<<endl;
cout<<" >> G : GO BACK"<<endl;
cout<<"\n";
if(flag==1)
cout<<" !.....ENTER Y / N / G.....!";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
cout<<"\n\n";
flag=0;
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);	
if(!strcmp(choice,""))
flag=1;
if(flag!=1)
if(strcmpi(choice,"Y")&&strcmpi(choice,"N")&&strcmpi(choice,"G"))
flag=2;
}while(flag);
if(!strcmpi(choice,"G"))
{
goto EDIT_PRODUCT_NAME;
}
if(!strcmpi(choice,"N"))
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| PRODUCT NAME NOT CHANGED ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\nHit ENTER To Continue...";
cin.get();
return 0;
}
if(!strcmpi(choice,"Y"))
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
strcpy(prod_name,new_name);
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" CHANGING PRODUCT NAME......"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
for(i=0;i<=700000000;i++);
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| PRODUCT NAME CHANGED SUCCESSFULLY ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\nHit ENTER To Continue...";
cin.get();
return 0;
}
}
if(!strcmp(choice,"price"))
{
EDIT_PRODUCT_PRICE:
int flag=0,i=0;
char temp_price[10],choice[5];
do
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" -----------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" OLD PRICE : "<<give_price()<<" SR"<<endl;
cout<<" NEW PRICE : "<<""<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag||flag==2)
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==1)
cout<<"!.....INVALID PRICE.....!\t\t\t\t HIT \'0\' TO GO BACK <<";
flag=0;
cout<<"\n\n";
cout<<" ";
cin.getline(temp_price,10);
flag=scan(temp_price,0);	//CHECKING FOR ALPHABET IN 'PRICE'
convert(temp_price);
if(!strcmp(temp_price,""))
flag=2;
if(!strcmp(temp_price,"0"))
return 0;
}while(flag);
flag=0;
do
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" OLD PRICE : "<<give_price()<<" SR"<<endl;
cout<<" NEW PRICE : "<<temp_price<<" SR"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n\n";
cout<<" Are You SURE To Change The PRICE Of This Item ? >> Y : YES"<<endl<<endl;
cout<<" >> N : NO"<<endl<<endl;
cout<<" >> G : GO BACK"<<endl;
cout<<"\n";
if(flag==1)
cout<<" !.....ENTER Y / N / G.....!";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
cout<<"\n\n";
flag=0;
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);	
if(!strcmp(choice,""))
flag=1;
if(flag!=1)
if(strcmpi(choice,"Y")&&strcmpi(choice,"N")&&strcmpi(choice,"G"))
flag=2;
}while(flag);
if(!strcmpi(choice,"G"))
{
goto EDIT_PRODUCT_PRICE;
}
if(!strcmpi(choice,"N"))
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| PRODUCT PRICE NOT CHANGED ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\nHit ENTER To Continue...";
cin.get();
return 0;
}
if(!strcmpi(choice,"Y"))
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
price=atof(temp_price);
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" CHANGING PRODUCT PRICE......"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
for(i=0;i<=700000000;i++);
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" --------"<<endl;
cout<<"\n\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| PRODUCT PRICE CHANGED SUCCESSFULLY ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\nHit ENTER To Continue...";
cin.get();
return 0;
}
}
return 1;
}
 
int sales::new_bill(int sno)
{
int srl=1,i=0,flag=0,j=0,k=0,z=0;
float disc=0.0;
char temp_qty[6],choice[5],temp_dsc[10],temp_cash[10];
total_bill=0.0;
ENTER_BC_BILL:
flag=0;
do
{
if(flag==12)
flag=0;
if(srl>1)
{
total_bill=0.0;
for(k=1;k<srl;++k)
total_bill+=item[k].tot_prc_item;
}
header(1);
cout<<"\t\t\t\t SALES & INVOICE"<<endl;
cout<<"\t\t\t\t ---------------"<<endl<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<::invoice<<"\t\t\t\t\t"<<" "<<total_bill<<" SR"<<setw(10)<<"TOTAL <<";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag&&srl==1)
cout<<"\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(!flag&&srl>1)
{
cout<<" >> HIT \'0\' TO EDIT PREVIOUS ITEM\t\t HIT \'ENTER\' TO CHECK OUT <<";
}
if(flag==1)
cout<<"!!.....|| ENTER BARCODE ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==2&&srl==1)
cout<<"!!.....|| INVALID BARCODE ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==2&&srl>1)
cout<<"!!.....|| INVALID BARCODE ||.....!!\t\t HIT \'ENTER\' TO CHECK OUT <<";
cout<<"\n\n";
flag=0;
if(srl>1)
{
for(k=1;k<srl;++k)
{
cout<<k<<".";show_item(item[k],1);
}
 
}
cout<<srl<<"."<<'\t';
cin.getline(item[srl].item_bc,20);
if(!strcmp(item[srl].item_bc,"0")&&srl==1)
break;
if(!strcmp(item[srl].item_bc,"0")&&srl>1)
{
--srl;
goto ENTER_BC_BILL;
}
if(!strcmp(item[srl].item_bc,"")&&srl==1)
flag=1;
if(!strcmp(item[srl].item_bc,"")&&srl>1)
break;
if(flag!=1)
{
for(i=1;i<sno;++i)
{
if(!strcmpi(item[srl].item_bc,prod[i].barcode))
{
flag=5;
strcpy(item[srl].item_name,prod[i].prod_name);
 
item[srl].item_rate=prod[i].give_price();
item[srl].item_bc[7]='\0';
for(k=0;item[srl].item_bc[k]!='\0';++k)
item[srl].item_bc[k]=toupper(item[srl].item_bc[k]);
break;
}
else
flag=2;
}
}
if(flag==5)
{
flag=0;
do
{
header(1);
cout<<"\t\t\t\t SALES & INVOICE"<<endl;
cout<<"\t\t\t\t ---------------"<<endl<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<::invoice<<"\t\t\t\t\t"<<" "<<total_bill<<" SR"<<setw(10)<<"TOTAL <<";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
if(!flag)
cout<<"\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==5)
cout<<"!!.....|| ENTER QUANTITY ||.....!!\t\t HIT \'0\' TO GO BACK <<";
if(flag==6)
cout<<"!!.....|| INVALID QUANTITY ||.....!!\t\t\t HIT \'0\' TO GO BACK <<";
flag=0;
cout<<"\n\n";	
if(srl>1)
{
for(k=1;k<srl;++k)
{
cout<<k<<".";show_item(item[k],1);
}
}
cout<<srl<<".";show_item(item[srl],0);
cin.getline(temp_qty,6);
if(!strcmp(temp_qty,""))
flag=5;
if(!strcmp(temp_qty,"0"))
goto ENTER_BC_BILL;
if(flag!=5)
{
for(j=0;temp_qty[j]!='\0';++j)
{
if(!isdigit(temp_qty[j]))
{
flag=6;
break;
}
}
}
if(flag==0)
{
if(srl!=1)
{
for(z=1;z<srl;z++)
{
if(!strcmp(item[z].item_bc,item[srl].item_bc))
{
item[z].qty+=atoi(temp_qty);
item[z].tot_prc_item=item[z].qty*item[z].item_rate;
flag=2;
--srl;
}
}
}
if(flag!=2)
{
item[srl].qty=atoi(temp_qty);
item[srl].tot_prc_item=item[srl].qty*item[srl].item_rate;
}
flag=0;
}
}while(flag);
flag=12;
++srl;
}
}while(flag);
item_ctr=(srl-1);
if(!strcmp(item[srl].item_bc,"0"))
return 0;
flag=0;
do
{
header(1);
cout<<"\t\t\t\t SALES & INVOICE"<<endl;
cout<<"\t\t\t\t ---------------"<<endl<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<::invoice<<"\t\t\t\t\t"<<" "<<total_bill<<" SR"<<setw(10)<<"TOTAL <<";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n";
if(srl>1)
{
for(k=1;k<srl;++k)
{
cout<<k<<".";show_item(item[k],1);
}
 
}
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n\n";
cout<<" Are You SURE To CHECK OUT ? >> ENTER : YES"<<endl<<endl;
cout<<" >> N : NO "<<endl<<endl;
cout<<" >> C : CANCEL INVOICE"<<endl;
cout<<"\n";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
flag=0;
cout<<"\n\n";
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);	
if(!strcmp(choice,""))
break;
if(!strcmpi(choice,"C"))
return 0;
if(!strcmpi(choice,"N"))
goto ENTER_BC_BILL;
if(strcmpi(choice,"N")&&strcmpi(choice,"C"))
flag=2;
}while(flag);
flag=0;
int dot=0;
do
{
header(1);
cout<<"\t\t\t\t SALES & INVOICE"<<endl;
cout<<"\t\t\t\t ---------------"<<endl<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<::invoice<<"\t\t\t\t\t";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n";
if(srl>1)
{
for(k=1;k<srl;++k)
{
cout<<k<<".";show_item(item[k],1);
}
 
}
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> TOTAL : "<<total_bill<<" SR"<<endl;
dot=0;
cout<<"\n";
if(flag==1)
{	cout<<"\t\t\t\t ";cout<<"!....INVALID DISCOUNT....!";}
if(flag==2)
{	cout<<"\t\t ";cout<<"!....DISCOUNT SHOULD NOT EXCEED 7.5% OF TOTAL....!";}
flag=0;
cout<<"\n\n";
if(total_bill<=100)
{
discount=0.00;
cout<<"\t\t\t\t\t\t ";cout<<" >> DISCOUNT : "<<discount<<" SR"<<endl;
}
else
{
cout<<"\t\t\t\t\t\t ";cout<<" >> DISCOUNT : ";
cin.getline(temp_dsc,10);
if(!strcmp(temp_dsc,""))
{
discount=0.0;
break;
}
for(k=0;temp_dsc[k]!='\0';++k)
{
if(isalpha(temp_dsc[k]))
{
flag=1;
break;
}
if(!isdigit(temp_dsc[k])&&temp_dsc[k]!='.')
{
flag=1;
break;
}
if(temp_dsc[k]=='.')
++dot;
if(dot>1)
{
flag=1;
break;
}
}
}
if(atof(temp_dsc)>0.075*total_bill)
flag=2;
}while(flag);
discount=atof(temp_dsc);
net_total=total_bill-discount;
flag=0;
do
{
header(1);
cout<<"\t\t\t\t SALES & INVOICE"<<endl;
cout<<"\t\t\t\t ---------------"<<endl<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<::invoice<<"\t\t\t\t\t";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n";
if(srl>1)
{
for(k=1;k<srl;++k)
{
cout<<k<<".";show_item(item[k],1);
}
 
}
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> TOTAL : "<<total_bill<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> DISCOUNT : "<<discount<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> NET TOTAL : "<<net_total<<" SR"<<endl<<endl;
cout<<"\n";
if(flag==1)
cout<<"\t\t\t\t\t !....INVALID AMOUNT....!";
if(flag==2)
cout<<"\t\t\t\t\t!....ENTER AMOUNT PAID....!";
if(flag==3)
cout<<"\t\t\t\t\t!....AMOUNT LESS THAN TOTAL....!";
flag=0;dot=0;
cout<<"\n\n";
cout<<"\t\t\t\t\t\t ";cout<<" >> CASH : ";
cin.getline(temp_cash,10);
if(!strcmp(temp_cash,""))
flag=2;
if(flag!=2)
{
for(k=0;temp_cash[k]!='\0';++k)
{
if(isalpha(temp_cash[k]))
{
flag=1;
break;
}
if(!isdigit(temp_cash[k])&&temp_cash[k]!='.')
{
flag=1;
break;
}
if(temp_cash[k]=='.')
++dot;
if(dot>1)
{
flag=1;
break;
}
}
}
if(!flag)
{
if(atof(temp_cash)<net_total)
flag=3;
}
}while(flag);
header(1);
cout<<"\t\t\t\t SALES & INVOICE"<<endl;
cout<<"\t\t\t\t ---------------"<<endl<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<::invoice<<"\t\t\t\t\t";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n";
if(srl>1)
{
for(k=1;k<srl;++k)
{
cout<<k<<".";show_item(item[k],1);
}
 
}
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> TOTAL : "<<total_bill<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> DISCOUNT : "<<discount<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> NET TOTAL : "<<net_total<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> CASH : "<<temp_cash<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> CHANGE : "<<atof(temp_cash)-net_total<<" SR"<<endl<<endl;
cout<<"================================================================================"<<endl;
cout<<" *** THANKS FOR SHOPPING WITH AMASI SUPERMARKET *** "<<endl;
cout<<"================================================================================"<<endl;
cin.get();
 
}
 
void sales::show_item(item_list item,int s=1)
{
if(s==1)
{
if(strlen(item.item_name)>=24)
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t"<<item.item_rate<<" SR"<<'\t'<<item.qty<<'\t'<<item.tot_prc_item<<" SR"<<endl<<endl;
else if(strlen(item.item_name)>=16)
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t\t"<<item.item_rate<<" SR"<<'\t'<<item.qty<<'\t'<<item.tot_prc_item<<" SR"<<endl<<endl;
else if(strlen(item.item_name)>=8)
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t\t\t"<<item.item_rate<<" SR"<<'\t'<<item.qty<<'\t'<<item.tot_prc_item<<" SR"<<endl<<endl;
else
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t\t\t\t"<<item.item_rate<<" SR"<<'\t'<<item.qty<<'\t'<<item.tot_prc_item<<" SR"<<endl<<endl;
}
if(s==0)
{
if(strlen(item.item_name)>=24)
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t"<<item.item_rate<<" SR"<<'\t';
else if(strlen(item.item_name)>=16)
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t\t"<<item.item_rate<<" SR"<<'\t';
else if(strlen(item.item_name)>=8)
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t\t\t"<<item.item_rate<<" SR"<<'\t';
else
cout<<'\t'<<item.item_bc<<"\t\t"<<item.item_name<<"\t\t\t\t"<<item.item_rate<<" SR"<<'\t';
}
 
}
 
void main()
{
//<||===========VARIABLE DECLARATIONS===========||>
int i=0,total=0,flag=0,go=0,sno=1;
char menuchoice[5],temp_user[20],temp_pwd[20],temp_sno[5];
char temp[10];
//<||===========VARIABLE DECLARATIONS OVER===========||>
fstream fin;
fstream dataread;
fstream invoiceno;
fstream getbillitems;
fstream renew;
fin.open("parental.txt",ios::in);	
fin.getline(temp_user,20,'\n');	//
fin.getline(temp_pwd,20,'\n');	//
if(!strcmp(temp_user,"")&&!strcmp(temp_pwd,""))
{
strcpy(temp_user,"amasi");
strcpy(temp_pwd,"amasi");
}
fin.close();	// >> PARENTAL ACTIONS
strcpy(::username,temp_user);	//
strcpy(::password,temp_pwd);	//
fstream serial;
serial.open("serial.txt",ios::in);
serial.getline(temp_sno,5);
if(!strcmp(temp_sno,"")||!strcmp(temp_sno,"0"))
strcpy(temp_sno,"1");
serial.close();
sno=atoi(temp_sno);
dataread.open("dataitems.txt",ios::in);
if(sno>1)
{
for(i=1;i<sno;++i)
{
dataread.getline(prod[i].barcode,20,'\n');
dataread.getline(prod[i].prod_name,50,'\n');
dataread.getline(temp,10,'\n');
prod[i].price=atof(temp);
}
}
dataread.close();
invoiceno.open("invoice.txt",ios::in);
invoiceno.getline(temp,10);
invoiceno.close();
if(!strcmp(temp,"")||!strcmp(temp,"0"))
::invoice=1;
else
::invoice=atoi(temp);
getbillitems.open("billitems.dat",ios::in|ios::binary);
for(i=1;i<::invoice;++i)
{
getbillitems.read((char*)&sale[i],sizeof(sales));
}
getbillitems.close();
header(0);
//go=login(0);
go=0;
do
{
for(i=1;i<sno;++i)
try_prod[i]=prod[i];
renew.open("items.dat",ios::out|ios::binary);
for(i=1;i<sno;++i)
{
renew.write((char*)&try_prod[i],sizeof(try_prod[i]));//truing to convert to binary file
}
 
renew.close();
renew.open("items.dat",ios::in|ios::binary);
for(i=1;i<sno;++i)
{
renew.read((char*)&try_prod[i],sizeof(try_prod[i]));//truing to convert to binary file
}
renew.close();
do
{
menu();
total=0;
cout<<"\n";
if(go==1)
cout<<"!.....INVALID CHOICE.....!";
if(go==2)
cout<<"!.....PLEASE CREATE A DATA ENTRY BEFORE USING THIS OPTION.....!";
if(go==4)
cout<<"!.....NO SALES PERFORMED YET.....!";
cout<<"\n\n";
go=0;
cout<<"Enter Your CHOICE : ";
cin.getline(menuchoice,5);
}while(!strcmp(menuchoice,""));
for(i=0;menuchoice[i]!='\0';++i)
{
total+=menuchoice[i];
}
go=0;
switch(total)
{
case 49: //1. NEW PRODUCT
sno=new_product_main(sno);
break;
case 50: //2. EDIT PRODUCT
if(sno==1)
{
go=2;
break;
}
go=edit_product_main(sno);
if(sno>1)
{
renew.open("dataitems.txt",ios::out);
for(i=1;i<sno;++i)
{
renew<<prod[i].barcode<<'\n'<<prod[i].prod_name<<'\n'<<prod[i].price<<"\n";
}
renew.close();
}
if(sno==1)
{
renew.open("dataitems.txt",ios::out);
renew.close();
}
break;
case 51: //3. ALL PRODUCT DATA
if(sno==1)
{
go=2;
break;
}
all_product_main(sno);
break;
case 52: //4. SEARCH DATA
if(sno==1)
{
go=2;
break;
}
go=search_product_main(sno);
renew.open("dataitems.txt",ios::out);
for(i=1;i<sno;++i)
{
renew<<prod[i].barcode<<'\n'<<prod[i].prod_name<<'\n'<<prod[i].price<<"\n";
}
renew.close();
break;
case 53: //5. DELETE DATA
int temp;
if(sno==1)
{
go=2;
break;
}
temp=delete_product_main(sno);
if(!temp)
{
go=3;
}
else
{
if(sno!=1)
--sno;
}
if(sno>1)
{
renew.open("dataitems.txt",ios::out);
for(i=1;i<sno;++i)
{
renew<<prod[i].barcode<<'\n'<<prod[i].prod_name<<'\n'<<prod[i].price<<"\n";
}
renew.close();
}
if(sno==1)
{
renew.open("dataitems.txt",ios::out);
renew.close();
}
break;
case 54: //6. INVOICE & SALES
if(sno==1)
{
go=2;
break;
}
go=billing_main(sno);
break;
case 55: //7. SALES HISTORY
if(::invoice==1)
{
go=4;
break;
}
sales_history();
break;
case 56: //8. CHANGE USERNAME AND PASSWORD
go=admin_ctrl(sno);
break;
case 57: //10. LOG OFF
menu();
cout<<"\n\n\n";
cout<<"LOGGING OFF..."<<endl;
for(i=0;i<=1000000000;i++);
logged_off();
cin.ignore();
go=login(1);
break;
case 97: //11. EXIT
menu();
cout<<"\n\n\n";
cout<<"LOGGING OFF..."<<endl;
for(i=0;i<=1000000000;i++);
footer();
break;
default:
go=1;
break;
}
if(total!=97&&go==0&&go!=3)	//go=3 ---->> GO BACK TO MAIN MENU
{
cout<<"Hit ENTER To Continue .. ";
if(cin.get()||!cin.get()){}
}
}while(go||!go);
}
 
void header(int s)
{
system("title AMASI");
system("cls");
cout<<"\n\n";
cout<<"\t\t\t WELCOME TO SUPERMARKET DATABASE"<<endl;
cout<<"\t\t\t *********************************"<<endl;
if(s==1)
{
cout<<"\n";
cout<<"\t\t\t ======================="<<endl;
cout<<"\t\t\t || AMASI SUPERMARKET ||"<<endl;
cout<<"\t\t\t ======================="<<endl;
cout<<"\n\n";
showtime();	//DISPLAYS CURRENT DATE AND TIME
}
}
void showtime()
{
time_t t1 = time(0); // get time now
struct tm * now = localtime( & t1 );
if(now->tm_hour<10)cout<<"0";
cout << now->tm_hour << ":";
if(now->tm_min<10)cout<<"0";
cout<< now->tm_min << ":";
if(now->tm_sec<10)cout<<"0";
cout<< now->tm_sec;
cout<<"\t\t\t\t\t\t\t ";
if(now->tm_mday<10)cout<<"0";
cout << now->tm_mday << '-';
if((now->tm_mon+1)<10)cout<<"0";
cout << (now->tm_mon + 1) << '-'
<< (now->tm_year + 1900) <<endl;
cout<<" ";
}
 
int login(int t)
{
int flag=1,i=0;
char usrnme[20],pwd[20];
do
{
do{
header(1);
cout<<"\t\t\t!====AUNTHETICATION REQUIRED====!"<<endl;
cout<<"\t\t\t---------------------------------"<<endl;
if(t==0||t==1)
cout<<"\t\t\t >> TO EXIT HIT \'0\' <<"<<endl<<endl<<endl;
else
cout<<"\t\t\t >> TO GO BACK HIT \'0\' <<"<<endl<<endl<<endl;
if(flag)
cout<<endl<<endl;
if(!flag)	// ERROR MSG
{
cout<<"\t\t!!!!=====USERNAME & PASSWORD DOES NOT MATCH=====!!!!"<<endl<<endl;
}
cout<<" >> USERNAME : ";
cin.getline(usrnme,20);
}while(!strcmp(usrnme,""));
if(!strcmp(usrnme,"0"))
{	// TO EXIT
if(t!=0&&t!=1)
return 3;
footer();
break;
}
do
{
header(1);
cout<<"\t\t\t!====AUNTHETICATION REQUIRED====!"<<endl;
cout<<"\t\t\t---------------------------------"<<endl;
if(t==0||t==1)
cout<<"\t\t\t >> TO EXIT HIT \'0\' <<"<<endl<<endl<<endl;
else
cout<<"\t\t\t >> TO GO BACK HIT \'0\' <<"<<endl<<endl<<endl;
if(flag)
cout<<endl<<endl;
cout<<" >> USERNAME : "<<usrnme;
cout<<endl<<endl;
cout<<" >> PASSWORD : ";
cin.getline(pwd,20);
}while(!strcmp(pwd,""));
if(!strcmp(pwd,"0"))
{	// TO EXIT
if(t!=0&&t!=1)
return 3;
footer();
break;
}
if(!strcmp(usrnme,::username)&&!strcmp(pwd,::password))
flag=1;	// LOGIN SUCCESSFUL !!!
else
flag=0;	// LOGIN UNSUCCESSFUL !!!
}while(!flag);
header(1);
cout<<"\t\t\t!!!!=====LOGIN SUCCESSFUL=====!!!!";
if(t==0)
{
cout<<"\n\n PLEASE WAIT......"<<endl;
for(i=0;i<=1000000000;i++);
cout<<"\n >> MEMORY ALLOTMENT.............COMPLETED!!"<<endl;
for(i=0;i<=1000000000;i++);
cout<<"\n >> DATABASE INITIALIZATION......COMPLETED!!"<<endl;
for(i=0;i<=1000000000;i++);
cout<<"\n >> LOADING COMPLETE !!"<<endl;
cout<<"\n\t\t =======================================";
cout<<"\n\t\t || >> MAXIMISE THE WINDOW << ||";
cout<<"\n\t\t =======================================";
cout<<"\n\n";
cout<<"Hit ENTER To Continue .. ";
if(cin.get()||!cin.get()){return 0;}
}
else if(t==1)
{
cout<<"\n\n\n >> STARTING FROM WHERE YOU LEFT OFF !!..."<<endl;
for(i=0;i<=1000000000;i++);
}
else
{	
cout<<"\n\n\n >> AUTHENTICATING..."<<endl;
for(i=0;i<=1000000000;i++);
}
cout<<endl<<endl;
}
 
char convert(char check[])
{
int i=0;
for(i=0;check[i]!='\0';++i)
if(isalpha(check[i]))
check[i]=toupper(check[i]);
return check[20];
}
 
int new_product_main(int sno)
{
int i=0,go=0,times=1;
fstream serial;
fstream data;
if(sno==1)
{
data.open("dataitems.txt",ios::out);
data.close();
}
data.open("dataitems.txt",ios::app);
for(i=sno;i<=100;i++)
{
go=prod[i].enter_data(i,times);
serial.open("serial.txt",ios::out);
serial<<i<<endl;
serial.close();
++times;
if(!go)
break;
data<<prod[i].barcode<<'\n'<<prod[i].prod_name<<'\n'<<prod[i].price<<"\n";
}
data.close();
header(1);
cout<<"\t\t\t\tNEW PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t-----------------"<<endl<<endl;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n\n";
return i;
}
 
void all_product_main(int sno)
{
int i=0;
header(1);
cout<<"\t\t\t\tALL PRODUCT ENTRIES"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n\n";
cout<<"================================================================================"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"================================================================================"<<endl;	
for(i=1;i<sno;++i)
{
cout<<i<<".";
prod[i].show_data();
cout<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;	
if(i==65)
{
cout<<"\nHit ENTER To VIEW MORE...";
cin.get();
header(1);
cout<<"\t\t\t\tALL PRODUCT ENTRIES"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n\n";
cout<<"================================================================================"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"================================================================================"<<endl;	
}
}
}
 
int search_product_main(int &sno)
{
int i=0,j=0,flag=0,go=0,size=0;
char choice[5],prod_name[50],barcode[20],temp[20]="";
SEARCH_MENU:
do
{
header(1);
cout<<"\t\t\t\tSEARCH PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> 1. SEARCH BY BARCODE "<<endl;
cout<<"\n";
cout<<" >> 2. SEARCH BY PRODUCT NAME "<<endl;
cout<<"\n";
cout<<" >> 3. GO BACK TO MAIN MENU "<<endl;
cout<<"\n";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
cout<<"\n\n";
flag=0;
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);
if(!strcmp(choice,""))
flag=1;
if((strcmp(choice,"1")&&strcmp(choice,"2")&&strcmp(choice,"3"))&&flag!=1)
flag=2;
}while(flag);
if(!strcmp(choice,"1"))	//SEARCH BY BARCODE
{
SEARCH_BC:
do
{
strcpy(temp,barcode);	//IN CASE IF USER SAY TO ADD.....
header(1);
cout<<"\t\t\t\tSEARCH PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> SEARCH BY BARCODE "<<endl;
cout<<" -------------------";
cout<<"\n\n";
if(!flag||flag==1)
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==2)
cout<<" !.....|| BARCODE NOT FOUND ||.....!\t HIT \'N\' TO ADD THIS ITEM <<";
cout<<"\n\n";
cout<<" Enter The ITEM BARCODE : ";
cin.getline(barcode,20);
barcode[20]=convert(barcode);
if(flag==2)
{
if(!strcmpi(barcode,"N"))
{
go=prod[sno].enter_data(sno,temp);
if(go!=0)
++sno;
flag=0;
goto SEARCH_BC;
}
}
flag=0;
if(!strcmp(barcode,""))
flag=1;
if(!strcmp(barcode,"0"))	//GO BACK TO PREVIOUS MENU
break;
if(flag!=1)
{
for(i=1;i<sno;++i)
{
if(!strcmp(barcode,prod[i].barcode))
{
flag=0;	//BARCODE FOUND
break;
}
else
flag=2;	//BARCODE NT FOUND
}
}
}while(flag);
if(!strcmp(barcode,"0"))
goto SEARCH_MENU;
if(flag==0)
{
header(1);
cout<<"\t\t\t\tSEARCH PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> SEARCH RESULTS "<<endl;
cout<<" ---------------";
cout<<"\n\n";
cout<<"================================================================================"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"================================================================================"<<endl;	
cout<<i<<".";
prod[i].show_data();
cout<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
}
}
SEARCH_NAME:
if(!strcmp(choice,"2"))	//SEARCH BY PRODUCT NAME
{
struct get_word
{
char wrd[50];
}words[50];
for(int l=0;l<50;++l)
{
strcpy(words[l].wrd,"");
}
struct prod_word
{
char prod_wrd[50];
int bc;
}prod_words[15000];
for(l=0;l<15000;++l)
{
strcpy(prod_words[l].prod_wrd,"");
prod_words[l].bc=0;
}
char mainword[50];
char query_word[50];
strcpy(mainword,"");
strcpy(query_word,"");
int i=0 , nwrd_query=0 , nwrd_prod=0 , bc_fnd[25] , size=0 , j=0 , k=0, flag=0;
do
{
header(1);
cout<<"\t\t\t\tSEARCH PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> SEARCH BY PRODUCT NAME "<<endl;
cout<<" -----------------------";
cout<<"\n\n";
if(!flag||flag==1)
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==2)
cout<<" !.....|| ITEM NOT FOUND ||.....!\t\t\t HIT \'0\' TO GO BACK <<";
flag=0;
cout<<"\n\n";
cout<<" Enter The ITEM NAME : ";
cin.getline(query_word,50);
if(!strcmp(query_word,""))
flag=1;
if(!strcmp(query_word,"0"))	//GO BACK TO PREVIOUS MENU
break;
if(flag!=1)
{
break;
}
}while(flag);
if(!strcmp(query_word,"0"))
goto SEARCH_MENU;
if(flag!=1)
{
strcpy(mainword,query_word);
for(i=0;query_word[i]!='\0';++i)
{
if(query_word[i]!=' ')
{
words[nwrd_query].wrd[j]=query_word[i];
++j;
}
if(query_word[i]==' '||query_word[i+1]=='\0')
{
words[nwrd_query].wrd[j]='\0';
++nwrd_query;
j=0;
}
}
for(i=1;i<sno;++i)
{
if(!strcmpi(mainword,prod[i].prod_name))
{
bc_fnd[size++]=i;
break;
}
}
int flag=0;
for(i=1;i<sno;++i)
{
for(j=0;prod[i].prod_name[j]!='\0';++j)
{
if(prod[i].prod_name[j]!=' ')
{
prod_words[nwrd_prod].prod_wrd[k]=prod[i].prod_name[j];
++k;
}
if(prod[i].prod_name[j]==' '||prod[i].prod_name[j+1]=='\0')
{
prod_words[nwrd_prod].prod_wrd[k]='\0';
prod_words[nwrd_prod].bc=i;
nwrd_prod++;
k=0;
}
}
for(int h=0;h<nwrd_query;++h)
{
for(int o=0;o<nwrd_prod;++o)
{
if(!strcmpi(words[h].wrd,prod_words[o].prod_wrd))
{
for(int n=0;n<size;++n)
{
if(bc_fnd[n]==prod_words[o].bc)
{
flag=1;
}
}
if(flag!=1)
{
bc_fnd[size]=prod_words[o].bc;
size=size+1;
flag=0;
}
}
}
}
}
nwrd_prod=0;
}
if(flag==0)
{
header(1);
cout<<"\t\t\t\tSEARCH PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> SEARCH RESULTS "<<endl;
cout<<" ---------------";
cout<<"\n\n";
cout<<"================================================================================"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"================================================================================"<<endl;	
for(int g=1;g<sno;++g)
{
for(int f=0;f<size;++f)
{
if(g==bc_fnd[f])
{
prod[g].show_data();
cout<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
}
}
}
}
}
if(!strcmp(choice,"3"))
return 3;
else
return 0;
}
 
int delete_product_main(int sno)
{
int flag=0,i=0,j=0;
char del_barcode[20],choice[5];
FIND_DEL_BC:
flag=0;
do
{
header(1);
cout<<"\t\t\t\tDELETE PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT \t\t >> CONFIRM \t\t >> DELETE PRODUCT"<<endl;
cout<<" -------------"<<endl;
cout<<"\n";
if(!flag||flag==1)
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==2)
cout<<" !.....|| BARCODE NOT FOUND ||.....!\t\t HIT \'0\' TO GO BACK <<";
flag=0;
cout<<"\n\n";
cout<<" Enter The ITEM BARCODE : ";
cin.getline(del_barcode,20);
del_barcode[20]=convert(del_barcode);
if(!strcmp(del_barcode,""))
flag=1;
if(!strcmp(del_barcode,"0"))
return 0;
if(flag!=1)
{
for(i=1;i<sno;++i)
{
if(!strcmp(prod[i].barcode,del_barcode))
{
flag=0;
break;
}
else
flag=2;
}
}
}while(flag);
flag=0;
do
{
header(1);
cout<<"\t\t\t\tDELETE PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT \t\t >> CONFIRM \t\t >> DELETE PRODUCT"<<endl;
cout<<"\t\t\t\t --------"<<endl;
cout<<"\n\n";
cout<<" !!....PRODUCT FOUND....!!";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
prod[i].show_data();
cout<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl<<endl<<endl;
cout<<" Are You Sure You Want To DELETE This Product ? >> Y : YES"<<endl<<endl;
cout<<" >> N : NO"<<endl<<endl;
cout<<" >> C : CHANGE PRODUCT"<<endl;
cout<<"\n";
if(flag==1)
cout<<" !.....ENTER Y / N / C.....!";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
cout<<"\n\n";
flag=0;
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);	
if(!strcmp(choice,""))
flag=1;
if(flag!=1)
if(strcmpi(choice,"Y")&&strcmpi(choice,"N")&&strcmpi(choice,"C"))
flag=2;
}while(flag);
if(!strcmpi(choice,"C"))	// --- >> "CHANGE PRODUCT"
goto FIND_DEL_BC;
if(!strcmpi(choice,"N"))	// --- >> "NO"
{
header(1);
cout<<"\t\t\t\tDELETE PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT \t\t >> CONFIRM \t\t >> DELETE PRODUCT"<<endl;
cout<<"\t\t\t\t --------"<<endl;
cout<<"\n\n\n";
cout<<"\t\t\t!.....|| PRODUCT NOT DELETED ||.....!"<<endl;
cout<<"\t\t\t-------------------------------------"<<endl<<endl;
return 0;
}
else	// --- >> "YES"
{
char news[150]="ITEM DELETED : ";
header(1);
cout<<"\t\t\t\tDELETE PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT \t\t >> CONFIRM \t\t >> DELETE PRODUCT"<<endl;
cout<<"\t\t\t\t\t\t\t ---------------"<<endl;
cout<<"\n";
cout<<"\n";
cout<<"\n\t\t\t\t DELETING...."<<endl;
for(j=0;j<=700000000;j++);
header(1);
cout<<"\t\t\t\tDELETE PRODUCT DATA"<<endl;
cout<<"\t\t\t\t-------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT \t\t >> CONFIRM \t\t >> DELETE PRODUCT"<<endl;
cout<<"\t\t\t\t\t\t\t ---------------"<<endl;
cout<<"\n\n\n";
for(j=i;j<=sno;++j)
{
prod[j]=prod[j+1];
}
cout<<"\t\t\t!.....|| PRODUCT DELETED ||.....!"<<endl;
cout<<"\t\t\t---------------------------------"<<endl<<endl;\
fstream serial;
serial.open("serial.txt",ios::out);
serial<<sno-1<<endl;
serial.close();
return --sno;
}
}
 
int edit_product_main(int &sno)
{
int flag=0,i=0,temp=0,go=0;
char choice[5],init_barcode[20],temp_bc[20]="";
FIND_EDIT_BC:
do
{
strcpy(temp_bc,init_barcode);
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" -------------"<<endl;
cout<<"\n";
if(!flag||flag==1)
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==2)
cout<<" !.....|| BARCODE NOT FOUND ||.....!\t HIT \'N\' TO ADD THIS ITEM <<";
cout<<"\n\n";
cout<<" Enter The ITEM BARCODE : ";
cin.getline(init_barcode,20);
init_barcode[20]=convert(init_barcode);
if(flag==2)
{
if(!strcmpi(init_barcode,"N"))
{
go=prod[sno].enter_data(sno,temp_bc);
if(go!=0)
++sno;
flag=0;
goto FIND_EDIT_BC;
}
}
flag=0;
if(!strcmp(init_barcode,""))
flag=1;
if(!strcmp(init_barcode,"0"))
return 3;	//GO BACK TO MAIN MENU
if(flag!=1)
{
for(i=1;i<sno;++i)
{
if(!strcmpi(prod[i].barcode,init_barcode))
{
flag=0;
break;
}
else
flag=2;
}
}
}while(flag);
flag=0;
EDIT_RESULTS:
do
{
header(1);
cout<<"\t\t\t\tEDIT PRODUCT ENTRY"<<endl;
cout<<"\t\t\t\t------------------"<<endl<<endl;
cout<<"\n";
cout<<" >> FIND PRODUCT >> SELECT FIELD >> EDIT FIELD >> CONFIRM"<<endl;
cout<<" -------------"<<endl;
cout<<"\n\n";
cout<<" !!....PRODUCT FOUND....!!";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\t\tPRODUCT NAME\t\t\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
prod[i].show_data();
cout<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl<<endl<<endl;
cout<<" Choose The FIELD To EDIT >> B : BARCODE"<<endl<<endl;
cout<<" >> N : PRODUCT NAME"<<endl<<endl;
cout<<" >> P : PRODUCT PRICE"<<endl<<endl;
cout<<" >> C : CHANGE PRODUCT"<<endl<<endl;
cout<<" >> G : MAIN MENU"<<endl;
cout<<"\n";
if(flag==1)
cout<<" !.....ENTER A VALID CHOICE.....!";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
cout<<"\n\n";
flag=0;
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);	
if(!strcmp(choice,""))
flag=1;
if(flag!=1)
if(strcmpi(choice,"B")&&strcmpi(choice,"N")&&strcmpi(choice,"P")&&strcmpi(choice,"C")&&strcmpi(choice,"G"))
flag=2;
}while(flag);
if(!strcmpi(choice,"C"))
goto FIND_EDIT_BC;
if(!strcmpi(choice,"G"))
return 3;
if(!strcmpi(choice,"B"))
{
temp=prod[i].edit_data("barcode",sno,i);
if(!temp)
goto EDIT_RESULTS;
}
if(!strcmpi(choice,"N"))
{
temp=prod[i].edit_data("product",sno,i);
if(!temp)
goto EDIT_RESULTS;
}
if(!strcmpi(choice,"P"))
{
temp=prod[i].edit_data("price",sno,i);
if(!temp)
goto EDIT_RESULTS;
}
return 0;
}
 
int parental_ctrl()
{
char new_user[20],new_pwd[20],confirm_pwd[20],choice[5],curr_pwd[20]="";
int flag=0;
ENTER_USER:
do
{
if(!strcmp(curr_pwd,""))
{
do
{
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
if(!flag)
{
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
}
if(flag==1)
{
cout<<" !!=====ENTER YOUR CURRENT PASSWORD=====!!\t\t HIT \'0\' TO GO BACK <<";
}
if(flag==2)
{
cout<<" !!=====INVALID CURRENT PASSWORD=====!!\t\t HIT \'0\' TO GO BACK <<";
}
cout<<"\n\n";
cout<<" >> CURRENT PASSWORD : ";
cin.getline(curr_pwd,20);
if(!strcmp(curr_pwd,::password))
break;
if(strcmp(curr_pwd,::password))
flag=2;
if(!strcmp(curr_pwd,""))
flag=1;
if(!strcmp(curr_pwd,"0"))
break;
}while(strcmp(curr_pwd,::password));
if(!strcmp(curr_pwd,"0"))
return 3;
flag=0;
}
if(flag!=4)	//IF PWD AND CONFIRM DONT MATCH
{
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
}
if(!flag)
{
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
}
if(flag==1)
{
cout<<" !!=====USERNAME FIELD IS MANDATORY=====!!\t\t HIT \'0\' TO GO BACK <<";
}
if(flag==4)
{
cout<<" !!=====PASSWORDS DO NOT MATCH=====!! \t\t HIT \'0\' TO GO BACK <<";
}
flag=0;
cout<<"\n\n";
cout<<" >> NEW USERNAME : ";
cin.getline(new_user,20);
if(!strcmp(new_user,"0"))
return 3;
if(!strcmp(new_user,""))
flag=1;	//flag=1 >> USERNAME BLANK
if(flag!=1)
{
do
{
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
if(!flag)
{
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
}
if(flag==2)
{
cout<<" !!=====PASSWORD FIELD IS MANDATORY=====!!\t\t HIT \'0\' TO GO BACK <<";
}
flag=0;
cout<<"\n\n";
cout<<" >> NEW USERNAME : "<<new_user;
cout<<"\n\n";
cout<<" >> NEW PASSWORD : ";	
cin.getline(new_pwd,20);
if(!strcmp(new_pwd,"0"))
goto ENTER_USER;
if(!strcmp(new_pwd,""))
flag=2;	//flag=2 >> PWD BLANK
if(flag!=2)
{
do
{
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
if(flag==3)
{
cout<<" !!=====RE-ENTER THE PASSWORD=====!!";
}
if(flag==4)
{
goto ENTER_USER;
}
flag=0;
cout<<"\n\n";
cout<<" >> NEW USERNAME : "<<new_user;
cout<<"\n\n";
cout<<" >> CONFIRM PASSWORD : ";
cin.getline(confirm_pwd,20);
if(!strcmp(confirm_pwd,""))
flag=3;	
if(flag!=3)
if(strcmp(new_pwd,confirm_pwd))
flag=4;
}while(flag);
}
}while(flag);
}
}while(flag);
flag=0;
do
{
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
cout<<"\n\n";
cout<<" ARE YOU SURE TO CHANGE THE USERNAME & PASSWORD OF THE DATABASE ?"<<endl<<endl;
cout<<" >> Y : YES"<<endl<<endl;
cout<<" >> N : NO"<<endl;
cout<<"\n";
if(flag==1)
cout<<" !.....ENTER Y / N.....!";
if(flag==2)
cout<<" !.....INVALID CHOICE.....!";
flag=0;
cout<<"\n\n";
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);
if(!strcmp(choice,""))
flag=1;
if(flag!=1)
if(strcmpi(choice,"Y")&&strcmpi(choice,"N"))
flag=2;
}while(flag);
if(!strcmpi(choice,"N"))
{
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| USERNAME & PASSWORD NOT CHANGED ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
return 0;
}
if(!strcmpi(choice,"Y"))
{
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" CHANGING USERNAME & PASSWORD......"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
for(int i=0;i<=700000000;i++);
header(1);
cout<<"\t\t\t USERNAME & PASSWORD CHANGE"<<endl;
cout<<"\t\t\t --------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
cout<<"\n\n";
fstream fout;
fout.open("parental.txt",ios::out);
fout<<new_user<<'\n'<<new_pwd;
fout.close();
strcpy(::username,new_user);
strcpy(::password,new_pwd);
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<" !.....|| USERNAME & PASSWORD CHANGED ||.....!"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
return 0;
}
return 0;
}
 
 
int billing_main(int sno)
{
int i=0,go=0,times=1;
fstream enter;
fstream billdata;
if(::invoice==1)
{
billdata.open("billdata.txt",ios::out);
billdata.close();
}
billdata.open("billdata.txt",ios::app);
for(i=::invoice;;)
{
go=sale[i].new_bill(sno);
++times;
if(!go)
break;
billdata<<sale[i].total_bill<<"\n"<<sale[i].discount<<"\n"<<sale[i].net_total<<"\n";
fstream ritebill;
if(::invoice==1)
ritebill.open("billitems.dat",ios::out|ios::binary);
else
ritebill.open("billitems.dat",ios::app|ios::binary);
ritebill.write((char*)&sale[i],sizeof(sale[i]));
ritebill.close();
i=++::invoice;
 
}
billdata.close();
enter.open("invoice.txt",ios::out);
enter<<::invoice;
enter.close();
header(1);
cout<<"\t\t\t\t SALES & INVOICE"<<endl;
cout<<"\t\t\t\t ---------------"<<endl<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<::invoice;
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl<<endl<<endl;	
return 0;
}
 
int sales_history()
{
int i=1,no=1;
float total_sales=0.0;
for(i=1;i<::invoice;++i)
total_sales+=sale[i].net_total;
if((::invoice-1)>5)
{
no=(::invoice-1)/5;
}
i=::invoice-1;
int temp=no;
for(int j=1;j<=no+1;j++)
{
header(1);
cout<<"\t\t\t\t SALES HISTORY"<<endl;
cout<<"\t\t\t\t -------------"<<endl<<endl;
cout<<" >> TOTAL SALES : "<<total_sales<<" SR"<<endl;
cout<<" ==================================="<<endl;
for(;i>0;--i)
{
cout<<"\n";
cout<<" >> INVOICE NO. : "<<i<<endl;
cout<<" -------------------"<<endl;
cout<<"\t\t ";cout<<" >> TOTAL : "<<sale[i].total_bill<<" SR"<<endl<<endl;
if(sale[i].discount!=0)
{
cout<<"\t\t ";cout<<" >> DISCOUNT : "<<sale[i].discount<<" SR"<<endl<<endl;
}
cout<<"\t\t ";cout<<" >> NET TOTAL : "<<sale[i].net_total<<" SR"<<endl<<endl;
if(i==5*temp)
{
temp--;
break;
}
}
if((j+1)<=(no+1))
{
cout<<"\nHit ENTER To VIEW PAST SALES...";
cin.get();
}
}
return 0;
}
int admin_ctrl(int sno)
{
int flag=0,go=0,total=0,i=0,error=0;
char menuchoice[5];
//flag=login(2);
if(flag==3)
return 3;
flag=0,go=0;
do
{
do
{
admin_menu();
cout<<"\n";
if(error==1)
{
cout<<"!.....INVALID CHOICE.....!";
error=0;
}
cout<<"\n\n";
cout<<"Enter Your CHOICE : ";
cin.getline(menuchoice,5);
}while(!strcmp(menuchoice,""));
total=0;
for(i=0;menuchoice[i]!='\0';++i)
{
total+=menuchoice[i];
}
flag=0;
switch(total)
{
case 49:
go=parental_ctrl();
flag=0;
break;
case 50:
flag=0;
go=init_all(sno);
if(!go)
{
cout<<"Hit ENTER To Continue .. ";
if(cin.get()||!cin.get()){}
main();
}
break;
case 51: //VIEW PAST INVOICES BY INVOICE NO.
go=invoice_history();
break;
case 52:
return 3;
break;
default:
break;
}
if(total!=49&&total!=50&&total!=51&&total!=52)error=1;
if(go!=3&&error==0)
{
cout<<"\n\n Hit ENTER To Continue .. ";
if(cin.get()||!cin.get()){}
}
}while(flag||!flag);
return 0;
}
int invoice_history()
{
int flag=0;
char inv_temp[6];
do
{
header(1);
cout<<"\t\t\t\t INVOICE HISTORY "<<endl;
cout<<"\t\t\t\t-----------------"<<endl;
cout<<"\n\n";
if(!flag||flag==1)
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
if(flag==2)
cout<<" !.....|| INVOICE NOT FOUND ||.....!\t\t\t HIT \'0\' TO GO BACK <<";
cout<<"\n\n";
cout<<" Enter The INVOICE NO.: ";
cin.getline(inv_temp,6);
if(!strcmp(inv_temp,""))
flag=1;
if(atoi(inv_temp)>=::invoice)
flag=2;
if(!strcmp(inv_temp,"0"))
return 3;
if(atoi(inv_temp)<::invoice&&atoi(inv_temp)>0&&atoi(inv_temp)!=0)
flag=0;
}while(flag);
int no=atoi(inv_temp);
header(1);
cout<<"\t\t\t\t SEARCH HISTORY "<<endl;
cout<<"\t\t\t\t----------------"<<endl;
cout<<"\n";
cout<<" >> INVOICE NUMBER : "<<inv_temp<<"\t\t\t\t\t";
cout<<"\n\n";
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"SNO.\tBARCODE\t\tPRODUCT NAME\t\t\tRATE\tQTY\tPRICE"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\n";
for(int k=1;k<=sale[no].item_ctr;++k)
{
cout<<k<<".";sale[no].show_item(sale[no].item[k],1);
}
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> TOTAL : "<<sale[no].total_bill<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> DISCOUNT : "<<sale[no].discount<<" SR"<<endl<<endl;
cout<<"\t\t\t\t\t\t ";cout<<" >> NET TOTAL : "<<sale[no].net_total<<" SR"<<endl<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
return 0;
}
int init_all(int sno)
{
int flag=0,i=0;
char choice[5],curr_pwd[20]="";
MAIN:
do
{
header(1);
cout<<"\t\t\t DATABASE INITIALIZATION "<<endl;
cout<<"\t\t\t -------------------------"<<endl;
cout<<"\n\n";
cout<<" !!....WARNING....!!";
cout<<"\n";
cout<<" ===================";
cout<<"\n\n";
cout<<" >> INITIALIZING THE DATABASE IN THE LOSS OF ALL DATA PERTAINING TO \n\n ITEMS AND SALES HISTORY ....... !!! "<<endl;
cout<<"\n\n";
cout<<" >> THE DATABASE WILL BE LIKE A FRESHLY BOUGHT ONES ...... "<<endl;
cout<<"\n\n";
cout<<" Are You SURE To FORMAT ? >> ENTER : YES"<<endl<<endl;
cout<<" >> N : NO "<<endl;
cout<<"\n";
if(flag==1)
cout<<" !=====INVLAID CHOICE=====!!";
cout<<"\n\n";
flag=0;
cout<<" Enter Your CHOICE : ";
cin.getline(choice,5);
if(strcmpi(choice,"N"))
flag=1;
if(!strcmpi(choice,""))
break;
}while(flag);
if(!strcmpi(choice,"N"))
return 3;
flag=0;
do
{
header(1);
cout<<"\t\t\t DATABASE INITIALIZATION "<<endl;
cout<<"\t\t\t -------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n";
if(!flag)
{
cout<<"\t\t\t\t\t\t\t HIT \'0\' TO GO BACK <<";
}
if(flag==1)
{
cout<<" !!=====ENTER YOUR CURRENT PASSWORD=====!!\t\t HIT \'0\' TO GO BACK <<";
}
if(flag==2)
{
cout<<" !!=====INVALID CURRENT PASSWORD=====!!\t\t HIT \'0\' TO GO BACK <<";
}
cout<<"\n\n";
cout<<" >> CURRENT PASSWORD : ";
cin.getline(curr_pwd,20);
if(!strcmp(curr_pwd,::password))
break;
if(strcmp(curr_pwd,::password))
flag=2;
if(!strcmp(curr_pwd,""))
flag=1;
if(!strcmp(curr_pwd,"0"))
break;
}while(strcmp(curr_pwd,::password));
if(!strcmp(curr_pwd,"0"))
goto MAIN;
//STARTING FORMATTING
fstream file;
header(1);
cout<<"\t\t\t DATABASE INITIALIZATION "<<endl;
cout<<"\t\t\t -------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n\n\n";
cout<<" >> INITIALIZING FORMATTING PROCESS . . . . . "<<endl<<endl;
for(i=0;i<=750000000;i++);
file.open("billitems.dat",ios::out|ios::binary);
file.close();
cout<<" >> CLEANING UP ITEM DATABASE . . . . . "<<endl<<endl;
for(i=0;i<=750000000;i++);
file.open("dataitems.txt",ios::out);
file.close();
cout<<" >> CLEANING UP SALES INFORMATION . . . . . "<<endl<<endl;
for(i=0;i<=750000000;i++);
file.open("invoice.txt",ios::out);
file.close();
cout<<" >> SETTING ALL COUNTERS TO \'0\' . . . . . "<<endl<<endl;
for(i=0;i<=750000000;i++);
file.open("parental.txt",ios::out);
file.close();
cout<<" >> FINISHING FORMATTING PROCESS . . . . . "<<endl<<endl;
for(i=0;i<=750000000;i++);
file.open("serial.txt",ios::out);
file.close();
header(1);
cout<<"\t\t\t DATABASE INITIALIZATION "<<endl;
cout<<"\t\t\t -------------------------"<<endl;
cout<<endl<<endl;
cout<<"\n\n\n";
cout<<" >> !! *** DATABASE FORMATTING IS COMPLETED *** !! << "<<endl;
cout<<" ------------------------------------------------- "<<endl;
cout<<"\n\n";
cout<<" >> USERNAME : amasi "<<endl<<endl;
cout<<" >> PASSWORD : amasi "<<endl<<endl;
return 0;
}
void menu()
{
header(1);
cout<<"\t\t\t\t MAIN MENU "<<endl;
cout<<"\t\t\t\t -----------"<<endl;
cout<<"\n\t\t";
for(int i=0;i<51;++i)
cout<<(char)220;
cout<<"\n\t\t"<<(char)219<<" "<<(char)219;
cout<<"\n\t\t| >> 1. New Product Entry |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 2. Edit Product Data |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 3. All Product Data |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 4. Search Product Data |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 5. Delete Product Data |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 6. Sales & Invoice |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 7. Sales History |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 8. Administrative Tools |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 9. Log Off |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 10. Exit |";
cout<<"\n\t\t"<<(char)219<<" "<<(char)219;
cout<<"\n\t\t";
for(i=0;i<51;++i)
cout<<(char)223;
cout<<endl<<endl;
}
 
void admin_menu()
{
header(1);
cout<<"\t\t\t\t ADMIN MENU "<<endl;
cout<<"\t\t\t\t ------------"<<endl;
cout<<"\n\t\t";
for(int i=0;i<51;++i)
cout<<(char)220;
cout<<"\n\t\t"<<(char)219<<" "<<(char)219;
cout<<"\n\t\t| >> 1. Change Username & Password |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 2. Reset Supermarket Database |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 3. View Past Invoices |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| >> 4. Main Menu |";
cout<<"\n\t\t"<<(char)219<<" "<<(char)219;
cout<<"\n\t\t";
for(i=0;i<51;++i)
cout<<(char)223;
cout<<endl<<endl;
}
 
void footer()
{
system("cls");
for(int i=0;i<=18;++i)
cout<<'\n';
cout<<"\n\t\t*----------------------------------------------------*";
cout<<"\n\t\t| |";
cout<<"\n\t\t| THANK YOU FOR USING THIS PROGRAMME |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| PROGRAMMED & DESIGNED BY |";
cout<<"\n\t\t| ---------------------------- |";
cout<<"\n\t\t| MOHAMMED AZHAR |";
cout<<"\n\t\t| |";
cout<<"\n\t\t*----------------------------------------------------*"<<endl;
getchar();
exit(0);
}
 
void logged_off()
{
header(1);
cout<<""<<endl;
cout<<""<<endl;
cout<<"\n\t\t*-------------------------------------------------*";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| LOGGED OFF |";
cout<<"\n\t\t| -------------- |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| !!...Hit ENTER To LOG IN...!! |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t| |";
cout<<"\n\t\t*-------------------------------------------------*"<<endl<<endl;
}