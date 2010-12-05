
#include <Non_graphics.h>


static int input_error ;


int check_input_error_flag ()
{
  return input_error ;
}



int inI ()
// input an integer
// its value is returned
{
  int i ;
  int x ;

  i = scanf("%d",&x) ;
  if (i == 1) {
     input_error = 0 ;
  } else {
     input_error = 1 ;
     printf("\nInput is not recognized as an int, 0 returned.\n") ;
     x = 0 ;
  } 

  return x ;
}



void outI (int x)
// output an integer
{
  printf("%d",x) ;
}




double inD ()
// input a double
// its value is returned
{
  int i ;
  double x ;

  i = scanf("%lf",&x) ;
  if (i == 1) {
     input_error = 0 ;
  } else {
     input_error = 1 ;
     printf("\nInput is not recognized as a double, 0 returned.\n") ;
     x = 0 ;
  } 

  return x ;
}



void outD (double x)
// output a double...switches to scientific notation
// for the extremely small and the extremely large
{

  if (x == 0.0) {
     printf("%.10lf",x) ;
  }
  else if (fabs(x) < 1e-10) {
     printf("%.10e",x) ;
  } else if (fabs(x) > 1e10) {
     printf("%.10e",x) ;
  } else {
     printf("%.10lf",x) ;
  }

}




void inS (void *p)
// the wisdom of the void * 
// allows for the input to go into
// a packed arrary of doubles (for instance)
{
  char *cp ;

  cp = (char *) p ;  
  scanf("%s",cp) ;
  input_error = 0 ;
}




void outS (void *p)
// the wisdom of the void * 
// allows for the output to come from
// a packed arrary of doubles (for instance)
{
  char *cp ;
  
  cp = (char *) p ;
  printf("%s",cp) ;

}





void pack (void *destination, void *source)
// pack a null-terminated array of double-characters
// into an array of single-byte-characters
// The null terminator is also packed
// destination and source can point to the same
// actual space.
{
  char *cp ;
  double *dp ;
  int i ; 
  double d ;
  char a;

  dp = (double *) source ;
  cp = (char *) destination ;

  i = -1 ;
  do {
   i++ ;

   d = floor(dp[i] + 0.5) ;

   if (d < 0) a = 0 ;
   else if (d > 255) a = 255 ;
   else a = (char)d ;
  
   cp[i] = a ;

  } while (a != 0) ;
  
  // this also copies over the null terminator
  // as it should
}







void unpack (void *destination, void *source)
// unpack a null-terminated array of single-byte
// characters into an array of  double-characters.
// the null terminator is also unpacked.
// destination and source can point to the same
// actual space provided it is of sufficient size
// to hold the unpacked data.
{
  char *cp ;
  double *dp ;
  int i ;

  cp = (char *) source ;
  dp = (double *) destination ;

  i = 0 ; 
  while (cp[i] != 0) {
    // printf("i = %d  cp[i] = %c\n",i,cp[i]) ;
    i++ ;
  }

  cp += i ;
  dp += i ;
  
  while (i >= 0) {
    *dp = (double)(*cp) ;
    dp-- ;
    cp-- ;
    i-- ;
  }

  // this also copies over the null terminator
  // as it should
}









int get_timeI (int *hms)
// hms had better be at least 3 ints long
// returns 1 for success, 0 for failure
// which is the opposite of what the standard
// gettimeofday returns
{
 int failure ;
 struct timeval Tp, *tp ;
 struct timezone Tzp, *tzp ;
 time_t  numseconds, *clock ;
 struct tm *x ;

 tp = &Tp ;
 tzp = &Tzp ;
 failure = gettimeofday(tp,tzp) ; // 1 for fail, 0 for success
 numseconds = tp-> tv_sec ;
 clock = &numseconds ;

 x =  localtime(clock) ; 

 hms[0] =     x->tm_hour ;
 hms[1] =     x->tm_min ;
 hms[2] =     x->tm_sec ;

 return (1 - failure) ;

}




int get_timeD (double *hms)
// hms had better be at least 3 doubles long
// returns 1 for success, 0 for failure
// which is the opposite of what the standard
// gettimeofday returns
{
 int ihms[3] ;
 int s ;

 s = get_timeI (ihms) ;

 hms[0] = ihms[0] ;
 hms[1] = ihms[1] ;
 hms[2] = ihms[2] ;

 return s ;
}


