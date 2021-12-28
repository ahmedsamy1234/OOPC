#include <iostream>

using namespace std;



class shape
{
protected :
    int dim1;
    int dim2;
public:
    shape()
    {
        dim1=dim2=0;
    }
    shape(int x)
    {
        dim1=dim2=x;
    }
        shape(int x,int y)
    {
        dim1=x;
        dim2=y;
    }
virtual float Area(){return 3;}
};


class circle : public shape
{
    public :
    circle(){};
    circle (int x):shape(x,x){};
    float Area()
    {
        return (1.0*3.14*dim1*dim2);
    }

};

class Rectangle :public shape
{public:
    Rectangle(){};
    Rectangle(int x,int y):shape(x,y){};
        float Area()
    {  // cout<<"hii";
        return (dim1*dim2);
    }
};


class Traingle :public shape
{  public :
    Traingle(){};
    Traingle(int x,int y):shape(x,y){};
        float Area()
    {
        return (0.5*dim1*dim2);
    }



};
class Square :public Rectangle
{  public :
    Square(){};
    Square(int x):Rectangle(x,x){};



};
class GeoShape
{
    shape** shapes;
    int mySize;
    public:
    GeoShape (shape** arr,int Size)
    { shapes= new shape*[4];
        for (int i=0;i<4;i++)
        {
            shapes[i]=arr[i];
        }
     mySize=Size;
    }
    float totalArea()
    {   float  sum=0;
                for (int i=0;i<4;i++)
        {

            sum+=shapes[i]->Area();
            //cout<<shapes[i]->Area();
        }
        return sum;
    }
};
int main()
{
    cout << "Hello world!" << endl;

    Rectangle r(20,5);
    circle c(7);
    Traingle t(20,10);
    Square s(5);
    shape* Shape[] ={&r,&c,&t,&s};

    GeoShape geo(Shape,4);

    cout << geo.totalArea()<<endl;
        return 0;
}



 //cir 7;
 // rect 20 5
 //traig 20 10
 //square 4



