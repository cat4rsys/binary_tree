#ifndef TREE_H
#define TREE_H

#include <stdio.h>

#define DO_CREATE_TREE(tree, pathToLog, rootElem) {                           \
	createTree(tree, pathToLog, rootElem, __FILE__, __LINE__);                   \
}

#define DO_CREATE_NODE(firstNode, newElement) {                           \
	createNode(firstNode, newElement, __FILE__, __LINE__);                   \
}

typedef int treeElem_t;

typedef struct Node
{
    treeElem_t data;
    struct Node * left;
    struct Node * right;
} Node;

enum TreeError {
    NORMAL      = 0,
    NULL_CALLOC = 1 << 1,
    LOG_FAIL    = 1 << 2,
    NULL_PTR    = 1 << 3
};

typedef struct Tree
{
    Node * firstNode;
    TreeError codeOfError;

    FILE * logFile;
    int numberOfOperation;
} Tree;

TreeError createTree(Tree * newTree, const char * pathToLog, treeElem_t rootElem, const char * file, int line);

TreeError createNode(Tree * firstNode, treeElem_t newElement, const char * file, const int line);

Node * _findPlaceForNode(Node * actualNode, treeElem_t newElement);

TreeError destructTree(Tree * tree);

void _freeNode(Node * node);

#endif // TREE_H
