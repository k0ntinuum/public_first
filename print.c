void print_bit(int b) { b == 0 ? printf("O") : printf("|"); }
void print_v(int* v, int L) { for (int i = 0; i < L; i++) print_bit(v[i]); }
void print_key(int k[pk_rows][pk_cols]) {
    for (int i = 0; i < pk_rows; i++)  { print_v(k[i], pk_cols); printf("\n"); }
}
void print_M(int k[Y][F_len]) {
    for (int i = 0; i < Y; i++)  { print_v(k[i], F_len); printf("\n"); }
}
void print_perm(int* p, int L) {
    for (int i = 0; i < L; i++) printf("%03d ", p[i]);
}
void print_F(int F[F_len]) {
    for (int i = 0 ; i < F_len; i++)
        printf("F(%03d) = %03d\n", i, F[i]);
}
void print_enc(int x, int y[Y]) {
    printf("E  %03d    =    ", x);
    for (int i = 0 ; i < Y; i++) printf("%03d   ", y[i]);
    printf("\n");
}
void print_chi(int chi[F_len]) {
    for (int i = 0; i < F_len; i++) {
        if (i >0 && i % 64 == 0 ) printf("\n");
        print_bit(chi[i]);
    }
    printf("\n\n");
}

void print_chi_code(int chi[Y][F_len], int y[Y]) {
    printf("chi       =    ");
    printf("\n");
}
void val_print(int* v, int L) {
    for (int i = 0; i < L; i++) printf("%d ", v[i]);
    printf("\n");

}
// void  val_print_T_matrix(int k[Y][F_len]) {
//     for (int i = 0; i < Y; i++) {
//         for (int j = 0; j < F_len; j++)  printf("%d", k[i][j]);
//         printf("\n");
//     }
// }



