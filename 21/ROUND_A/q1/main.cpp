void solve() {
	string s;
	int a,n;
	cin >> a >> n >> s;
	for(int i = 0; i < a/2; i++) {
		if(s[i]!=s[a-i-1]) {
			n--;
		}
	}
	cout << ABS(n);
}
