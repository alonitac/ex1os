#include <sys/time.h>
#include "osm.h"
#include <math.h>

/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations) {
    if (iterations == 0){
        return -1;
    }
    int x=1, y=1, z=1, w=1, k=1, p=1, q=1, e=1, r=1, t=1;
    double tot_time = 0;
    timeval tv;
    for (unsigned int i = 0; i < iterations; i += 1)
    {
        gettimeofday(&tv, nullptr);
        time_t start_tv_sec = tv.tv_sec;
        suseconds_t start_tv_usec = tv.tv_usec;

        x + 1;
        y + 1;
        z + 1;
        w + 1;
        k + 1;
        p + 1;
        q + 1;
        e + 1;
        r + 1;
        t + 1;

        gettimeofday(&tv, nullptr);
        tot_time += tv.tv_sec - start_tv_sec + (tv.tv_usec - start_tv_usec) / 1000000.0;
    }
    return (tot_time / (iterations * 10)) * pow(10, 9);
}

void empty_func1(){}
void empty_func2(){}
void empty_func3(){}
void empty_func4(){}
void empty_func5(){}
void empty_func6(){}
void empty_func7(){}
void empty_func8(){}
void empty_func9(){}
void empty_func10(){}


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations) {
    if (iterations == 0){
        return -1;
    }
    double tot_time = 0;
    timeval tv;
    for (unsigned int i = 0; i < iterations; i += 1)
    {
        gettimeofday(&tv, nullptr);
        time_t start_tv_sec = tv.tv_sec;
        suseconds_t start_tv_usec = tv.tv_usec;

        empty_func1();
        empty_func2();
        empty_func3();
        empty_func4();
        empty_func5();
        empty_func6();
        empty_func7();
        empty_func8();
        empty_func9();
        empty_func10();

        gettimeofday(&tv, nullptr);
        tot_time += tv.tv_sec - start_tv_sec + (tv.tv_usec - start_tv_usec) / 1000000.0;
    }
    return (tot_time / (iterations * 10)) * pow(10, 9);
}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations) {
    if (iterations == 0){
        return -1;
    }
    double tot_time = 0;
    timeval tv;

    for (unsigned int i = 0; i < iterations; i += 1)
    {
        gettimeofday(&tv, nullptr);
        time_t start_tv_sec = tv.tv_sec;
        suseconds_t start_tv_usec = tv.tv_usec;

        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;

        gettimeofday(&tv, nullptr);
        tot_time += tv.tv_sec - start_tv_sec + (tv.tv_usec - start_tv_usec) / 1000000.0;
    }

    return (tot_time / (iterations * 10)) * pow(10, 9);
}

