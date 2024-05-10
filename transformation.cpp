#include <bits/stdc++.h>
using namespace std;

class Transformation {
    int n;
    int **a;
    int **o;
    public:
    Transformation() {
        cout<<"Enter the no of vertices : ";
        cin>>n;
        a = new int*[n];
        o = new int*[n];
        for(int i=0;i<n;i++) {
            a[i] = new int[2];
            o[i] = new int[3];
        }
    }
    void input() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<2;j++) {
                cin>>a[i][j];
                o[i][2] = 1;
            }
        }
    }
    void output() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<3;j++) {
                cout<<o[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void translate() {
        int tx,ty;
        cout<<"Enter Translation x and y resp : ";
        cin>>tx>>ty;
        int mat[3][3] = {
            {1,0,0},
            {0,1,0},
            {tx,ty,1}
        };
        for(int i=0;i<n;i++) {
            o[i][0] = a[i][0] + tx;
            o[i][1] = a[i][1] + ty;
        }
    }
    void scale() {
        int sx,sy;
        cout<<"Enter scale x and y resp : ";
        cin>>sx>>sy;
        for(int i=0;i<n;i++) {
            o[i][0] = a[i][0]*sx;
            o[i][1] = a[i][1]*sy;
        }
    }
    void shear() {
        cout<<"1. x-shear\n2. y-shear\n3. both shear\n";
        int c;
        cin>>c;
        cout<<"Enter x-shear and y-shear (for 1 and 2 onlyone shear will be considered) : ";
        int shx,shy;
        cin>>shx>>shy;
        for(int i=0;i<n;i++) {
            if(c == 1) {
                o[i][0] = a[i][0]+shx*a[i][1];
                o[i][1] = a[i][1];
            } else if(c==2) {
                o[i][1] = a[i][1]+shy*a[i][0];
                o[i][0] = a[i][0];
            } else {
                o[i][0] = a[i][0]+shx*a[i][1];
                o[i][1] = a[i][1]+shy*a[i][0];
            }
        }
    }
    void rotate() {
        cout<<"1.rotate clockwise\n2.rotate anticlockwise\n";
        int dir;
        cin>>dir;
        cout<<"Enter the angle of rotation in degrees : ";
        int theta;
        cin>>theta;
        for(int i=0;i<n;i++) {
            if(dir == 2) {
                o[i][0] = round(a[i][0]*cos(theta) - a[i][1]*sin(theta));
                o[i][1] = round(a[i][0]*sin(theta) + a[i][1]*cos(theta));
            } else {
                o[i][0] = round(a[i][0]*cos(theta) + a[i][1]*sin(theta));
                o[i][1] = round(-a[i][0]*sin(theta) + a[i][1]*cos(theta));
            }
        }
    }
    void reflect() {
        cout<<"Reflect against\n1. x axis\n2.y axis\n3. origin\n4. line y=x\n5. line y=-x\n";
        int ref;
        cin>>ref;
        for(int i=0;i<n;i++) {
            if(ref == 1) {
                o[i][0] = a[i][0];
                o[i][1] = -a[i][1];
            } else if(ref == 2) {
                o[i][0] = -a[i][0];
                o[i][1] = a[i][1];
            } else if(ref == 3) {
                o[i][0] = -a[i][0];
                o[i][1] = -a[i][1];
            } else if(ref == 4) {
                o[i][0] = a[i][1];
                o[i][1] = a[i][0];
            } else {
                o[i][0] = -a[i][1];
                o[i][1] = -a[i][0];
            }
        }
    }
};

int main() {
    Transformation t;
    t.input();
    t.reflect();
    t.output();
}