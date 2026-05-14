#include "13_huffman_tree.h"
#include <cstdio>
#include <cstring>
#include <string>

static void print_menu(void)
{
    printf("\n========== 哈夫曼树操作菜单 ==========\n");
    printf("  1. 构建哈夫曼树\n");
    printf("  2. 编码(打印各字符编码)\n");
    printf("  3. 解码比特串\n");
    printf("  4. 计算带权路径长度(WPL)\n");
    printf("  0. 退出\n");
    printf("======================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    HuffmanTree tree;
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
            printf("请输入字符个数: ");
            if (scanf("%d", &n) != 1 || n < 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            char *chars = new char[n];
            int *freqs = new int[n];
            printf("请输入%d个字符(连续输入，无空格): ", n);
            char buf[1024];
            scanf("%s", buf);
            int len = (int)strlen(buf);
            for (int i = 0; i < n && i < len; i++)
                chars[i] = buf[i];
            printf("请输入%d个频率: ", n);
            for (int i = 0; i < n; i++) {
                if (scanf("%d", &freqs[i]) != 1) {
                    while (getchar() != '\n')
                        ;
                    printf("输入无效\n");
                    n = i;
                    break;
                }
            }
            tree.BuildHuffmanTree(chars, freqs, n);
            printf("哈夫曼树构建成功\n");
            delete[] chars;
            delete[] freqs;
            break;
        }
        case 2:
            if (!tree.IsBuilt()) {
                printf("请先构建哈夫曼树\n");
                break;
            }
            tree.Encode();
            break;
        case 3: {
            if (!tree.IsBuilt()) {
                printf("请先构建哈夫曼树\n");
                break;
            }
            char bitbuf[1024];
            printf("请输入比特串(仅含0和1): ");
            scanf("%s", bitbuf);
            tree.Decode(std::string(bitbuf));
            break;
        }
        case 4:
            if (!tree.IsBuilt()) {
                printf("请先构建哈夫曼树\n");
                break;
            }
            printf("带权路径长度(WPL): %d\n", tree.CalculateWPL());
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
