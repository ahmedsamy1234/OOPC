
#include <iostream.h>
#include <string.h>
#include <stdlib.h>


//static char* company= "ahmed";
class Employee
{

private :
    static char* company;
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
        free(name);
    }
public :
    void setSalary(int salary)
    {
        this->salary = salary;
    };
public :
    static void setCompay(char* y )
    {
//  company= (char *)malloc(8*sizeof(char));// 1 mlahash lazma
        //  company= x;
        //company=y;
        strcpy(company,y);


        //      strcpy(this->name,name);
    };
public :
    static  char*  getCompany()
    {
        return company;

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

public :
    Employee operator++()
    {
        (this->id)++;
        this->salary++;

        return *this;
    };


    Employee operator++(int d)
    {
        Employee emp=*this;
        this->id++;
        this->salary++;
        return emp;
    };

    Employee operator+(Employee C)
    {
        Employee temp;
        temp.id=this->id +C.id;
        temp.salary=this->salary +C.salary;
        cout << "samy";
        return temp;
    }

    Employee operator+(int sal)
    {
        Employee temp;
        temp.id=this->id;
        temp.salary=this->salary +sal;

        return temp;
    }

    operator int()
    {
        return this->id;
    }

    operator char*()
    {
        return this->getName();
    }
    Employee operator+(char* str)
    {

        char* var = (char *)malloc(strlen(str)+1+strlen(this->getName()));// 1 mlahash lazma

        strcpy(var,str);
        strcat(var,this->getName());
        Employee temp;
        temp=this->id;
        temp=this->salary;
        temp.setName(var);
        free(var);

        return temp;
    }
    Employee& operator=(Employee emp)
    {
        id = emp.id;
        salary= emp.salary;
        setName(emp.getName());
        return *this;
    }
    int operator==(Employee emp)
    {
        return ((id==emp.id)&&(salary==emp.id)&&strcmp(this->getName(),emp.getName()));
    }
};



class Deparment
{
private:

    int numofHalls;
    int numberOFdevices;
    char* dateOfStart;
    Employee empCapacity[100];
    int currentNumOfEmployee;
    int numOfproject;

public :
    void initDefaultPar(int numOFEmplay)
    {
        currentNumOfEmployee=0;




        currentNumOfEmployee=numOFEmplay;
        Employee emp ;// default object
        numOfproject=numOFEmplay/2; //each 2 employee in 1 prokject
        numofHalls=numOFEmplay/3; //each 3 Emp in 1 hall;
        numberOFdevices=numOFEmplay;

        if (numOFEmplay>currentNumOfEmployee)
            for (int i=0; i<numOFEmplay; i++) //// if he enter employee with negtaive will create a one employee at least (min number of employee)
                empCapacity[i]=emp;
        else
            empCapacity[0]=emp;

    }
public :
    Deparment(int numOFEmplay)
    {
        initDefaultPar(numOFEmplay);

    };


public :
    void setNumofHalls(int numofHalls )
    {
        this->numofHalls=numofHalls;
    }
    // Getter

public :
    int getnumofHalls()
    {
        return this->numofHalls;

    };


public :
    void setnumberOFdevices(int numberOFdevices )
    {
        this->numberOFdevices=numberOFdevices;
    }
    // Getter
public :
    int getnumberOFdevices()
    {
        return this->numberOFdevices;

    };

public :
    void setnumOfproject(int numOfproject )
    {
        this->numOfproject=numOfproject;
    }
    // Getter
public :
    int getnumbernumOfproject()
    {
        return this->numOfproject;

    };
public :
    Employee getEmployee(int num)
    {


        if (num< currentNumOfEmployee)
            return empCapacity[num];
        else
            return -1;
    }
public:
    void addEployee(Employee emp)
    {
        empCapacity[currentNumOfEmployee]=emp;
    }

};
class NationalCompany
{
private :
    char* name;

private :
    char* loaction;

private :
    char* country ;

private :
    int numOfDepartment;
private :
    Deparment *Dept; // i assumed that the company has only 1 department , it's a startup :P :v

public :
    void initDefaultPar()
    {
        name=(char*)malloc(8*sizeof(char));
        loaction=(char*)malloc(8*sizeof(char));
        country=(char*)malloc(8*sizeof(char));
        strcpy(name,"Default");
        strcpy(loaction,"Alex");
        strcpy(country,"Egypt");
        Dept=NULL;

    }
    NationalCompany()
    {
        initDefaultPar();

    };

    NationalCompany(Deparment *dept)
    {
        initDefaultPar();
        this->Dept=dept;





    };

    void setDepartment(Deparment *p)
    {
        this->Dept=p;
    }

    Deparment* getDept ()

    {
        return Dept;
    }

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
    void setlocation(char* location )
    {
        this->loaction= (char *)realloc(this->loaction,strlen(location)+1);// 1 mlahash lazma


        strcpy(this->loaction,loaction);
    };
public :
    char* getlocation()
    {
        return this->loaction;

    };
public :
    void setCountry(char* country )
    {
        this->country= (char *)realloc(this->country,strlen(country)+1);// 1 mlahash lazma


        strcpy(this->country,country);
    };
public :
    char* getCountry()
    {
        return this->country;

    };

    NationalCompany& operator=(NationalCompany c)
    {
        Dept = c.Dept;

        setCountry(c.getCountry());
        setlocation(c.getlocation());
        setName(c.getName());
        return *this;
    }
    NationalCompany(NationalCompany &c)
    {
        Dept = c.Dept;
        setCountry(c.getCountry());
        setlocation(c.getlocation());
        setName(c.getName());
    }

    ~NationalCompany()
    {
        free(name);
        free(loaction);
        free(country);

    }
} ;

//int Deparment ::currentNumOfEmployee=0;
char* Employee::company="ibnelhaytham";// is totaly un safe // it stored  value in code segment not data , but setCompyname: changing the pointer to another pointer,, we can easily use  dynamic allocation " bs ana kslan "
char* ca="ahm";
//char* Employee::company=NULL;

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
Employee operator+ (int n, Employee emp)
{
    return (emp + n);

}
Employee operator+ (char* str, Employee emp)
{
    return (emp + str);

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
    Employee e1;
    int n;
    cout<< e1.getCompany()<< endl;
    Employee ar2[3];
    printEmply(ar2,3);
    cout << "enter num of employes"<< endl;
    cin >> n;
    Employee* dynamic_alo=new Employee[n];
    printEmply(dynamic_alo,n);

    NationalCompany comp;

    cout<<comp.getCountry();
    comp.setCountry("india");

    cout<<comp.getCountry();
    Deparment dep(4);
    Deparment *dep_DA= new Deparment(4);

    cout <<dep.getEmployee(1).getSalary();
    NationalCompany com(dep_DA);

    cout <<com.getDept()->getnumbernumOfproject();
    // cout<<dep.;

    return 0;
}
