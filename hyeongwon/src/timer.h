#include <stdlib.h>
#include <stdint.h>

#ifdef __MACH__
#include <mach/mach_time.h>
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 0
int clock_gettime(int, struct timespec* t) {
    mach_timebase_info_data_t timebase;
    mach_timebase_info(&timebase);
    uint64_t time;
    time = mach_absolute_time();
    double nsec = ((double)time * (double)timebase.numer)/((double)timebase.denom);
    double sec = ((double)timebase.numer)/((double)timebase.denom * 1e9);
    t->tv_sec = sec;
    t->tv_nsec = nsec;
    return 0;
}
#else
#include <time.h>
#endif

#define BILLION 1000000000L
#define MILLION 1000000L

struct timer {
	struct timespec start;
	struct timespec end;
	uint64_t diff;
};

struct timer* CreateTimer()
{
	struct timer* ptr = (struct timer*)malloc(sizeof(struct timer));
	return ptr;
}

void CheckTime(struct timespec* ts)
{
	clock_gettime(CLOCK_MONOTONIC, ts);
}

uint64_t GetDiff(struct timer* t)
{
	t->diff = BILLION * (t->end.tv_sec - t->start.tv_sec) + (t->end.tv_nsec - t->start.tv_nsec);
	return t->diff;
}

void PrintTimer(struct timer* t)
{
	uint64_t sec = t->diff/BILLION;
	uint64_t usec = (t->diff - sec * BILLION)/MILLION;
	uint64_t msec = (t->diff - sec * BILLION - usec * MILLION)/1000;
	uint64_t nsec = (t->diff - sec * BILLION - usec * MILLION - msec * 1000);

    printf("Elapsed Time : ");
	printf("%llus %llums %lluus %lluns\n",
			(long long unsigned int)sec,
			(long long unsigned int)msec,
			(long long unsigned int)usec,
			(long long unsigned int)nsec);
}
