class TrieNode{
public:
    TrieNode* children[26];
    bool is_end=false;
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i]=nullptr;
        }
        is_end=false;
    }
};
class WordDictionary {
    // we can use brute force and trie to solve 
    // brute force will store every word and search in every word
    // brute force will TLE since the time complexity will be O(nm) for search
    // use trie and dfs to search the word
public:
    // vector<string> dict;
    TrieNode* root;
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        // dict.push_back(word);
        TrieNode* node=root;
        for(char c : word){
            if(node->children[c-'a']==nullptr){
                node->children[c-'a']=new TrieNode();
            }
            node=node->children[c-'a'];
        }
        node->is_end=true;
    }
    
    bool search(string word) {
        /*
        for(auto &w : dict){
            if(w.length()!=word.length()){
                continue;
            }
            int i=0;
            while(i<w.length()){
                if(w[i]==word[i] || word[i]=='.'){
                    i++;
                }
                else{
                    break;
                }
            }
            if(i==w.length()){
                return true;
            }
        }
        return false;
        */
        return dfs(root,0,word);

    }
private:
    bool dfs(TrieNode* root, int i, string word){
        TrieNode* cur=root;
        for(int j=i; j<word.length(); j++){
            char c=word[j];
            // solve the special case when c is '.' 
            if(c=='.'){
                for(TrieNode* child : cur->children){
                    if(child!=nullptr && dfs(child, j+1, word)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(cur->children[c-'a']==nullptr){
                    return false;
                }
                cur=cur->children[c-'a'];
            }

        }
        return cur->is_end;
    }
};
