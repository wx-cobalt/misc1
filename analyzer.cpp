#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::chrono::system_clock;
using std::chrono::milliseconds;
using msType = std::chrono::duration<int, std::ratio<1, 1000>>;

int linearSearch(vector<string> container, string word)
{
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] == word)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<string> container, string word)
{
    int low = 0;
    int high = container.size() - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        if (word > container[mid])
        {
            low = mid + 1;
        }
        else if (word < container[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void compareSpeeds(vector<string> container, string query)
{
    // linear
    auto start = system_clock::now();
    int index = linearSearch(container, query);
    auto end = system_clock::now();
    auto diff = end - start;
    cout << "linear search found " << query << " at " << index << "  in " << diff.count() << endl;
    // binary
    start = system_clock::now();
    index = binarySearch(container, query);
    end = system_clock::now();
    diff = end - start;
    cout << "binary search found " << query <<  " at " << index << "  in " << diff.count() << endl;
}

int main() {
    vector<string> dataset;
    //would bring in dataset here with external function (for prior lab used stringdata.py, in this case would presumably use a C++ equivalent and include that)

    //test 1
    string query =  "not_here";
    compareSpeeds(dataset, query);

    //test 2
    query =  "mzzzz";
    compareSpeeds(dataset, query);

    //test 3
    query =  "aaaaa";
    compareSpeeds(dataset, query);
    return 0;
}