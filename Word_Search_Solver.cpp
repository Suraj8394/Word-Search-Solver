#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEndOfWord = false;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'A';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'A';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }
};

vector<string> foundWords;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; // 8 directions
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node, string word, vector<vector<bool>>& visited) {
    if (node->isEndOfWord) {
        foundWords.push_back(word);
        node->isEndOfWord = false; // Avoid duplicates
    }

    int rows = board.size(), cols = board[0].size();
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i], newY = y + dy[i];

        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY] && node->children[board[newX][newY] - 'A']) {
            visited[newX][newY] = true;
            dfs(board, newX, newY, node->children[board[newX][newY] - 'A'], word + board[newX][newY], visited);
            visited[newX][newY] = false;
        }
    }
}

vector<string> wordSearch(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for (string word : words) trie.insert(word);

    int rows = board.size(), cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (trie.root->children[board[i][j] - 'A']) {
                visited[i][j] = true;
                dfs(board, i, j, trie.root->children[board[i][j] - 'A'], string(1, board[i][j]), visited);
                visited[i][j] = false;
            }
        }
    }
    return foundWords;
}

int main() {
    vector<vector<char>> board = {
        {'C', 'A', 'T'},
        {'X', 'Z', 'T'},
        {'Y', 'O', 'G'}
    };

    vector<string> words = {"CAT", "TOY", "DOG"};

    vector<string> result = wordSearch(board, words);
    cout << "Words found: ";
    for (string word : result) cout << word << " ";
    cout << endl;
    return 0;
}
