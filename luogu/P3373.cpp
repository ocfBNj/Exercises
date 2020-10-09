#include <algorithm>
#include <iostream>
#include <iterator>

long long n, m, p;
long long arr[500000];
long long segment_tree[4 * 500000];
long long add_tree[4 * 500000];
long long mult_tree[4 * 500000];

// construct a segment tree, that is the sum of range.
// range[low, high].
void construct_segment_tree(long long low, long long high, long long root = 0) {
    // leaf node
    if (low == high) {
        segment_tree[root] = arr[low];
        return;
    }

    // construct left child and right child
    long long mid = (low + high) / 2;
    construct_segment_tree(low, mid, 2 * root + 1);
    construct_segment_tree(mid + 1, high, 2 * root + 2);

    // construct root
    segment_tree[root] = (segment_tree[2 * root + 1] + segment_tree[2 * root + 2]) % p;
}

void make_sure_update(long long low, long long high, long long root) {
    if (mult_tree[root] != 1) {
        segment_tree[root] = (segment_tree[root] * mult_tree[root]) % p;

        // if not a leaf node, propagate to children
        if (low != high) {
            mult_tree[2 * root + 1] = (mult_tree[2 * root + 1] * mult_tree[root]) % p;
            mult_tree[2 * root + 2] = (mult_tree[2 * root + 2] * mult_tree[root]) % p;

            add_tree[2 * root + 1] = (add_tree[2 * root + 1] * mult_tree[root]) % p;
            add_tree[2 * root + 2] = (add_tree[2 * root + 2] * mult_tree[root]) % p;
        }

        mult_tree[root] = 1;
    }

    // make sure all propagation is done at root
    if (add_tree[root] != 0) {
        segment_tree[root] = (segment_tree[root] + add_tree[root] * (high - low + 1)) % p;

        // if not a leaf node, propagate to children
        if (low != high) {
            add_tree[2 * root + 1] = (add_tree[2 * root + 1] + add_tree[root]) % p;
            add_tree[2 * root + 2] = (add_tree[2 * root + 2] + add_tree[root]) % p;
        }

        add_tree[root] = 0;
    }
}

// update segment tree, lazy.
// range[start, end].
void update_add_segment_tree_range_lazy(long long start, long long end, long long value, long long low, long long high,
                                        long long root = 0) {
    make_sure_update(low, high, root);

    // no overlap
    if (start > high || end < low) {
        return;
    }

    // total overlap
    if (start <= low && end >= high) {
        segment_tree[root] = (segment_tree[root] + value * (high - low + 1)) % p;
        // std::cout << "value: " << (high - low + 1)*value << "\n";

        // if not a leaf node, propagate to children
        if (low != high) {
            add_tree[2 * root + 1] = (add_tree[2 * root + 1] + value) % p;
            add_tree[2 * root + 2] = (add_tree[2 * root + 2] + value) % p;
        }

        return;
    }

    // partical overlap
    long long mid = (low + high) / 2;
    update_add_segment_tree_range_lazy(start, end, value, low, mid, 2 * root + 1);
    update_add_segment_tree_range_lazy(start, end, value, mid + 1, high, 2 * root + 2);

    // after update children, update root node
    segment_tree[root] = (segment_tree[2 * root + 1] + segment_tree[2 * root + 2]) % p;
}

// update segment tree, lazy.
// range[start, end].
void update_mult_segment_tree_range_lazy(long long start, long long end, long long value, long long low, long long high,
                                         long long root = 0) {
    make_sure_update(low, high, root);

    // no overlap
    if (start > high || end < low) {
        return;
    }

    // total overlap
    if (start <= low && end >= high) {
        segment_tree[root] = (segment_tree[root] * value) % p;

        // if not a leaf node, propagate to children
        if (low != high) {
            mult_tree[2 * root + 1] = (mult_tree[2 * root + 1] * value) % p;
            mult_tree[2 * root + 2] = (mult_tree[2 * root + 2] * value) % p;

            add_tree[2 * root + 1] = (add_tree[2 * root + 1] * value) % p;
            add_tree[2 * root + 2] = (add_tree[2 * root + 2] * value) % p;
        }

        return;
    }

    // partical overlap
    long long mid = (low + high) / 2;
    update_mult_segment_tree_range_lazy(start, end, value, low, mid, 2 * root + 1);
    update_mult_segment_tree_range_lazy(start, end, value, mid + 1, high, 2 * root + 2);

    // after update children, update root node
    segment_tree[root] = (segment_tree[2 * root + 1] + segment_tree[2 * root + 2]) % p;
}

// return the sum of range[q_low, q_high].
long long range_sum_lazy(long long q_low, long long q_high, long long low, long long high, long long root = 0) {
    make_sure_update(low, high, root);

    // total overlap
    if (q_low <= low && q_high >= high) {
        return segment_tree[root];
    }

    // no overlap
    if (q_low > high || q_high < low) {
        return 0;
    }

    // partical overlap
    long long mid = (low + high) / 2;

    return (range_sum_lazy(q_low, q_high, low, mid, 2 * root + 1) +
           range_sum_lazy(q_low, q_high, mid + 1, high, 2 * root + 2)) % p;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m >> p;
    for (long long i = 0; i != n; i++) {
        std::cin >> arr[i];
    }

    std::fill(std::begin(mult_tree), std::end(mult_tree), 1);
    construct_segment_tree(0, n - 1);

    long long op;
    long long x, y, k;

    for (long long i = 0; i != m; i++) {
        std::cin >> op;

        switch (op) {
        case 1:
            std::cin >> x >> y >> k;

            update_mult_segment_tree_range_lazy(x - 1, y - 1, k, 0, n - 1);
            break;
        case 2:
            std::cin >> x >> y >> k;

            update_add_segment_tree_range_lazy(x - 1, y - 1, k, 0, n - 1);
            break;
        case 3:
            std::cin >> x >> y;

            std::cout << range_sum_lazy(x - 1, y - 1, 0, n - 1) << "\n";
            break;
        default:
            break;
        }
    }
}