#include<stdlib.h>
typedef struct {
    int duration;
    int profit;
    int deadline;
}job;
extern int ScheduleJobs(const job* jobs, size_t j_size);


int main(void) {

    job jobs[] = { {1,2,3}, {4,5,9}, {7,8,18} };

    ScheduleJobs(jobs, 3);
    return 0;
}