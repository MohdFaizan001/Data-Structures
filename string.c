#include<stdio.h>
#include<string.h>

// Function for traversal the string.
void displayString(char str[]){
    printf("String is : ");
    for (int i = 0; str[i] != '\0'; i++)
    {
       printf("%c",str[i]);
    }
    
}

// Function for finding length of string without using string library function.
void stringLength(char str[]){
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
      length++;
    }
    printf("The length of string is : %d\n",length);
    
}


//Function for reversing the string using  two pointer approach.
void reverseString(char str[]){
    char * p , * q;
    p = &str[0];
    q = &str[0];
    while (*q != '\0')
    {
        q++;
    }
    q--;

    while (q >= p)
    {
       printf("%c",*q);
       q--;
    }
}


//Function for checking if string is palindrome or not using pointer.
void isPalindrome(char str[]){
    int palindrome = 1;
    char * q , * p;
    p = &str[0];
    q = &str[0];
    while (*q != '\0')
    {
      q++;
    }
    q--;

    while (p < q)
    {
       if (*p != *q)
       {
        palindrome = 0;
       }
       p++;
       q--;
    }

    if (palindrome == 1)
    {
       printf("The string  is palindrome.");
    } else{
        printf("The string is not a palindrome.");
    }
    
}


//Function for inserting string 2 in string 1.
void insertString(char str[]){
    char str1[10];
    printf("Enter the string you want to insert :");
    scanf("%s",str1);
    
    int length1 = strlen(str); 
    int length2 = strlen(str1);

    int position ;
    printf("Enter the position where you want to insert string :");
    scanf("%d",&position);

    for (int i =length1  ; i >= position-1; i--)
    {
        str[i+length2] = str[i];
    }

    for (int i = 0; i < length2; i++)
    {
       str[position-1 +i] = str1[i];
    }

    printf("%s\n",str);
}



//Function for deleting any element.
void deletion(char str[]){
    
}




int main(){
    char str[20];
    printf("Enter the string:");
    scanf("%s",&str);
    
    int choice;
    printf("Enter the choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1 :
        displayString(str);
        break;

    case 2 :
        stringLength(str);
        break;

    case 3 :
       reverseString(str);
       break;
    
    case 4 :
       isPalindrome(str);
       break;

    case 5 :
       insertString(str);
       break;
    default:
        break;
    }
    

    return 0;

}
