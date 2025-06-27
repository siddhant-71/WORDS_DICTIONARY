#include<iostream>
#include<vector>
class trieNode
{
    public:
    std::vector<trieNode*>child;
    bool isLast;
    int start;
    std::vector<std::string> Meaning;
    trieNode() {
        this->start = 1;
        this->isLast = false;
        this->child.resize(26, nullptr);
    }
};

/*vector<string> SearchWord(string word){
        trieNode* temp=root;
        vector<string>ans;
        for(int i=0;i<word.length();i++){
            int t=word[i]-'a';
            if(!temp->child[t])return ans;
            temp=temp->child[t];
        }
        return temp->Meaning;
    }
        */