/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int full = 0, empty = 3, mutex = 1;
int x = 0;
void producer()
{
    mutex = wait(mutex);
    full = signall(full);
    empty = wait(empty);
    x++;
    printf("\n Producer produces the item %d",x);
    mutex = signall(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signall(empty);
    printf("\n Consumer consumes the item %d",x);
    x--;
    mutex = signall(mutex);
}
int wait(int s)
{
    return(--s);
}
int signall(int s)
{
    return(++s);
}
int main()
{
    while(1){
        int n = 0;
        printf("\nEnter the choice of operation\n1. Produce\n2. Consume\n3. Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                if(mutex == 1 && empty != 0)
                    producer();
                else
                    printf("\nBuffer is full %d %d", mutex, empty);
                break;
            case 2:
                if(mutex == 1 && full != 0)
                    consumer();
                else
                    printf("\nBuffer is empty%d %d", mutex, full);
                break;
            case 3:
                exit(0);
                break;
        }
    }
    return 0;
}

