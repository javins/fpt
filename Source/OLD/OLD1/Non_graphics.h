

#ifndef NG_aabbxyz_9875678__2
#define NG_aabbxyz_9875678__2


#include <stdio.h>
#include <math.h>
#include <stdlib.h> // drand48, atoi
#include <unistd.h> // usleep
#include <time.h> // for the get_time stuff
#include <sys/time.h> 



int check_input_error_flag () ;

int inI () ;
// input an integer
// its value is returned


void outI (int x) ;
// output an integer


double inD () ;
// input a double
// its value is returned


void outD (double x) ;
// output a double...switches to scientific notation
// for the extremely small and the extremely large



void inS (void *p) ;
// the wisdom of the void * 
// allows for the input to go into
// a packed arrary of doubles (for instance)

void outS (void *p) ;
// the wisdom of the void * 
// allows for the output to come from
// a packed arrary of doubles (for instance)



void pack (void *p) ;
// pack a null-terminated array of doubles
// into an array of characters
// using the same array space.
// clearly there is sufficient array space
// to do this. ... the null terminator is
// also packed



void unpack (void *p) ;
// unpack a null-terminated array of characters
// into an array of doubles
// using the same array space.
// clearly, the array space NEEDS to be sufficient
// to do this. ... the null terminator is also
// unpacked




int get_timeI (int *hms) ;
// hms had better be at least 3 ints long
// returns 1 for success, 0 for failure
// which is the opposite of what the standard
// gettimeofday returns


int get_timeD (double *hms) ;
// hms had better be at least 3 doubles long
// returns 1 for success, 0 for failure
// which is the opposite of what the standard
// gettimeofday returns



#endif
