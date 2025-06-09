#include <bits/stdc++.h>

using namespace std;

struct Node {
	int next[26];
	bool end;

	Node() {
		for (int i = 0; i < 26; i++) {
			next[i] = 0;
		}
		end = false;
	}
};

struct Trie {
	int cnt;
	vector<Node> trie;
	vector<int> root;

	Trie() : cnt(0) { root.push_back(new_node()); }

	int new_node() {
		if (cnt >= trie.size())
			trie.push_back(Node());
		else
			trie[cnt] = Node();
		return cnt++;
	}

	void insert(string &word) { root.push_back(insert(root.back(), word)); }

	int insert(int prev, string &word) {
		int cur = new_node();
		int node = cur;
		int old = prev;
		for (char c : word) {
			int idx = c - 'a';
			if (old) {
				trie[cur] = trie[old];
				old = trie[old].next[idx];
			}
			trie[cur].next[idx] = new_node();
			cur = trie[cur].next[idx];
		}
		trie[cur].end = true;
		return node;
	}

	bool search(string &word) {
		int cur = root.back();
		for (char c : word) {
			int idx = c - 'a';
			if (!trie[cur].next[idx]) return false;
			cur = trie[cur].next[idx];
		}
		return trie[cur].end;
	}
};

int main() { return 0; }