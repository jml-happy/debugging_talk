// C++ program for implementation of Bubble sort  
#include <iostream>
#include "debugging/segfault.h"

using namespace std;

// Driver code  
int main()
{
    // Try testing various watch points with this code
    int i = 0;
    int k = 0;
    int c = 0;
    for (i = 0; i < 10; i ++) {
        for (k = 10; k > 0; k--) {
            c++;
        }
    }

    // This will setfault!
    segfault_a();

    return 0;
}  