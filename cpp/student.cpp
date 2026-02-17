#include<iostream>
#include<string>
using  namespace std;
class student{
    private:
    string name;
    int age;
    string branch;
public:
void setdata(string n,int a,string b){
    name =n;
    age =a;
    branch=b;
}
void displaydata(){
    cout<<"name:"<<name;
    cout<<"age:"<<age;
    cout<<"\nbranch:"<<branch;
}
};
int main(){
    student student1;
    student1.setdata("shasheesh\n",100,"CSE");
    student1.displaydata();
    return 0;
}