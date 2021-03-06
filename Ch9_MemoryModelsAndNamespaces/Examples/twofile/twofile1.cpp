// twofile1.cpp -- variable with external and internal linkage
#include <iostream>


int tom = 3;                // external variable definition
int dick = 30;              // external variable definition
static int harry  = 300;    // static, internal linkage

// function prototypes
void remote_access();

int main()
{
    using namespace std;
    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = *dick, ";
    cout << &harry << " = &harry\n";
    remote_access();
    return 0;
}
