
class Velocity
{
  public:
    Velocity(int a, int v, int t);
    ~Velocity();

   void setAcceleration(int a);
   void setInitialVelocity(int v);
   void setTime(int t);
   int compute();

  private:

  protected:
    int acceleration;
    int initialVelocity;
    int time;
    int velocity;
};
