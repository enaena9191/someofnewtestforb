#include <string>
#include <vector>
#include <array>
using namespace std;

class WordDictionary {
    vector<array<int, 26>> child;
    vector<bool> end;

public:
    WordDictionary() {
        child.push_back({});
        end.push_back(false);
    }
    
    void addWord(string word) {
        int cur = 0;
        for (char c : word) {
            c -= 'a';
            if (!child[cur][c]) {
                child[cur][c] = child.size();
                child.push_back({});
                end.push_back(false);
            }
            cur = child[cur][c];
        }
        end[cur] = true;
    }

    bool searchhelp(string& word, int pos, int cur) {
        for (; pos < (int) word.size(); pos++) {
            if (word[pos] == '.') {
                int ft = false;
                for (int j : child[cur]) {
                    if (j && searchhelp(word, pos + 1, j)) return true;
                }
                return false;
            } else {
                int nxt = child[cur][word[pos] - 'a'];
                if (!nxt) return false;
                cur = nxt;
            }
        }
        return end[cur]; // full match
    }
    
    bool search(string word) {
        return searchhelp(word, 0, 0);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */