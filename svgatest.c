
#include <stdio.h>
#include <vga.h>
#include <vgagl.h>

int main()
{
  GraphicsContext physicalscreen;

/* Initialize */
  if (vga_init()!=0) {
   printf("Error initialising svgalib!\n");
   exit(1);
   }
  if (vga_setmode(G320x200x256)!=0) {
   printf("Can't set mode 320x200x256!\n");
   exit(1);
   }
  if (gl_setcontextvga(G320x200x256)!=0) {
   printf("Error setting context!\n");
   exit(1);
   }
  gl_getcontext(&physicalscreen);
  if (gl_setcontextvgavirtual(G320x200x256)!=0) {
   printf("Error setting virtual context!\n");
   exit(1);
   }

   gl_setpalettecolor(0,0,0,0);
   gl_setpalettecolor(1,63,0,0);
   gl_setpalettecolor(2,0,63,0);
   gl_setpalettecolor(3,0,0,63);
   gl_setpalettecolor(4,63,63,63);

/* Use */
   gl_clearscreen(0);
   gl_setpixel(20,20,1);
   gl_fillbox(50,50,100,100,3);
   gl_line(30,20,300,180,3);
   gl_fillbox(100,80,100,100,4);
   vga_waitretrace();
   gl_copyscreen(&physicalscreen);
   getchar();

/* Restore */
   vga_setmode(TEXT);
   return(0);
}
