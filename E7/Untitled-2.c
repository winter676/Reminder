#include <stdio.h>

#define MAX 100

void rotateMatrix(char matrix[MAX][MAX], int n) {
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            char top = matrix[first][i]; // 保存顶部元素

            // 左 -> 顶
            matrix[first][i] = matrix[last - offset][first];

            // 下 -> 左
            matrix[last - offset][first] = matrix[last][last - offset];

            // 右 -> 下
            matrix[last][last - offset] = matrix[i][last];

            // 顶 -> 右
            matrix[i][last] = top; // 右 <- 保存的顶部元素
        }
    }
}

int main() {
    int n;
    char A[MAX][MAX];

    scanf("%d", &n);
    getchar(); // 读取并丢弃换行符

    for (int i = 0; i < n; i++) {
        gets(A[i]);
    }

    rotateMatrix(A, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}