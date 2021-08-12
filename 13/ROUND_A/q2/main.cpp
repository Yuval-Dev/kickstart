void solve2(string);
void solve() {
	char * names[20] = {"zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","","double ","triple ","quadruple ","quintuple ","sextuple ","septuple ","octuple ","nonuple ","decuple "};
	string num, fmt;
	cin >> num >> fmt;
	vt<string> fmt_nums = split(fmt, "-");
	int index = 0;
	for(int i = 0; i < fmt_nums.sz; i++) {
		solve2(num.substr(index,stoi(fmt_nums[i])));
		cout << " ";
		index += stoi(fmt_nums[i]);
	}
	solve2(num.substr(index,num.sz-index));
}
void solve2(string str) {
	char * names[20] = {"zero","one","two","three","four","five","six","seven","eight","nine","","double ","triple ","quadruple ","quintuple ","sextuple ","septuple ","octuple ","nonuple ","decuple "};
	int index = 0;
	char digit;
	int occ = 0;
	while(index<str.sz) {
		digit = str[index];
		while(index<str.sz && str[++index]==digit) {
			occ++;
		}
		if(occ>9) {
			for(int i = 0; i <= occ; i++) {
				cout << names[digit-'0'] << " ";
			}
		} else {
			cout << names[occ+10] << names[digit-'0'];
			if(index<str.sz) {
				cout << " ";
			}
		}
		occ = 0;
	}
}
