#include <iostream.h>
#include <stdlib.h> /*for system()*/

int val=8;
struct Employee
{
    int id ;
    char name[10];
    int salary;
};

void fillEmply(struct Employee* emp,int sizeofArray)

{
    for (int i=0; i<sizeofArray; i++)

    {
        cout << "enter Employee id of  Num "<< i<<endl;
        cin >>emp[i].id;
        cout << "enter Employee name " << i<<endl;
        cin >>emp[i].name;
        cout << "enter Employee Num " << i <<endl;
        cin >>emp[i].salary;
        cout << "thank you"<< endl;
    }
	system("cls");
	
}


void printEmply(struct Employee* emp,int sizeofArray)
{

    for (int i=0; i<sizeofArray; i++)

    {
        cout<<"--------------------------------"<<endl;
        cout <<"employee id :" <<emp[i].id<<endl;
        cout <<"employee name:"<<emp[i].name<<endl;
        cout <<"employe id :"<< emp[i].salary<<endl;


        cout << "thank you"<< endl;
    }
}

void displayNum(int x = 3, int y = 4)
{
    cout<<"-------  Default Argu----"<< endl;
    cout<<"x:" <<x;
    cout<<"     y:"<<y<< endl;
}

int main()
{
    cout << "enter size of array" <<endl;
    int x;
    cin>>x;

    struct Employee* emp ;
    emp = new Employee[x];
    fillEmply(emp,x);
    printEmply( emp,x);
    displayNum(5,4);
        displayNum(70);
            displayNum();
    cout << "Scope operator!" << endl;
    cout << ::val;

	delete(emp);
    return 0;
}
