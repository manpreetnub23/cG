#include <bits/stdc++.h>
using namespace std;
const int MAX_POINTS = 20;
int x_intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
    int n = (x1*y2 - y1*x2)*(x3 -x4) - (x1 - x2)*(x3*y4 - y3*x4);
    int d = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);
    return n/d;
}
int y_intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
    int n = (x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4);
    int d = (x1 -x2)*(y3 - y4) - (y1 - y2)*(x3- x4);
    return n/d; 
}

void clip(int pp[][2],int &ps,int x1,int y1,int x2,int y2) {
    int new_pts[MAX_POINTS][2],new_poly_size=0;
    for(int i=0;i<ps;i++) {
        int k = (i+1)%ps;
        int ix = pp[i][0], iy = pp[i][1];
        int kx = pp[k][0], ky = pp[k][1];
        int i_pos = (x2 - x1)*(iy - y1) - (y2-y1)*(ix - x1);
        int k_pos = (x2 - x1)*(ky - y1) - (y2-y1)*(kx - x1);
        if(i_pos < 0 && k_pos < 0) {
            new_pts[new_poly_size][0] = kx;
            new_pts[new_poly_size][1] = ky;
            new_poly_size++;
        }
        else if(i_pos >=0 && k_pos < 0) {
            new_pts[new_poly_size][0] = x_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
            new_pts[new_poly_size][1] = y_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
            new_poly_size++;
            new_pts[new_poly_size][0] = kx;
            new_pts[new_poly_size][1] = ky;
            new_poly_size++;
        }
        else if(i_pos < 0 && k_pos >= 0) {
            new_pts[new_poly_size][0] = x_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
            new_pts[new_poly_size][1] = y_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
            new_poly_size++;
        }
        else {
            //both points are outside clipper hence no op
        }
    }
    ps = new_poly_size;
    for(int i=0;i<ps;i++) {
        pp[i][0] = new_pts[i][0];
        pp[i][1] = new_pts[i][1];
    }
}

void shc(int pp[][2],int ps,int cp[][2],int cs) {
    for(int i=0;i<cs;i++) {
        int k = (i+1)%cs;
        clip(pp,ps,cp[i][0],cp[i][1],cp[k][0],cp[k][1]);
    }
    for(int i=0;i<ps;i++) {
        cout<<"("<<pp[i][0]<<","<<pp[i][1]<<")\n";
    }
}

int main() {
    int poly_size=3;
    // cout<<"Enter no of vertices of polygon :";
    // cin>>poly_size;
    int poly_point[20][2] = {{100,150},{200,250},{300,200}};
    // cout<<"Enter the polygon points\n";
    // for(int i=0;i<poly_size;i++) {
    //     for(int j=0;j<2;j++) {
    //         cin>>poly_point[i][j];
    //     }
    // }
    int clipper_size=4;
    // cout<<"Enter clipper size : ";
    // cin>>clipper_size;
    int clipper_point[clipper_size][2] = {{150,150},{150,200},{200,200},{200,150}};
    // cout<<"Enter the clipper points\n";
    // for(int i=0;i<clipper_size;i++) {
    //     for(int j=0;j<2;j++) {
    //         cin>>clipper_point[i][j];
    //     }
    // }
    shc(poly_point,poly_size,clipper_point,clipper_size);
}