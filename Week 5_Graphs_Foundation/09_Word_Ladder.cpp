// 127. Word Ladder
// Approach: BFS over the word graph where edges connect words differing by one
// letter. Generate neighbors by trying all 26 letters at each position and
// checking membership in a hash set for O(1) lookups.
// Time: O(N * L * 26)  Space: O(N * L)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front(); q.pop();
                if (word == endWord) return steps;

                for (int pos = 0; pos < (int)word.size(); pos++) {
                    char original = word[pos];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        word[pos] = c;
                        if (wordSet.count(word)) {
                            wordSet.erase(word);
                            q.push(word);
                        }
                    }
                    word[pos] = original;
                }
            }
            steps++;
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution sol;
    cout << "Ladder length: " << sol.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
