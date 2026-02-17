#include<iostream>
#include<string>
using namespace std;
class student{
    private :
    string name;
int age;
float marks;
public :
student(){
    name = "";
    age=0;
    marks=0;
}
void input(){
    cout<<"enter student name"<<endl;
    cin>>name;
    cout<<"enter age"<<endl;
    cin>>age;
    
    
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
student s1;
s1.input();
student s2;
s2.input();
s1.display();
s2.display();
return 0;
}