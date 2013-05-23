#include <iostream>
#include <cstring>

using namespace std;

struct traincar
{
   char top[16];
   char lvl1[16];
   char lvl2[16];
   char wheels[16];
   char link[16];
   traincar *next;
};

int main()
{
  traincar *locomotive;
  traincar *thiscar;

  cout << "Creating locomotive..." << endl;

  locomotive = new traincar;
  locomotive->next = 0;
  strcpy(locomotive->top,"^^^^^^");
  strcpy(locomotive->lvl1,"| L  |");
  strcpy(locomotive->lvl2,"|    |");
  strcpy(locomotive->wheels,"-o--o-");
  strcpy(locomotive->link,"   |  ");

  thiscar = locomotive;

  cout << "Creating train..." << endl;
  for (int i=0; i < 10; ++i)
  {
    thiscar->next = new traincar;
    thiscar = thiscar->next;
    thiscar->next = 0;
    strcpy(thiscar->top,"------");
    strcpy(thiscar->lvl2,"|    |");
    strcpy(thiscar->wheels,"-o--o-");
    if ( i == 9 )
    {
      cout << "Creating pushcar..." << endl;
      strcpy(thiscar->lvl1,"| P  |");
      strcpy(thiscar->link,"      ");
    }
    else
    {
      strcpy(thiscar->lvl1,"| C  |");
      strcpy(thiscar->link,"  |   ");
    }
  }

  thiscar = locomotive;

  cout << "Rendering train ..." << endl;

  while (thiscar != NULL)
  {
    cout << thiscar->top << endl;
    cout << thiscar->lvl1 << endl;
    cout << thiscar->lvl2 << endl;
    cout << thiscar->wheels << endl;
    cout << thiscar->link << endl;
    thiscar = thiscar->next;
  }
  
}
