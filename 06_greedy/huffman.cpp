#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

void huffmanCoding(map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    map<char, string> huffmanCode;
    generateCodes(pq.top(), "", huffmanCode);

    cout << "Huffman Kodlari:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << endl;
}
