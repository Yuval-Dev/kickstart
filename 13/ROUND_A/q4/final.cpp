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
		cout << "Case #" << case_num << ": ";
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
void solve() {
	int size;
	cin >> size;
	string * maze = new string[size+2];
	maze[0] = "##";
	maze[size+1] = "##";
	for(int i = 1; i < size+1; i++) {
		cin >> maze[i];
		maze[i] = "#" + maze[i] + "#";
		maze[0] += "#";
		maze[size+1] += "#";
	}
	int a,b,c,d;
	if(maze[2][1]=='#' and maze[1][2]=='#') {
		cin >> a >> b >> c >> d;
		cout << "Edison ran out of energy.";
		return;
	}
	int x, y, tx, ty;
	cin >> x >> y >> tx >> ty;
	int steps = 0;
	string moves = "";
	char dir = 'S';
	while((not (x==tx and y==ty)) and steps<10001) {
		if(dir=='E') {
			if(maze[x+1][y]=='#') {
				dir = 'S';
			} else {
				x++;
				dir = 'N';
				moves += 'S';
				steps++;
			}
		}
		if(dir=='S') {
			if(maze[x][y-1]=='#') {
				dir = 'W';
			} else {
				y--;
				dir = 'E';
				moves += 'W';
				steps++;
			}
		}
		if(dir=='W') {
			if(maze[x-1][y]=='#') {
				dir = 'N';
			} else {
				x--;
				dir = 'S';
				moves += 'N';
				steps++;
			}
		}
		if(dir=='N') {
			if(maze[x][y+1]=='#') {
				dir = 'E';
			} else {
				y++;
				dir = 'W';
				moves += 'E';
				steps++;
			}
		}

	}
	if(steps<10001) {
		cout << steps << endl << moves;
	} else {
		cout << "Edison ran out of energy.";
	}
}
