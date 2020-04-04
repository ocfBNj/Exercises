#include <iostream>
#include <algorithm>
#include <list>
#include <tuple>
#include <limits>

int m, n;

struct Work {
	int machines[20]{}; // 第n道工序的机器号
	int times[20]{};    // 第n道工序的加工时间

	int j = 1;
	int begin_time = 0;
};

struct Machine {
	std::list<std::tuple<int, int>> spares{{0, std::numeric_limits<int>::max()}}; // 空闲时间片段
	int time = 0;         // 总时间
};

Work works[20];
Machine machines[20];
int sequence[500];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> m >> n;
	for (int i = 1; i <= m * n; i++) {
		std::cin >> sequence[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> works[i].machines[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> works[i].times[j];
		}
	}

	for (int i = 1; i <= n * m; i++) {
		const int j = sequence[i];  // 第j个工件
		const int k = works[j].j++; // 第k道工序
		int& begin_time = works[j].begin_time;   // 这道工序能够开始的最早时间
		// 工作时间
		const int work_time = works[j].times[k];
		// 机器
		Machine& machine = machines[works[j].machines[k]];

		machine.spares.sort([](const std::tuple<int, int>& l, const std::tuple<int, int>& r) {
			return std::get<0>(l) < std::get<0>(r);
		});

		// 找到最靠前的空闲时间
		auto it = std::find_if(machine.spares.begin(), machine.spares.end(),
							   [=](const std::tuple<int, int>& spare) {
			auto [begin, end] = spare;
			// 当前空闲时间总和足够，并且工作能正常结束
			return end - begin >= work_time && (begin_time < begin || begin_time + work_time <= end);
		});

		// 插入
		auto [begin, end] = *it;
		int left = begin;
		int right = end;

		if (begin < begin_time) begin = begin_time;

		end = begin + work_time;

		if (end > machine.time) {
			machine.time = end;
		}

		begin_time = end;

		if (begin - left > 0) machine.spares.push_back({left, begin});
		if (right - end > 0) machine.spares.push_back({end, right});

		machine.spares.erase(it);
	}

	std::cout << std::max_element(machines + 1, machines + m + 1, [](const Machine& l, const Machine& r) {
		return l.time < r.time; })->time << "\n";
}
