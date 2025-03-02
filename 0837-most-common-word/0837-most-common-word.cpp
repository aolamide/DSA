class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        for(char& ch: paragraph) {
            if(isalpha(ch)) ch = tolower(ch);
            else ch = ' ';
        }

        istringstream ss(paragraph);
        string word;

        //store banned words in set
        unordered_set<string> bannedWords;
        for(string b : banned) bannedWords.insert(b);

        //map to store count of occurence of word
        unordered_map<string, int> wordCount;

        pair<string, int> result = make_pair("", 0);

        while(ss >> word) {
            if(!bannedWords.count(word)) {
                wordCount[word]++;
                if(wordCount[word] > result.second) {
                    result = make_pair(word, wordCount[word]);
                }
            }
        }

        return result.first;
    }
};

//convert paragraph to lowercase, and remove all non-alpha charcaters.
//add all banned words to set
//strem words and increase count. If word is not banned, and count is greater that current highest count, update result