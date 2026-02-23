#include<iostream>
using namespace std;
class fact{
    public:
    int factorial(int n){
        if(n<=0) return 0;
        if(n==1) return 1;
        else return n*factorial(n-1);
    }
};
int main(){
    int num;
    fact obj;
    cout<<"enter a number "<<endl;
    cin>>num;
    cout<<"factorial of "<<num<<" is "<<obj.factorial(num);
    return 0;
}