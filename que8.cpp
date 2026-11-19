
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    // Vector to store marks
    vector<int> marks = {75, 90, 65, 85, 40};
    // Map to store student names and erp
    map<string, int> students;

    students["Anu"] = 952;
    students["Shaqib"] = 241;
    students["Shazia"] = 252;
    students["Santosh"] = 203;

    // Unordered Map
    unordered_map<string, int> data;
    data["Anu"] = 75;
    data["Shazi"] = 90;

    cout << "Student Marks:" << endl;
    for (auto x : students) {
        cout << x.first << " : " << x.second << endl;
    }

    // Sort Algorithm
    sort(marks.begin(), marks.end());
    cout << "\nSorted Marks: ";
    for (int x : marks)
        cout << x << " ";

    // Find_if Algorithm
    auto it = find_if(marks.begin(), marks.end(),
                      [](int x) { return x > 80; });

    if (it != marks.end())
        cout << "\nFirst mark above 80: " << *it << endl;

    // Transform Algorithm
    transform(marks.begin(), marks.end(), marks.begin(),
              [](int x) { return x + 5; });

    cout << "\nMarks after adding 5: ";
    for (int x : marks)
        cout << x << " ";

    return 0;
}
