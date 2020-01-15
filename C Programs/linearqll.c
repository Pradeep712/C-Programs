//Linear Queue using ll
/*
 What is Queue?
The queue is a linear data structure where operations of insertion and deletion are performed at separate ends that are known as front and rear. The queue follows FIFO (First in First Out) concept. First element added to the queue will be first one to be removed.

In this program we will implement linear queue using linked list. It is a menu driven program that contains four options insert, delete, display and exit. The program will ask the user to enter the choice and then appropriate functions are invoked to perform specific operation according to the user’s choice.

 Insertion
In the insertion operation, temp points to the new node. If this is first node to be inserted then front will be NULL and now both front and rear points to this new node. If front is not NULL then insertion is similar to adding the node at the end of linked list. The next pointer of rear points to temp and rear becomes temp.

Deletion
For deletion purpose, it is first checked whether front is NULL, if it is NULL, we display the message “Queue is empty”. In case the queue is not empty, deletion is done in such a way that temp pointer points to front and front pointer points to its next node. After displaying data for the node to be deleted, node is deleted by delete(temp) function.

Display

For display, it is first checked whether front is NULL, if it is NULL, we display the message “Queue is empty”. If queue is not empty, front pointer is assigned to temp and data for all the nodes are displayed till temp does not become NULL.

*/

 #include<iostream.h>
#include<stdlib.h>

using namespace std;

struct node
{
                int data;
                struct node *next;
}*front=NULL,*rear,*temp;


void ins()
{
                temp=new node;
                cout<<"Enter data:";
                cin>>temp->data;
                temp->next=NULL;        

                if(front==NULL)
                                front=rear=temp;
                else
                {
                                rear->next=temp;
                                rear=temp;
                }
                cout<<"Node has been inserted\n";      
}


void del()
{
                if(front==NULL)
                                cout<<"Queue is empty\n";
                else
                {
                                temp=front;
                                front=front->next;
                                cout<<"Deleted node is "<<temp->data<<"\n";
                                delete(temp);
                }
}


void dis()
{
                if(front==NULL)
                                cout<<"Queue is empty\n";
                else
                {
                                temp=front;
                                while(temp->next!=NULL)
                                {
                                                cout<<temp->data<<"->";
                                                temp=temp->next;
                                }

                                cout<<temp->data;
                }
}


main()
{
                int ch;
                while(1)
                {
                                cout<<"\n*** Menu ***"<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit";
                                cout<<"\n\nEnter your choice(1-4):";
                                cin>>ch;
                                cout<<"\n";

                                switch(ch)
                                {
                                                case 1:  ins();
                                                                break;
                                                case 2: del();
                                                                break;
                                                case 3: dis();
                                                                break;
                                                case 4: exit(0);
                                                                break;
                                                default: cout<<"Wrong Choice!!!";
                                }
                }

                return 0;
}

