
void create_M(int T_mat[Y][F_len], int perm[F_len]) {
	int v;
	for (int c = 0; c < F_len; c++) {
		v = perm[c];
		for (int r = 0; r < Y; r++) {
			T_mat[r][c] = v / val[r];
			v -= T_mat[r][c] * val[r];
		}
	}
}

// int val_T_mat_col(int T[Y][F_len], int c) {
// 	int v = 0;
// 	for (int r = 0; r < Y; r++) v += T[r][c] * val[r];
// 	return v;

// }
void create_T_set(int T[X], int T_mat[Y][F_len], int r ) {
	int T_count = 0;
	for (int i = 0; i < F_len && T_count < X; i++ )
		if (T_mat[r][i]) T[T_count++] = i;
}
void create_comp(int T[X], int TC[X]) {
	int flag = 0;
	int TC_count = 0;
	for (int i = 0; i < F_len && TC_count < X; i++) {
		flag = 0;
		for (int j = 0; j < X; j++) if (T[j] == i) flag = 1;
		if (flag == 0) TC[TC_count++] = i;
	}
}

void create_S_set(int S[X]) {
	int p[F_len];
	create_perm(p, F_len);
	for (int i = 0; i < X; i++) S[i] = p[i];
}

void create_chi(int U[X], int chi[F_len]) {
	for (int i = 0; i < F_len; i++) chi[i] = 0;
	for (int i = 0; i < X; i++) chi[U[i]] = 1;
}

void disjoint(int T[X], int S[X]) {
	int m[F_len] = {0};
	for (int i = 0; i < X; i++) m[S[i]] += 1;
	for (int i = 0; i < X; i++) m[T[i]] += 1;
	for (int i = 0; i < F_len; i++) if (m[i] > 1) printf("overlap at %d\n", i);
}


