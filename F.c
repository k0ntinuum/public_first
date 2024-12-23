void create_F( int T[X],int TC[X],int S[X],int SC[X], int F[F_len] ) {
    int T_to_S[X] = {0};
    int TC_to_SC[X] = {0};
    create_perm(T_to_S, X);
    create_perm(TC_to_SC, X);
    for (int i = 0; i < X; i++) F[T[i]] = S[T_to_S[i]];
    for (int i = 0; i < X; i++) F[TC[i]] = SC[T_to_S[i]];
}

void enc(int F[Y][F_len], int x, int y[Y]) {
    for (int i = 0; i < Y; i++) y[i] = F[i][x];
}

int dec(int chi_S[X][F_len], int M[Y][F_len],  int y[X] ) {
    int code[Y];int fail_flag;
    for (int i = 0 ; i < Y; i++) code[i] =  chi_S[i][y[i]];
    for (int c = 0; c < F_len; c++) {
        fail_flag = 0;
	    for (int r = 0; r < Y; r++) if ( code[r] != M[r][c] ) fail_flag = 1;
        if (fail_flag == 0) return c;
	}
    printf("\n\ncould not invert\n\n");
    return -1;
}