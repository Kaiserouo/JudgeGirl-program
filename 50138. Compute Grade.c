#include <stdio.h>

typedef struct{
    int rawScore;
    double scaledScore;
}Score;
 
typedef struct{
    char id[10];
    Score score[18];
    double finalScore;
}Student;
 
typedef struct{
    int numStudent;
    Student student[1000];
}Classes;

void print_score(Classes classes[2]){
    for(int c = 0; c < 2; c++){
        for(int i = 0; i < classes[c].numStudent; i++){
            Student *curStu = &(classes[c].student[i]);
            printf("%s %f\n", curStu->id, curStu->finalScore);
        }
    }
}

// Too dumb to forget that one can simply set a Student pointer instead of something
// like classes[c].student[i].score[quizIndex].scaledScore, so this function has already
// lost its readability and I don't really wanna fix it now.
void computeGrade(Classes classes[2]){
    // deal with all quiz one by one
    for(int quizIndex = 0; quizIndex < 18; quizIndex++){
        double sum[2] = {0};
        for(int c = 0; c < 2; c++){
            for(int i = 0; i < classes[c].numStudent; i++){
                sum[c] += classes[c].student[i].score[quizIndex].rawScore;
            }
            sum[c] /= classes[c].numStudent;
        }
        int lowerClass = sum[0]>sum[1]?1:0;
        int higherClass = sum[0]>sum[1]?0:1;
        double ratio = sum[higherClass] / sum[lowerClass];
        for(int c = 0; c < 2; c++){
            if(c == lowerClass){
                for(int i = 0; i < classes[c].numStudent; i++){
                    classes[c].student[i].score[quizIndex].scaledScore = classes[c].student[i].score[quizIndex].rawScore * ratio;
                    if(classes[c].student[i].score[quizIndex].scaledScore > 100)classes[c].student[i].score[quizIndex].scaledScore = 100;
                }
            }else{
                for(int i = 0; i < classes[c].numStudent; i++){
                    classes[c].student[i].score[quizIndex].scaledScore = classes[c].student[i].score[quizIndex].rawScore;
                }
            }
        }
    }

    // deal with students' final score
    for(int c = 0; c < 2; c++){
        for(int i = 0; i < classes[c].numStudent; i++){
            Student *curStu = &(classes[c].student[i]);
            double allSum = 0;
            for(int quizIndex = 0; quizIndex < 18; quizIndex++){
                allSum += curStu->score[quizIndex].scaledScore;
            }
            curStu->finalScore = allSum*0.06;
            if(curStu->finalScore > 100)curStu->finalScore = 100;
        }
    }
    print_score(classes);
}

/* main guessed by myself */
int main(){
    Classes classes[2];
    for(int c = 0; c < 2; c++){
        scanf("%d", &(classes[c].numStudent));
        for(int i = 0; i < classes[c].numStudent; i++){
            Student *curStu = &(classes[c].student[i]);
            scanf("%s", curStu->id);
            for(int j = 0; j < 18; j++){
                scanf("%d", &(curStu->score[j].rawScore));
            }
        }
    }
    computeGrade(classes);
}