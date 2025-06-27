#include<iostream>
#include "trieNode.cpp"
using namespace std;
class trie{
private:
    trieNode* root;
    int count=0;
    void findAll(trieNode* root,vector<string>&ans,string word){
        for(int i=0;i<26;i++){
            if(root->child[i]){
                word.push_back('a'+i);
                if(root->child[i]->isLast)ans.push_back(word);
                findAll(root->child[i],ans,word);
                word.pop_back();
            }
        }
    }
    void findMeaning(trieNode* root,vector<string>&ans,string word){
        for(int i=0;i<26;i++){
            if(root->child[i]){
                word.push_back('a'+i);
                if(root->child[i]->isLast){
                    for(string a:root->child[i]->Meaning)ans.push_back(a);
                }
                findMeaning(root->child[i],ans,word);
                word.pop_back();
            }
        }
    }
public:
    trie(){
        root=new trieNode();
    }
    void AddWord(string word,string meaning){
        trieNode* temp=root;
        for(int i=0;i<word.length();i++){
            int t=word[i]-'a';
            if(!temp->child[t]){
                temp->child[t]=new trieNode();
            }
            temp->start++;
            temp=temp->child[t];
        }
        temp->Meaning.push_back(meaning);
        temp->isLast=true;
        count++;
    }
    void DeleteWord(string word){
        trieNode* temp=root;
        for(int i=0;i<word.length();i++){
            int t=word[i]-'a';
            if(!temp->child[t])return;
            temp->child[t]->start--;
            if(temp->child[t]->start==0){
                trieNode* a=temp->child[t];
                temp->child[t]=NULL;
                delete(a);
                count--;
                return;
            }
            temp=temp->child[t];
        }
        count--;
        temp->isLast=false;
    }
    bool SearchWord(string word){
        trieNode* temp=root;
        for(int i=0;i<word.length();i++){
            int t=word[i]-'a';
            if(!temp->child[t])return false;
            temp=temp->child[t];
        }
        return temp->isLast;
    }
    vector<string> SearchWordMeaning(string word){
        trieNode* temp=root;
        vector<string>ans;
        for(int i=0;i<word.length();i++){
            int t=word[i]-'a';
            if(!temp->child[t])return ans;
            temp=temp->child[t];
        }
        return temp->Meaning;
    }
    bool StartsWith(string word){
        trieNode* temp=root;
        for(int i=0;i<word.length();i++){
            int t=word[i]-'a';
            if(!temp->child[t])return false;
            temp=temp->child[t];
        }
        return true;
    }
    vector<string> getAllWords(){
        trieNode* temp=root;
        vector<string>ans;
        string word="";
        findAll(root,ans,word);
        return ans;
    }
    vector<string> getWordsWithPrefix(string prefix){
        trieNode* temp=root;
        vector<string>ans;
        for(int i=0;i<prefix.length();i++){
            int t=prefix[i]-'a';
            if(!temp->child[t])return ans;
            temp=temp->child[t];
        }
        findAll(temp,ans,prefix);
        return ans;
    }
    vector<string> SearchMeaning(string prefix){
        trieNode* temp=root;
        vector<string>ans;
        for(int i=0;i<prefix.length();i++){
            int t=prefix[i]-'a';
            if(!temp->child[t])return ans;
            temp=temp->child[t];
        }
        findMeaning(temp,ans,prefix);
        return ans;
    }
    int size(){
        return count;
    }
};