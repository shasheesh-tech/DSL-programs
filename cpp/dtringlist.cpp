#include<iostream>
#include<list>
using namespace std;
int main(){
list<string> l;
l.push_back("c++");
l.push_back("java");
l.push_back("python");
for(auto it=l.begin();it!=l.end();it++){
    cout<<*it<<" ";
}
cout<<endl;
l.push_back("DSS");
l.pop_front();
for(auto it=l.begin();it!=l.end();it++){
    cout<<*it<<" ";
}
return 0;

}
