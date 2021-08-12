#define inv cout << "No"; return;
#define inv2 cout << "No2"; return;
#define inv3 cout << "No3"; return;
#define inv4 cout << "No4"; return;
void solve() {
	int size;
	cin >> size;
	bool * testarr = new bool[size*size];
	int * board = new int[size*size*size*size];
	for(int i = 0; i < size*size*size*size; i++) {
		int tmp;
		cin >> tmp;
		board[i]= tmp;
	}
	for(int i = 0; i < size*size; i++) {
		memset(testarr, false, size*size);
		for(int j  = 0; j < size*size; j++) {
			int cur = board[i*(size*size)+j]-1;
			if(cur > size*size-1) {
						inv;
					}
					if(cur < 0) {
						inv;
					}
					if(testarr[cur]) {
						inv;
					}
					testarr[cur] = true;
		}
		memset(testarr, false, size*size);
		for(int j  = 0; j < size*size; j++) {
			int cur = board[j*(size*size)+i]-1;
			if(cur > size*size-1) {
						inv;
					}
					if(cur < 0) {
						inv;
					}
					if(testarr[cur]) {
						inv;
					}
					testarr[cur] = true;
		}
	}
	for(int a = 0; a < size; a++) {
		for(int b = 0; b < size; b++) {
			memset(testarr, false, size*size);
			for(int c = 0; c < size; c++) {
				for(int d = 0; d < size; d++) {
					int cur = board[(a*size+c)*(size*size)+b*size+d]-1;
					if(cur > size*size-1) {
						inv;
					}
					if(cur < 0) {
						inv;
					}
					if(testarr[cur]) {
						inv;
					}
					testarr[cur] = true;
				}
			}
		}
	}
	cout << "Yes";
}
