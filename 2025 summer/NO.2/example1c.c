#include <stdio.h>

int main() {
    int output = 0, num = 0, sgn = 1, afternum;
    char now, before = '\0', after;

    while (scanf("%c", &now) != EOF) {
        if (now == ' ') {
            continue;  
        }

        if (now == '+' || now == '-') {
            output += sgn * num;
            sgn = (now == '+') ? 1 : -1;
            num = 0;
            before = now;
            continue;
        }

        if (now == '*' || now == '/') {
            char op = now;
            scanf("%d", &afternum);
            if (op == '*') {
                num *= afternum;
            } else {
                num /= afternum;
            }
            before = now;
            continue;
        }

        if (now >= '0' && now <= '9') {
            if (before >= '0' && before <= '9') {
                num = num * 10 + (now - '0');
            } else {
                num = now - '0';
            }
            before = now;
            continue;
        }

        if (now == '=') {
            output += sgn * num;
            printf("%d\n", output);
            break;
        }
    }

    return 0;
}