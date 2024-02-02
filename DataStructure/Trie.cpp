struct trie {
    trie* nxt[26];
    int cnt;    // Records the number of strings ending at this node
    int sz;     // Records the count of strings with prefixes including this node
    trie() : cnt(0), sz(0) {
        memset(nxt, 0, sizeof(nxt));
    }
};

trie* root = new trie(); // Create a new trie

void insert(string& s) {
    trie* now = root;  // Start from the root node each time
    for (auto i : s) {
        now->sz++;
        if (now->nxt[i - 'a'] == NULL) {
            now->nxt[i - 'a'] = new trie();
        }
        now = now->nxt[i - 'a'];  // Move to the next letter
    }
    now->cnt++;
    now->sz++;
}

int query_prefix(string& s) {  // Query the count of prefixes equal to s
    trie* now = root;    // Start from the root node each time
    for (auto i : s) {
        if (now->nxt[i - 'a'] == NULL) {
            return 0;
        }
        now = now->nxt[i - 'a'];
    }
    return now->sz;
}

int query_count(string& s) {  // Query the count of occurrences of the string s
    trie* now = root;    // Start from the root node each time
    for (auto i : s) {
        if (now->nxt[i - 'a'] == NULL) {
            return 0;
        }
        now = now->nxt[i - 'a'];
    }
    return now->cnt;
}
