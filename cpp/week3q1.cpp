#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
int n,x;
cout<<"enter number of elements"<<endl;
cin>>n;
for(int i=0;i<n;i++){
    cout<<"enter element "<<i+1<<endl;
    cin>>x;
    v.push_back(x);//insert elements 
}
cout<<"vector elements are :"<<endl;
for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    cout<<*it<<" ";
}
return 1;
}