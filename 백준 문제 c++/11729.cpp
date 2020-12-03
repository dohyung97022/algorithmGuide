#include <stdio.h>
#include <math.h>
void hanoi(int N, int start, int mid, int end);
int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", (int)pow(2, N) - 1);
    hanoi(N, 1, 2, 3);
}
void hanoi(int N, int start, int mid, int end)
{
    if (N == 1)
        printf("%d %d\n", start, end);
    else
    {
        hanoi(N - 1, start, end, mid);
        printf("%d %d\n", start, end);
        hanoi(N - 1, mid, start, end);
    }
}