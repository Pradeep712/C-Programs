//rvrs lnkd lst ver3
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void printList(char* msg) {
    struct node* current = head;

    printf("\n%s\n", msg);

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void insert_beginning(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insert_at(int data, int location) {

    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }

    else {
        struct node* currentNode = head;
        int index = 0;

        while (currentNode != NULL && index < (location - 1)) {
            currentNode = currentNode->next;
            index++;
        }

        if (currentNode != NULL)
        {
            if (location == 0) {
                newNode->next = currentNode;
                head = newNode;
            } else {
                newNode->next = currentNode->next;
                currentNode->next = newNode;
            }
        }
    }
}


int delete_from(int location) {

    int retValue = -1;

    if (location < 0 || head == NULL)
    {
        printf("\nList is empty or invalid index");
        return -1;
    } else {

        struct node* currentNode = head;
        int index = 0;

        while (currentNode != NULL && index < (location - 1)) {
            currentNode = currentNode->next;
            index++;
        }

        if (currentNode != NULL)
        {
            // we've reached the node just one prior to the one we want to delete

            if (location == 0) {

                if (currentNode->next == NULL)
                {
                    // this is the only node in the list
                    retValue = currentNode->data;
                    free(currentNode);
                    head = NULL;
                } else {

                    // the next node should take its place
                    struct node* nextNode = currentNode->next;
                    head = nextNode;
                    retValue = currentNode->data;
                    free(currentNode);
                }
            } // if (location == 0)
            else {
                // the next node should take its place
                struct node* nextNode = currentNode->next;
                currentNode->next = nextNode->next;

                if (nextNode != NULL
                ) {
                    retValue = nextNode->data;
                    free(nextNode);
                }
            }

        } else {
            printf("\nInvalid index");
            return -1;
        }
    }

    return retValue;
}

void another_reverse() {
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    } else {
        // get the tail pointer

        struct node* tailNode = head;
        int index = 0, counter = 0;

        while (tailNode->next != NULL) {
            tailNode = tailNode->next;
            index++;
        }

        // now tailNode points to the last node
        while (counter != index) {
            int data = delete_from(index);
            insert_at(data, counter);
            counter++;
        }
    }
}

int main(int argc, char** argv) {

    insert_beginning(4);
    insert_beginning(3);
    insert_beginning(2);
    insert_beginning(1);
    insert_beginning(0);

    /*  insert_at(5, 0);
     insert_at(4, 1);
     insert_at(3, 2);
     insert_at(1, 1);*/

    printList("Original List\0");

    //reverse_list();
    another_reverse();

    printList("Reversed List\0");

    /*  delete_from(2);
     delete_from(2);*/

    //printList();
    return 0;
}

