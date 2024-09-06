#include<stdlib.h>
#include<stdio.h>

typedef struct {
    int duration;
    int profit;
    int deadline;
}job;

void AppetibilitySort(double* appetibilita, job* jobs, size_t* index,size_t j_size) {

    for (size_t i = 1; i < j_size; i++) {

        if (appetibilita[i] > appetibilita[i - 1]) {

            double tmp = appetibilita[i - 1];
            appetibilita[i - 1] = appetibilita[i];
            appetibilita[i] = tmp;

            job tmp1 = jobs[i - 1];
            jobs[i - 1] = jobs[i];
            jobs[i] = tmp1;

            size_t tmp2 = index[i - 1];
            index[i - 1] = index[i];
            index[i] = tmp2;
        }

    }

}

int ScheduleJobs(const job* jobs, size_t j_size) {

    double* appetibilita = malloc(j_size * sizeof(double));
    size_t* index = malloc(j_size * sizeof(size_t));
    job* copy = malloc(j_size * sizeof(job));
    
    for (size_t i = 0; i < j_size; i++) {
        
        index[i] = i;

        appetibilita[i] = jobs[i].profit / jobs[i].duration;

        copy[i].deadline = jobs[i].deadline;
        copy[i].duration = jobs[i].duration;
        copy[i].profit = jobs[i].profit;
    }
    
    AppetibilitySort(appetibilita, copy, index, j_size);

    int time = 0;
    size_t i = 0;
    int ris = 0;

    while (i < j_size){

        time += copy[i].duration;
        if (time <= copy[i].deadline) {
            printf("%zu ", index[i]);
            ris += copy[i].profit;
        }
        else {
            time -= copy[i].duration;
        }
        i++;
    }
    
    return ris;

}