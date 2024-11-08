#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "tree.h"

void logDump(const char * func, const int line, const char * file, Tree * tree)
{
    char dotFile[sizeOfBuf] = {};
    char pngFile[sizeOfBuf] = {};

    snprintf(dotFile, sizeOfBuf, "log/%d.dot", tree->numberOfOperation);
    snprintf(pngFile, sizeOfBuf, "log/%d.png", tree->numberOfOperation);

    tree->numberOfOperation++;

    fprintf(tree->logFile, "Dump called from function %s (\n\n", func);
    dump(tree, dotFile);

    char cmd[sizeOfBuf] = "dot -Tpng -o ";
    strcat(cmd, pngFile);
    strcat(cmd, " ");
    strcat(cmd, dotFile);

    system(cmd);

    fprintf(log->logFile, "<img src=\"%s\">", pngFile + 4);
}

void dump(List * list, char * pathToDot)
{
    FILE * dotFile = fopen(pathToDot, "w");
    if (!dotFile) return;

    fprintf(dotFile, "digraph G{\n\trankdir=LR;\n\tnode[shape=rect,style=rounded];\n\t");

    for (int i = 0; i < list->capacity; i++) {
        fprintf(dotFile, "id%d [shape=record,label=\"{ id:%d } | data:%d | next:%d | prev:%d }\"]\n\t", i, i, list->data[i].element, list->data[i].next, list->data[i].prev);
    }

    int c = 0;
    int next = list->data[c].next;
    for (int i = 0; i < list->actualSize; i++) {
        fprintf(dotFile, "id%d -> id%d;\n\t", c, next);
        c = next;
        next = list->data[c].next;
    }

    c = list->free;
    next = - list->data[c].next;
    for (int i = 1; i < list->capacity - list->actualSize; i++) {
        fprintf(dotFile, "id%d -> id%d;\n\t", c, next);
        c = next;
        next = - list->data[c].next;
    }

    fprintf(dotFile, "}\n");

    fclose(dotFile);
}

void logClose(LogInfo * log)
{
    fclose(log->logFile);
}

