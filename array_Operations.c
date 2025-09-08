// C program to demonstrate array operations
#include<stdio.h>

int linearSearch(int arr[] , int n){
    int target ; 
    printf("Enter you target element to search in array : ");
    scanf("%d",&target);
    int a[10];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target)
        {
          a[count] = i;
          count++;
        }
        
    } 
    if (count == 0)
    {
      printf("Element not found in array.");
    } else if (count == 1)
    {
       printf("Element found at position : %d\n",a[0]);
    } else if ( count > 1)
    {
       printf("Element found at %d positions.\n",count);
       printf("** Search Options **\n");
       printf("1.Search all occurence.\n");
       printf("2.Search first occurence only.\n");
       printf("3.Search last occerence only.\n");
       printf("4.Search at any occurence.\n");

       int option;
       printf("Enter the option from search options (1-4):");
       scanf("%d",&option);

       switch (option)
       {
       case 1:
        for (int i = 0; i < count; i++)
        {
           printf("Element found at position : %d\n",a[i] + 1);
           return 0;
        }
        break ;

        case 2 :
        printf("Element found at position : %d\n",a[0]+1);
        return a[0];
        break;

        case 3 :
        printf("Element found at position : %d\n",a[count -1] + 1);
        return a[count-1];
        break;

        case 4 : {
        int position;
        printf("Enter which occurence you want (2-%d):",count-1);
        scanf("%d",&position);

        if (position > 1 && position < count)
        {
           printf("Element at position : %d\n",a[position-1] + 1);
        } else {
            printf("Invalid Position.\n");
        }
        return a[position-1];
       break;
    }
       
       default:
        break;
       }
    } 
    return 0;
}




void displayArray(int arr[],int n){
    printf("Array element are :");
    for (int i = 0; i < n; i++)
    {
      printf("%d ",arr[i]);
    }  
}




int insertion(int arr[] , int n){
    int option;
    printf("---- Insertion Menu ----\n");
    printf("1.Insertion at end.\n");
    printf("2.Insertion at beginning.\n");
    printf("3.Insertion at any position.\n");

    printf("Enter the option from Insertion menu (1-3) :");
    scanf("%d",&option);

    int x;
    printf("Enter the element you want to insert in array :");
    scanf("%d", &x);

   if (option == 1)
   {
   arr[n] = x;
   
   } else if (option == 2){

   for (int i = n-1 ; i >= 0 ; i--)
   {
    arr[i+1] = arr[i];
   }
   arr[0] = x;

   } else if (option == 3){

    int index;
    printf("Enter the position to insert the number (2-n) :");
    scanf("%d",&index);
    for (int i = n-1; i >= index - 1; i--)
    {
       arr[i+1] = arr[i];
    }
    arr[index-1] = x;
    }  else  {

        printf("Invalid selection.\n");
    }

   printf("Array after insertion of array :");
    for (int i = 0; i < n+1; i++)
    {
       printf("%d ",arr[i]);
    }
    return 0;
}





int deletion(int arr[] , int n){
int option;
printf("**** Deletion Menu ****\n");
printf("1.deletion at end.\n");
printf("2.deletion at beginning.\n");
printf("3.deletion at any position.\n");
printf("4.deletion any particular number.\n");

printf("Enter the option from deletion menu:");
scanf("%d",&option);

switch (option)
{
case 1:
    n = n-1;
    break;

case 2:
   for (int i = 0; i < n-1; i++)
   {
    arr[i] = arr[i+1];
   }
   n = n-1;
   break;

case 3: {
   int index;
   printf("Enter the position you want to delete(2-%d):",n-1);
   scanf("%d", &index);

   for (int i = index-1 ; i < n-1 ; i++)
   {
   arr[i] = arr[i+1];
   }
   n = n-1;
}
case 4 :{
int z = linearSearch(arr , n);
if (z != 0)
{
   for (int i = z; i < n-1; i++)
   {
    arr[i] = arr[i+1];
   }
   n = n - 1;
}

}
default:
    break;
}

printf("Array after deletion :");

for (int i = 0; i < n; i++)
{
   printf("%d ",arr[i]);
}

return 0;
}



int main(){
    int n;
    printf("Enter the number of element in array:");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the element of array:");
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }

    int choice;
    printf("****** Operations-Menu ******\n");
    printf("1.Linear Search.\n");
    printf("2.Traversal.\n");
    printf("3.Insertion of element.\n");
    printf("4.Deletion of element.\n");

    printf("Enter the choice from operation menu (1-4):");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1 :
        linearSearch(arr,  n);
        break;
    case 2 :
        displayArray(arr , n);
        break;
    case 3 :
        insertion(arr , n);
        break;
    case 4 :
        deletion(arr , n);
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }


      
}