#include<stdio.h>

int main(int argc, char const *argv[]) {
    int sum = 0;
    for(int i=3;i<1000;i+=3)
        sum += i;
    for(int j=5;j<1000;j+=5)
        if(j%3!=0)
            sum+=j;
    printf("%d",sum);
    return 0;
}
