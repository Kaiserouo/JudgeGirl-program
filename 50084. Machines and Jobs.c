#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

// XXX: never ending: do job1 all the time, exceeding 2 and go up to 50X???
// XXX: task needs to wait until previous task ends: fix FinishTime such that time_arrival updates

typedef struct{
    int index_machine, time;
} Task;
typedef struct{
    int time_arrival;   // also updates, representing next min start time
    int time_finish;
    int num_task;
    int cur_task;   // current task index
    Task task[500];
} Job;

// input function for all job & task data
void JobInfoInput(Job job[], int num_job){
    for(int ji = 0; ji < num_job; ji++){
        scanf("%d%d", &job[ji].time_arrival, &job[ji].num_task);
        for(int ti = 0; ti < job[ji].num_task; ti++){
            scanf("%d%d", &job[ji].task[ti].index_machine, &job[ji].task[ti].time);
        }
        job[ji].cur_task = 0;
        job[ji].time_finish = -1;
    }
    return;
}

bool HasFinishedJob(Job *job){
    return job->num_task == job->cur_task;
}

// can also use "time_finished != -1", maybe...
bool HasFinishedAllJob(Job job[], int num_job){
    for(int ji = 0; ji < num_job; ji++){
        if(!HasFinishedJob(&job[ji])){
            return false;
        }
    }
    return true;
}

// find finish time of machine after executed cur_job's task
// note that data won't update, and task executed is cur_job->cur_task
int FindFinishTime(int machine[], Job *cur_job){
    Task *cur_task = cur_job->task + cur_job->cur_task;
    int *cur_machine = machine + cur_task->index_machine;

    int finish_time;
    if(*cur_machine <= cur_job->time_arrival){
        finish_time = cur_job->time_arrival + cur_task->time;
    }
    else{
        finish_time = *cur_machine + cur_task->time;
    }

    return finish_time;
}

// tackles with HasFinishedJob stuff inside, returning next job *
Job *FindNextJob(int machine[], int num_machine, Job job[], int num_job){
    int index_job = 0;
    int min_finish_time = __INT16_MAX__;

    // iterate all job
    for(Job *cur_job = job; cur_job < job + num_job; cur_job++){
        if(HasFinishedJob(cur_job)){
            continue;
        }

        int cur_finish_time = FindFinishTime(machine, cur_job);

        // update min_finish_time
        if(cur_job == job){ // first iteration
            min_finish_time = cur_finish_time;
            continue;
        }
        else if(cur_finish_time < min_finish_time){
            index_job = cur_job - job;
            min_finish_time = cur_finish_time;
        }
    }
    return job + index_job;
}

void PrintAllFinishTime(Job job[], int num_job){
    for(int ji = 0; ji < num_job; ji++){
        printf("%d\n", job[ji].time_finish);
    }
    return;
}

// test only
void PrintAllJob(Job job[], int num_job){
    for(int ji = 0; ji < num_job; ji++){
        printf("Job #%d:\n", ji);
        for(int ti = 0; ti < job[ji].num_task; ti++){
            printf("    task #%d: (%d, %d)\n", ti, job[ji].task[ti].index_machine, job[ji].task[ti].time);
        }
    }
}
void PrintAllStatus(int machine[], int num_machine, Job job[], int num_job){
    printf("[*] Print all status...\n");
    printf("  machine:\n");
    for(int mi = 0; mi < num_machine; mi++){
        printf("      #%d: %d\n", mi, machine[mi]);
    }
    printf("  job:\n");
    for(int ji = 0; ji < num_job; ji++){
        printf("      #%d: num_task = %d, cur_task = %d, time_finish = %d\n", ji, job[ji].num_task, job[ji].cur_task, job[ji].time_finish);
    }
    return;
}

int machine[501];   // machine ready
Job job[501];

int main(){
    int num_machine, num_job;
    scanf("%d%d", &num_machine, &num_job);

    // input & init, and i don't like RE so I'll give it a try
    memset(machine, 0, num_machine * sizeof(int));
    JobInfoInput(job, num_job);

    while(!HasFinishedAllJob(job, num_job)){
        Job *cur_job = FindNextJob(machine, num_machine, job, num_job);
        int cur_machine_index = cur_job->task[cur_job->cur_task].index_machine;
        machine[cur_machine_index] = cur_job->time_arrival = FindFinishTime(machine, cur_job);
        (cur_job->cur_task)++;
        if(HasFinishedJob(cur_job)){ // finished job
            cur_job->time_finish = machine[cur_machine_index];
        }
    }

    PrintAllFinishTime(job, num_job);
}