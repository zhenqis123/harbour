#include <iostream>
#pragma warning(disable:4996)
using namespace std; 
int main() {
    int n;
    std::cin >> n;//接收n
    unsigned int *t = new unsigned int[n];//new数组出来
    unsigned int *k = new unsigned int[n];
    unsigned int  **x;
    x = new unsigned int *[n];
    for (int i = 0; i  < n; i++) {
        scanf("%d%d",&t[i], &k[i]);
        x [i] = new unsigned int [k [i]];
        for (int j = 0; j < k[i]; j++) {
            scanf("%d", &x[i][j]);
        }
    }
    unsigned int c = 0;
    unsigned int *p = new unsigned int [100000]();
    int lasttem = 0;
    int tem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[i]; j++) {
            unsigned int o = 0;
            if (p[x[i][j]] == 0) {
                c++;
                p[x[i][j]]++;
            }
            else{
                p[x[i][j]]++;
            }
        }
        if (t[i] >= 86400) {
            tem = lasttem;
            int temp = t[i] - 86400;
            while (t[tem] <= temp)tem++;
            for (int e = lasttem; e < tem; e++) {
                for (int j = 0; j < k[e]; j++) {
                    p[x[e][j]]--;
                    if (p[x[e][j]] == 0)c--;
                }
            }
            lasttem = tem;
        }
        printf("%d\n", c);
    }
    delete []k;
    delete []p;
    delete []x;
    delete[]t;
    return 0;
}
