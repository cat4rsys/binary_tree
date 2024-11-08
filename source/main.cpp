#include "tree.h"

int main() 
{
    Tree tree = {};
    DO_CREATE_TREE(&tree, "log/logfile.htm", 10);

    DO_CREATE_NODE(&tree, 5);

    DO_CREATE_NODE(&tree, 15);

    DO_CREATE_NODE(&tree, 25);

    DO_CREATE_NODE(&tree, 0);

    DO_CREATE_NODE(&tree, 3);

    destructTree(&tree);
}