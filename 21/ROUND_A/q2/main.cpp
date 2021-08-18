int f(int a, int b) {
	return POS(MIN((a/2)-1,b-1)) + POS(MIN(a-1,(b/2)-1));
}
void solve() {
	int r,c,t,s=0;
	cin >> r >> c;
	int ** grid = new int*[r];
	for(int i = 0; i < r; i++) {
		int * row = new int[c];
		for(int j = 0; j < c; j++) {
			cin >> t;
			row[j] = t;
		}
		grid[i] = row;
	}
	vt<int> points;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(!grid[i][j]) {
				continue;
			}
			int ia = i+1, ib = i-1, ja = j+1, jb = j-1;
			while(ia<r and grid[ia][j]) { ia++;}
			while(ja<c and grid[i][ja]) { ja++;}
			while(ib>=0 and grid[ib][j]){ ib--;}
			while(jb>=0 and grid[i][jb]){ jb--;}
			ia-=i;ib=i-ib;ja-=j;jb=j-jb;
			//printf("(%d %d %d %d)",ia,ib,ja,jb);
			s += f(ia,ja) + f(ib,jb) + f(ia,jb) + f(ib,ja);
		}
	}
	cout << s;
}

//1,1:0
//2,2:0
//3,3:0
//4,4:2
//5,5:2
//6,6:4
//1:n:0
//2,2:0
//2,3:0
//2,4:1
//2,5:1
//2,6:1
//3,4:1
//3,5:1
//3,6:2
//3,9:2
//4,8:4
//5,7:3
//6,6:4
//
