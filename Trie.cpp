//208. Implement Trie (Prefix Tree) - https://leetcode.com/problems/implement-trie-prefix-tree/description/


class TrieNode {
public:
    TrieNode *links[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for(auto& a: links)a = nullptr;
    }
};



class Trie {
public:
TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(auto& c:word)
        {
            if(cur->links[c - 'a'] == NULL)
            {
                TrieNode* child = new TrieNode();
                cur->links[c-'a'] = child;
            }
            cur = cur->links[c- 'a']; 
        }
        cur->isWord = 1;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(auto& c:word)
        {
            if(cur->links[c-'a'] == NULL)return false;
            else
                cur = cur->links[c-'a'];
        }
        if(cur->isWord == 1)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(auto& c:prefix)
        {
            if(cur->links[c-'a'] == NULL)return false;
            else
                cur = cur->links[c-'a'];
        }
        return true;
    }
};

//211. Design Add and Search Words Data Structure - https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

class TrieNode{
public:
    TrieNode *links[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for(auto& c : links)c = nullptr;
    }
};



class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for(auto& c : word)
        {
            if(cur->links[c - 'a'] == NULL)
            {
                TrieNode* child = new TrieNode();
                cur->links[c - 'a'] = child;
            }
            cur = cur->links[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(auto& c : word)
        {
            if(cur->links[c - 'a'] == NULL)
                return false;
            else
                cur = cur->links[c - 'a'];
        }
        if(cur->isWord == true)return true;
        return false;
    }
};


//212. Word Search II - https://leetcode.com/problems/word-search-ii/description/
class TrieNode {
public:
    char value;
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(char val) {
        value = val;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isEndOfWord = false;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode('\0');
    }

    void insertWord(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode(ch);
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words) {
            insertWord(word);
        }

        set<string> foundWords;
        string currentWord = "";
        int numRows = board.size();
        int numCols = board[0].size();
        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                searchWords(board, foundWords, root, row, col, currentWord, visited);
            }
        }

        return vector<string>(foundWords.begin(), foundWords.end());
    }

    void searchWords(vector<vector<char>>& board, set<string>& foundWords, TrieNode* currentNode, int row, int col, string& currentWord, vector<vector<bool>>& visited) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col]) return;

        char currentChar = board[row][col];
        if (currentNode->children[currentChar - 'a'] == nullptr) return;

        currentWord.push_back(currentChar);
        currentNode = currentNode->children[currentChar - 'a'];

        if (currentNode->isEndOfWord) foundWords.insert(currentWord);

        visited[row][col] = true;
        searchWords(board, foundWords, currentNode, row + 1, col, currentWord, visited);
        searchWords(board, foundWords, currentNode, row - 1, col, currentWord, visited);
        searchWords(board, foundWords, currentNode, row, col + 1, currentWord, visited);
        searchWords(board, foundWords, currentNode, row, col - 1, currentWord, visited);
        visited[row][col] = false;

        currentWord.pop_back();
    }
};