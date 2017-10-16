#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10
int help();
int quit();
int add();
int sub();
typedef struct DataNode
{
	tLinkTableNode *pNext;
	char* cmd;
	char* desc;
	int (*handler)();
	struct DataNode *next;
}tDataNode;


tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
		tDateNode* pNode = (tDataNode*)GetLinkTableHead(head);
		while(pNode != NULL)
		{
			if(strcmp(pNode->cmd, cmd) == 0)
			{
				return pNode;
			}
			pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode)pNode);
		}
		return NULL;
}
int ShowAllCmd(tLinkTable* head)
{
	tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		printf("%s - %s\n",pNode -> cmd, pNode -> desc);
		pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
	}
	return 0;
}

int InitMenuData(tLinkTable **ppLinkTable)
{
	*ppLinkTable = CreatLinkTable();
	tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode -> cmd = "help";
	pNode -> desc = "Show all commands: ";
	pNode -> handler = help;
	AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);
	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode -> cmd = "quit";
	pNode -> desc = "Quit the menu";
	pNode -> handler = quit;
	AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);
	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode -> cmd = "add";
	pNode -> desc = "Add two numbers:";
	pNode -> handler = add;
	AddLinkTalbeNode(*ppLinkTable, (tLinkTableNode*)pNode);
	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode -> cmd = "sub";
	pNode -> desc = "Sub two numbers:";
	pNode -> handeler = sub;
	AddLinkTableNode(*ppLinkTable, (tLinkeTableNode *)pNode);
	return 0;
}
tLinkTable* head = NULL;
int main()
{
	InitMeanuData(&head);
	while(1)
	{
			char cmd[CMD_MAX_LEN];
			printf("Please Input Command> ");
			scanf("%s", cmd);
			tDataNode *p = FindCmd(head, cmd);
			if(p == NULL)
			{
				printf("Illegal Command!Try again.\n");
				continue;
			}
			printf("%s\t&s\n", p -> cmd, p -> desc);
			if(p -> handler != NULL)
			{
				p -> handler();
			}
	}
}
int help()
{
	printf("Menu List:\n");
	ShowAllCmd(head);
	return 0;
}
int quit()
{
	exit(0);
}
int add()
{
	int x, y;
	printf("Input two numbers: ");
	scanf("%d,%d", &x, &y);
	printf("The result is: %d\n", x + y);
	return 0;
}
int sub()
{
	int x, y;
	printf("Input two numbers: ");
	scanf("%d,%d", &x, &y);
	printf("The result is %d\n", x - y);
	return 0;
}

