typedef struct DataNode
{
    char *cmd;
    char *desc;
    void (*handler)();
    struct DataNode *next;
}tDataNode;

tDataNode* FindCmd(tDataNode *head, char* cmd);

int ShowALLCmd(tDataNode *head);
