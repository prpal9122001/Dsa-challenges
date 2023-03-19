//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

class WordDictionary
{
     unordered_map<int, vector<string>> words;  //unordered map to store index as the size of word and vector of string to store words of same sizes.
    //we need to create a function bool isEqual(string word1, string word2) so that it can ignore the particular character while 
    //comparing with other characters Eg:- "a . c" == "a b c' or vice versa "a b c" == "a . c".
     bool isEqual(string &word1, string &word2)
     {
          for (int i = 0; i < word1.size(); i++)  
          {
               if (word2[i] == '.')
                    continue;
               if (word1[i] != word2[i])
                    return false;
          }
          return true;
     }

public:
     WordDictionary() {}

     void addWord(string word)
     {
          words[word.size()].push_back(word); //To insert a word we just need to push the word at push_back(word)
     }

     bool search(string word)
     {
          for (auto &&s : words[word.size()]) //For search operation we just need to search at words[word.size()]
               if (isEqual(s, word))
                    return true;
          return false;
     }
};



//
 * //Your WordDictionary object will be instantiated and called as such:
 * //WordDictionary* obj = new WordDictionary();
 * //obj->addWord(word);
 * //bool param_2 = obj->search(word);
 //
