/*
 * Created on 2017-04-01.
 * -------------------------------------------------------------------------------
 * Question: Given a set of distinct integers, S, return all possible subsets
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: [1,2,3]
 * Output: [
 *          [],
 *          [1],
 *          [1, 2],
 *          [1, 2, 3],
 *          [1, 3],
 *          [2],
 *          [2, 3],
 *          [3],
 *        ]
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: Resolved for 2nd time - ~30 mins
 * Complexities:
 *      Time: O(2^n)
 *      Space: O(n)
 * Idea: We do a dfs for entire map. The map is defined as for each number
 * there are 2 nodes, on and off. When it hits the end of the list, output accumulated
 * numbers
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

void subsetsHelper(int index, vector<int> &input, vector<int> &current, vector<vector<int> > &result) {
    // Base case
    if (index == input.size()) {
        result.push_back(current);
        return;
    }
    // Excluding element at current index
    subsetsHelper(index+1, input, current, result);

    // Including element at current index
    current.push_back(input[index]);
    subsetsHelper(index+1, input, current, result);
    current.pop_back();
    return;
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    vector<int> current;
    sort(S.begin(), S.end());
    subsetsHelper(0, S, current, result);
    sort(result.begin(), result.end());
    return result;
}


int main() {
    vector<int> input = {1,2,3};
    vector<vector<int> > mySubsets = subsets(input);
    for (auto i : mySubsets) {
        if (i.empty()) {cout << "[]";}
        else {
            for (auto j : i) {
                cout << j;
            }
        }
        cout << endl;
    }
}