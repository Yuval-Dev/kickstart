void solve() {
	int N;
	cin >> N;
	int sum = 0;
	int power = 1;
	int * arr = new int[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < N; i++) {
		sum += arr[i]*power;
		sum -= arr[N-i-1]*power;
		power = 1000000007 + (power*2) % 1000000007;
	}
	delete[] arr;
	cout << ((sum % 1000000007) + 1000000007) % 1000000007;
}
//12345
//1,2,3,4,5
//12,13,14,15
//23,24,25
//34,35
//45
//123,124,125
//134,135
//145
//234,235
//245
//345
