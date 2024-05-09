#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float xi,yi,xi1,yi1;
    cout << "Enter the initial point : ";
    cin >> xi >> yi;
    cout << "\nEnter the final point : ";
    cin >> xi1 >> yi1;
    float delx,dely,m;
    delx = xi1 - xi;
    dely = yi1 - yi;
    m = dely/delx;
    if (delx >= dely) {
        delx = 1;
    } else {
        dely = 1;
    }
    while ((xi != xi1) || (yi != yi1)) {
        if (delx == 1) {
            cout << "(" << round(xi) << "," << round(yi) << ")";
            xi++;
            yi += m;
            cout << "           (" << round(xi) << "," << round(yi) << ")\n";
        }
        else {
            cout << "(" << round(xi) << "," << round(yi) << ")";
            yi++;
            xi += 1/m;
            cout << "           (" << round(xi) << "," << round(yi) << ")\n";
        }
    }
}