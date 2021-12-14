#include <iostream.h>
#include <string.h>
#include <stdlib.h>



class Employee
{
private :
    int id ;
private :
    char name[10];
private :
    int salary;

    public :void setSalary(int salary)
    {
        this->salary = salary;
    };
    // Getter
    public :int getSalary()
    {
        return salary;

    };

   public : void setName(char name[10])
    {
        strcpy(this->name,name);
    };
    // Getter
   public : char* getName()
    {
        return this->name;

    };

   public : void setID(int id )
    {
        this->id=id;
    }
    // Getter
   public : int getId()
    {
        return this->id;

    };


};

void printEmply( Employee* emp,int sizeofArray)
{

    for (int i=0; i<sizeofArray; i++)

    {
        cout<<"--------------------------------"<<endl;
        cout <<"employee id :" <<emp[i].getId()<<endl;
        cout <<"employee name:"<<emp[i].getName()<<endl;
        cout <<"employe sal :"<< emp[i].getSalary()<<endl;


        cout << "thank you"<< endl;
    }
}

void fillEmply(struct Employee* emp,int sizeofArray)

{
    for (int i=0; i<sizeofArray; i++)

    {   int id,sal;
        char name[10];
        cout << "enter Employee id of  Num "<< i<<endl;
        cin >>id;
        emp[i].setID(id);
        cout << "enter Employee name " << i<<endl;
        cin >>name;
        emp[i].setName(name);

        cout << "enter Employee Num " << i <<endl;
        cin >>sal;
        emp[i].setSalary(sal);


        cout << "thank you"<< endl;
    }
	system("cls");

}
void swaping(int &x, int &y) {
   int temp;
   temp = x;
   x = y;
   y = temp;

   return;
}
    int main()
    {

         cout << "enter size of array" <<endl;
    int x;
    cin>>x;

    Employee* emp ;
    emp = new Employee[x];
    fillEmply(emp,x);
    printEmply(emp,x);
    int a,b;
    cout << "enter Num1 :" ;
    cin >>a;
        cout << "enter Num2 :" ;
    cin >>b;

    swaping(a,b);

    cout << a <<endl;
    cout << b << endl;

        cout << "Hello world!" << endl;
        return 0;
    }
