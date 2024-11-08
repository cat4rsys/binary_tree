#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

TreeError createTree(Tree * newTree, char * pathToLog, char * file, int line)
{
    newTree->logfile           = fopen(pathToLog, "w");
    newTree->numberOfOperation = 0;

    if (!newTree->logfile) {
        newTree->codeOfError = LOG_FAIL;
        return LOG_FAIL;
    }



    return NORMAL;
}

Node * createNode(treeElem_t newElement)
{
    return (Node *)calloc(sizeof(Node), 1);
}
