#include <stdio.h>
#include <string.h>

int main()
{
    int n, len;
    char food[10][2000], key[20000] = "", Sorder[1001];

    // 读取食材种类数量
    scanf("%d", &n);

    // 读取每种食材的名称
    for (int i = 0; i < n; i++) {
        scanf("%s", food[i]);
    }

    // 读取食材顺序字符串
    scanf("%s", Sorder);

    // 按顺序连接食材名称
    for (int i = 0; i < strlen(Sorder); i++) {
        int index = Sorder[i] - '1'; // 将字符转换为对应的数组索引
        strcat(key, food[index]);
    }

    // 获取连接后的字符串长度
    len = strlen(key);

    // 输出连接后的字符串的后半部分
    for (int i = len / 2; i < len; i++) {
        printf("%c", key[i]);
    }
    printf("\n");

    return 0;
}