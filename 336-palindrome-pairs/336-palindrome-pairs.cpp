class Solution {
public:
  bool isPalindrome(int start, int end, string& s) {
      int i = start, j = end;
      while (i < j) {
        if (s[i++] != s[j--]) return false;
      }
      return true;
    }
  
    struct Node {
      // pointers to next chars
      Node* node[26] = {nullptr};
      // stores index of string ending at this node.
      int index = -1;
      // stores indexes for which palindromes exist after the current trie node.
      vector<int> palindromic_indexes;
      Node() {}
    };
    
    Node* start_node = new Node();
    
    void insert(string& s, int index) {
      int n = s.size();  
      Node* cur = start_node;
      for (int i = n-1; i >= 0; --i) {
        if (isPalindrome(0, i, s)) cur->palindromic_indexes.push_back(index);
        int node_index = s[i]-'a';
        if (cur->node[node_index] == nullptr) {
          cur->node[node_index] = new Node();
        }
        cur = cur->node[node_index];
      }
      cur->index = index;
      // string is complete, empty string is palindromic 
      cur->palindromic_indexes.push_back(index);
    }
  
    vector<vector<int>> palindromePairs(vector<string>& words) {
      int n = words.size();
      
      for (int i = 0; i < n; ++i) insert(words[i], i);
      vector<vector<int>> ans;
      
      for (int i = 0; i < n; ++i) {
        string cur = words[i];
        int m = cur.size();
        auto now_node = start_node;
        
        for (int j = 0; j < m && now_node; ++j) {
          if (now_node->index != -1 && now_node->index != i &&
              isPalindrome(j, m-1, cur)) {
            ans.push_back({i, now_node->index});
          }
          now_node = now_node->node[cur[j]-'a'];
        }
        
        if (!now_node) continue;
        
        for (const auto& x: now_node->palindromic_indexes) {
          if (x != i) ans.push_back({i, x});
        }
      }
      
      return ans;
    }
};