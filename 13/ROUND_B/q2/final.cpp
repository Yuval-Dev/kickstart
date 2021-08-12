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
	cout << "Case #1:\n";
	solve();
	/*cin >> T;
	for(case_num = 1; case_num <= T; ++case_num) {
		cout << "Case #" << case_num << ": ";
		solve();
		cout << endl;
	}*/
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
