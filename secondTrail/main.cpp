#include <iostream.h>
#include <fstream.h>
class three_d
{
 int x, y, z;
 public:
 three_d(int a, int b, int c)
 {
 x = a;
 y = b;
 z = c;
 }
 friend ostream& operator<<(ostream &out, three_d obj)
 {
 out<<obj.x<<",";
 out<<obj.y<<",";
 out<<obj.z<<"\n";
 return out;
 }
 friend istream& operator>>(istream &in, three_d &obj)
 {
 cout<<"enter x, y, z values : ";
 cin>>obj.x>>obj.y>>obj.z;
 return in;
 }
};

int main(void)
{    /*
    fstream obj2;
    obj2.open("sam.txt",ios::out);
    int x=10;
    obj2<<x<<endl;
    obj2.close();
   fstream obj3;
    obj2.open("sam.txt",ios::in);
    int y;
    obj2>>y;
    obj2.close();
    cout <<y<<endl;

obj2.close();
*/
     fstream obj;
    char x='b';
    char g;
    obj.open("try2", ios::binary| ios::out);
    obj.write(&x, sizeof(char*));
    //cout<<"samy";



obj.close();
    obj.open("try2", ios::binary| ios::in);
    obj.read(&g, sizeof(char*));
    cout<<g << endl;
    // cout <<"thank you";


obj.close();

return 0;

}
