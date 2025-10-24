struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    string fullTransaction;

    Transaction(string trans) {
        int p1 = trans.find(',');
        int p2 = trans.find(',', p1 + 1);
        int p3 = trans.find(',', p2 + 1);

        name = trans.substr(0, p1);
        time = stoi(trans.substr(p1 + 1, p2 - p1 - 1));
        amount = stoi(trans.substr(p2 + 1, p3 - p2 - 1));
        city = trans.substr(p3 + 1);
        fullTransaction = trans;
    };
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Transaction> list;
        vector<int> marked(transactions.size());
        vector<string> result;

       for(string transaction : transactions) {
        Transaction curr(transaction);
        list.push_back(curr);
       }

       for(int i = 0; i < list.size(); i++) {

        Transaction curr = list[i];
        if(curr.amount > 1000) {
            marked[i] = 1;
            continue;
        }

        for(int j = 0; j < list.size(); j++) {
            cout << j;
            if(i == j) continue;
            Transaction compareCurr = list[j];

            if((curr.name == compareCurr.name) && (abs(curr.time - compareCurr.time) <= 60) && (curr.city != compareCurr.city)) {
                marked[i] = 1;
                // marked[j] = 1;
                break;
            }
        }
       }

       for(int i = 0; i < list.size(); i++) {
        if(marked[i]) {
            result.push_back(list[i].fullTransaction);
        }
       }


       return result;
    }
};


// "abc,cde,fgh,ijk"
// a0
// b1
// c2
// ,3
// c4
// d5
// e6
// ,7
// f8
// g9
// h10
//,11
//i12
//j13
//k14

