char addarr[123] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
#define ROW 36*37
void solve() {
	int N;
	cin >> N;
	int * rooms = new int[N];
	for(int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		if(temp.sz==1) {
			rooms[i] = addarr[temp[0]];
		} else {
			rooms[i] = addarr[temp[0]]*36+addarr[temp[1]]+36;
		}
	}
	int * lifts = new int[ROW*ROW];
	memset(lifts, 0xFF, ROW*ROW*8);
	cin >> N;
	for(int i = 0; i < N; i++) {
		int src, dst, spd;
		cin >> src >> dst >> spd;
		if(spd < lifts[rooms[src-1]*ROW+rooms[dst-1]] || lifts[rooms[src-1]*ROW+rooms[dst-1]]==-1) {
			lifts[rooms[src-1]*ROW+rooms[dst-1]] = spd;
		}
	}
	cin >> N;
	for(int i = 0; i < N; i++) {
		int src, dst;
		cin >> src >> dst;
		cout << endl << dsp(lifts, ROW, rooms[src-1], rooms[dst-1]);
	}
		
}
