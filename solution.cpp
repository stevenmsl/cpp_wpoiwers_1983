#include "solution.h"

#include <unordered_map>
#include <functional>
using namespace sol1983;
using namespace std;

/*takeaways
  - delta is defined as the sum of differences of each
    pair visited so far (n1[0]-n2[0]) + ... +(n1[j]-n2[j])

  - let's look at an extreme case first
    n1 = [0,0,0,0], n2=[0,0,0,0]
    - n1[0]-n2[0] = 0 that means we are changing
      the delta between n1 and n2. so the distance
      can be calculate for(i=0,j=0) is j - deltas[0]
      =0-(-1) = 1, and therefore we set the
      initial entry of the mapping to {{0,-1}}:
      last time when the delta is 0 it happens
      at index -1
    - now we introduce another pair (n1[1],n2[1])
      (n1[0]-n2[0]) + (n1[1]-n2[1]) = 0 so the
      distance for (i=0,j=1) is j-deltas[delta]
      = 1-deltas[0] = 1-(-1)=2
    - adding the next two pairs still keeps the
      delta the same. So in the end when (i=0,j=3)
      the distance becomes 3-deltas[0]= 3-(-1)=4

  - let's look at another case n1=[0,1], n2=[1,1]
    - n1[0]-n2[0]= -1, we have a new delta here
      and it happens at j=0, so we record it
      as deltas[-1] = 0, with the new delta
      being the key and the index of j being
      the value. Introducing a new delta also
      means we have a new baseline to look at
      if the delta remains the same while we
      are processing the remaining pairs
    - n1[1]-n2[1] = 0, we don't change the
      delta for (i=1,j=1), so the distance
      is now j-deltas[-1]=1-0=1
    - we can look at it this way: when we
      scan the first pair it introduces
      a new delta value, so it's a new baseline.
      And our job now is to see how far we
      can go with that new delta value. The delta
      value might change afterwards, but every time
      it comes back to the same value we can
      update the distance accordingly

*/

int Solution::find(vector<int> &nums1, vector<int> &nums2)
{
  /*record each different delta value and where it starts
    happening
    - see the explanation above for why we set the
      initial entry as below
  */
  auto deltas = unordered_map<int, int>{{0, -1}};
  int dist = 0, delta = 0;
  for (auto i = 0; i < nums1.size(); i++)
  {
    delta += nums1[i] - nums2[i];
    /* we have never seen this delta before
       - we found a new baseline to calculate
         distance if the delta values ever
         comes back to the same value as we
         recorded here
    */
    if (!deltas.count(delta))
      deltas[delta] = i;

    /* calculate the distance per my delta
       - don't forget we recorded when a certain
         dela value first happened
       - we then update the global max distance
         if needed
    */
    dist = max(dist, i - deltas[delta]);
  }

  return dist;
}