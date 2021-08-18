void solve() {
	int N, K, S;
	cin >> N >> K >> S;
	cout << min(K-S+N-S,N)+K;
}
