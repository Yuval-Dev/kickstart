void solve() {
	int R, C;
	cin >> R >> C;
	int m = MIN(R,C)-1;
	//(R-i+2)(C-i+2)(i) -> (RCi-Rii-Cii+2Ri+2Ci-4ii+4i+iii)
	int vel = (((m+1)*(m)) / 2) % 1000000007;
	int acc = (((m+1)*(2m+1)*(m)) / 6) % 1000000007;
	int jrk = (vel*vel) % 1000000007;
	cout << ((R*C*vel)-(R*acc)-(C*acc)+(2*R*vel)+(2*R*vel)-(4*acc)+(4*vel)+jrk) % 1000000007;
}
