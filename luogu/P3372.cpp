#include <iostream>

int n, m;
int arr[500000];
int segment_tree[4 * 500000];
int lazy_tree[4 * 500000];

// construct a segment tree, that is the sum of range.
// range[low, high].
void construct_segment_tree(int low, int high, int root = 0) {
    // leaf node
    if (low == high) {
        segment_tree[root] = arr[low];
        return;
    }

    // construct left child and right child
    int mid = (low + high) / 2;
    construct_segment_tree(low, mid, 2 * root + 1);
    construct_segment_tree(mid + 1, high, 2 * root + 2);

    // construct root
    segment_tree[root] = segment_tree[2 * root + 1] + segment_tree[2 * root + 2];
}

// return the sum of range[q_low, q_high].
int range_sum(int q_low, int q_high, int low, int high, int root = 0) {
    // total overlap
    if (q_low <= low && q_high >= high) {
        return segment_tree[root];
    }

    // no overlap
    if (q_low > high || q_high < low) {
        return 0;
    }

    // partical overlap
    int mid = (low + high) / 2;

    return range_sum(q_low, q_high, low, mid, 2 * root + 1) + range_sum(q_low, q_high, mid + 1, high, 2 * root + 2);
}

// update segment tree, lazy.
// range[start, end].
void update_segment_tree_range_lazy(int start, int end, int value, int low, int high, int root = 0) {
    // make sure all propagation is done at root
    if (lazy_tree[root] != 0) {
        segment_tree[root] += lazy_tree[root] * (high - low + 1);

        // if not a leaf node, propagate to children
        if (low != high) {
            lazy_tree[2 * root + 1] += lazy_tree[root];
            lazy_tree[2 * root + 2] += lazy_tree[root];
        }

        lazy_tree[root] = 0;
    }

    // no overlap
    if (start > high || end < low) {
        return;
    }

    // total overlap
    if (start <= low && end >= high) {
        segment_tree[root] += value * (high - low + 1);
        // std::cout << "value: " << (high - low + 1)*value << "\n";

        // if not a leaf node, propagate to children
        if (low != high) {
            lazy_tree[2 * root + 1] += value;
            lazy_tree[2 * root + 2] += value;
        }

        return;
    }

    // partical overlap
    int mid = (low + high) / 2;
    update_segment_tree_range_lazy(start, end, value, low, mid, 2 * root + 1);
    update_segment_tree_range_lazy(start, end, value, mid + 1, high, 2 * root + 2);

    // after update children, update root node
    segment_tree[root] = segment_tree[2 * root + 1] + segment_tree[2 * root + 2];
}

// return the sum of range[q_low, q_high].
int range_sum_lazy(int q_low, int q_high, int low, int high, int root = 0) {
    // make sure all propagation is done at root
    if (lazy_tree[root] != 0) {
        segment_tree[root] += lazy_tree[root] * (high - low + 1);

        // if not a leaf node, propagate to children
        if (low != high) {
            lazy_tree[2 * root + 1] += lazy_tree[root];
            lazy_tree[2 * root + 2] += lazy_tree[root];
        }

        lazy_tree[root] = 0;
    }

    // total overlap
    if (q_low <= low && q_high >= high) {
        return segment_tree[root];
    }

    // no overlap
    if (q_low > high || q_high < low) {
        return 0;
    }

    // partical overlap
    int mid = (low + high) / 2;

    return range_sum_lazy(q_low, q_high, low, mid, 2 * root + 1) +
           range_sum_lazy(q_low, q_high, mid + 1, high, 2 * root + 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;
    for (int i = 0; i != n; i++) {
        std::cin >> arr[i];
    }

    construct_segment_tree(0, n - 1);

    int op;
    int x, y, k;

    for (int i = 0; i != m; i++) {
        std::cin >> op;

        switch (op) {
        case 1:
            std::cin >> x >> y >> k;

            update_segment_tree_range_lazy(x - 1, y - 1, k, 0, n - 1);
            break;
        case 2:
            std::cin >> x >> y;

            std::cout << range_sum_lazy(x - 1, y - 1, 0, n - 1) << "\n";
            break;
        default:
            break;
        }
    }
}