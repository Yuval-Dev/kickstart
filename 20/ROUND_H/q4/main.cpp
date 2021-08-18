void solve() {
	int N, K;
	cin >> N >> K;
	vt<string> names;
	int * weights = new int[26*26];
	memset(weights, 0xFF, 26*26*8);
	for(int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		names.pb(tmp);
		for(char& c : tmp) {
			for(char& d : tmp) {
				weights[(c-'A')*26+(d-'A')] = 1;
			}
		}
	}
	for(int i = 0; i < K; i++) {
		int smallest = 0x7FFFFFFFFFFFFFFF;
		int src, dst;
		cin >> src >> dst;
		for(char& s : names[src-1]) {
			for(char& d : names[dst-1]) {
				int tmp = _dsp(weights, 26, s-'A', d-'A');
				if(tmp < smallest) {
					smallest = tmp;
				}
			}
		}
		cout << ((smallest+1) ? (smallest + 2) : -1);
		if(i!=K-1) {
			cout << " ";
		}
	}
}
