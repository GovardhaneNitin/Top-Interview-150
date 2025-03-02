#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet
{
public:
    vector<int> arr;
    unordered_map<int, int> map;
    RandomizedSet()
    {
        // Constructor
        arr.clear();
        map.clear();
    }

    bool insert(int val)
    {
        // Write your code here
        if (map.count(val))
        {
            return false;
        }

        arr.push_back(val);
        map[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        // Write your code here
        if (map.count(val))
        {
            int index = map[val];
            int v = arr.back();
            arr[index] = v;
            map[v] = index;
            arr.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        // Write your code here
        int index = rand() % arr.size();
        return arr[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet *obj = new RandomizedSet();
    cout << obj->insert(1) << endl;   // Example test case
    cout << obj->remove(2) << endl;   // Example test case
    cout << obj->insert(2) << endl;   // Example test case
    cout << obj->getRandom() << endl; // Example test case
    cout << obj->remove(1) << endl;   // Example test case
    cout << obj->insert(2) << endl;   // Example test case
    cout << obj->getRandom() << endl; // Example test case
    return 0;
}
