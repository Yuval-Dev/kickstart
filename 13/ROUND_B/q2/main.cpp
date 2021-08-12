void solve() {
	string tmp;
	getline(cin, tmp);
	bool fslash = false;
	bool ast = false;
	int cval = 0;
	bool exit = false;
	bool empt = false;
	while(!exit) {
		if(tmp.sz==0) {
			if(empt) {
				exit = true;
			}
			empt = true;
		} else {
			empt = false;
		}
		for(int i = 0; i < tmp.sz; i++) {
			char c = tmp[i];
			if(cval) {
				if(c=='*') {
					if(fslash) {
						cval++;
						fslash = false;
					} else {
						ast = true;
					}
				} else if(c=='/') {
					if(ast) {
						cval--;
						ast = false;
					} else {
						fslash = true;
					}
				} else {
					ast = false;
					fslash = false;
				}
			} else {
				if(fslash) {
					if(c=='*') {
						cval++;
						fslash = false;
					} else {
						if(c=='/') {
							cout << c;
						} else {
							cout << "/" << c;
							fslash = false;
						}
					}
				} else if(c=='/') {
					fslash = true;
				} else {
					cout << c;
				}
			}
		}
		if(cval==0) {
			if(fslash) {
				cout << "/";
				fslash = false;
			}
			if(ast) {
				cout << "*";
				ast = false;
			}
			cout << endl;
		}
		getline(cin, tmp);
	}
}
