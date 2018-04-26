#include <cstdio>
 
int main() {
    unsigned int n, k, t;
    unsigned int count = 0;
     
    scanf("%u %u", &n, &k);
     
    for (unsigned int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if ((t % k==0)) {
            ++count;
        }
    }
    printf("%d", count);
}
