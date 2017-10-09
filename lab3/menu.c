#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"

void help();
void quit();
void add();
void sub();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

static tDataNode head[]=
{
    {"help", "1.Show all commad",           help, &head[1]},
    {"quit", "2.Quit from the application", quit, &head[2]},
    {"add",  "3.Add two numbers",           add,  &head[3]},
    {"sub",  "4.Sub two numbers",           sub,  NULL},
};

int main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please input a command >");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if(p == NULL)
        {
            printf("Wrong command,please try again");
            continue;   
        }
        printf("%s\t - %s\n", p -> cmd, p->desc);
        if(p -> handler != NULL)
        {
            p -> handler();
        }
    }
    return 0;
}

void help()
{
    ShowALLCmd(head);   
}


void quit()
{
    printf("GOOD BYE");
    exit(0);
}


void add()
{
    int x, y;
    printf("Input two numbers: ");
    scanf("%d%d", &x, &y);
    printf("The result is: %d\n", x + y);
}

void sub()
{
    int x, y;
    printf("Input two numbers: ");
    scanf("%d%d", &x, &y);
    printf("The result is: %d", x - y);
}



































