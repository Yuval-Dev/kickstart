void solve() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	int num = 0;
	for(int i = 0; i < (N+1)/2; i++) {
		num += (s[i]-'0');
	}
	int max = num;
	for(int i = 0; i < (N)/2; i++) {
		num -= (s[i]-'0');
		num += (s[i+(N+1)/2]-'0');
		if(num>max) {
			max = num;
		}
	}
	cout << max;
}
