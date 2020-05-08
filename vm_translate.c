/**
 * VM translator function:
 *
 * given input/output file as FILE pointer,
 * translate input .vm file as assembly file
 * 
 * op code: 
 *      000: Arithmic: {add, sub, neg, eq, gt, lt, and, or, not}
 *      100: Memory access: {pop, push}
 *      200: Program flow: {label, goto, if-goto}
 *      300: Function calling: {function, call, return}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "output_statement.h"

/* define and operation strings */

#define MAXLEN_PER_LINE 1000    // maximum chars per line
#define MAXLEN_ARG 10    // maximum chars per argument

char op_str [4][12][MAXLEN_ARG] = { // "0" is end of array
    {"add", "sub", "neg", "eq", "gt", "lt", "and", "or", "not", "0"},
    {"pop", "push", "0"}, {"label", "goto", "if-goto", "0"}, {"function", "call", "return", "0"}
};
int op_arg [4][12] = { // "0" is end of array
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2, 0}, {1, 1, 1, 0}, {2, 2, 0, 0}
};
char segment_str[8][10] = {
    "static", "temp", "pointer", "this", "local", "argument", "that", "constant"
};
enum Error{NOT_OP, NOT_SEG, NOT_NUM,};
struct Statement{
    int op;
    int arg_needed;
    char arg[2][MAXLEN_ARG];
};

/* function */

/* smaller functions as helper for following functions */


// find element in set (char), if can't return -1
int find_element(char *set[], char element[]){

}

// see if char represents a num, if can't return -1
int is_number(char *str){

}

/* major functions used in function "translate" */
// initialize given output file
void initialize(FILE *fout){
}

// read op and input op and arg_needed, if not found return -1;
int read_op(char *buffer, struct Statement *statement){
    for(int i = 0; i < 4; i++){
        for(int j = 0; ; j++){
            if(!strcmp(op_str[i][j], "0"))  break;
            else{
                if(!strcmp(op_str[i][j], buffer)){
                    statement->op = 100*i+j;
                    statement->arg_needed = op_arg[i][j];
                    return 0;
                }
            }
        }
    }
    statement->op = -1;
    return 0;
}


// Do the magic.
int translate(FILE *fin, FILE *fout){

    /* variable */
    struct Statement statement;

    int hasReadOp = 0;  // has read recognized operation ? 0: no, i: read operation that need i arguments
    int readArgs = 0;   // number of arguments read
    int hasReadCmt = 0; // has detected comment, skip rest of input in this line

    int cur_line = 0;    // current processing line number, for error detection
    char input[MAXLEN_PER_LINE];    // for every fgets
    char buffer[MAXLEN_PER_LINE];    // for every sscanf


    while(fgets(input, MAXLEN_PER_LINE, fin) != NULL){
        
        cur_line++;
        while(sscanf(input, "%s", buffer) != NULL){

            // comment searching
            char *comment_ptr = buffer;
            if((comment_ptr = strstr(buffer, "//")) != NULL){   // searched inline comments
                *comment_ptr = '\0';    // cut current string
                if(comment_ptr == buffer)   // whole line is comment, direct skip
                    break;
                hasReadCmt = 1;
            }
            if((comment_ptr = strstr(buffer, "//")) != NULL){   // searched inline comments
                *comment_ptr = '\0';    // cut current string
                if(comment_ptr == buffer)   // whole line is comment, direct skip
                    break;
                hasReadCmt = 1;
            }

            if(!hasReadOp){
                read_op(buffer, &statement);
                if(statement.op == -1){ // illegal operation
                    my_error_msg(NOT_OP, cur_line, buffer);
                }
                else{
                    hasReadOp = 1;
                }
            }
            else{   //hasReadOp = 1
                strcpy(statement.arg[ readArgs ], buffer);
                readArgs++;
                if(readArgs == statement.arg_needed){
                    output(&statement, fout);
                    hasReadOp = 0;
                }
            }

            /*** LAST ***/
            if(hasReadCmt){
                hasReadCmt = 0;
                break;
            }  
        }
    }
    
}