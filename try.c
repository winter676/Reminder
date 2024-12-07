#include <stdio.h>

int a[250000];

int main()
{
    int n, k;
    long long sum = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 初始化段的按位或和整个序列的按位与
    int segment_or = 0;
    int result_and = (1 << 30) - 1; // 初始化为全1

    // 贪心算法划分段
    int segments = 1;
    for (int i = 0; i < n; i++) {
        segment_or |= a[i];
        if (segments < k && (result_and & segment_or) != result_and) {
            result_and &= segment_or;
            segment_or = a[i];
            segments++;
        }
    }
    result_and &= segment_or;

    printf("%d\n", result_and);
    return 0;
}