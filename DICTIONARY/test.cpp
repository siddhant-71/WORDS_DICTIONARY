#include<bits/stdc++.h>
#include "trieLibrary.cpp"
int main(){
    cout << "Loading words into the Trie..." << endl;
    trie* dict = new trie();

    ifstream file("dictionary.txt");
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            string word = line.substr(0, pos);
            string meaning = line.substr(pos + 1); // ✅ extract meaning

            // Clean up: remove whitespace and normalize
            word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            dict->AddWord(word, meaning); // ✅ now meaning is defined!
        }
    }
file.close();


    while (1) {
        cout<< " WELCOME TO THE DICTIONARY ";
        cout<<" ENTER 1 TO INSERT WORD "<<endl;
        cout<<" ENTER 2 TO DELETE WORD "<<endl;
        cout<<" ENTER 3 TO SEARCH WORD "<<endl;
        cout<<" ENTER 4 TO SEARCH MEANING OF THE WORD "<<endl;
        cout<<" ENTER 5 TO GET ALL WORDS "<<endl;
        cout<<" ENTER 6 TO GET ALL WORDS WITH THE MEANING  "<<endl;
        cout<<" ENTER 7 TO GET ALL WORDS WITH ENTERED PREFIX"<<endl;
        cout<<" ENTER 8 TO GET MEANING WITH ENTERED PREFIX "<<endl;
        cout<<" ENTER 9 TO GET SIZE OF DICT"<<endl;
        cout<<" ENTER 0 TO EXIT"<<endl;
        int n;
        cin>>n;
        system("cls");
        switch(n){
            case 1:{
                cout<<"enter the word : ";
                string word;
                cin>>word;
                cout<<"type the meaning : ";
                string meaning;
                cin>>meaning;
                dict->AddWord(word,meaning);
                cout<<" WORD ADDED SUCCESSFULLY ";
                break;
            }
            case 2:{
                cout<<"enter the word : ";
                string word;
                cin>>word;
                dict->DeleteWord(word);
                cout<<" WORD DELETED SUCCESSFULLY ";
                break;
            }
            case 3:{
                cout<<"enter the word : ";
                string word;
                cin>>word;
                if(dict->SearchWord(word))cout<<" WORD IS THERE IN DICTIONARY ";
                else cout<<" WORD NOT FOUND ";
                break;
            }
            case 4:{
                cout<<"enter the word : ";
                string word;
                cin>>word;
                if(!dict->SearchWord(word))cout<<" WORD NOT FOUND ";
                else{
                    vector<string>me=dict->SearchWordMeaning(word);
                    for(string a:me)cout<<a<<endl;
                }
                break;
            }
            case 5:{
                vector<string>wordlist=dict->getAllWords();
                for(auto i:wordlist)cout<<i<<endl;
                break;
            }
            case 6:{
                vector<string>wordlist=dict->getAllWords();
                for(auto i:wordlist){
                    cout<<i<<" : "<<endl;
                    for(auto a:dict->SearchMeaning(i))cout<<"        "<<a<<endl;
                }
                break;
            }
            case 7:{
                cout<<" enter the word : ";
                string word;
                cin>>word;
                if(!dict->StartsWith(word))cout<<" No Words !!";
                else{
                    vector<string>list=dict->getWordsWithPrefix(word);
                    for(auto i:list)cout<<i<<endl;
                }
            }
            case 8:{
                cout<<" enter the word : ";
                string word;
                cin>>word;
                if(!dict->StartsWith(word))cout<<" No Words !!";
                else{
                    vector<string>list=dict->getWordsWithPrefix(word);
                    for(auto i:list){
                        cout<<i<<endl;
                        for(auto a:dict->SearchMeaning(i))cout<<"    "<<a<<endl;
                    }
                }
                break;
            }
            case 9:{
                cout<<"Number of words in the Dictionary are "<<dict->size()<<endl;
            }
            case 0: {
                cout<<"THANK YOU FOR VISITING ..";
            }
            default: {
                cout<<"enter the valid key : ";
            }
        }
        cout<<endl;
    }
    return 0;
}