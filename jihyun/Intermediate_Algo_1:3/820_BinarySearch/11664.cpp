

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double dist(double n[3], double m[3]){
    return sqrt(pow(n[2]-m[2], 2) + pow(n[1]-m[1], 2) + pow(n[0]-m[0], 2));
}

int main(){
    double a[3], b[3], c[3];
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2] >> c[0] >> c[1] >> c[2];
    
    double left[3];
    double right[3];
    
    for(int i=0; i<3; i++){
        left[i] = a[i];
        right[i] = b[i];
    }

    while(dist(left, right)>1e-11){
        double mid[3];
        mid[0] = (left[0]+right[0]) / 2.0;
        mid[1] = (left[1]+right[1]) / 2.0;
        mid[2] = (left[2]+right[2]) / 2.0;
        
        double p1 = dist(left, c);
        double p2 = dist(right, c);
        
        if(p1 < p2){
            for(int i=0; i<3; i++)
                right[i] = mid[i];
        }
        else{
            for(int i=0; i<3; i++)
                left[i] = mid[i];
        }
    }
    
    printf("%.10f",dist(left,c));
}
