#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXLEN 100
#define MAXN 100

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int initialize(FILE *fp){
    fprintf(fp, "<table border=\"1\">\n<tbody>\n");
}
int finalize(FILE *fp){
    fprintf(fp, "</tbody>\n</table>");
}

int main(){
    char in[MAXLEN];
    char out[MAXLEN];
    scanf("%s%s", in, out);
    FILE *fin, *fout;
    fin = fopen(in, "rb");
    assert(fin != NULL);
    fout = fopen(out, "w");
    assert(fout != NULL);

    initialize(fout);

    int size;
    Student buf[MAXN];
    while((size = fread(buf, sizeof(Student), MAXN, fin)) != 0){
        for(int i = 0; i < size; i++){
            fprintf(fout, "<tr>\n<td>%s</td>\n<td>%d</td>\n<td>%s</td>\n<td>%f, %f, %f, %f</td>\n<td>%d, %d, %d</td>\n</tr>\n", 
                    buf[i].name,buf[i].id,buf[i].phone,buf[i].grade[0],buf[i].grade[1],buf[i].grade[2],buf[i].grade[3],buf[i].birth_year,buf[i].birth_month,buf[i].birth_day);
        }
    }

    finalize(fout);

    fclose(fin);
    fclose(fout);
}