#include <iostream>
#include <velocity.h>

//using namespace std;

Velocity::Velocity(int a, int v, int t)
{
  acceleration = a;
  initialVelocity = v;
  time = t;
  velocity = 0; 
}

Velocity::~Velocity()
{
}

void Velocity::setAcceleration(int a)
{
  acceleration = a;
}

void Velocity::setInitialVelocity(int v)
{
  initialVelocity = v; 
}

void Velocity::setTime(int t)
{
  time = t;
}

int Velocity::compute()
{
  velocity = initialVelocity + acceleration * time;

  return velocity;
}
