#include "trie.h"
#include <cstdio>
#include <string>

static void print_menu(void)
{
    printf("\n========== Trie(前缀树)操作菜单 ==========\n");
    printf("  1. 插入单词\n");
    printf("  2. 查找单词\n");
    printf("  3. 前缀查找\n");
    printf("  4. 删除单词\n");
    printf("  5. 统计单词数\n");
    printf("  0. 退出\n");
    printf("==========================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    Trie trie;
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
            char buf[256];
            printf("请输入要插入的单词(仅小写字母): ");
            scanf("%s", buf);
            trie.Insert(std::string(buf));
            printf("插入成功\n");
            break;
        }
        case 2: {
            char buf[256];
            printf("请输入要查找的单词: ");
            scanf("%s", buf);
            if (trie.Search(std::string(buf)))
                printf("单词 \"%s\" 存在\n", buf);
            else
                printf("单词 \"%s\" 不存在\n", buf);
            break;
        }
        case 3: {
            char buf[256];
            printf("请输入前缀: ");
            scanf("%s", buf);
            if (trie.StartsWith(std::string(buf)))
                printf("存在以 \"%s\" 为前缀的单词\n", buf);
            else
                printf("不存在以 \"%s\" 为前缀的单词\n", buf);
            break;
        }
        case 4: {
            char buf[256];
            printf("请输入要删除的单词: ");
            scanf("%s", buf);
            if (trie.Delete(std::string(buf)))
                printf("删除成功\n");
            else
                printf("删除失败，单词不存在\n");
            break;
        }
        case 5:
            printf("Trie中单词总数: %d\n", trie.CountWords());
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
