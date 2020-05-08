/** PERSONAL NOTE : DELETE AFTER DONE
 *  IF MEET ANG 3 STAR COMMENT THAT MEANS UNFINISHED
 * 
 * CURRENT PROGRESS : 
 * READ PROJECT 7/8 ON WEBSITE BEFORE CONTINUING!!!!!!!
 * 
 * derive assembly. (Actually it's sepearated from other things)
 * 
 * Consider leaving all error detection later.
 * 
 * block comments possible and needs to realize: see vm_translate.c
 * 
 * Initialization & multi-file translating : 
|* translate function MUST only rely on 2 FILE pointer. Since catencatation is necessary,
|* make sure to deal with the order of file inputted. May do this in "final project.c"
|*  
|* Consider multi-file translate. Need to research if more than "SP=256;call Main.main" is needed for 
|* builtin Sys.init.
|* Notes for multi-file: fopen can read absolute path. <libgen.h> for basename for dirname.
|* https://stackoverflow.com/questions/13805059/dirname-in-c-is-the-manual-wrong
|* 
|* Initialization must be dealt with now or later. Maybe can work after every 
|* output_ function dealt with and program above tested, along with other smaller functions.
 * INITIALIZATION DONE IN "final project.c"!!!
 * 
 * Need to consider how to dissect function further into more files. Must but not emergent.
 * 
 * Maybe a bit of testing on program "final project", "translate" would be great.
 * 
 * error detection:
|* Need to deal with error message in output_memory before continuing. Best to
|* also plan further error message first before actually fix error message
|* function and its argument. Maybe fixing statement variable by recording every
|* argument line in file would be a good idea.
|* 
|* After error message problem is fixed, consider how to dissect some of the
|* output_ functions or it will be a mess.
 * 
 * 
 * NOTE :
 * 1.error message type(haven't dealt with):
 *      program flow: label not defined
 *      function: function not defined
**/


/**
 *  Final project: VM translator
 *  
 *  This translator translates a .vm file to its assembly form.
 *  Use something like cmd and type input .vm filename as an argument.
 * 
 *  Note:
 *      1. Only one argument can be used, while file must be in the same folder /*** NOT ANYMORE
 *         and ends in ".vm" or program ends in assertion failure.
 * 
 *      2. This is only a program containing a main function and deals with some
 *         simple stuff such as filename extensions fixes. All the magic is in another
 *         file in function form.
 * 
 *      3. Doesn't support all comment form: only inline comment is available.  /*** NOT ANYMORE
 *         
 *      4. Supports some error detection: /*** INPUT SUPPORTED DETECTION
 *      
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "vm_translate.h"

/* define */
#define MAXLEN_FILENAME 100

/* function */
// change file extension into .asm
void fix_filename_extension(char filename[MAXLEN_FILENAME]){
    char dot = strchr(filename, '.');
}
int initialization(FILE *fout){

}

/* main */
int main(int argc, char *argv[]){
    assert(argc == 2);  // input must be 2 string, second string is filename

    // make output filename
    char output_filename[MAXLEN_FILENAME];
    strcpy(output_filename, argv[1]);
    fix_filename_extension(output_filename);

    // open file
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(output_filename, "w");
    assert(fin != NULL);
    assert(fout != NULL);

    // call translate
    initialization(fout);
    translate(fin, fout);   // in another file
    
    // finish translation, close file
    fclose(fin);
    fclose(fout);

    return 0;
}