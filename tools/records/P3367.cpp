#include <iostream>
#include <vector>

template <typename _Ty>
struct Node {
	Node(const _Ty& d) : data(d) {}

	_Ty data;
	int rank = 0;
	Node<_Ty>* p = nullptr;
};

template <typename _Ty>
void make_set(Node<_Ty>* node) {
	node->p = node;
	node->rank = 0;
}

template <typename _Ty>
void __link(Node<_Ty>* lhs, Node<_Ty>* rhs) {
	if (lhs->rank > rhs->rank) {
		rhs->p = lhs;
	} else {
		lhs->p = rhs;
		if (lhs->rank == rhs->rank) {
			rhs->rank++;
		}
	}
}

template <typename _Ty>
void union_set(Node<_Ty>* lhs, Node<_Ty>* rhs) {
	__link(find_set(lhs), find_set(rhs));
}

template <typename _Ty>
Node<_Ty>* find_set(Node<_Ty>* node) {
	if (node != node->p) {
		node = find_set(node->p);
	}
	return node;
}

int main() {
	int n, m;
	int oper, left, right;
	std::cin >> n >> m;
	std::vector<Node<int>*> vec(n, nullptr);

	for (int i = 0; i < n; i++) {
		vec[i] = new Node<int>(i);
		make_set(vec[i]);
	}
	
	for (int i = 0; i < m; i++) {
		std::cin >> oper >> left >> right;
		if (oper == 1) {
			union_set(vec[left - 1], vec[right - 1]);
		} else if (oper == 2) {
			if (find_set(vec[left - 1]) == find_set(vec[right - 1]))
				std::cout << "Y" << std::endl;
			else
				std::cout << "N" << std::endl;
		}
	}


}