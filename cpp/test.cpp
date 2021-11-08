#include <iostream>
using namespace std;
class Parent {
public:
virtual void func() { cout << "a!" << endl; }
};
class Child : public Parent {
public:
void func() { cout << "b!" << endl; }
};
int main()
{
Parent P, *pP;
Child C;
pP=&P;
pP->func();
pP=&C;
pP->func();
return 0;
}
