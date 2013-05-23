#include <iostream>

using namespace std;

class Computer
{
  public:
    Computer();  //Contructor
    ~Computer();  //Destructor

    void setSpeed(int p);
    int readSpeed();

  protected:
    int processorSpeed;
};

Computer::Computer()
{
  processorSpeed = 0;
}

Computer::~Computer()
{

}

void Computer::setSpeed(int p)
{
  processorSpeed = p;
}

int Computer::readSpeed()
{
  return processorSpeed;
}

int main()
{
  Computer compute;

  compute.setSpeed(100);
  cout <<  "\n";
  cout << compute.readSpeed();
  cout <<  "\n";
}
