class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
  	vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....", "..",".---","-.-",".-..","--","-.","---",".--.", "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    set<string> codeSet;

  	for (int i = 0; i < words.size(); i++) {
        
  		string code;
  		for (int j=0; j<words[i].size(); j++) code += codes[words[i][j] - 'a'];
        
  		codeSet.insert(code);
  	 }

    return codeSet.size();
  }
};