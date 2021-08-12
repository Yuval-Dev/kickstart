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
