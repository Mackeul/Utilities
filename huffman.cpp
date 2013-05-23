#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream infile;
  char myletter;
  struct inletter
  {
    char letter;
    int  frequency;
    inletter *next;
  };
  inletter *start;
  inletter *thisletter;

  if ( argc != 2 )
  {
    cout << "Error.  Invalid parameters specified." << endl;
    cout << "Usage:  " << argv[0] << ": <filename>" << endl;
  }
  else
  {
    infile.open(argv[1]);
    if (infile.is_open() )
    {
      start = new inletter; 
      start->next = 0;
      start->frequency = 0;

      while (infile.get(myletter))
      {
         thisletter = start;
         while (thisletter != NULL)
         {
           if (thisletter->letter == myletter)
           {
             ++thisletter->frequency;
             break;
           }
           else
           {
             if (thisletter->next == 0 )
             {
               if (thisletter->frequency != 0)
               {
                 thisletter->next = new inletter;

                 thisletter = thisletter->next;
                 thisletter->next = 0;
               }
               thisletter->letter = myletter;
               thisletter->frequency = 1;
             }
             thisletter = thisletter->next;
           }
         }
      }
      infile.close();
      thisletter = start;
      cout << "List of letters and the frequency of each in the file." << endl;
      while (thisletter != NULL)
      {
        if (static_cast <int> (thisletter->letter) == 10)
        {
          cout << "letter: \\n";
        }
        else
        {
          cout << "letter: " << thisletter->letter; 
        }
        cout << " frequency: " << thisletter->frequency << endl; 
        thisletter = thisletter->next;
      }
    }
    else
    {
      cout << argv[1] << ": No such file." << endl;
    }
  }    
} 
