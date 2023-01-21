class ParkingSystem {
public:
    vector<int> spaces;
    ParkingSystem(int big, int medium, int small) {
        spaces = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(spaces[carType - 1]-- < 1) return false;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */