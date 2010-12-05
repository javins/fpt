
#include <FPT.h>   

int main()
{
   int swidth, sheight ;
   int lowleftx, lowlefty, width, height ;
   int x[10],y[10] ;
   int numpoints,q, x0,y0,x1,y1 ;
   int p[2] ;

   // must do this before you do 'almost' any other
   // graphical tasks 
   swidth = 400 ;  sheight = 400 ;
   G_init_graphics (swidth, sheight) ;


   // draw a point, a line, some rectangles, some triangles 

   G_rgb(1, 0, 0) ;  // red 
   G_point(200, 380) ;

   G_rgb(0, 1, 0) ;  // green
   //   G_line (0, 0, 400, 400) ; // won't show if part is off screen
   G_line (0, 0, 399, 399) ;
  
   G_rgb(0, 0, 1) ;  // blue 
   lowleftx = 200 ; lowlefty = 50 ; width = 10 ; height = 30 ;
   G_rectangle (lowleftx, lowlefty, width, height) ;
   lowleftx = 250 ; 
   G_fill_rectangle (lowleftx, lowlefty, width, height) ;

   G_rgb(1, 0, 1) ;  // purple
   G_triangle (10, 300,  40,300,  60,250) ;
   G_fill_triangle (10,100,  40,100,  60,150) ;

   G_rgb(1, 0.5, 0) ;  // orange
   G_circle (100, 300, 75) ;
   G_fill_circle (370, 200, 50) ;

   // prints text in your graphics window 
   G_rgb(0, 0, 0) ;  // black
   G_draw_string ((void *) "hello",300,100) ;

   // draw a polygon 
   x[0] = 100 ;   y[0] = 100 ;
   x[1] = 100 ;   y[1] = 300 ;
   x[2] = 300 ;   y[2] = 300 ;
   x[3] = 300 ;   y[3] = 100 ;
   x[4] = 200 ;   y[4] = 175 ;
   numpoints = 5 ;
   Gi_polygon (x,y,numpoints) ;


   q = G_wait_key() ; // pause to look ...any key to continue


   G_rgb (0.4, 0.2, 0.1) ; // brown
   Gi_fill_polygon (x,y,numpoints) ;

   G_rgb (0.5, 0.8, 0.4) ;// what color is this?

   Gi_wait_click(p) ;   // wait for a mouse click
   x0 = p[0] ; y0 = p[1] ; // extract coordinates 
   G_fill_rectangle (x0-2, y0-2, 4,4) ;// mark the clicked point


   Gi_wait_click(p) ;  
   x1 = p[0] ; y1 = p[1] ;
   G_fill_rectangle (x1-2, y1-2, 4,4) ;


   G_rgb (0.5, 0.5, 0.5) ; // a grey
   G_line (x0,y0, x1,y1) ;

   q = G_wait_key() ;    // pause again before exit 

   G_save_image_to_file ((void*) "t01a.xwd") ;

   G_close() ; // terminate graphics...probably not fatal if forgotten

}



