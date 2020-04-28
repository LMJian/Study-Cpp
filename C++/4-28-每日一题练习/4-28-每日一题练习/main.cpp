/*// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string> arr;
		arr.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr.begin(), arr.end(), [](const string& left, const string& right) {
			return strcmp(left.c_str(), right.c_str()) < 0;
		});
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i + 1].find(arr[i], 0) != 0)
				cout << "mkdir -p " << arr[i] << endl;
		}
		cout << "mkdir -p " << arr[n - 1] << endl;
	}
	return 0;
}*/

#include<iostream>
#include<vector>
using namespace std;

int n, m, k;
int x, y;
vector<vector<char>> arr;

void dfs(int x, int y, bool key, int& a, int& b) {
	if (x == n && y == m) {
		++b;
		if (key)
			++a;
		return;
	}
	if (arr[x][y] == -1)
		key = true;
	if (x + 1 <= n)
		dfs(x + 1, y, key, a, b);
	if (y + 1 <= m)
		dfs(x, y + 1, key, a, b);
}
int main() {
	while (cin >> n >> m >> k) {
		arr.clear();
		arr.resize(n + 1, vector<char>(m + 1, 0));
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			arr[x][y] = -1;
		}
		int a = 0;
		int b = 0;
		dfs(1, 1, false, a, b);
		printf("%.2f\n", 1.0*a / b);
	}
	return 0;
}