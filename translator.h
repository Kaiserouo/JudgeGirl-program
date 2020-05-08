#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define NAMELEN 100
#define MAXN 65536
#define COUNT 10

enum{FILE_OUTPUT, STDOUT};

int binary_translator(int mode, char *file_in, char *file_out);