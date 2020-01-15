/*
* Program to illustrate the implementation of unsorted linear
* linked list
*/
 
#include<stdio.h>
#include<conio.h>
 
/*--------- defining the structure of a node ----------*/
 
typedef struct nodetype
{
int info;
struct nodetype *next;
}node;
/*--------- function prototypes ---------*/
void crtlist(node **head);
void traordr(node *head);
void trarevordr(node *head);
node *srchsortdlist(node *head,int item);
void auxsrch(node *head,node **ploc,node **loc,int item);
void insrtbeg(node **head,int item);
void insrtaftr(node *head,int item,int after);
void insrtend(node **head,int item);
void dltfrmbeg(node **head);
void dltfrmend(node **head);
void dltaftrele(node *head,int after);
void revlist(node **head);
void dltlist(node **head);
 
void main()
{
node *head;
int choice,element,after;
clrscr();
crtlist(&head);
while(1)
{
printf("\n******************************\n");
printf("1. Insert at beginning\n");
printf("2. Insert at end\n");
printf("3. Insert after a given element\n");
printf("4. Traverse in order\n");
printf("5. Traverse in Reverse order\n");
printf("6. Delete from beginning\n");
printf("7. Delete from end\n");
printf("8. Delete after a given element\n");
printf("9. Reverse linked list\n");
printf("10. Exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : printf("\nEnter element : ");
scanf("%d",&element);
insrtbeg(&head,element);
break;
case 2 : printf("\nEnter element : ");
scanf("%d",&element);
insrtend(&head,element);
break;
case 3 : printf("\nEnter element : ");
scanf("%d",&element);
printf("Enter element after which to insert : ");
scanf("%d",&after);
insrtaftr(head,element,after);
break;
case 4 : if(head==NULL)
printf("\nList is Empty...");
else
traordr(head);
printf("\n\nPress any key to continue...");
getch();
break;
case 5 : if(head==NULL)
printf("\nList is Empty...");
else
trarevordr(head);
printf("\n\nPress any key to continue...");
getch();
break;
case 6 : dltfrmbeg(&head);
break;
case 7 : dltfrmend(&head);
break;
case 8 : printf("\nEnter element after which to delete : ");
scanf("%d",&after);
dltaftrele(head,after);
break;
case 9 : revlist(&head);
break;
case 10: dltlist(&head);
exit(1);
default: printf("You have enterd wrong choice...");
printf("\nPress any to Continue...");
getch();
}
}
} /*********** end of main function **********/
 
void crtlist(node **head)
{
*head=NULL;
}
 
void traordr(node *head)
{
while(head!=NULL)
 
{
printf("%d\t",head->info);
head=head->next;
}
}
 
void trarevordr(node *head)
{
if(head->next!=NULL)
trarevordr(head->next);
printf("%d\t",head->info);
}
node *srchsortdlist(node *head,int item)
{
while(head!=NULL)
{
if(head->info==item)
return head;
else if(item<head->info)
return NULL;
else
head=head->next;
}
return NULL;
}
void auxsrch(node *head,node **ploc,node **loc,int item)
{
int flag=0;
if(head==NULL) /*if list is empty */
*ploc=*loc=NULL;
else if(head->info==item) /*if item is present in first node */
{
*ploc=NULL;
*loc=head;
}
else
{
*ploc=head;
*loc=head->next;
while((*loc!=NULL)&&(!flag))
{
if((*loc)->info==item)
flag=1;
else
{
*ploc=*loc;
*loc=(*loc)->next;
}
}
}
}
 
void insrtbeg(node **head,int item)
{
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->info=item;
if(*head==NULL) /*list initially empt */
ptr->next=NULL;
else
ptr->next=*head;
*head=ptr;
}
 
void insrtend(node **head,int item)
{
node *ptr,*loc;
ptr=(node*)malloc(sizeof(node));
ptr->info=item;
ptr->next=NULL;
if(*head==NULL) //list initially empty
*head=ptr;
else
{
loc=*head;
while(loc->next!=NULL)
loc=loc->next;
loc->next=ptr;
}
}
 
void insrtaftr(node *head,int item,int after)
{
node *ptr,*loc;
loc=srchsortdlist(head,after);
if(loc==(node*)NULL) //element after not fouund
return;
ptr=(node*)malloc(sizeof(node));
ptr->info=item;
ptr->next=loc->next;
loc->next=ptr;
}
 
void dltfrmbeg(node **head)
{
node *ptr;
if(*head==NULL)
return;
else
{
ptr=*head;
*head=(*head)->next;
free(ptr);
}
}
 
void dltfrmend(node **head)
{
node *ptr,*loc;
if(*head==NULL)
return;
else if((*head)->next==(node*)NULL)
{
ptr=*head;
*head=NULL;
free(ptr);
}
else
{
loc=*head;
ptr=(*head)->next;
while(ptr->next!=NULL)
{
loc=ptr;
ptr=ptr->next;
}
loc->next=NULL;
free(ptr);
}
}
 
void dltaftrele(node *head,int after)
{
node *ptr,*loc;
loc=srchsortdlist(head,after);
if(loc==(node*)NULL) //element after not found
return;
ptr=loc->next;
loc->next=ptr->next;
free(ptr);
}
void revlist(node **head)
{
node *previousnode,*currentnode,*nextnode;
currentnode=*head;
nextnode=currentnode->next;
previousnode=NULL;
currentnode->next=NULL;
while(nextnode!=NULL)
{
previousnode=currentnode;
currentnode=nextnode;
nextnode=currentnode->next;
currentnode->next=previousnode;
}
*head=currentnode;
}
void dltlist(node **head)
{
node *ptr;
while(*head!=NULL)
{
ptr=*head;
*head=(*head)->next;
free(ptr);
}
}
