#include<iostream>
#include<string>
using namespace std;
class student{
    private :
    string name;
int age;
float marks;
public :
student (string n,int a,float m){
    name = n;
    age=a;
    marks=m;
}
void display(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"marks: "<<marks<<endl;
}
~student(){
    cout<<"marks of studnet has been deleted "<<marks<<endl;
}
};
int main(){
student s1("shasheesh",56,99.99);
student s2("rakesh",99,100);
s1.display();
s2.display();
return 0;
}
