#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1983;

/*
Input: nums1 = [1,1,0,1], nums2 = [0,1,1,0]
Output: 3
Explanation:
If i = 1 and j = 3:
nums1[1] + nums1[2] + nums1[3] = 1 + 0 + 1 = 2.
nums2[1] + nums2[2] + nums2[3] = 1 + 1 + 0 = 2.
The distance between i and j is j - i + 1 = 3 - 1 + 1 = 3.
*/

tuple<vector<int>, vector<int>, int> testFixture1()
{
  return make_tuple(vector<int>{1, 1, 0, 1}, vector<int>{0, 1, 1, 0}, 3);
}

/*
Input: nums1 = [0,1], nums2 = [1,1]
Output: 1
Explanation:
If i = 1 and j = 1:
nums1[1] = 1.
nums2[1] = 1.
The distance between i and j is j - i + 1 = 1 - 1 + 1 = 1.
*/

tuple<vector<int>, vector<int>, int> testFixture2()
{
  return make_tuple(vector<int>{0, 1}, vector<int>{1, 1}, 1);
}

/*
Input: nums1 = [0], nums2 = [1]
Output: 0
Explanation:
There are no pairs of indices that meet the requirements.
*/

tuple<vector<int>, vector<int>, int> testFixture3()
{
  return make_tuple(vector<int>{0}, vector<int>{1}, 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::find(get<0>(f), get<1>(f))) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::find(get<0>(f), get<1>(f))) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}