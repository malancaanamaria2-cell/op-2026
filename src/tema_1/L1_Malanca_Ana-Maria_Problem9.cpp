#include <iostream>
using namespace std;
int v2[100],v1[100],v3[100];
int relativ_prim(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    if (a==1)
        return 1;
    return 0;
}
void zahlen_kleiner_rprim(int n) {
    int i=n-1,j=0;
    while (i!=0) {
        if (relativ_prim(i,n)) {
            v3[j]=i;
            j++;
        }
        i--;
    }
    for (i=0; i<j; i++)
        cout<<v3[i]<<" ";

}
void max_summe_zahlenfolge(int v2[], int n) {
    int summe = v2[0];
    int max_sum = v2[0];

    int start = 0, max_start = 0;
    int end = 0;

    for (int i = 1; i < n; i++) {
        if (summe < 0) {
            summe = v2[i];
            start = i;
        } else {
            summe += v2[i];
        }

        if (summe > max_sum) {
            max_sum = summe;
            max_start = start;
            end = i;
        }
    }

    for (int i = max_start; i <= end; i++)
        cout << v2[i] << " ";
}
int main() {
    int n;
    cin>>n;
    zahlen_kleiner_rprim(n);
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v1[i];
    max_summe_zahlenfolge(v1,n);
    return 0;

}