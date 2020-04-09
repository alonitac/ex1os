#include <sys/time.h>
#include 'osm.h'

/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations) {
    int x=1, y=2, z=3, w=4, k=5, p=6, q=7, e=8, r=9, t=10;
    int tot_time = 0;
    struct timeval {
        time_t      tv_sec;     /* seconds */
        suseconds_t tv_usec;    /* microseconds */
    };

    for (int i = 0; i < iterations; i += 1)
    {
        gettimeofday(timeval);
        time_t start_tv_sec = timeval.tv_sec;
        suseconds_t start_tv_usec = timeval.tv_usec;

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

        gettimeofday(timeval);
        tot_time += timeval.tv_sec - start_tv_sec + (start_tv_usec - timeval.tv_usec) / 1000000.0;
    }
    return tot_time;
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
    int tot_time = 0;
    struct timeval {
        time_t      tv_sec;     /* seconds */
        suseconds_t tv_usec;    /* microseconds */
    };
    for (int i = 0; i < iterations; i += 1)
    {
        gettimeofday(timeval);
        time_t start_tv_sec = timeval.tv_sec;
        suseconds_t start_tv_usec = timeval.tv_usec;

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

        gettimeofday(timeval);
        tot_time += timeval.tv_sec - start_tv_sec + (start_tv_usec - timeval.tv_usec) / 1000000.0;
    }
    return tot_time;
}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations) {
    int tot_time = 0;
    struct timeval {
        time_t      tv_sec;     /* seconds */
        suseconds_t tv_usec;    /* microseconds */
    };

    for (int i = 0; i < iterations; i += 1)
    {
        gettimeofday(timeval);
        time_t start_tv_sec = timeval.tv_sec;
        suseconds_t start_tv_usec = timeval.tv_usec;

        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();
        OSM_NULLSYSCALL();

        gettimeofday(timeval);
        tot_time += timeval.tv_sec - start_tv_sec + (start_tv_usec - timeval.tv_usec) / 1000000.0;
    }
}

