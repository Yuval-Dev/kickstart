void solve() {
	int r,c,s = 0;
	cin >> r >> c;
	vt<int> * rows = new vt<int>[r];
	for(int i = 0; i < r; i++) {
		rows[i] = vt<int>();
		for(int j = 0; j < c; j++) {
			int t;
			cin >> t;
			rows[i].pb(t);
		}
	}
	bool exit = true;
	while(exit) {
		bool check = false;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				vt<int> tc;
				if(i>0) {
					tc.pb(i-1);
					tc.pb(j);
				}
				if(i<r-1) {
					tc.pb(i+1);
					tc.pb(j);
				}
				if(j>0) {
					tc.pb(i);
					tc.pb(j-1);
				}
				if(j<c-1) {
					tc.pb(i);
					tc.pb(j+1);
				}
				for(int e = 0; e < tc.sz/2; e++) {
					int tmp1 = rows[tc[e*2]][tc[e*2+1]]-1;
					if(tmp1>rows[i][j]) {
						check = true;
						s += tmp1-rows[i][j];
						rows[i][j] = tmp1;
					}
				}
			}
		}
		if(!check) {
			exit = false;
		}
	}
	cout << s;
}
