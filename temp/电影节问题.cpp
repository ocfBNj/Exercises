#include <iostream>
#include <vector>
#include <algorithm>

struct Film {
    int id;
    int start;
    int finish;
};

bool operator<(const Film& lhs, const Film& rhs) {
    return lhs.finish < rhs.finish;
}

void resolve(std::vector<Film>& films) {
    std::sort(films.begin(), films.end());
    int time = 0;

    std::cout << "播放编号为如下的电影: \n";
    for (const Film& film : films) {
        if (film.start > time) {
            time = film.finish;
            std::cout << film.id << " ";
        }
    }
    std::cout.put('\n');
} 

int main() {
    std::vector<Film> films{{1, 1, 4}, {2, 3, 5}, {3, 0, 6}, {4, 5, 7}, {5, 3, 9}, {6, 5, 9}, 
                           {7, 6, 10}, {8, 8, 11}, {9, 8, 12}, {10, 2, 14}, {11, 12, 16}};
    resolve(films);
}