void solve() {
	int N, P;
	cin >> N >> P;
	vt<int> v;
	for(int i = 0; i  < N; i++) {
		int tmp;
		cin >> tmp;
		v.pb(tmp);
	}
	sort_increasing(v);
	int value = 0;
	for(int i = 0; i < P-1; i++) {
		value += v[P-1]-v[i];
	}
	int best_value = value;
	for(int i = 1; i < N-P+1; i++) {
		value = value - (v[i+P-2]-v[i-1]) + (P-1)*(v[i+P-1]-v[i+P-2]);
		if(value<best_value) {
			best_value = value;
		}
	}
	cout << best_value;
}
