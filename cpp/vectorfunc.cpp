#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5,6};
        v.push_back(7);
        v.push_back(9);
         for(int va : v){
            cout<<va<<" ";
}
cout<<endl;
v.pop_back();
for(int val : v){
            cout<<val<<" ";
}
return 0;
}

