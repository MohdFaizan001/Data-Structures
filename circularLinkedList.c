#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void creation(struct node *h,int n){
   struct node *temp = h;

   for (int i = 1; i < n ; i++)
   {
       struct node *newNode = (struct node *)malloc(sizeof(struct node));
       printf("Enter the Node %d data : ",i + 1);
       scanf("%d",&newNode->data);

       newNode->next = h;          
       newNode->prev = temp;
       temp->next = newNode;
       h->prev = newNode;          
       temp = temp->next;
   }
}

void traverseList(struct node *h){
    struct node *temp;
    if(h == NULL){
        printf("Linked list is empty.");
    } else {
        temp = h;
        int i = 1;
        do {
            printf("Data of Node %d = %d\n",i,temp->data);
            i++;
            temp = temp->next;
        } while(temp != h);
    }
}

void insertNode(struct node *h,int n){
    struct node *q = h;
    printf("\nInsertion Menu.\n");
    printf("1.At beginning.\n");
    printf("2.At last.\n");
    printf("3.At any position\n");

    int choice;
    printf("Enter the choice from above Menu(1-3): ");
    scanf("%d",&choice);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert :");
    scanf("%d",&newNode->data);

    int position;

    switch (choice)
    {
    case 1:
        newNode->prev = h->prev;
        newNode->next = h;
        h->prev->next = newNode;
        h->prev = newNode;
        h = newNode;
        break;

    case 2:
        while (q->next != h)
        {
            q = q->next;
        }
        newNode->next = h;
        newNode->prev = q;
        q->next = newNode;
        h->prev = newNode;
        break;

    case 3:
        printf("Enter the position to insert the node : ");
        scanf("%d",&position);

        for (int i = 2 ; i < position ; i++)
        {
            q = q->next;
        }

        newNode->next = q->next;
        newNode->prev = q;
        q->next->prev = newNode;
        q->next = newNode;
        break;

    default:
        break;
    }

    printf("Linked list after inserting new node :\n");
    traverseList(h);
}

void deleteNode(struct node *h){
    struct node *temp = h;
    int choice, position, value;

    printf("\nDeletion Menu.\n");
    printf("1.At beginning.\n");
    printf("2.At last.\n");
    printf("3.At any position.\n");
    printf("4.By value.\n");
    printf("Enter your choice (1-4): ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        if (h == NULL) {
            printf("List is empty.\n");
            return;
        }
        h->prev->next = h->next;
        h->next->prev = h->prev;
        temp = h->next;
        free(h);
        h = temp;
        break;

    case 2:
        if (h == NULL) {
            printf("List is empty.\n");
            return;
        }
        while (temp->next != h)
            temp = temp->next;
        temp->prev->next = h;
        h->prev = temp->prev;
        free(temp);
        break;

    case 3:
        printf("Enter the position to delete: ");
        scanf("%d",&position);

        for (int i = 1; i < position && temp->next != h; i++)
            temp = temp->next;

        if (temp == h) {
            printf("Use beginning option for position 1.\n");
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        break;

    case 4:
        printf("Enter the value to delete: ");
        scanf("%d",&value);

        do {
            if (temp->data == value) {
                if (temp == h) {
                    h->prev->next = h->next;
                    h->next->prev = h->prev;
                    struct node *newHead = h->next;
                    free(h);
                    h = newHead;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                }
                break;
            }
            temp = temp->next;
        } while (temp != h);

        break;

    default:
        printf("Invalid choice.\n");
        return;
    }

    printf("Linked list after deletion :\n");
    traverseList(h);
}

void DisplayReverse(struct node *h){
    struct node *temp = h;
    if (h == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = h->prev; 
    int i = 1;
    do {
        printf("Data of Node (Reverse %d) = %d\n", i, temp->data);
        i++;
        temp = temp->prev;
    } while (temp->next != h->prev->next);
}

int main(){
    struct node s1;

    struct node *h;
    h = &s1;

    int num;
    printf("Enter the number of nodes in LL : ");
    scanf("%d",&num);
    printf("Enter the Node 1 data : ");
    scanf("%d",&h->data);
    h->next = h;
    h->prev = h;

    creation(h,num);

    printf("\nCircular Doubly Linked List Operations.\n");
    printf("1. Traversal.\n");
    printf("2. Insertion.\n");
    printf("3. Display Reverse.\n");
    printf("4. Deletion.\n");

    int choice;
    printf("Enter the choice from above Menu(1-4) : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        traverseList(h);
        break;

    case 2:
        insertNode(h,num);
        break;

    case 3:
        printf("Linked list in reverse order:\n");
        DisplayReverse(h);
        break;

    case 4:
        deleteNode(h);
        break;

    default:
        break;
    }

    return 0;
}
