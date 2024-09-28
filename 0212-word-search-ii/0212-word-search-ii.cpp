struct Node {
    char val {};
    std::unordered_map<char, Node*> children;
    bool is_word = false;
    Node() = default;
    Node(char val) : val(val) {};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head = new Node();
        for (const auto& word : words) {
            addWord(word);
        }
        
        std::vector<std::string> result;
        std::string currentWord;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, head, currentWord, result);
            }
        }

        return result;
    }
    
private:
    std::vector<std::pair<int, int>> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Moves: down, right, up, left
    Node* head;
    
    void addWord(const std::string& word) {
        Node* curr = head;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Node(c);
            }
            curr = curr->children[c];
        }
        curr->is_word = true;
    }

    void dfs(std::vector<std::vector<char>>& board, int i, int j, Node* node, std::string& currentWord, std::vector<std::string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#')
            return;
        
        char c = board[i][j];
        if (node->children.find(c) == node->children.end())
            return;

        node = node->children[c];
        currentWord.push_back(c);
        
        if (node->is_word) {
            result.push_back(currentWord);
            node->is_word = false; // Avoid duplicates
        }

        // Mark as visited
        board[i][j] = '#';
        for (const auto& move : moves) {
            int new_i = i + move.first;
            int new_j = j + move.second;
            dfs(board, new_i, new_j, node, currentWord, result);
        }
        // Restore the character
        board[i][j] = c;

        currentWord.pop_back();
    }
};