#include<stdio.h>
//importing the standard input output libraries


//this function helps find the length of the collatz sequence for a particular number
int collatzLength(int n)
{
    int current = n;    //the chain already consists one element
    int len = 1;    
    while(current!=1)   //manipulating until the sequence reaches 1
    {
        if(current%2==0)
            current = current/2;
        else
            current = current*3 + 1;
        len++;
    }
    return len;         //returning the length of the required sequence
}


//thsi function facilitates the printing of the Collatz sequence
void printCollatz(int n)
{
    int current = n;
    while(current!=1)
    {
        printf("%d -> ", current);          //printing in the required manner
        if(current%2==0)
            current = current/2;
        else
            current = current*3 + 1;
    }
    printf("%d",current);   //printing the last digit
}

int main()
{
    //  Insert your code here.
    int n, i, nummax; //declaring variables and taking input
    scanf("%d", &n);    
    int max = collatzLength(1);
    nummax = 1;
    for(i = 2; i<=n; i++)
    {
        printf("i = %d\n",i);
        if(collatzLength(i)>max)
        {
            max = collatzLength(i);         //find the maximum length till now
            nummax = i;
        }
    }
    printf("%d\n", max);        //printing the length
    printCollatz(nummax);       //printing the sequence by calling the void function
    return 0;
}
//end of program