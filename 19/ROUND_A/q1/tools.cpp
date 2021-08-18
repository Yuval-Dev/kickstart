/* 
 * Yuval's default header for competitive coding related stuff
 * contains basic macro definitions for ease of use, debug related code,
 * and some algorithms.
 * 
 * This isn't meant to be some static, unchangable file to be used as a header.
 * in fact, my goal is to make it in a way that it provides a reasonable
 * framework to many useful functions that arent included in
 * standard libraries such that I can modify them as needed to fit
 * with the program.
 *
 * I assume this isn't considered cheating since everything in this file has been written solely by me
 * it just acts as a basis for the program that includes input and output that saves me
 * just a couple of minutes in most cases.
 *
 * Name: Yuval Eli Vaknin
 * Email: yuvalvaknin2004@gmail.com
 * Github: Yuval-Dev
 * Last update: August 12 2021
 */

//the file below is a header that includes most of the standard headers. Very useful so that I don't need to include every file under the sun.
#include <bits/stdc++.h>
using namespace std;

//definitions for ease of use
#define a2n(alpha) ((int)((alpha)-'a'))
#define n2a(numeric) ((char)((char)(numeric)+'a'))
#define vt vector
#define pb push_back
#define sz size()
#define sort_increasing(vector) sort(vector.begin(), vector.end())
#define sort_decreasing(vector) sort(vector.begin(), vector.end(), greater<int>())
#define atoi atoll
#define MAX(a,b) ((b)>(a) ? (b) : (a))
#define MIN(a,b) ((b)<(a) ? (b) : (a))
#define ABS(a) ((a)>0 ? (a) : (0-(a)))
#define POS(a) ((a)>0 ? (a) : 0)

void solve(void);
long long T;
long long case_num;
int main(int argc, char ** argv) {
#define int long long
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifdef DEBUG_MODE
	//in the case of debugging, the input comes from a file, and the output is redirected to another file
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

//this function takes an integer that is to be factored, and returns the number of prime factors the number has, which isnt the same as number of factors
//for example, 1 returns 1, because it is divisible only by itself, prime numbers return 2 because they are divisible by themselves and 1
//and as an example number, 12 returns 5, because it is divisible by 1,2,2,3,12, notice how 2 is listed twice there and 6 is not listed at all,
//thats because this function finds the prime factorization count, not the normal factorization.
int _prime_factors(int num) {
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

//simple function to split a string. takes a string, and a delimiter to split the string by, and returns a vector of the fragments of that string
//in the case that it starts or ends with the delimiter, or has the delimiter repeat consecutively, there will be empty strings in the vector
vt<string> _split(string str, string delim) {
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

//helper function for the next function
int _dsp_min(int * list, int size, char * visited) {
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

//stands for dijkstra shortest path. the function takes an array of weights, which is actually a 2d array condensed into a 1d array 
//(you could imagine how that works, with what would have been weights[x][y] turning into weights[x*row_length+y])
//an integer for size, an integer for the source intex, and an integer for the destination index, and returns an integer representing
//the shortest path from the source to the destination. In the weights array, each weights[i*size+j] has the value representing
//the time taken to get from i to j, (not reversible, this is a one way thing that doesnt apply to the distance from j to i), where a value -1 means there is no path between them.
int _dsp(int * weights, int size, int src, int dst) {
	char * visited = new char[size];
	int * dist = new int[size];
	memset(dist, 0xFF, size*8);
	memset(visited, false, size);
	dist[src] = 0;
	while(!visited[dst]) {
		int mindist = _dsp_min(dist, size, visited);
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
	delete[] visited;
	int ret = dist[dst];
	delete[] dist;
	return ret;
}

