#define offset 0x100000000
void  solve() {
	int M, N;
	cin >> M >> N;
	int nx, ny, ex, ey;
	cin >> ny >> nx >> ey >> ex;
	int * maze = new int[M*N];
	for(int i = 0; i < N*M; i++) {
		int tmp;
		cin >> tmp;
		maze[i] = tmp;
	}
	char * found = new char[N*M];
	memset(found, false, N*M);
	int * dist = new int[N*M];
	memset(dist, 0xFF, N*M*8);
	dist[ny*N+nx] = offset - maze[ny*N+nx];
	while(!found[ey*N+ex]) {
		int md = _dsp_min(dist,N*M,found);
		if(md==-1) {
			cout << "Mission Impossible.";
			return;
		}
		found[md] = true;
		if(md%N>0 and !found[md-1] and maze[md-1]!=-1 and (dist[md]+offset-maze[md-1]<dist[md-1] || dist[md-1]==-1)) {
			dist[md-1] = dist[md]+offset-maze[md-1];
		}
		if(md%N<N-1 and !found[md+1] and maze[md+1]!=-1 and (dist[md]+offset-maze[md+1]<dist[md+1] || dist[md+1]==-1)) {
			dist[md+1] = dist[md]+offset-maze[md+1];
		}
		if(md/N>0 and !found[md-N] and maze[md-N]!=-1 and (dist[md]+offset-maze[md-N]<dist[md-N] || dist[md-N]==-1)) {
			dist[md-N] = dist[md]+offset-maze[md-N];
		}
		if(md/N<M-1 and !found[md+N] and maze[md+N]!=-1 and (dist[md]+offset-maze[md+N]<dist[md+N] || dist[md+N]==-1)) {
			dist[md+N] = dist[md]+offset-maze[md+N];
		}
	}
	cout << 0-(dist[ey*N+ex]%offset)+offset;
}
