#include <iostream>
#include "velocity.h"

using namespace std;

int main()
{
  Velocity mySpeed(10,2,10);

  cout << "Current veloctiy:" << mySpeed.compute() << endl;

}
