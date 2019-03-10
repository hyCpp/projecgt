#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
double s[100];
double mn;

double closest(int low, int high)
{
    if (low + 1 == high) {
        return s[high] - s[low];
    }

    if (low + 2 == high) {
        return min(s[low + 1] - s[low], s[high] - s[low + 1]);
    }

    int mid = (low + high) >> 1;
    double ans = min(closest(low, mid), closest(mid + 1, high));
    if (s[mid] + 1 - s[mid] < ans) {
        ans = s[mid + 1] -s[mid];
    }
    return ans;
}

double Random()
{
    double result = rand() % 10000;
    return result * 0.01;
}

int main()
{
    int n,m;
    srand(1);
    while (~scanf("%d", &n)) {
        for (int i = 0;i < n; i++) {
            s[i] = rand() % 10000;
            printf("---1---%d\n", s[i]);
        }

        sort(s, s + n);
        for (int i = 0; i < n;++i) {
            printf("---2---%lf\n", s[i]);
        }
        printf("%.4lf\n", closest(0, n -1));
    }
}
