#include <iostream>
#include <string.h>

using namespace std;


class Person
{
protected:
    int id;
    char name[20];

public :


    Person (int id,char name[])
    {
        this->id=id;
        strcpy(this->name,name);
        //  this->name=name;
    }
    void printFun()
    {
        cout<<"ID :  "<< id  << endl ;
        cout << "Name : " << name <<endl;
    }

};

class Customer : public Person
{
    int contact;

public :
    Customer(int k,char* l,int m) : Person(k,l)
    {
        contact=m;
    };

    void printFun()
    {
        cout<<"ID :  "<< id  << endl ;
        cout << "Name : " << name <<endl;
        cout << "Contact " << contact << endl ;

    };
}

class Employee : public Person
{
    int salary;


public :

        Employee(int k,char* l,int m) : Person(k,l)
    {
        salary=m;
    };

    void printFun()
    {
        cout<<"ID :  "<< id  << endl ;
        cout << "Name : " << name <<endl;
        cout << "employee salary " << salary << endl ;
    }


};



int main()
{
    Person p(60,"ahmed");

    cout << "Hello world!" << endl;
    return 0;
}
