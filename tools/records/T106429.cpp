#include <iostream>
#include <algorithm>

#define N 64

int sticks[N];
bool used[N];
int n, len;
int des_len;

void dfs(int cur_len, int last_sticks, int last_sticks_len, int begin) {
	if (last_sticks == 0 || last_sticks_len == des_len) {
		std::cout << des_len << std::endl;
		exit(0);
	} else {
		if (des_len == cur_len) {
			dfs(0, last_sticks, last_sticks_len, 0);
		} else {
			if (cur_len > des_len || last_sticks_len < des_len - cur_len) return;
			for (int i = begin; i < n; i++) {
				if (!used[i]) {
					used[i] = true;
					dfs(cur_len + sticks[i], last_sticks - 1,
						last_sticks_len - sticks[i], begin + 1);
					used[i] = false;

					if (sticks[i] == des_len - cur_len || des_len == des_len - cur_len) return;
					while (i + 1 < n && sticks[i + 1] == sticks[i]) i++;
				}
			}
		}
	}
}

int main() {
	std::cin >> n;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> len;
		sticks[i] = len;
		sum += len;
	}

	std::sort(sticks, sticks + n, [](int l, int r) {
		return r < l;
		});

	des_len = sticks[0];
	while (1) {
		if (sum % des_len == 0) {
			dfs(0, n, sum, 0);
		}
		des_len++;
	}

}
