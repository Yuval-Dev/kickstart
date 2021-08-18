void solve() {
	int N, P;
	cin >> N >> P;
	vt<string> v;
	for(int i = 0; i < P; i++) {
		string tmp;
		cin >> tmp;
		v.pb(tmp);
	}
	for(int i = 0; i < v.sz; i++) {
		for(string& s : v) {
			if(s.sz<v[i].sz) {
				if(v[i].substr(0,s.sz)==s) {
					v.erase(v.begin()+i);
					i--;
					break;
				}
			}
		}
	}
	int n = pow(2,N);
	for(string & s : v) {
		n -= pow(2,N-s.sz);
	}
	cout << n;
}
