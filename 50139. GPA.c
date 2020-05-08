#include <stdio.h>
#include <stdlib.h>

struct Class{
    int academic_credit;  
    char score[3];
};
struct Student{
    char name[20];
    int N_class; // total number of classes the student takes.
    int N_credit; // total number of academic credits.
    double GPA;
    struct Class all_class[10];
};
double score_to_GPA(char c[3]){
    double score = 0;
    switch(c[0]){
    case 'A':score = 4;break;
    case 'B':score = 3;break;
    case 'C':score = 2;break;
    case 'F':score = 0;break;
    }
    switch(c[1]){
    case '+':score += 0.3;break;
    case '-':score -= 0.3;break;
    }
    return score;
}
// calculate that student's GPA
void calc_student_GPA(struct Student *student){
    // calculate N_credit
    student->N_credit = 0;
    for(int i = 0; i < student->N_class; i++){
        student->N_credit += student->all_class[i].academic_credit;
    }
    // calculate sum of weighted GPA
    student->GPA = 0;
    for(int i = 0; i < student->N_class; i++){
        student->GPA += score_to_GPA(student->all_class[i].score) * student->all_class[i].academic_credit;
    }
    student->GPA /= student->N_credit;
}
// rank GPA
int compare(const void *a, const void *b){
    if(((struct Student *)b)->GPA - ((struct Student *)a)->GPA == 0)return 0;
    return (((struct Student *)b)->GPA - ((struct Student *)a)->GPA) > 0 ? 1 : -1;
}
void GPA_calculation(struct Student all_student[], int N){
    for(int i = 0; i < N; i++){
        calc_student_GPA(all_student+i);
    }

    qsort(all_student, N, sizeof(struct Student), compare);

    int numPrize = (N/20 + 1 - (N % 20 == 0));
    for(int i = 0; i < numPrize; i++){
        if((all_student[i].N_credit >= 15) && (all_student[i].GPA > 3.38)){
            printf("%d %s %f\n", i+1, all_student[i].name, all_student[i].GPA);
        }
    }
    return;
}

/* given main */
int main(int argc, char const *argv[])
{
    struct Student all_student[10000];
    int N, i, j;
 
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%s%d", all_student[i].name, &all_student[i].N_class);
        for(j = 0; j < all_student[i].N_class; j++){
            scanf("%d%s", &all_student[i].all_class[j].academic_credit, all_student[i].all_class[j].score);
        }
        all_student[i].N_credit = 0;
        all_student[i].GPA = 0.0;
    }
 
    GPA_calculation(all_student, N);
    for(int i = 0; i < N; i++){
        printf("%s : (%d, %f)\n",all_student[i].name , all_student[i].N_credit, all_student[i].GPA);
    }
 
    return 0;
}