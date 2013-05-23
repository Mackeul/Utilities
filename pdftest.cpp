#include <fstream>
#include <iostream>

#define UNDERLINE_ON "&d0"
#define UNDERLINE_OFF "&d@"

using namespace std;

char * verify_code( char *);

int main ( int argc, char *argv[] )
{
  char x;
  char *buffer;
  char *code;
  int buffering;

  if ( argc != 2 ) // argc should be 2 for correct execution
    // We print argv[0] assuming it is the program name
    cout<<"usage: "<< argv[0] <<" <filename>\n";
  else 
  {
    // We assume argv[1] is a filename to open
    ifstream the_file ( argv[1] );
    // Always check to see if file opening succeeded
    if ( !the_file.is_open() )
      cout<<"Could not open file\n";
    else
    {
      // the_file.get ( x ) returns false if the end of the file
      //  is reached or an error occurs
      while ( the_file.get ( x ) )
      {
        if ( x == "" )
        {
           code[0] = '\0';
           /* start the buffer to store values until we find a match */
           while (the_file.get( buffer ) && code[0] != '\0' )
             code = verify_code(buffer); 
            
           cout << code;
         }
        cout<< x;
      }
    // the_file is closed implicitly here
    }
  }
}

char * verify_code(char *code)
{
  char *retString;

  if ( strcmp(code,UNDERLINE_ON) == 0 )
  {
     retString = "<underline>";
  } 
  else if (strcmp(code,UNDERLINE_OFF) == 0 )
  {
     retString = "</underline>";
  }

  return retString;

}
