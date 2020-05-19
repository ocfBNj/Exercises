#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <utility>

char map[255][255];
char used[255][255]; // 只有1才被标记
int row, col;
int count;
std::map<int, int> result;


void reslove() {
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (!used[i][j] && map[i][j] == '1') {
                count++;
                // 搜索该点
                q.push({i, j});
                used[i][j] = 1;
                int first = 0; // 浮游块的大小
                while (!q.empty()) {
                    auto px = q.front();
                    q.pop();
                    
                    first++;

                    if (px.first - 1 >= 0 && !used[px.first - 1][px.second] 
                            && map[px.first - 1][px.second] == '1') {
                        q.push({px.first - 1, px.second});
                        used[px.first - 1][px.second] = 1;
                    }
                        
                    if (px.first + 1 < row && !used[px.first + 1][px.second] 
                            && map[px.first + 1][px.second] == '1') {
                        q.push({px.first + 1, px.second});
                        used[px.first + 1][px.second] = 1;
                    }

                    if (px.second - 1 >= 0 && !used[px.first][px.second - 1]
                                && map[px.first][px.second - 1] == '1') {
                        q.push({px.first, px.second - 1});
                        used[px.first][px.second - 1] = 1;
                    }

                    if (px.second + 1 < col && !used[px.first][px.second + 1]
                                && map[px.first][px.second + 1] == '1') {
                        q.push({px.first, px.second + 1});
                        used[px.first][px.second + 1] = 1;
                    }
                }

                // 搜索完毕，统计数据
                if (result.find(first) == result.end()) {
                    result.insert({{first, 1}});
                } else {
                    ++result.at(first);
                }
                
            }

        }
    }
}

int main() {
    while (true) {
        std::cin >> row >> col;

        if (!row && !col) {
            break;
        }

        memset(map, 0, sizeof map);
        memset(used, 0, sizeof used);
        count = 0;
        result.clear();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cin >> map[i][j];
            }
        }

        reslove();

        std::cout << count << std::endl;
        for (const auto& item : result) {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }
}    
