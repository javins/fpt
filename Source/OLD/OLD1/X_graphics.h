
#ifndef  X_graphics_a0b1c2d3
#define  X_graphics_a0b1c2d3

// Inspiration :
// Peter Meyers
// Eric Rorem
// Barry Schaudt
// Tony Leclerc
// Mark Vojkovich
// Jeff Ely

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/keysym.h> 
#include <X11/Xutil.h>// for XComposeStatus
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for drand48



int Init_X (int swidth, int sheight) ;

int Close_Down_X() ;

int Clear_Buffer_X() ; 

int Select_Gray_X (double color) ;




int Copy_Buffer_X() ;

int Flush_X() ;

int Copy_Buffer_And_Flush_X() ;

int Sync_X (int bool_val) ;







int Handle_Events_X (int *px, int *py) ;

int Get_Events_X (int *d) ;
// d needs to point to 2 or more ints
// merely repackages Handle_Events_X

int Get_Events_DX (double *d) ;
// d needs to point to 2 or more doubles
// merely repackages Handle_Events_X






int Set_Color_Rgb_X (int r, int g, int b) ;
// assumes r,g,b are ints in [0,255]

int Set_Color_Rgb_DX (double dr, double dg, double db) ;
// assumes r,g,b are doubles in [0, 1]

int Point_X (int x, int y) ; 

int Safe_Point_X (int x, int y) ;

int Line_X (int xs, int ys, int xe, int ye) ;

int Rectangle_X (int xlow, int ylow, int width, int height) ; 

int Fill_Rectangle_X (int xlow, int ylow, int width, int height) ;

int Triangle_X (int x1, int y1, 
                 int x2, int y2,
                 int x3, int y3) ;

int Fill_Triangle_X (int x1, int y1,
                      int x2, int y2,
                      int x3, int y3) ;

int Polygon_X (int *x, int *y, int npts) ;

int Polygon_DX (double *x, double *y, int npts) ;

int Fill_Polygon_X (int *x, int *y, int npts) ;

int Fill_Polygon_DX (double *x, double *y, int npts) ;

int Horizontal_Single_Pixel_Line_X (int x0, int x1, int y) ;

int Circle_X (int a, int b, int r) ;

int Fill_Circle_X (int a, int b, int r) ;

int Font_Pixel_Height_X () ;
// Returns the height of the font in pixels. 

int String_Pixel_Width_X (char *s) ;
// Returns the length, in pixels, of the string s 

int Draw_String_X (char *s, int x, int y) ;
// Draw the string s, with the lower left hand corner at (x,y)


int Get_Current_Dimensions_X (int dimensions[2]) ;

int Get_Current_Dimensions_DX (double dimensions[2]) ;

int Change_Pen_Dimensions_X (int w, int h) ;

int Draw_Text_X (
               int num_lines_of_text,
               char **lines_of_text,
               double startx, 
               double starty,
               double height,
               double x_over_y_ratio,
               double extra_space_between_letters_fraction,
               double extra_space_between_lines_fraction)  ;


int Save_Image_To_File_X (char *filename) ;

#endif

