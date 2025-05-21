#include<bits/stdc++.h>
using namespace std;

struct trie{
    trie *childreen[26];
    bool eoW = false;
    trie(){
        for(int i = 0;i<26;i++){
            childreen[i]=NULL;
        }
    }
};
void insert(trie* root, string word){
    trie *point = root;
    for(int i =0 ; i< word.length();i++){
        if(point->childreen[word[i]-'a']==NULL){
            point->childreen[word[i]-'a'] = new trie();
        }
        point = point->childreen[word[i]-'a'];
    }
    point->eoW = true;

}
bool search(trie* root, string word){
    trie* point = root;
    for(int i = 0 ; i< word.length();i++){
        if(point->childreen[word[i]-'a']){
            point = point->childreen[word[i]-'a'];
        }
        else return false;
    }
    return point->eoW;
}
int main(){
    string word[] = {"canada","canva","cumins","coctail"};
    trie* root = new trie();
    for(int i=0;i<4;i++){
         insert(root,word[i]);
    }
    if(search(root , "can")) cout <<"YES";
    else cout<<"NO";
    return 0;
}
