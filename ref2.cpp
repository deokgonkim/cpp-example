#include <iostream>
using namespace std;
 
void change(int &ref) {
ref = 3;
}
 
int main() {
int a=5;
cout<<a<<endl;
change(a);
cout<<a<<endl;
}
