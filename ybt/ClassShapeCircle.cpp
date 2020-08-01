#include <iostream>
using namespace std;

class shape
{
  protected:
    double x;
    double y;
  public:
    virtual double Area() = 0;
    virtual double circumfrenece() = 0;
    virtual double point() = 0;
    
    void setx(double x)
    {
      this->x=x;
    }
    void sety(double y)
    {
      this->y=y;
    }
    ~shape()
    {
      cout<<"shape is delete"<<endl;
    }

};
class circle:public shape
{
  private:
    double r;
  public:
    circle(double x,double y,double r)
    {
      this->r=r;
      setx(x);
      sety(y);
    }
    virtual double Area()
    {
      return 3.14*r*r; 
    }
    virtual double circumfrenece()
    {
      return 2.0*3.14*r;
    }
    virtual double point()
    {
      cout<<"( x == "<<x<<" , y == "<<y<<" )"<<endl;
    } 
    ~circle()
    {
      cout<<"circle is delete!"<<endl;
    }
};

int main()
{
  circle yuan1(1.0,1.0,1.0); 
  shape *p,&q=yuan1;
  circle yuan2(3.0,2.0,5.0);
  p=&yuan2;
  cout<<"yuan1: q.point() == "<<q.point()<<endl;
  cout<<"yuan1: q.circumfrenece() == "<<q.circumfrenece()<<endl;
  cout<<"yuan1: q.Area() == "<<q.Area()<<endl;
  cout<<"yuan2: p->point() == "<<p->point()<<endl;
  cout<<"yuan2: p->circumfrenece() == "<<p->circumfrenece()<<endl;
  cout<<"yuan2: p->Area() == "<<p->Area()<<endl;
}