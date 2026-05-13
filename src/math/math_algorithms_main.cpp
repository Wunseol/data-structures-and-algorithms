#include "math_algorithms.h"
#include <cstdio>

static void print_menu(void)
{
    printf("\n========== 数学算法操作菜单 ==========\n");
    printf("  1.  判断素数 (isPrime)\n");
    printf("  2.  Miller-Rabin素性测试\n");
    printf("  3.  最大公约数 (gcd)\n");
    printf("  4.  最小公倍数 (lcm)\n");
    printf("  5.  埃拉托斯特尼筛法\n");
    printf("  6.  快速幂 (fastPow)\n");
    printf("  7.  斐波那契矩阵快速幂\n");
    printf("  8.  模逆元 (modInverse)\n");
    printf("  9.  卡特兰数 (catalan)\n");
    printf("  10. 组合数 (binomial)\n");
    printf("  11. 自测\n");
    printf("  0.  退出\n");
    printf("======================================\n");
    printf("请选择操作: ");
}

static void self_test(void)
{
    printf("\n----- 数学算法自测 -----\n");

    printf("isPrime(7) = %s\n", isPrime(7) ? "素数" : "合数");
    printf("isPrime(12) = %s\n", isPrime(12) ? "素数" : "合数");
    printf("isPrime(97) = %s\n", isPrime(97) ? "素数" : "合数");

    printf("millerRabin(97, 5) = %s\n", millerRabin(97, 5) ? "素数" : "合数");
    printf("millerRabin(561, 5) = %s (561是Carmichael数)\n", millerRabin(561, 5) ? "素数" : "合数");

    printf("gcd(12, 18) = %d\n", gcd(12, 18));
    printf("gcd(35, 14) = %d\n", gcd(35, 14));

    printf("lcm(12, 18) = %d\n", lcm(12, 18));
    printf("lcm(4, 6) = %d\n", lcm(4, 6));

    printf("sieveOfEratosthenes(30): ");
    auto primes = sieveOfEratosthenes(30);
    for (int p : primes) printf("%d ", p);
    printf("\n");

    printf("fastPow(2, 10, 1000000007) = %lld\n", (long long)fastPow(2, 10, 1000000007));
    printf("fastPow(3, 13, 1000000007) = %lld\n", (long long)fastPow(3, 13, 1000000007));

    printf("fibonacciMatrix(0) = %lld\n", (long long)fibonacciMatrix(0));
    printf("fibonacciMatrix(1) = %lld\n", (long long)fibonacciMatrix(1));
    printf("fibonacciMatrix(10) = %lld\n", (long long)fibonacciMatrix(10));
    printf("fibonacciMatrix(50) = %lld\n", (long long)fibonacciMatrix(50));

    printf("modInverse(3, 7) = %d\n", modInverse(3, 7));
    printf("modInverse(7, 11) = %d\n", modInverse(7, 11));

    printf("catalan(0) = %lld\n", (long long)catalan(0));
    printf("catalan(5) = %lld\n", (long long)catalan(5));
    printf("catalan(10) = %lld\n", (long long)catalan(10));

    printf("binomial(5, 2) = %lld\n", (long long)binomial(5, 2));
    printf("binomial(10, 3) = %lld\n", (long long)binomial(10, 3));
    printf("binomial(20, 10) = %lld\n", (long long)binomial(20, 10));

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
            printf("%d %s素数\n", n, isPrime(n) ? "是" : "不是");
            break;
        }
        case 2: {
            int64_t n;
            int k;
            printf("请输入整数和测试轮数(用空格分隔): ");
            if (scanf("%lld %d", &n, &k) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("%lld %s素数(概率性测试, 轮数=%d)\n",
                   (long long)n, millerRabin(n, k) ? "可能是" : "不是", k);
            break;
        }
        case 3: {
            int a, b;
            printf("请输入两个整数(用空格分隔): ");
            if (scanf("%d %d", &a, &b) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
            break;
        }
        case 4: {
            int a, b;
            printf("请输入两个整数(用空格分隔): ");
            if (scanf("%d %d", &a, &b) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("lcm(%d, %d) = %d\n", a, b, lcm(a, b));
            break;
        }
        case 5: {
            int n;
            printf("请输入上限n: ");
            if (scanf("%d", &n) != 1 || n < 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            auto primes = sieveOfEratosthenes(n);
            printf("2到%d的素数共%lld个: ", n, (long long)primes.size());
            for (int p : primes) printf("%d ", p);
            printf("\n");
            break;
        }
        case 6: {
            int64_t base, exp, mod;
            printf("请输入底数、指数、模数(用空格分隔): ");
            if (scanf("%lld %lld %lld", &base, &exp, &mod) != 3) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("(%lld ^ %lld) mod %lld = %lld\n",
                   (long long)base, (long long)exp, (long long)mod,
                   (long long)fastPow(base, exp, mod));
            break;
        }
        case 7: {
            int n;
            printf("请输入n: ");
            if (scanf("%d", &n) != 1 || n < 0) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("fib(%d) = %lld (mod 1000000007)\n", n, (long long)fibonacciMatrix(n));
            break;
        }
        case 8: {
            int a, m;
            printf("请输入a和m(用空格分隔): ");
            if (scanf("%d %d", &a, &m) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            int inv = modInverse(a, m);
            if (inv == -1)
                printf("%d在模%d下没有逆元(gcd!=1)\n", a, m);
            else
                printf("%d在模%d下的逆元: %d\n", a, m, inv);
            break;
        }
        case 9: {
            int n;
            printf("请输入n: ");
            if (scanf("%d", &n) != 1 || n < 0) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("catalan(%d) = %lld\n", n, (long long)catalan(n));
            break;
        }
        case 10: {
            int n, k;
            printf("请输入n和k(用空格分隔): ");
            if (scanf("%d %d", &n, &k) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("C(%d, %d) = %lld\n", n, k, (long long)binomial(n, k));
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
