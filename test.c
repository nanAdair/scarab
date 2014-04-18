#include <stdio.h>

int num[100];

void dfs(int depth, int n);
void print(int n);

int main()
{
    int input;
    scanf("%d", &input);
    dfs(0, input);
}

void dfs(int depth, int n)
{
    if (depth == n) {
        print(n);
        return ;
    }
    num[depth] = 0;
    dfs(depth+1, n);
    num[depth] = 1;
    dfs(depth+1, n);
}

void print(int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d", num[i]);
    printf("\n");
}
