// ============================================================
// Practice: Data Structures
// Summary: word frequency, two sum, dedupe, parens, merge, anagrams.
// Run:     g++ -std=c++17 practice/cpp/data_structures.cpp -o practice/cpp/data_structures && practice/cpp/data_structures
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>
#include <algorithm>

// ----- 1. Word frequency — count each word in a string -----
std::vector<std::pair<std::string, int>> wordFrequency(const std::string& text) {
    std::unordered_map<std::string, int> freq;
    std::vector<std::pair<std::string, int>> order;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        if (!freq.count(word)) order.push_back({word, 0});
        freq[word]++;
    }
    for (auto& kv : order) kv.second = freq[kv.first];
    return order;
}

void printMap(const std::vector<std::pair<std::string, int>>& items) {
    std::cout << "{";
    for (size_t i = 0; i < items.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << "'" << items[i].first << "': " << items[i].second;
    }
    std::cout << "}" << std::endl;
}

// ----- 2. Two sum — indices of two numbers that add to target -----
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int complement = target - nums[i];
        if (seen.count(complement)) return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}

// ----- 3. Remove duplicates, preserve first-seen order -----
std::vector<int> removeDuplicatesPreserveOrder(const std::vector<int>& arr) {
    std::unordered_set<int> seen;
    std::vector<int> result;
    for (int x : arr) {
        if (!seen.count(x)) {
            seen.insert(x);
            result.push_back(x);
        }
    }
    return result;
}

// ----- 4. Valid parentheses — stack-based bracket matching -----
bool validParentheses(const std::string& s) {
    std::stack<char> stk;
    std::unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty() || stk.top() != pairs[c]) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

// ----- 5. Merge two sorted arrays — two-pointer merge -----
std::vector<int> mergeTwoSorted(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < (int)a.size()) result.push_back(a[i++]);
    while (j < (int)b.size()) result.push_back(b[j++]);
    return result;
}

// ----- 6. Group anagrams — sort each group, sort groups by first word -----
std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& words) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const std::string& word : words) {
        std::string key = word;
        std::sort(key.begin(), key.end());
        groups[key].push_back(word);
    }
    std::vector<std::vector<std::string>> result;
    for (auto& kv : groups) {
        std::sort(kv.second.begin(), kv.second.end());
        result.push_back(kv.second);
    }
    std::sort(result.begin(), result.end(),
              [](const auto& a, const auto& b) { return a[0] < b[0]; });
    return result;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]" << std::endl;
}

void printGroups(const std::vector<std::vector<std::string>>& groups) {
    std::cout << "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << "[";
        for (size_t j = 0; j < groups[i].size(); ++j) {
            if (j) std::cout << ", ";
            std::cout << "'" << groups[i][j] << "'";
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}

int main() {
    printMap(wordFrequency("the cat sat on the mat cat"));  // {'the': 2, 'cat': 2, 'sat': 1, 'on': 1, 'mat': 1}
    printVec(twoSum({2, 7, 11, 15}, 9));                        // [0, 1]
    printVec(removeDuplicatesPreserveOrder({1, 2, 1, 3, 2, 4, 1}));  // [1, 2, 3, 4]
    std::cout << std::boolalpha << validParentheses("()[]{}") << std::endl;  // true
    std::cout << std::boolalpha << validParentheses("([)]") << std::endl;     // false
    printVec(mergeTwoSorted({1, 4, 7}, {2, 3, 6}));            // [1, 2, 3, 4, 6, 7]
    printGroups(groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}));  // [['ate', 'eat', 'tea'], ['bat'], ['nat', 'tan']]
    return 0;
}