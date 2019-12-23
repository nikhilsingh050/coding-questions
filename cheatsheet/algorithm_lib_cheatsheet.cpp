
#include<algorithm>

///////////////////////////////////////////////////////////////////////////////

//Non-modifying sequence operations:

sort(first_iterator, last_iterator)
reverse(first_iterator, last_iterator)


*max_element (first_iterator, last_iterator)
*min_element (first_iterator, last_iterator)


accumulate(first_iterator, last_iterator, initial value of sum)


count(first_iterator, last_iterator,x);
find(first_iterator, last_iterator, x);


//search for a subsequence:
auto itr = search(v1.begin(), v1.end(), v2.begin(), v2.end());


/////////////////////////////////////////////////////////////////////////////////


arr.erase(iterator);


//remove a value from a range:
remove(v.begin(),v.end(),x);


//Remove duplicate values in a sorted vector:
arr.erase(unique(arr.begin(),arr.end()),arr.end());


/////////////////////////////////////////////////////////////////////////////////


fill(arr,arr+n,0);
//OR
fill(arr.begin(),arr.end());


//////////////////////////////////////////////////////////////////////////////////

//Permutations of a range:
//rearranges the elements.
next_permutation(first_iterator, last_iterator);
prev_permutation(first_iterator, last_iterator);

//Lexicographical permutations of a string:
string s="abc";
next_permutation(s.begin(),s.end());
prev_permutation(s.begin(),s.end());

while(next_permutation(s.begin(),s.end()))
    cout<<s;



//////////////////////////////////////////////////////////////////////////////////


//find index of a position iterator.
distance(first_iterator,desired_position);


//////////////////////////////////////////////////////////////////////////////////


//merge operation on a sorted range:

//merge v1 and v2 to v3.

merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

