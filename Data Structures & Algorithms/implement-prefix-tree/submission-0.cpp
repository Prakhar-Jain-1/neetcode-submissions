class PrefixTree {
    PrefixTree* children[26] = {nullptr};
    bool isEnd = false;
public:
    PrefixTree() {

    }
    ~PrefixTree() {
        for (int i = 0; i < 26; i++) {
            delete children[i];
        }
    }
    void insert(string word) {
        PrefixTree* tmp;
        int i = 0;
        if(!children[word[i] - 'a']){
            children[word[i] - 'a'] = new PrefixTree();
        }
        tmp = children[word[i] - 'a'];
        i++;
        for(;i < word.size(); i++){
            if(!tmp->children[word[i] - 'a']){
                tmp->children[word[i] - 'a'] = new PrefixTree();
            }
            tmp = tmp->children[word[i] - 'a'];
        }
        tmp->isEnd = true;
    }
    
    bool search(string word) {
        PrefixTree* tmp;
        int i = 0;
        if(!children[word[i] - 'a']){
            return false;
        }
        tmp = children[word[i] - 'a'];
        i++;
        for(;i < word.size(); i++){
            if(!tmp->children[word[i] - 'a']){
                return false;
            }
            tmp = tmp->children[word[i] - 'a'];
        }
        return tmp->isEnd;
    }
    
    bool startsWith(string word) {
        PrefixTree* tmp;
        int i = 0;
        if(!children[word[i] - 'a']){
            return false;
        }
        tmp = children[word[i] - 'a'];
        i++;
        for(;i < word.size(); i++){
            if(!tmp->children[word[i] - 'a']){
                return false;
            }
            tmp = tmp->children[word[i] - 'a'];
        }
        return true;
    }
};
