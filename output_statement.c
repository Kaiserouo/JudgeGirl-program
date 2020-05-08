#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

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

// output assembly to fout
void output_arithmic(struct Statement *statement, FILE *fout){
    int op_num = statement->op % 100;
    char jump_str = (op_num == 3 ? "JEQ" : ((op_num == 4) ? "JGT" : "JLE"));
    static label_num = 0;   // to prevent overlap name
    switch(op_num){
        case 0: /* add*/ case 1: /* sub */
            fprintf(fout, "@SP\nAM=M-1\nD=M\nA=A-1\nM=M%cD\n", op_num == 1 ? '-' : '+');
            break;
        case 2: // neg
            fprintf(fout, "@SP\nA=M-1\nM=-M\n");
            break;
        case 3: /* eq */ case 4: /* gt */ case 5: /* lt */
            fprintf(fout, "@SP\nAM=M-1\nD=M\nA=A-1\nD=M-D\n@VM_IF_%d\nD;JEQ\n", label_num);
            fprintf(fout, "@SP\nA=M-1\nM=0\n@VM_CONT_%d\n0;%s\n", label_num, jump_str);
            fprintf(fout, "(VM_IF_%d)\n@SP\nA=M-1\nM=-1\n(VM_CONT_%d)\n", label_num, label_num);
            label_num++;
            break;
        case 6: /* and */ case 7: /* or */
            fprintf(fout, "@SP\nAM=M-1\nD=M\nA=A-1\nM=D%cM\n", op_num == 6 ? '&' : '|');
            break;
        case 8: // not
            fprintf(fout, "@SP\nA=M-1\nM=!M\n");
            break;
        default:
            assert(0);
    }
}
void output_memory(struct Statement *statement, FILE *fout){
    int op_num = statement->op % 100;
    char segment[10];
    if(find_element(segment_str, statement->arg[0]) < 0){
        my_error_msg()
    }
    if(is_number(statement->arg[2]) < 0){

    }
    // assign segment
    switch(find_element(segment_str, statement->arg[0])){
        
    }
    switch(op_num){
        case 0: // pop
            break;
        case 1: // push
            break;
    }
}
void output_program_flow(struct Statement *statement, FILE *fout){
    int op_num = statement->op % 100;
    switch(op_num){
        case 0: // label
            break;
        case 1: // goto
            break;
        case 2: // if-goto
            break;
        default:
            assert(0);
    }
}
void output_function(struct Statement *statement, FILE *fout){
    int op_num = statement->op % 100;
    switch(op_num){
        case 0: // function
            break;
        case 1: // call
            break;
        case 2: // return
            break;
        default:
            assert(0);
    }
}

// output statement into fout (actually calls above function to do stuff)
void output(struct Statement *statement, FILE *fout){
    int op_catagory = statement->op / 100;
    switch(op_catagory){
        case 0:
            output_arithmic(statement, fout);
            break;
        case 1:
            output_memory(statement, fout);
            break;
        case 2:
            output_program_flow(statement, fout);
            break;
        case 3:
            output_function(statement, fout);
            break;
        default:
            assert(0);
    }
}
