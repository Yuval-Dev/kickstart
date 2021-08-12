/* 
 * Yuval's default header for competitive coding related stuff
 * contains basic macro definitions for ease of use, debug related code,
 * and some algorithms.
 * Last updated: August 12 2021
 */
#include <bits/stdc++.h>
using namespace std;
#define a2n(alpha) ((int)((alpha)-'a'))
#define n2a(numeric) ((char)((char)(numeric)+'a'))
#define vt vector
#define pb push_back
#define sz size()
#define sort_increasing(vector) sort(vector.begin(), vector.end())
#define sort_decreasing(vector) sort(vector.begin(), vector.end(), greater<int>())
#define atoi atoll
#define DBM(num) cout << "debug message #" << num; printf("debug message #%d",num);
void solve(void);
long long T;
long long case_num;
int main(int argc, char ** argv) {
#define int long long
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifdef DEBUG_MODE
	std::ifstream in("input.txt"); std::cin.rdbuf(in.rdbuf());
	std::ofstream ofs; ofs.open("results.txt", std::ofstream::out | std::ofstream::trunc); ofs.close();
	std::ofstream out("results.txt"); std::cout.rdbuf(out.rdbuf());
#endif
	cin >> T;
	for(case_num = 1; case_num <= T; ++case_num) {
		cout << "Case #" << case_num << ":";
		solve();
		cout << endl;
	}
	return 0;
}
int prime_factors(int num) {
	int facts = 1;
	for(int i = 2; num!=1; i++) {
		if(num%i==0) {
			num /= i;
			i = 1;
			facts++;
		}
	}
	return facts;
}
vt<string> split(string str, string delim) {
	size_t pos = 0;
	string token;
	vt<string> ret;
	while ((pos = str.find(delim)) != string::npos) {
		token = str.substr(0, pos);
		ret.pb(token);
		str.erase(0, pos + delim.length());
	}
	return ret;
}
static int min(int * list, int size, char * visited) {
	int smallest = 0x7FFFFFFFFFFFFFFF;
	int index = -1;
	for(int i = 0; i < size; i++) {
		if(list[i]==0xFFFFFFFFFFFFFFFF || visited[i]) {
			continue;
		}
		if(list[i]<smallest) {
			smallest = list[i];
			index = i;
		}
	}
	return index;
}
int dsp(int * weights, int size, int src, int dst) {
	char * visited = new char[size];
	int * dist = new int[size];
	memset(dist, 0xFF, size*8);
	memset(visited, false, size);
	dist[src] = 0;
	while(!visited[dst]) {
		int mindist = min(dist, size, visited);
		if(mindist==-1) {
			return -1;
		}
		visited[mindist] = true;
		for(int i = 0; i < size; i++) {
			if(weights[mindist*size+i]!=0xFFFFFFFFFFFFFFFF and (dist[i] > dist[mindist]+weights[mindist*size+i] || dist[i]==-1)) {
				dist[i] = dist[mindist]+weights[mindist*size+i];
			}
		}
	}
	return dist[dst];
}	
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
