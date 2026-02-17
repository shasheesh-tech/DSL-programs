#include<iostream>
using namespace std;
int main(){
    int opt;
    cout<<"1.coffee\n2.tea\n3.juice\n";
    cout<<"enter your choice(1-3)\n";
cin>>opt;
switch(opt){
    case 1:
    cout<<"you selected coffee"<<endl;
    break;
    case 2:
    cout<<"you selected tea"<<endl;
    break;
    case 3:
    cout<<"you selected juice"<<endl;
    break;
}
return 0;
}