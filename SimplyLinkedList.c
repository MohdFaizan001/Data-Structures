#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *ptr;
};


void creation(struct node *h,int n){
   struct node *temp = h;

   for (int i = 1; i < n ; i++)
   {
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
   printf("Enter the Node %d data : ",i + 1);
   scanf("%d",&newNode->data);

   newNode->ptr = NULL;
   temp->ptr = newNode;
   temp = temp->ptr;
   }
   
}
void traverseList(struct node *h){
    struct node *temp ;
    if(h ==NULL){
        printf("linked list is empty.");
    } else {
        temp = h;
         int i = 1;
        while( temp != NULL){
           
            printf("data of Node %d = %d\n",i,temp->data);
            i++;
            temp = temp->ptr;
            
        }
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
       
        newNode->ptr = h;
        h = newNode;

        break;

    case 2:
        
        while (q->ptr != NULL)
        {
          q = q->ptr;
        }
        newNode->ptr = NULL;
        q->ptr = newNode;
        
        
       break;

    case 3:
       printf("Enter the position to insert the node : ");
       scanf("%d",&position);

       for (int i = 2 ; i < position ; i++)
       {
       q = q->ptr;
       }

       newNode->ptr = q->ptr;
       q->ptr = newNode;
       break;
    
    default:
        break;
    }

    printf("Linked list after inserting new node :\n");
    traverseList(h);
}



void DisplayReverse(struct node * h){
    if (h == NULL)
        return;
    DisplayReverse(h->ptr);
    printf("%d ", h->data);
}




void deleteNode(struct node *h){
    struct node *temp = h, *prev = NULL;
    int choice, position, value;

    printf("\nDeletion Menu.\n");
    printf("1.At beginning.\n");
    printf("2.At last.\n");
    printf("3.At any position.\n");
    printf("4.By value.\n");

    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        if (h == NULL) {
            printf("List is empty.\n");
            return;
        }
        temp = h->ptr;
        free(h);
        h = temp;
        break;

    case 2:
        if (h == NULL || h->ptr == NULL) {
            printf("List is empty or has one node.\n");
            return;
        }
        while (temp->ptr->ptr != NULL)
            temp = temp->ptr;
        free(temp->ptr);
        temp->ptr = NULL;
        break;

    case 3:
        printf("Enter the position to delete: ");
        scanf("%d", &position);
        if (position == 1) {
            temp = h->ptr;
            free(h);
            h = temp;
            break;
        }
        for (int i = 1; i < position - 1 && temp != NULL; i++)
            temp = temp->ptr;

        if (temp == NULL || temp->ptr == NULL) {
            printf("Invalid position.\n");
            return;
        }

        prev = temp->ptr;
        temp->ptr = prev->ptr;
        free(prev);
        break;

    case 4:
        printf("Enter value to delete: ");
        scanf("%d", &value);

        // If head has the value
        if (h != NULL && h->data == value) {
            temp = h->ptr;
            free(h);
            h = temp;
            break;
        }

        while (temp != NULL && temp->ptr != NULL && temp->ptr->data != value)
            temp = temp->ptr;

        if (temp == NULL || temp->ptr == NULL) {
            printf("Value not found.\n");
            return;
        }

        prev = temp->ptr;
        temp->ptr = prev->ptr;
        free(prev);
        break;

    default:
        printf("Invalid choice.\n");
        return;
    }

    printf("\nLinked list after deletion:\n");
    traverseList(h);
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

    creation(h,num);

    printf("\nSimply Linked List Operations.\n");
    printf("1. Traversal.\n");
    printf("2. Insertion.\n");
    printf("3. Display Reverse.\n");
    printf("4. Deletion.\n");

    int choice ;
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
