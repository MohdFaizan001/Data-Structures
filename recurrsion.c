#include<stdio.h>

//Funtion for finding factorial of any number.
int Factorial(int n){
   
    if (n == 1 )
    {
       return 1;
    } else if (n > 1)
    {
       
       return ( n * Factorial(n - 1)) ;
    } else {
      return 0;
    }
   
}

//Function for printing n terms of fibonacci series using  recursion.
void fibonacciSeries(int n , int a , int b){
   if (n > 0 )
   {
     printf("%d ",a);
     fibonacciSeries(n-1,b ,a+b);
   }
   
}



// Function for solve tower of hanai problem.
void tower_OfHanoi(int n , char source , char auxilary , char destination){
    if(n == 1){
        printf("the disc %d moves from %c to %c\n",n, source , destination);
    return;
    }
    tower_OfHanoi(n-1, source , destination , auxilary);
    printf("the disc %d moves from %c to %c\n",n,source ,destination);

    
    tower_OfHanoi(n-1,auxilary ,source , destination);
}


int main(){
  
  while(1){

   printf("\nRecurrsion Menu\n");
   printf("1.Factorial.\n");
   printf("2.Fibonacci Series.\n");
   printf("3.Exit.\n");
   int choice ;
   printf("Enter the choice from menu :");
   scanf("%d",&choice);

   switch (choice)
   {
   case 1: {

      int n;
      printf("Enter the number :");
      scanf("%d",&n);
      int factorial = Factorial(n);
      printf("The factorial of %d is : %d",n,factorial);
      break;
      return 1;
   }
   case 2:{
    int n;
    printf("Enter the number nth term :");
    scanf("%d",&n);
    printf("Fibonacci Series :");
    fibonacciSeries(n,0,1);
   
   return 1;
   break;
   }
   case 3 :{
      int n;
      printf("Enter the no. of disks : ");
      scanf("%d",&n);

      tower_OfHanoi(n,'A','B','C','D');
       return 1;
       break;
   }
       
   case 4 :
   return 0;
   default:
          
      break;
   }
  

   
}
}