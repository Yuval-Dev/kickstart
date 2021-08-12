void solve() {
	int N;
	cin >> N;
	vt<int> vOdd;
	vt<int> vEven;
	bool * parity = new bool[N];
	for(int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if(tmp%2==0) {
			vEven.pb(tmp);
			parity[i] = false;
		} else {
			vOdd.pb(tmp);
			parity[i] = true;
		}
	}
	sort(vOdd.begin(),vOdd.end(),greater<int>());
	sort(vEven.begin(),vEven.end());
	for(int i = 0; i < N; i++) {
		if(parity[i]) {
			cout << vOdd.back();
			vOdd.pop_back();
		} else {
			cout << vEven.back();
			vEven.pop_back();
		}
		if(i<N-1) {
			cout << " ";
		}
	}
	delete[] parity;
}
