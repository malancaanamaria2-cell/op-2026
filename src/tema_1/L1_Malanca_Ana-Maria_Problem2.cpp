#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;
int v[100];
int prim(int nr) {
    if (nr<2)
        return 0;
    if (nr==2)
        return 1;
    if (nr%2==0)
        return 0;
    for (int i=3;i<=int(sqrt(nr));i+=2) {
        if (nr%i==0)
            return 0;
    }
    return 1;
}
void prim_zahlen(int n) {
    int i=0,nr=2;
    while (i<n) {
        if (prim(nr)==1) {
            v[i]=nr;
            i++;
        }
        nr++;
    }
    for (i = 0; i < n; i++)
        cout << v[i] << " ";
}
int ggt(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    if (a==1)
        return 1;
    return 0;
}

void secv_rel_prim(int v[],int n){
    int start=0,start_max=0,l=1,l_max=-1;
    for (int i = 0; i < n - 1; i++) {
        if (ggt(v[i], v[i+1]) == 1) {
            l++;
            if (l > l_max) {
                l_max = l;
                start_max = start;
            }

        }
        else {
            l=1;
            start=i+1;
        }
    }
    for (int i = start_max; i < start_max+l_max; i++)
        cout << v[i] << " ";
}

int main() {
    int n;
    cin>>n;
    prim_zahlen(n);

    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>v[i];
    secv_rel_prim(v,n);
    return 0;
}