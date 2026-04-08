/* 
Leetcode: https://leetcode.com/problems/time-based-key-value-store/description/

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]


*/

#include <unordered_map>
#include <vector>

using namespace std;



// TimeMap: stores key -> sorted vector of (timestamp, value) pairs
// set: append to vector (timestamps always increasing, so stays sorted)
// get: binary search for largest timestamp <= target; end pointer lands there



class TimeMap {
public:



    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string> value_pair(timestamp, value);
        m[key].push_back(value_pair);
        
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if(m.find(key) != m.end()){
            vector<pair<int, string>>&data = m[key]; 

            int st = 0, end = m[key].size()-1;

            while(st <= end){
                int mid = st+((end-st))/2;

                if(data[mid].first == timestamp){
                    ans = data[mid].second;
                    return ans;
                }

                if(data[mid].first > timestamp){

                    end = mid-1;
                }else{
                    st = mid+1;
                }

            }

            if(end>=0){
                ans = data[end].second;
            }

        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */