#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float xi,yi,xi1,yi1;
    cout << "Enter the initial point : ";
    cin >> xi >> yi;
    cout << "\nEnter the final point : ";
    cin >> xi1 >> yi1;
    float delx,dely,m,pi;
    delx = xi1 - xi;
    dely = yi1 - yi;
    pi = 2*dely - delx;
    m = dely/delx;
    while ((xi != xi1) || (yi != yi1)) {
        if (m < 1 && pi < 0) {
            cout << "(" << xi << "," << yi << ")";
            xi++;
            pi = pi + 2*dely;
            cout << "           (" << xi << "," << yi << ")\n";
        } else if (m < 1 && pi >= 0) {
            cout << "(" << xi << "," << yi << ")";
            xi++;
            yi++;
            pi = pi + 2*(dely - delx);
            cout << "           (" << xi << "," << yi << ")\n";
        } else if (m >= 1 && pi < 0) {
            cout << "(" << xi << "," << yi << ")";
            yi++;
            pi = pi + 2*delx;
            cout << "           (" << xi << "," << yi << ")\n";
        } else {
            cout << "(" << xi << "," << yi << ")";
            xi++;
            yi++;
            pi = pi + 2*(delx - dely);
            cout << "           (" << xi << "," << yi << ")\n";
        }
    }
}