/* File: mgrep.cpp
   Author: Michael Laporte
   Date: December 10, 2006
*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main ( int argc, char *argv[] )
{
  int numPatterns=0;
  int lineNum=1;
  string myLine;
  string aFlag;
  int num=0,i=0;
  string myPattern;

  if ( argc != 5)
  {
    cout<<"Usage: "<< argv[0] <<" <filename> <pattern> < -m <num>|-n <num> >"
        << endl;
    cout<<"Flags:"<<endl;
    cout<<setw(6)<<" "
        <<"-m <num>: Print line #'s that match <num> patterns"<<endl;
    cout<<setw(6)<<" "
        <<"-n <num>: Print line #'s that do NOT match <num> patterns" <<endl; 
  }
  else
  {
    myPattern=argv[2];
    aFlag=argv[3];
    num=atoi(argv[4]);
    
    // We assume argv[1] is a filename to open
    ifstream the_file ( argv[1] );
  
    if ( the_file.is_open() )
    {
      cout << "Reading file " << argv[1] << ", printing lines that have "
           << num << " instances of pattern: '"<< myPattern << "'"<<endl;

      while ( getline(the_file,myLine,'\n') ) 
      {
        numPatterns=0;
        for (i = myLine.find(myPattern,0); i != string::npos;
             i = myLine.find(myPattern,i))
        {
          numPatterns++;
          i++;
        }

        if (( aFlag == "-m") && ( numPatterns == num))
          cout << argv[1] <<":"<< lineNum << endl;

        if (( aFlag == "-n") && ( numPatterns != num ))
          cout << argv[1] <<":"<< lineNum << endl;

        ++lineNum;
      }
      the_file.close();
    }
    else 
      cout<<"Could not open file: "<<argv[1]<<endl;
  } // argc = 4
} //main
