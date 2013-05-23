 #include <stdio.h>
#include <ggi/ggi.h>

int main()
{
/* Initialize */
  ggi_visual_t vis;
  ggi_color palette[5];
  int myGgiVal;

  if (ggiInit()!=0) {
//   myGgiVal=ggiInit();
   printf("Error initialising GGI %d!\n",myGgiVal);
   exit(1);
   }
  if ((vis=ggiOpen(NULL))==NULL) {
   printf("Error opening visual!\n");
   ggiExit();
   exit(1);
   }
  if (ggiSetGraphMode(vis,320,200,320,200,GT_8BIT)) {
   printf("Set the GGI_DISPLAY variable to the palemu!\n");
   exit(1);
   }

  palette[0].r=0;
  palette[0].g=0;
  palette[0].b=0;
  palette[1].r=0xffff;
  palette[1].g=0;
  palette[1].b=0;
  palette[2].r=0;
  palette[2].g=0xffff;
  palette[2].b=0;
  palette[3].r=0;
  palette[3].g=0;
  palette[3].b=0xffff;
  palette[4].r=0xffff;
  palette[4].g=0xffff;
  palette[4].b=0xffff;

  ggiSetPalette(vis,0,5,palette);

/* Use */
  ggiSetGCForeground(vis,0);
  ggiFillscreen(vis);
  ggiSetGCForeground(vis,1);
  ggiDrawPixel(vis,20,20);
  ggiSetGCForeground(vis,2);
  ggiDrawBox(vis,50,50,100,100);
  ggiSetGCForeground(vis,3);
  ggiDrawLine(vis,30,20,300,180);
  ggiSetGCForeground(vis,4);
  ggiDrawBox(vis,100,80,100,100);

  ggiFlush(vis);
  ggiGetc(vis);

/* Quit */
  ggiClose(vis);
  ggiExit();
  return(0);
}
