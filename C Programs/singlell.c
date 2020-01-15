 #include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>

struct node
{
                int data;
                struct node *next;
}*start=NULL,*q,*t;

main()
{
                int ch;

                void insert_beg();
                void insert_end();
                int insert_pos();
                void display();

                void delete_beg();
                void delete_end();
                int delete_pos();

                while(1)
                {
                                clrscr();
                                printf("---- Singly Linked List(SLL) Menu ----");
                                printf("\n\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
                                printf("Enter your choice(1-4):");
                                scanf("%d",&ch);

                                switch(ch)
                                {
                                                case 1:
                                                                {
                                                                                clrscr();
                                                                                printf("---- Insert Menu ----");
                                                                                printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
                                                                                printf("\n\nEnter your choice(1-4):");
                                                                                scanf("%d",&ch);

                                                                                switch(ch)
                                                                                {
                                                                                                case 1: insert_beg();
                                                                                                                break;
                                                                                                case 2: insert_end();
                                                                                                                break;
                                                                                                case 3: insert_pos();
                                                                                                                break;
                                                                                                case 4: exit(0);
                                                                                                default: printf("Wrong Choice!! Press any key to continue...");
                                                                                                                 getch();
                                                                                }
                                                                }
                                                                break;

                                                case 2: display();
                                                                 break;

                                                case 3:
                                                                {
                                                                                clrscr();
                                                                                printf("---- Delete Menu ----");
                                                                                printf("\n\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
                                                                                printf("\n\nEnter your choice(1-4):");
                                                                                scanf("%d",&ch);

                                                                                switch(ch)
                                                                                {
                                                                                                case 1: delete_beg();
                                                                                                                break;
                                                                                                case 2: delete_end();
                                                                                                                break;
                                                                                                case 3: delete_pos();
                                                                                                                break;
                                                                                                case 4: exit(0);
                                                                                                default: printf("Wrong Choice!! Press any key to continue...");
                                                                                                                 getch();
                                                                                }
                                                                }
                                                                break;

                                                case 4: exit(0);
                                                default: printf("Wrong Choice!! Press any key to continue...");
                                                                 getch();
                                }
                }
                return 0;
}

void insert_beg()
{
                int num;
                clrscr();

                t=(struct node*)malloc(sizeof(struct node));
                printf("Enter data:");
                scanf("%d",&num);
                t->data=num;

                if(start==NULL)                 //If list is empty
                {
                                t->next=NULL;
                                start=t;
                }
                else
                {
                                t->next=start;
                                start=t;
                }
}

void insert_end()
{
                int num;
                clrscr();

                t=(struct node*)malloc(sizeof(struct node));
                printf("Enter data:");
                scanf("%d",&num);
                t->data=num;
                t->next=NULL;

                if(start==NULL)                 //If list is empty
                {
                                start=t;
                }
                else
                {
                                q=start;
                                while(q->next!=NULL)
                                                q=q->next;

                                q->next=t;
                }
}

int insert_pos()
{
                int pos,i,num;
                clrscr();

                if(start==NULL)
                {
                                printf("List is empty!! Press any key to continue...");
                                getch();
                                return 0;
                }

                t=(struct node*)malloc(sizeof(struct node));
                printf("Enter data:");
                scanf("%d",&num);
                printf("Enter position to insert:");
                scanf("%d",&pos);
                t->data=num;

                q=start;
                for(i=1;i<pos-1;pos++)
                {
                                if(q->next==NULL)
                                {
                                                printf("There are less elements!! Press any key to continue...");
                                                getch();
                                                return 0;
                                }
                                q=q->next;
                }

                t->next=q->next;
                q->next=t;
                return 0;
}

void display()
{
                if(start==NULL)
                {
                                printf("List is empty!! Press any key to continue...");
                                getch();
                }
                else
                {
                                q=start;
                                clrscr();
                                printf("The linked list is:\n");
                                while(q->next!=NULL)
                                {
                                                printf("%d-> " ,q->data);
                                                q=q->next;
                                }
                }
                printf("\nPress any key to continue...");
                getch();
}

void delete_beg()
{
                clrscr();
                if(start==NULL)
                {
                                printf("The list is empty!! Press any key to continue...");
                                getch();
                }
                else
                {
                                q=start;
                                start=start->next;
                                free(q);
                                printf("Element deleted! Press any key to continue...");
                                getch();
                }
}

void delete_end()
{
                clrscr();
                if(start==NULL)
                {
                                printf("The list is empty!! Press any key to continue...");
                                getch();
                }
                else
                {
                                q=start;
                                while(q->next->next!=NULL)
                                                q=q->next;

                                t=q->next;
                                q->next=NULL;
                                free(t);

                                printf("Element deleted! Press any key to continue...");
                                getch();
                }
}

int delete_pos()
{
                int pos,i;
                clrscr();

                if(start==NULL)
                {
                                printf("List is empty!! Press any key to continue...");
                                getch();
                                return 0;
                }

                printf("Enter position to delete:");
                scanf("%d",&pos);

                for(i=1;i<pos-1;pos++)
                {
                                if(q->next==NULL)
                                {
                                                printf("There are less elements!! Press any key to continue...");
                                                getch();
                                                return 0;
                                }
                                q=q->next;
                }

                t=q->next;
                q->next=t->next;
                free(t);

                printf("Element deleted! Press any key to continue...");
                getch();
                return 0;
}