#include<iostream>
#include<string>
using namespace std;
class student{
private:
int rollnum;
string name;
float marks;
public:
student(){
    rollnum=0;
    name="";
    marks=0.0;
}
void input(){
    cout<<"enter roll number: ";
    cin.ignore();
    cin>>rollnum;
     cin.ignore();
    cout<<"enter name: ";
    getline(cin,name);
cout<<"enter marks: ";
cin>>marks;
}
void display(){
    cout<<rollnum<<"\t"<<name<<"\t"<<marks<<endl;
}
~student(){
    cout<<"student object with rollnumber "<<rollnum<<" is destroyed\n";
}
};
int main(){
    int n;
    cout<<"enter number of students\n";
    cin>>n;
    student *students=new student[n];
    for(int i=0;i<n;i++){
        cout<<"\nenter the details of student "<<i+1<<endl;
        students[i].input();
    }
     for(int i=0;i<n;i++){
        students[i].display();
    }
    delete[] students;
    return 0;

}
