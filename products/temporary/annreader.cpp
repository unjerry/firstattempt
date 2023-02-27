#include <stdio.h>
#include <math.h>
#include <field_matrix.h>
#include <complexnumber.h>
unsigned char c;
int a;
FILE *f, *of, *ff;
field_matrix<complexnumber> iptm(28 * 28, 1), optm(10, 1);
int main()
{
    f = fopen("dataset/train-images.idx3-ubyte", "rb");
    ff = fopen("dataset/train-labels.idx1-ubyte", "rb");
    of = fopen("mnist_train_annbrainin", "wb");
    for (int i = 1; i <= 4; i++)
    {
        fread(&a, 4, 1, f);
        printf("%x\n", a);
    }
    for (int i = 1; i <= 2; i++)
    {
        fread(&a, 4, 1, ff);
        printf("%x\n", a);
    }
    fprintf(of, "60000\n");
    printf("number^\n");
    for (int k = 1; k <= 60000; k++)
    {
        if (k % 1000 == 0)
        {
            printf("%d\n", k);
        }
        for (int i = 1; i <= 28; i++)
        {
            for (int j = 1; j <= 28; j++)
            {
                fscanf(f, "%c", &c);
                int dd = int(c);
                // printf("size %d %d\n", sizeof(dd), sizeof(c));
                // printf("%4u", c);
                complexnumber tmp(c / 255.0, 0);
                iptm.dt[(i - 1) * 28 + j][1] = tmp;
            }
            // printf("\n");
        }
        fscanf(ff, "%c", &c);
        // printf("%4u\n", c);
        for (int itr = 1; itr <= 10; itr++)
        {
            if (c == itr - 1)
            {
                complexnumber tmp(1, 0);
                optm.dt[itr][1] = tmp;
            }
            else
            {
                complexnumber tmp(0, 0);
                optm.dt[itr][1] = tmp;
            }
        }
        iptm.fprint(of);
        optm.fprint(of);
    }
    fprintf(of, "\n");
    fclose(f);
    fclose(of);
    fclose(ff);
    return 0;
}
