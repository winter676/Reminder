#include <stdio.h>
#include <string.h>

int getNumFromNum(char *p1, char *p2); // 数字，以字符输出，用正数来表示
int getNumFromChar(char *p2, char *p1); // 字符累加的和，要以数字输出，返回值为负数可以加以区分

int main() {
    int len, num = 0, output[200];
    char input[200];
    char *p1 = NULL, *p2 = NULL;

    while (scanf("%s", input) != EOF) {
        len = strlen(input);
        p1 = input;
        p2 = input;

        // 找到第一个数字字符的位置
        while (*p1 && (*p1 < '0' || *p1 > '9')) {
            p1++;
        }

        // 找到第一个非数字字符的位置
        while (*p2 && (*p2 >= '0' && *p2 <= '9')) {
            p2++;
        }

        while (*p1 && *p2) {
            if (p1 < p2) {
                output[num] = getNumFromNum(p1, p2);
                num++;
                while (*p1 && (*p1 < '0' || *p1 > '9')) {
                    p1++;
                }
            } else {
                output[num] = getNumFromChar(p2, p1);
                num++;
                while (*p2 && (*p2 >= '0' && *p2 <= '9')) {
                    p2++;
                }
            }
        }

        // 输出结果
        for (int i = 0; i < num; i++) {
            if (output[i] <= 0) {
                printf("%d", -output[i]);
            } else {
                printf("%c", (char)output[i]);
            }
        }
        printf("\n");
        num = 0; // 重置 num 以便处理下一次输入
    }

    return 0;
}

int getNumFromNum(char *p1, char *p2) {
    // 示例实现：将数字字符转换为整数
    int num = 0;
    while (p1 < p2 && *p1 >= '0' && *p1 <= '9') {
        num = num * 10 + (*p1 - '0');
        p1++;
    }
    return num;
}

int getNumFromChar(char *p2, char *p1) {
    // 示例实现：将字符累加的和返回为负数
    int sum = 0;
    while (p2 < p1 && (*p2 < '0' || *p2 > '9')) {
        sum += *p2;
        p2++;
    }
    return -sum;
}