class OrderedStream {
public:
    int ptr = 1;
    vector<string> stream;
    OrderedStream(int n) {
        stream = vector<string>(n, "");
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey - 1] = value;
        vector<string> result;
        if(idKey == ptr) {
            while(ptr <= stream.size() && stream[ptr - 1] != "") {
                result.push_back(stream[ptr - 1]);
                ptr++;
            }
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */