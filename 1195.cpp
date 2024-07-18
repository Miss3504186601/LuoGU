#include <bits/stdc++.h>
using namespace std;

const int num = 10001;
int pre[num];
struct node{int x, y, l;}a[num];
bool operator<(node x, node y){return x.l < y.l;}
int find(int x){
    if(pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n ,m, k;
    cin >> n >> m >> k;
    //init
    for(int i = 1; i <= n; i++)
        pre[i] = i;

    for(int i = 1; i <= m; i++)
        cin >> a[i].x >> a[i].y >> a[i].l;
    sort(a + 1, a + 1 + m);
    //join
    int kk = 0, ll = 0;
    for(int i = 1; i <= m; i++){
        int x = find(a[i].x);
        int y = find(a[i].y);
        if(x != y) {
            pre[x] = y;
            kk++;
            ll += a[i].l;
        }

        if(kk == n-k){
            cout << ll << endl;
            return 0;
        }
    }
    cout << "No Answer" << endl;

    return 0;
}
