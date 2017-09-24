#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmdHelp();
void add();
void subtract();
void multiple();
void divid();
void function();
void matrix();
void img();
void words();
void quit();

int main()
{
    char cmd[128];
    int number;

    while(1)
    {
        printf("\nPlease intput 'help' to get commands: ");
        scanf("%s", cmd);
        if(strcmp(cmd, "help") == 0)
        {
            cmdHelp();
        }
        printf("\nInput the number:");
        scanf("%d", &number);
        if(number ==1)
        {
            add();
        }
        else if(number == 2)
        {
            subtract();
        }
        else if(number == 3)
        {
            multiple();
        }
        else if(number == 4)
        {
            divid();
        }
        else if(number == 5)
        {
            function();
        }
        else if(number == 6)
        {
            matrix();
        }
        else if(number == 7)
        {
            img();
        }  
        else if(number == 8)
        {
            words();
        }
        else
        {
            quit();
        }
    }
}
/* The welcome GUI */
void cmdHelp()
{
    printf("\n");
    printf("************************************\n");
    printf("*The followings are commands:\n");
    printf("************************************\n");
    printf("*1. Addtion\n");
    printf("*2. Subtraction\n");
    printf("*3. Multiplictive\n");
    printf("*4. Divid\n");
    printf("*5. Y=x`3 + 1\n");
    printf("*6. A matrix in 3 dimension\n");
    printf("*7. Img\n");
    printf("*8. My best wish!\n");
    printf("*9. Quit\n");
    printf("************************************\n");

}

/* Addition */
void add()
{
    int x, y;
    printf("input two numbers: ");
    scanf("%d%d", &x, &y);
    printf("the result: %d", x + y);
}   

/* Subtraction */
void subtract()
{ 
    int x, y;
    printf("input two numbers: ");
    scanf("%d%d", &x, &y);
    printf("the result: %d", x - y);
}

/* Multiple */
void multiple()
{
    int x, y;
    printf("input two numbers: ");
    scanf("%d%d", &x, &y);
    printf("the result: %d\n", x * y);
}

/* Divid */
void divid()
{
    int x, y;
    printf("input two numbers: ");
    scanf("%d%d", &x, &y);
    printf("the result: %f", (float)(x / y));
}
/* Function */
void function()
{
    int x, y;
    printf("input the x: ");
    scanf("%d", &x);
    printf("Y = %d\n", x * x * x + 1);
}

/* Matrix */
void matrix()
{
    int num[9];
    int i;
    int x;
    printf("input the 9 elements in matrix in order:\n");
    for(i = 0; i < 9; i ++)
    {
        scanf("%d", &x);
        num[i] = x;
    }
    for(i = 0; i < 9; i ++ )
    {
        if((i + 1) % 3 == 0)
        {
            printf("%d\t", num[i]);
            printf("\n");
        }
        else 
            printf("%d\t", num[i]);
    }
}

/* Img */
void img()
{
    printf("****\n");
    printf(" ****\n");
    printf("  ****\n");
    printf(" ****\n");
    printf("****\n");   
}

/* Words */
void words()
{ 
    printf("Good luck to you!\n");
}

/* Quit */
void quit()
{
    exit(0);
}
