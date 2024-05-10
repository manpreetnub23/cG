#include <bits/stdc++.h>
using namespace std;
const int I=0,L=1,R=2,B=4,T=8;
int reg_code(int x,int y,int xmi, int ymi, int xma, int yma) {
    int code = I;
    if(x < xmi) code |= L;
    else if(x > xma) code |= R;
    if(y < ymi) code |= B;
    else if(y > yma) code |= T;
    return code;
}

void clip(int &x1,int &y1,int &x2,int &y2,int xmi,int ymi,int xma,int yma) {
    int c1 = reg_code(x1,y1,xmi,ymi,xma,yma);
    int c2 =  reg_code(x2,y2,xmi,ymi,xma,yma);
    bool accept = false;
    while(true) {
        if(!(c1 | c2)) {
            accept = true;
            break;
        } else if(c1 & c2) break;
        else {
            int c = c1 ? c1 : c2;
            int x,y;
            if(c & T) {
                x=x1 + (x2 - x1)*(yma - y1)/(y2 - y1);
                y=yma;
            } else if(c & B) {
                x=x1 + (x2 - x1)*(ymi - y1)/(y2 - y1);
                y=ymi;
            } else if(c & R) {
                y=y1 + (y2 - y1)*(xma - x1)/(x2 - x1);
                x=xma;
            } else if(c & L) {
                y=y1 + (y2 - y1)*(xmi - x1)/(x2 - x1);
                x=xmi;
            }
            if(c == c1) {
                x1=x;y1=y;
                c1 = reg_code(x1,y1,xmi,ymi,xma,yma);
            } else {
                x2=x;y2=y;
                c2 = reg_code(x2,y2,xmi,ymi,xma,yma);
            }
        }
    }
    if(accept) {
        cout<<"Line after clipping : ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<")\n";
    } else {
        cout<<"Line completely outside\n";
    }
}

int main() {
    int x1,x2,y1,y2,xmi,ymi,xma,yma;
    cout<<"Enter the end points : ";
    cin>>x1>>y1>>x2>>y2;
    cout<<"Enter the window coordinates : ";
    cin>>xmi>>ymi>>xma>>yma;
    clip(x1,y1,x2,y2,xmi,ymi,xma,yma);
}