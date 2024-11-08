#include <stdio.h>

#define DO_CREATE_TREE(tree, pathToLog) {                           \
	(tree, pathToLog, __FILE__, __LINE__);                   \
}

typedef int treeElem_t;

typedef struct Node
{
    treeElem_t data;
    struct Node * left;
    struct Node * right;
} Node;

typedef struct Tree
{
    Node * firstNode;
    TreeError codeOfError;

    FILE * logfile;
    int numberOfOperation;
} Tree;

enum TreeError {
    NORMAL      = 0,
    NULL_CALLOC = 1 << 1,
    LOG_FAIL    = 1 << 2
};

Node * createTree(Tree * newTree, char * pathToLog, char * file, int line);

Node * createNode(treeElem_t newElement);
