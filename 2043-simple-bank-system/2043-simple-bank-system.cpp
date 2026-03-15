class Bank {
private:
    vector<long long> balances;

    bool accountExists(int account) {
        return account > 0 && account <= balances.size();
    }
public:
    Bank(vector<long long>& balance) {
        balances = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if(accountExists(account1) && accountExists(account2)) {
            return withdraw(account1, money) && deposit(account2, money);
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        //check if account exists
        if(!accountExists(account)) return false;

        //deposit money
        balances[account - 1] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        //check if account exists
        if(!accountExists(account)) return false;

        //check that account has enough balance
        if(balances[account - 1] < money) return false;

        //withdraw money
        balances[account - 1] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */