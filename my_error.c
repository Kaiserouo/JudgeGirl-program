#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "vm_translate.h"

#define MAXLEN_PER_LINE 1000    // maximum chars per line
#define MAXLEN_ARG 10    // maximum chars per argument

enum Error{NOT_OP, NOT_SEG, NOT_NUM,};
struct Statement{
    int op;
    int arg_needed;
    char arg[2][MAXLEN_ARG];
};

// output error message
int my_error_msg(enum Error err, int cur_line, char *str){
    printf("Error: at %d: ", cur_line);
    switch(err){
        case NOT_OP:
            printf("Not a valid operation type\n    %s\n\n", str);
            break;
        case NOT_SEG:
            printf()
    }
}