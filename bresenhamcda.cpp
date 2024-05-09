#include<bits/stdc++.h>
using namespace std;
int main() {
    float xi = 0,yi,r,pi;
    cout << "Enter the radius : ";
    cin >> r;
    yi = r;
    cout << "Initial point : "<<"("<<xi<<","<<yi<<endl;
    pi = 3 - 2*r;
    while(xi < yi) {
        if(pi < 0) {
            cout<<"("<<xi<<","<<yi<<")";
            cout<<"     ("<<-xi<<","<<yi<<")";
            cout<<"     ("<<-xi<<","<<-yi<<")";
            cout<<"     ("<<xi<<","<<-yi<<")\n";
            cout<<"("<<yi<<","<<xi<<")";
            cout<<"     ("<<-yi<<","<<xi<<")";
            cout<<"     ("<<-yi<<","<<-xi<<")";
            cout<<"     ("<<yi<<","<<-xi<<")\n";
            xi++;
            pi = pi + 4*xi + 6;
        } else {
            cout<<"("<<xi<<","<<yi<<")";
            cout<<"     ("<<-xi<<","<<yi<<")";
            cout<<"     ("<<-xi<<","<<-yi<<")";
            cout<<"     ("<<xi<<","<<-yi<<")\n";
            cout<<"("<<yi<<","<<xi<<")";
            cout<<"     ("<<-yi<<","<<xi<<")";
            cout<<"     ("<<-yi<<","<<-xi<<")";
            cout<<"     ("<<yi<<","<<-xi<<")\n";
            xi++;
            yi--;
            pi = pi  + 4*(xi - yi) + 10;
        }
    }
    cout<<"("<<xi<<","<<yi<<")";
    cout<<"     ("<<-xi<<","<<yi<<")";
    cout<<"     ("<<-xi<<","<<-yi<<")";
    cout<<"     ("<<xi<<","<<-yi<<")\n";
    cout<<"("<<yi<<","<<xi<<")";
    cout<<"     ("<<-yi<<","<<xi<<")";
    cout<<"     ("<<-yi<<","<<-xi<<")";
    cout<<"     ("<<yi<<","<<-xi<<")\n"; 
}