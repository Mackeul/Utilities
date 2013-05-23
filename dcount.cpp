#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main ( int argc, char *argv[] )
{
  int delims=0;
  int lineNum=1;
  char x;
  char *flag;
  int num=0;
  char *delim;

  if ( argc != 5)
  {
    cout<<"Usage: "<< argv[0] <<" <filename> <delimiter> < -m <num>|-n <num> >"
        << endl;
    cout<<"Flags:"<<endl;
    cout<<setw(6)<<" "
        <<"-m <num>: Print line #'s that match <num> delimiters"<<endl;
    cout<<setw(6)<<" "
        <<"-e <num>: Print line #'s that do NOT match <num> delimiters" <<endl; 
  }
  else
  {
    delim=argv[2];
    flag=argv[3];
    num=atoi(argv[4]);
    
    // We assume argv[1] is a filename to open
    ifstream the_file ( argv[1] );
  
    if ( !the_file.is_open() )
      cout<<"Could not open file"<<argv[1]<<endl;
    else 
    {
      cout << "Reading file " << argv[1] << ", printing lines that have "
           << argv[4] << " delimiters: "<< delim << endl;

      while ( the_file.get ( x ) )
      {
        if ( static_cast <int>(x) == 10 ) // newline -- ascii 10
        {
            if (strcmp(flag,"-m") == 0)
            {
              if ( delims == num)
                cout << "Line #:" << lineNum << endl;
            }
            if (strcmp(flag,"-n") == 0)
            {
              if ( delims != num )
                cout << "Line #:" << lineNum << endl;
            }
          ++lineNum;
          delims=0;
        } // checking for new line.
        if ( x == *delim)
        {
          ++delims;
        }
      } // while loop
    } // file is open 
  } // argc = 4
} //main
