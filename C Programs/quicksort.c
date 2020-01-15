#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
node *next;
node *prev;
};
 
struct node *head=NULL;
struct node *rear=NULL;
int size=0;
 
void insert()
{
struct node *ptr=(struct node *)malloc(sizeof(struct node));
printf("Enter value : ");
scanf("%d",&ptr->data);
if(head==NULL)
{
head=ptr;
rear=ptr;
ptr->next=NULL;
ptr->prev=NULL;
}
ptr->prev=rear;
rear->next=ptr;
rear=ptr;
rear->next=NULL;
size++;
}
 
void Quicksort(struct node *ptr, struct node *ptr1)
{
struct node *temp=ptr;
struct node *current=temp->next;
int y;
if (ptr == ptr1)
return;
while (ptr->next!=ptr1)
{
if (temp->data < current->data)
{
y = current->data;
current->data =temp->data;
temp->data = y;
}
if (current == ptr1)
break;
current = current->next;
}
y = ptr->data;
ptr->data = current->data;
current->data = y;
struct node *OldCurrent = current;
current = current->prev;
if (current != NULL)
{
if ((ptr->prev != current) && (current->next != ptr))
Quicksort(ptr, current);
}
current = OldCurrent;
current = current->next;
if (current != NULL)
{
if ((current->prev != ptr1) && (ptr1->next != current))
Quicksort(current, ptr1);
}
}
 
void display()
{
struct node *ptr=head;
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
 
int main()
{
int n,i;
printf("No. of elements to be sorted : ");
scanf("%d",&n);
for(i=1; i<=n; ++i)
{
insert();
}
display();
printf("Sorted list is : \n");
Quicksort(head,rear);
display();
return 0;
}