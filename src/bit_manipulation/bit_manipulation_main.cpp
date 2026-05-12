#include "bit_manipulation.h"
#include <cstdio>

static void print_menu(void)
{
    printf("\n========== 位运算操作菜单 ==========\n");
    printf("  1. 判断奇偶 (isOdd)\n");
    printf("  2. 判断2的幂 (isPowerOfTwo)\n");
    printf("  3. 统计1的个数 (countBits)\n");
    printf("  4. 获取某一位 (getBit)\n");
    printf("  5. 设置某一位 (setBit)\n");
    printf("  6. 清除某一位 (clearBit)\n");
    printf("  7. 翻转某一位 (toggleBit)\n");
    printf("  8. XOR交换 (swapXor)\n");
    printf("  9. 汉明距离 (hammingDistance)\n");
    printf("  10. 反转位 (reverseBits)\n");
    printf("  11. 自测\n");
    printf("  0. 退出\n");
    printf("====================================\n");
    printf("请选择操作: ");
}

static void self_test(void)
{
    printf("\n----- 位运算自测 -----\n");

    printf("isOdd(7) = %s\n", isOdd(7) ? "奇数" : "偶数");
    printf("isOdd(8) = %s\n", isOdd(8) ? "奇数" : "偶数");

    printf("isPowerOfTwo(16) = %s\n", isPowerOfTwo(16) ? "是" : "否");
    printf("isPowerOfTwo(15) = %s\n", isPowerOfTwo(15) ? "是" : "否");

    printf("countBits(13) = %d (13 = 1101b)\n", countBits(13));
    printf("countBits(255) = %d (255 = 11111111b)\n", countBits(255));

    printf("getBit(13, 2) = %d (13 = 1101b, bit2=1)\n", getBit(13, 2));
    printf("getBit(13, 1) = %d (13 = 1101b, bit1=0)\n", getBit(13, 1));

    printf("setBit(13, 1) = %d (13->15, 1101->1111)\n", setBit(13, 1));
    printf("clearBit(13, 2) = %d (13->9, 1101->1001)\n", clearBit(13, 2));
    printf("toggleBit(13, 0) = %d (13->12, 1101->1100)\n", toggleBit(13, 0));

    int a = 10, b = 20;
    printf("swapXor前: a=%d, b=%d\n", a, b);
    swapXor(a, b);
    printf("swapXor后: a=%d, b=%d\n", a, b);

    printf("hammingDistance(1, 4) = %d (1=001, 4=100)\n", hammingDistance(1, 4));
    printf("hammingDistance(0, 0) = %d\n", hammingDistance(0, 0));

    uint32_t val = 0b00000010100101000001111010011100;
    uint32_t rev = reverseBits(val);
    printf("reverseBits(0x%08X) = 0x%08X\n", val, rev);

    printf("----- 自测完成 -----\n");
}

int main(void)
{
    int choice;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n')
                ;
            printf("输入无效，请重新输入\n");
            continue;
        }

        switch (choice) {
        case 1: {
            int n;
            printf("请输入整数: ");
            if (scanf("%d", &n) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("%d 是%s数\n", n, isOdd(n) ? "奇" : "偶");
            break;
        }
        case 2: {
            int n;
            printf("请输入整数: ");
            if (scanf("%d", &n) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("%d %s2的幂\n", n, isPowerOfTwo(n) ? "是" : "不是");
            break;
        }
        case 3: {
            int n;
            printf("请输入整数: ");
            if (scanf("%d", &n) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("%d 的二进制中1的个数: %d\n", n, countBits(n));
            break;
        }
        case 4: {
            int n, i;
            printf("请输入整数和位索引(用空格分隔): ");
            if (scanf("%d %d", &n, &i) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("%d 的第%d位: %d\n", n, i, getBit(n, i));
            break;
        }
        case 5: {
            int n, i;
            printf("请输入整数和位索引(用空格分隔): ");
            if (scanf("%d %d", &n, &i) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("setBit(%d, %d) = %d\n", n, i, setBit(n, i));
            break;
        }
        case 6: {
            int n, i;
            printf("请输入整数和位索引(用空格分隔): ");
            if (scanf("%d %d", &n, &i) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("clearBit(%d, %d) = %d\n", n, i, clearBit(n, i));
            break;
        }
        case 7: {
            int n, i;
            printf("请输入整数和位索引(用空格分隔): ");
            if (scanf("%d %d", &n, &i) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("toggleBit(%d, %d) = %d\n", n, i, toggleBit(n, i));
            break;
        }
        case 8: {
            int a, b;
            printf("请输入两个整数(用空格分隔): ");
            if (scanf("%d %d", &a, &b) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("交换前: a=%d, b=%d\n", a, b);
            swapXor(a, b);
            printf("交换后: a=%d, b=%d\n", a, b);
            break;
        }
        case 9: {
            int a, b;
            printf("请输入两个整数(用空格分隔): ");
            if (scanf("%d %d", &a, &b) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("%d 和 %d 的汉明距离: %d\n", a, b, hammingDistance(a, b));
            break;
        }
        case 10: {
            uint32_t n;
            printf("请输入无符号整数: ");
            if (scanf("%u", &n) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("reverseBits(%u) = %u\n", n, reverseBits(n));
            break;
        }
        case 11:
            self_test();
            break;
        case 0:
            printf("程序退出\n");
            return 0;
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    }
}
