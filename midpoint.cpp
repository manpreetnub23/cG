#include<bits/stdc++.h>
using namespace std;
int main() {
    float xi = 0,yi,r,pi;
    cout << "Enter the radius : ";
    cin >> r;
    yi = r;
    cout << "Initial point : "<<"("<<xi<<","<<yi<<endl;
    pi = 1 - r;
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
            pi = pi + 2*xi + 1;
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
            pi = pi + 2*(xi - yi) + 5;
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