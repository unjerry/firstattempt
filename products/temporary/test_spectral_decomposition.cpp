#include "field_matrix.h"
#include "field_matrix_algorithm.h"
#include "complexnumber.h"
#include <vector>

field_matrix<complexnumber> M, N, Q, L, U, S, W, IN;
field_polynomial<complexnumber> P;
std::vector<complexnumber> V;

FILE *f;

int main()
{
    f = fopen("test_spectral_decomposition.in", "rb");
    M.fscan(f);
    M.print();
    N.fscan(f);
    N.print();
    P.fscan(f);
    P.print();
    printf("\n");
    fclose(f);

    P = character_polynomial(M);
    P.print();
    printf("\n");
    V = factorization(P);
    for (int i = 0; i < V.size(); i++)
    {
        V[i].print();
        printf("\n");
    }

    /*
    spectral_decomposition(M, Q, L);
    (Q * transpose(Q)).print();
    Q.print();
    transpose(Q).print();
    L.print();
    (Q * L * transpose(Q)).print();
    determinant(M).print();
    printf("\n");
    determinant(Q).print();

    singular_value_decomposition(N, U, S, W);
    U.print();
    S.print();
    W.print();
    (U * S * transpose(W)).print();

        N.print();
        IN = general_inverse(N);
        // IN.print();
        //(IN * N).print();
        //(N * IN).print();

        V = factorization(P);
        for (int i = 0; i < V.size(); i++)
        {
            V[i].print();
        }

    */

    return 0;
}
