#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "log.h"

TreeError createTree(Tree * newTree, const char * pathToLog, treeElem_t rootElem, const char * file, int line)
{
    if (!newTree) return NULL_PTR;

    newTree->logFile           = fopen(pathToLog, "w");
    newTree->numberOfOperation = 0;

    if (!newTree->logFile) {
        newTree->codeOfError = LOG_FAIL;
        return LOG_FAIL;
    }

    fprintf(newTree->logFile, "<pre><span style=\"font-size: 16px\">\n\n");

    newTree->firstNode = (Node *)calloc(1, sizeof(Node));
    if (!newTree->firstNode) return NULL_CALLOC;

    newTree->firstNode->data = rootElem;

    DO_LOG_DUMP(line, file, newTree)
    
    return NORMAL;
}

TreeError createNode(Tree * tree, treeElem_t newElement, const char * file, const int line)
{
    Node * prevNode = _findPlaceForNode(tree->firstNode, newElement);

    Node * newNode = (Node *)calloc(1, sizeof(Node));
    if (!newNode) return NULL_CALLOC;

    newNode->data = newElement;

    if (prevNode->data > newElement) prevNode->left = newNode;
    else prevNode->right = newNode;

    DO_LOG_DUMP(line, file, tree);

    return NORMAL;
}

Node * _findPlaceForNode(Node * actualNode, treeElem_t newElement)
{
    if (newElement < actualNode->data && actualNode->left) return _findPlaceForNode(actualNode->left, newElement);
    else if (newElement >= actualNode->data && actualNode->right) return _findPlaceForNode(actualNode->right, newElement);

    return actualNode;
}

TreeError destructTree(Tree * tree)
{
    _freeNode(tree->firstNode);
    fclose(tree->logFile);

    return NORMAL;
}

void _freeNode(Node * node)
{
    if (node->left) _freeNode(node->left);
    if (node->right) _freeNode(node->right);

    free(node);
}