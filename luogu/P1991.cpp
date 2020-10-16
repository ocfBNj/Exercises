#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

struct point_t {
    double x, y;
};

struct edge_t {
    int u, v;
    double disteance;
};

int disjoint_set[505];
point_t points[505];
std::vector<edge_t> edges;

int p, s;
double res = std::numeric_limits<double>::min();

void make_set(int i) {
    disjoint_set[i] = i;
}

int find_set(int i) {
    if (disjoint_set[i] != i) {
        disjoint_set[i] = find_set(disjoint_set[i]);
    }

    return disjoint_set[i];
}

void union_set(int lhs, int rhs) {
    disjoint_set[find_set(lhs)] = find_set(rhs);
}

double distance(int i, int j) {
    const point_t& p1 = points[i];
    const point_t& p2 = points[j];

    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void resolve() {
    for (int i = 1; i <= p; i++) {
        make_set(i);
    }

    for (int i = 1; i <= p; i++) {
        for (int j = i + 1; j <= p; j++) {
            edges.emplace_back(edge_t{i, j, distance(i, j)});
        }
    }

    std::sort(edges.begin(), edges.end(),
              [](const edge_t& l, const edge_t& r) { return l.disteance < r.disteance; });

    int count = p - s;
    auto it = edges.cbegin();

    while (count) {
        const auto& [u, v, distance] = *it++;
        if (find_set(u) != find_set(v)) {
            union_set(u, v);
            res = std::max(res, distance);
            count--;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> s >> p;
    for (int i = 1; i <= p; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    resolve();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << res << "\n";
}