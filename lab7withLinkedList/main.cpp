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


struct Node
{
    shape* myshape ;
     Node* pnext;
     Node* pprev;

};


struct linkedlist
{
     Node* phead;
     Node* ptail;
};
struct linkedlist *createLinklist(void)
    {
         linkedlist* mainList=( linkedlist*) malloc(sizeof(struct linkedlist));
        //     mainList->phead = (struct Node*) malloc(sizeof(struct Node));
        //   mainList->ptail = (struct Node*) malloc(sizeof(struct Node));
        mainList->phead=NULL;
        mainList->ptail=NULL;
        return mainList;

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
    linkedlist* mylist;
    int mySize;
    public:
    GeoShape (linkedlist* mylist)
    { this->mylist=mylist;
       // cout << mylist->phead->myshape->Area();
    }
    float totalArea()
  {

float sum=0;
        struct Node *pcur;
        pcur=mylist->phead;
        for(pcur; (pcur); pcur=pcur->pnext)
        {
        sum+=  (pcur->myshape->Area());//bad implementation , this violate encapsulation!!!  ,, we should pass a function get area(shape *) to fun traverse area bs mksl bsa7a
        }
        return sum;
    }
};



 Node* createNode(shape* e)
{
     Node* ptr;
    ptr = (Node*) malloc(sizeof(Node));
    if (ptr)
    {
        ptr->myshape=e;
        ptr->pnext=NULL;
        ptr->pprev=NULL;

    }

    return ptr;
};
int AddNode(struct linkedlist* list,shape* e)
{
    int reval=0;
    struct Node *ptr;
    ptr= createNode(e);

    if (ptr)
    {
        if(!list->phead)
        {

            list->phead=ptr;
            list->ptail=ptr;
        }
        else
        {

            list->ptail->pnext=ptr;
            ptr->pprev=list->ptail;
            list->ptail=ptr;

        }
        reval=1;

    }

    return reval;
}
    float TraverseNode(struct linkedlist* list,float (*func))
    {   float sum=0;
        struct Node *pcur;
        pcur=list->phead;
        for(pcur; (pcur); pcur=pcur->pnext)
        {
      //  sum+=    (*pf)(pcur->myshape);
        }
        return sum;
    }


int main()
{
    cout << "Hello world!" << endl;

    Rectangle r(20,5);
    circle c(7);
    Traingle t(20,10);
    Square s(5);
    shape* Shape[] ={&r,&c,&t,&s};
    linkedlist* ownList=createLinklist();
    AddNode(ownList,&r);
    AddNode(ownList,&c);
    AddNode(ownList,&t);
    AddNode(ownList,&s);
    GeoShape geo(ownList);

    cout << geo.totalArea()<<endl;
        return 0;
}



 //cir 7;
 // rect 20 5
 //traig 20 10
 //square 4



