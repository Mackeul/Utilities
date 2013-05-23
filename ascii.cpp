#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  for ( int x = 0; x < 256; x++ ) {
    cout<< setw(5) << x <<"."<< static_cast <char>(x); 
    if ( x%10 == 0 && x != 0)
      cout << endl;
    //Note the use of the int version of x to 
    // output a number and the use of (char) to 
    // typecast the x into a character 	
    // which outputs the ASCII character that 
    // corresponds to the current number
  }
  cin.get();
}
