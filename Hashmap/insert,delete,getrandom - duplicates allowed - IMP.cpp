/*
Leetocode 381. Insert Delete GetRandom O(1) - Duplicates allowed
ques:-
Implement the RandomizedCollection class:

RandomizedCollection() Initializes the RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item was present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements (it's guaranteed that at least one element exists when this method is called). The probability of each element being returned is linearly related to the number of same values the multiset contains.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
randomizedCollection.insert(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
randomizedCollection.insert(2);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.
*/

class RandomizedCollection
{
public:
    unordered_map<int, set<int>> mp;
    vector<int> nums;
    int size;

    RandomizedCollection() : size(0)
    {
        srand(time(NULL));
    }

    bool insert(int val)
    {
        bool ans = mp.find(val) == mp.end() || mp[val].size() == 0;
        mp[val].insert(size);
        size++;
        nums.push_back(val);
        return ans;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
        {
            return false;
        }
        int last = nums.back();
        int pos = *(mp[val].rbegin());
        mp[last].erase(*(mp[last].rbegin()));
        mp[last].insert(pos);
        nums[pos] = last;
        nums.pop_back();
        if (mp[val].size() > 1)
        {
            mp[val].erase(*(mp[val].rbegin()));
        }
        else
        {
            mp.erase(val);
        }
        size--;
        return true;
    }

    int getRandom()
    {
        if (size == 0)
            return -1;
        int randidx = rand() % size;
        return nums[randidx];
    }
};