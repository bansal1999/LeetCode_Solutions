struct TrieNode {
    TrieNode *links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    TrieNode *get(char ch){
        return links[ch - 'a'];
    }
    
    void put(char ch, TrieNode* node){
        links[ch - 'a'] = node;
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    TrieNode *root;
    
public:
    Trie(){
        root = new TrieNode();
    }
    
    //Inserts all the words in the vector into the trie DS
    void insert(string word){
        TrieNode *node = root;
        for(int i =0; i < word.size(); i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new TrieNode());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }
    
    bool checkAllPrefixExists(string word){
        TrieNode *node = root;
        bool flag = true;
        for(int i =0; i< word.size(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
                flag = flag & node -> isEnd();
            }
            else{
                return false;
            }
        }
        return flag;
    }
    
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *obj = new Trie();
        
        for(auto &it: words){
            obj -> insert(it);
        }
        
        string longest = "";
        for(auto &it: words){
            if(obj -> checkAllPrefixExists(it)){
                if(it.size() > longest.size()){
                    longest = it;
                }
                else if(it.size() == longest.size() && it < longest){
                    longest = it;
                }
            }
        }
        return longest;
    }
};