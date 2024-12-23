#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "text.c"
#include "print.c"
#include "random.c"
#include "F.c"
#include "compute.c"



int main() {
    cls();
    int x = 34;
    int y[Y] = {0};
    int d;
    int p[F_len];
    int n[F_len];
    int M[Y][F_len] = {0};
    int T[Y][X];
    int TC[Y][X];
    int S[Y][X];
    int SC[Y][X];
    int F[Y][F_len];
    int chi_S[Y][F_len];
    int chi_T[Y][F_len];
    for (int i = 0; i < F_len; i++) n[i] = i;
    
    create_perm(p, F_len);
    //print_perm(p, F_len);
    printf("\n");
    create_M(M, p);
    //print_M(M);printf("\n\n");
    for (int i = 0; i < Y; i++)  create_T_set(T[i], M, i);
    for (int i = 0; i < Y; i++)  create_comp(T[i], TC[i]);
    for (int i = 0; i < Y; i++)  disjoint(T[i],TC[i]);
    for (int i = 0; i < Y; i++)  create_S_set(S[i]);
    for (int i = 0; i < Y; i++)  create_comp(S[i], SC[i]);
    for (int i = 0; i < Y; i++)  disjoint(S[i],SC[i]);
    for (int i = 0; i < Y; i++)  create_chi(S[i], chi_S[i]);
    for (int i = 0; i < Y; i++)  create_chi(T[i], chi_T[i]);
    for (int i = 0; i < Y; i++)  print_chi(chi_T[i]);
    for (int i = 0; i < Y; i++)  print_chi(chi_S[i]);


    // for (int i = 0; i < Y; i++) { print_perm(T[i], X); printf("\n\n");}
    // for (int i = 0; i < Y; i++) { print_perm(S[i], X); printf("\n\n");}
    //create_TC_set(T[0], TC[0]);
    // print_perm(T[0], X); printf("\n\n");
    // print_perm(TC[0], X); printf("\n\n");
    // print_perm(S[0], X); printf("\n\n");
    // print_perm(SC[0], X); printf("\n\n");
    for (int i = 0; i < Y; i++) create_F(T[i], TC[i], S[i], SC[i], F[i]);
    for (x = 0; x < 256; x++) {
        enc( F , x , y);
        d = dec(chi_S, M, y);
        print_enc(x,y);
        print_chi_code(chi_S, y);
        printf("decodes to %d \n", d);
        if (x != d) printf("\nERROR\n");
        printf("\n");
    }

    //print_F(F[0]);


    
}
      