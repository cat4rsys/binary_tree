#ifndef LOGH
#define LOGH

#include <stdio.h>

#define DO_LOG_DUMP(line, file, tree) {                           \
	logDump(__func__, line, file, tree);                          \
}

const int sizeOfBuf = 100;

void logDump(const char * func, const int line, const char * file. Tree * tree);

void dump(Tree * tree, char * pathToDot);

void logClose(Tree * tree);

#endif // LOGH
