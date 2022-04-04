#include <string>
#include "node.h"
#include "util.h"
using namespace std;
using namespace sol1983;

string Util::toString(vector<string> input)
{
    string result = "[";
    for (auto e : input)
    {
        result += e;
        result += ",";
    }
    /* remove the last comma */
    if (result.back() == ',')
        result.pop_back();
    result += "]";
    return result;
}

string Util::toString(vector<int> input)
{
    string result = "[";
    for (auto e : input)
    {
        result += to_string(e);
        result += ",";
    }
    /* remove the last comma */
    if (result.back() == ',')
        result.pop_back();
    result += "]";
    return result;
}

string Util::toString(vector<vector<int>> input)
{
    string result = "[";
    for (auto i : input)
        result += toString(i), result += ",";
    if (result.back() == ',')
        result.pop_back();
    result += "]";
    return result;
}