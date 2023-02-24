#include <stdio.h>
#include <math.h>
char c;
int a;
FILE *f;
int main()
{
    f = fopen("dataset/train-images.idx3-ubyte", "rb");
    for (int i = 1; i <= 4; i++)
    {
        fread(&a, 4, 1, f);
        printf("%x\n", a);
    }
    printf("number^\n");
    for (int k = 1; k <= 5; k++)
    {
        for (int i = 1; i <= 28; i++)
        {
            for (int j = 1; j <= 28; j++)
            {
                fscanf(f, "%c", &c);
                printf("%4d", c);
            }
            printf("\n");
        }
    }
    return 0;
}
