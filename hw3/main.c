#include <stdio.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

struct{
    double x,y,z,acceleration,pitch,roll,yaw;
    struct timespec dataTime;
} pos={0,0,0,0,0,0,0};

static pthread_mutex_t posMutex;

void *secondThread(void *);

int main(){
    pthread_t newTid = 0;
    int errorCode;

    if ((errorCode = pthread_mutex_init(&posMutex, NULL)) != 0){
        printf("\n  Bad pthread_mutex_init: %s", strerror(errorCode));
        return -1;
    }
}

void *secondThread(void *pVoid){
    int errorCode;

    while ()
}