#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct string_count {
    char seen[80];
    int count;
};

int find_length(struct string_count strings[]){
    int num = 0;
    while(strings[num].count != 0)  num++;
    return num;
}

int compare(const void *a, const void *b){
    struct string_count *ptr1 = (struct string_count *)a;
    struct string_count *ptr2 = (struct string_count *)b;

    if(ptr1->count > ptr2->count)   return 1;
    else if(ptr1->count < ptr2->count)   return -1;
    else return strcmp(ptr1->seen, ptr2->seen);
}

int compare_and_add(char *string, struct string_count strings[]) {
    int num = 0;
    while(strings[num].count != 0){
        if(!strcmp(string, strings[num].seen)){
            strings[num].count++;
            return 1;
        }
        num++;
    }
    strings[num].count = 1;
    strcpy(strings[num].seen, string);
    return 0;
}

void sort(struct string_count strings[]) {
    int num = find_length(strings);
    qsort(strings, num, sizeof(struct string_count), compare);
}

void print(struct string_count strings[]) {
    int num = find_length(strings);
    for(int i = 0; i < num; i++){
        printf("%d %s\n", strings[i].count, strings[i].seen);
    }
}

/* given main */
int main() {
        struct string_count strings[20];
        int i;
        for( i=0 ; i<20 ; i++ )
                strings[i].count = 0;
        compare_and_add( "This", strings );
        compare_and_add( "is", strings );
        compare_and_add( "an", strings );
        compare_and_add( "apple,", strings );
        compare_and_add( "and", strings );
        compare_and_add( "this", strings );
        compare_and_add( "is", strings );
        compare_and_add( "a", strings );
        compare_and_add( "book.", strings );
        sort( strings );
        print( strings );
        return 0;
}