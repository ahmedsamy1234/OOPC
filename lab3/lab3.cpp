#include <iostream.h>
#include <string.h>
#include <stdlib.h>



class Employee
{
private :
    int id ;
private :
    char *name;
private :
    int salary;
    void initDefaultPar()
    {
        this->id=10;
        this->salary=60;
        initString();
        strcpy(name,"Default");

    }



public :

    Employee()
    {
        initDefaultPar();

    };

    Employee(int id )
    {
        initDefaultPar();
        this->id=id;

    };

    Employee(int id, int salary)
    {
        initDefaultPar();
        this->id=id;
        this->salary=salary;



    };

    Employee(int id, int salary,char* s)
    {
        initDefaultPar();
        this->id=id;
        this->salary=salary;
        name= (char *)realloc(name,strlen(s)+1);// 1 mlahash lazma

        strcpy(this->name,s);



    };


    Employee(Employee &rst)
    {
        id = rst.id;
        salary = rst.salary;
        initString();
        name= (char *)realloc(name,strlen(rst.name)+1);// 1 mlahash lazma

        strcpy(this->name,rst.name);//can we use prev dynamic allocation but we will remove delete from destractor

    }
    ~Employee()
    {
        delete name;
    }
public :
    void setSalary(int salary)
    {
        this->salary = salary;
    };


    void  initString()
    {
        this->name=(char*)malloc(6*sizeof(char));


    }
    // Getter
public :
    int getSalary()
    {
        return salary;

    };

public :
    void setName(char* name )
    {
        this->name= (char *)realloc(this->name,strlen(name)+1);// 1 mlahash lazma


        strcpy(this->name,name);
    };
public :
    char* getName()
    {
        return this->name;

    };

public :
    void setID(int id )
    {
        this->id=id;
    }
    // Getter
public :
    int getId()
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

    {
        int id,sal;
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

Employee ReturnClass()
{
    Employee e(50,60,"ahmed.");

    return e;
}
void swaping(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

    return;
}
int main()
{

// Employee e(1,4,"ahmed");




    cout<< "Default one" <<endl;
    Employee e1;
    printEmply(&e1,1);

    cout<< "Default with 1par" <<endl;
    Employee e2(100);
    printEmply(&e2,1);

    cout<< "Default with 2par" <<endl;
    Employee e3(1005,9000);
    printEmply(&e3,1);

    cout<< "Default with 3par" <<endl;
    Employee e4(100,9000,"ahmed");
    printEmply(&e4,1);

    cout<< "Return function" <<endl;

    printEmply(&ReturnClass(),1);






    cout << "Hello world!" << endl;
    return 0;
}
