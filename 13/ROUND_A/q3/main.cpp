void solve_forward() {
	unsigned int index;
	cin >> index;
	unsigned int p=1,q=1;
	unsigned int i = 64;
	bool started = false;
	while(i--) {
		if(started) {
			if((index>>i)&1==1) {
				p += q;
			} else {
				q += p;
			}
		}
		if((index>>i)&1==1) {
			started = true;
		}
	}
	cout << p << " " << q;
}
void solve_backward() {
	unsigned int p, q;
	cin >> p >> q;
	unsigned int index = 0;
	unsigned int power = 1;
	while(p>1 or q>1) {
		if(p>q) {
			p -= q;
			index += power;
		} else {
			q -= p;
		}
		power *= 2;
	}
	cout << power+index;
}
void solve() {
	int num;
	cin >> num;
	if(num==1) {
		solve_forward();
	} else {
		solve_backward();
	}
}
