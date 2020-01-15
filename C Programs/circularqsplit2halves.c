#include<stdio.h>
#include<malloc.h>
 
struct Node
{
int data;
struct Node *next;
};
 
struct Node *start=NULL;
struct Node *rear=NULL;
int size=0;
 
void insert()
{
struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
printf("\nEnter data to be inserted in circular queue : ");
scanf("%d",&ptr->data);
if(start==NULL)
{
ptr->next=ptr;
start=ptr;
}
else
{
struct Node *temp=start;
while(temp->next!=start)
{
temp=temp->next;
}
temp->next=ptr;
ptr->next=start;
}
size++;
}
 
void print(struct Node *start)
{
struct Node *ptr=start;
if(start==NULL)
{
printf("List is empty try entering elements first ");
return;
}
printf("List is : \n");
printf("-->");
printf("%d\n",ptr->data);
ptr=ptr->next;
while(ptr->next!=start)
{
printf("| %d\n",ptr->data);
ptr=ptr->next;
}
printf("| %d\n",ptr->data);
printf("-->%d\n",ptr->next->data);/*printing first element again to show it is circular*/
}
 
void splitList(struct Node *head, struct Node **first, struct Node **second)
{
struct Node *pointer1 = head;
struct Node *pointer2 = head;
if(head == NULL)
return;
while(pointer1->next->next != head)
{
pointer1 = pointer1->next->next;
pointer2 = pointer2->next;
}
if(pointer1->next->next == head)
pointer1 = pointer1->next;
*first = head;
if(head->next != head)
*second = pointer2->next;
pointer1->next = pointer2->next;
pointer2->next = head;
}
 
main()
{
printf("\t\tPROGRAM TO SPLIT A CIRCULAR QUEUE INTO TWO HALVES\n\n");
struct Node *first_half=(struct Node *)malloc(sizeof(struct Node));
struct Node *second_half=(struct Node *)malloc(sizeof(struct Node));
char ch;
ch='a';
printf("For insertion enter i\n\n");
printf("For printing enter p\n\n");
printf("For spliting list into two parts enter s\n\n");
printf("To quit enter q\n\n");
while(ch!='q')
{
printf("\nEnter operation : ");
scanf(" %c",&ch);
switch(ch)
{
case 'i':
insert();
break;
case 'p':
print(start);
break;
case 's':
if((size%2!=0)&&(size>=1))
{
printf("Try after entering one more element \n");
break;
}
if(size<1)
{
printf("Enter elements first \n");
break;
}
splitList(start,&first_half,&second_half);
printf("First half : \n");
print(first_half);
printf("Second half : \n");
print(second_half);
exit(0);
break;
case 'q':
exit(0);
break;
}
}
}

