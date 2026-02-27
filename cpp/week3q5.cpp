#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
int main() {
    vector<int> v;
    int n,element,searchValue,countValue;
    cout<< "Enter number of elements: ";
    cin>>n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> element;
        v.push_back(element);
    }
    cout<< "\nOriginal Vector: ";
    for(int x : v) {
        cout << x << " ";
    }
    sort(v.begin(), v.end());
    cout << "\nSorted Vector: ";
    for(int x : v) {
        cout << x << " ";
    }
    cout<< "\n\nEnter element to find: ";
    cin>> searchValue;

    auto it = find(v.begin(), v.end(), searchValue);
    if (it != v.end()) {
        cout << "Element " << searchValue << " found at position: "
             << (it - v.begin()) << endl;
    } else {
        cout << "Element not found in vector." << endl;
    }
    cout << "Enter element to count occurrences: ";
    cin >> countValue;

    int c = count(v.begin(), v.end(), countValue);
    cout << "Element " << countValue << " occurs " << c << " times in vector." << endl;

    return 0;

}
