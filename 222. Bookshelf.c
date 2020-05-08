#include <stdio.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int Readint(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int findpos(unsigned long long int shelf, int num);
int findnum(unsigned long long int shelf, int pos);
void takeout(unsigned long long int *shelf, int pos);
int main(){
    unsigned long long int shelf = 0;
    int num;
    while(Readint(&num)){
        int pos = findpos(shelf, num);
        
        switch(pos){
        case -1: //not in shelf
            shelf <<= 8;shelf += num;
            break;
        default:  //in shelf
            takeout(&shelf, pos);
            shelf <<= 8;shelf += num;
        }
        
    }
    for(int i=7; i>=0; i--)printf("%d%c", findnum(shelf, i), i==0?'\n':' ');
}

/* function */

/* findpos: 
* if (exist in shelf) return pos, 76543210
* else return -1
*/
int findpos(unsigned long long int shelf, int num){
    for(int i=7; i>=0; i--){
        if(findnum(shelf, i) == num){
            return i;
        }
    }
    return -1;
}
/* takeout:
* take book out, others put left if possible
*/
void takeout(unsigned long long int *shelf, int pos){
    unsigned long long int tmp = 0;
    for(int i=0; i<pos; i++)tmp += (unsigned long long int)255<<(i*8);
    tmp = (*shelf) & tmp;
    (*shelf) -= tmp;
    (*shelf) >>= (8*(pos+1));
    (*shelf) <<= (8*(pos));
    (*shelf) += tmp;
}

int findnum(unsigned long long int shelf, int pos){
    return shelf>>(pos*8) & 255;
}