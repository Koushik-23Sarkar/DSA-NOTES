map<data_type1, data_type2> mp;

mp[1] = "abc"; // O(log(n))
mp[2] = "cde"; 
mp.insert({4,"acd"}); 
mp[6]; //  O(log(n)) // insert with default values


//  O(log(n)) ---> for accessing each element in a map;



// ##############################################################################################################################################################

auto it = mp.find(3)  // find(key) ---> return iterator  // O(log(n))
if(it == mp.end()){  // find(key) ---> mp.end() if, it is not found inside that map.
    cout<<"No Value"
}


// mp.erase( key  (or) iterator )    // 'iterator' should exist, otherwise it will give you 'segmentation fault'

mp.clear();


// ##############################################################################################################################################################
// Time Complexity depends on "keys", becoz they are compared while doing operation





// ___________________Unordered_Map______________________________________________________________________________________________________________________________________________
1. inBuilt Implementation ===>  Hash table is used
2. order doesn't matter
3. valid keys datatypes. 

// almost every complexity will be O(1).


mp[1] = "abc"; // O(1) avg case
mp[2] = "cde"; 
mp.insert({4,"acd"}); 






