#include<iostream>
#include <unordered_map>
using namespace std;


int main() {
  // Create a hashmap
  unordered_map < int, string > hashmap;
  unordered_map<int, bool> visited;

  // Insert key-value pairs
  hashmap.insert({ 1, "Value 1"});
  hashmap.insert({ 2, "Value 2"});
  hashmap.insert({ 3, "Value 3"});

  // Access values using keys
  cout << "Value associated with key 1: " << hashmap[1] << endl;
  cout << "Value associated with key 2: " << hashmap[2] << endl;
  cout << "Value associated with key 3: " << hashmap[3] << endl;

  // Check if a key exists
  if (hashmap.find(4) != hashmap.end()) {
    cout << "Key 4 found!" << endl;
  } else {
    cout << "Key 4 not found!" << endl;
  }

  // Remove a key-value pair
  hashmap.erase(2);

  // Iterate over key-value pairs
  for (const auto & pair: hashmap) {
    cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
  }

  return 0;
}