//rvrs lnkd list ver 2
#include <stdio.h>

typedef struct node
{
    int num;
    struct node* next;
}node;

void reverse(node* head)
{
   node* ptr;
   if(!head || !head->next || !head->next->next) return;
   ptr = head->next->next;
   head->next->next = NULL;
   while(ptr)
   {
     /* Swap head->next and ptr. */
     head->next = (unsigned)(ptr =\
     (unsigned)ptr ^ (unsigned)(head->next =\
     (unsigned)head->next ^ (unsigned)ptr)) ^ (unsigned)head->next;

     /* Swap head->next->next and ptr. */
     head->next->next = (unsigned)(ptr =\
     (unsigned)ptr ^ (unsigned)(head->next->next =\
     (unsigned)head->next->next ^ (unsigned)ptr)) ^ (unsigned)head->next->next;
   }
}

void add_end(node* ptr, int n)
{
    while(ptr->next) ptr = ptr->next;
    ptr->next = malloc(sizeof(node));
    ptr->next->num = n;
    ptr->next->next = NULL;
}

void print(node* ptr)
{
    while(ptr = ptr->next) printf("%d ", ptr->num);
    putchar('\n');
}

void erase(node* ptr)
{
    node *end;
    while(ptr->next)
    {
        if(ptr->next->next) ptr = ptr->next;
        else
        {
            end = ptr->next;
            ptr->next = NULL;
            free(end);
        }
    }
}

void main()
{
    int i, n = 5;
    node* dummy_head;
    dummy_head->next = NULL;
    for(i = 1; i <= n ; ++i) add_end(dummy_head, i);
    print(dummy_head);
    reverse(dummy_head);
    print(dummy_head);
    erase(dummy_head);
}

