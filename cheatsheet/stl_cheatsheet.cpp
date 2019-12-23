//1. Iterators:
map<string,int>::iterator itr;





//////////////////////////////////////////////////////////////////////////////////////////////

//2. map and unordered_map:

//map:
// - sorted(by keys)
// - uses self balancing BST(red-black tree)
// - O(logn)

//unordered_map:
// - not sorted.
// - uses hashtable. (key hashed to index)
// - O(1)       (worst case: in case of collision handling: O(n))

map<string,int> m;
m["a"]=1;
m.insert({"b",2});
map<string,int>::iterator itr;
itr = m.begin();
cout<<"key: "<<itr->first;
cout<<"value: "<<itr->second;

//Traversing:
for(itr = m.begin();i!=m.end();itr++)
{
    cout<<itr->first;
    cout<<itr->second;
}

for(auto i : m)
{
    cout<<i->first;
    cout<<i->second;
}

//Other functions:
m.erase(key);
erase(m.begin(),m.find(key));    // for map (sorted)
m.size();





///////////////////////////////////////////////////////////////////////////////////////////////

//2. multimap:

// - Sorted.
// - Multimap is similar to map with an addition that multiple elements can have same keys.
// - Rather than each element being unique, the key value and mapped value pair has to be unique.

//insertion:
multimap<string,int> m;
m.insert({"a",1});

//Error: m["b"]=2;





///////////////////////////////////////////////////////////////////////////////////////////////

//3. sets and unordered sets:

//sets:
// - allows only unique elements.
// - sorted
// - Internal implementation: Similar to map


set<int> s;
s.insert(1);
s.erase(1);
if(s.empty())
s.clear();
s.size();





/////////////////////////////////////////////////////////////////////////////////////////////////

//4. stack:

stack<int> s;
s.push(10);
s.pop();
s.top();
s.size();
s.empty();





//////////////////////////////////////////////////////////////////////////////////////////////////

//5. Queue:

queue<int> q;
q.push(10);

q.front();
q.back();

q.size();
q.pop();
q.empty();





///////////////////////////////////////////////////////////////////////////////////////////////////

//6. priority_queue:

//sorted in descending order:
priority_queue<int> pq;

//sorted in ascending order:
priority_queue< int, vector<int>, greater<int> > pq;

pq.push(10);
pq.size();

pq.top();   //no fornt or back

pq.pop();
pq.empty();






/////////////////////////////////////////////////////////////////////////////////////////////////////

// 7. vector:

// - dynamic array.
// - Access: O(1)
// - Insertion and deletion: O(n)

//empty vector:
vector<int> v;

//empty vector with size n:
vector<int> v2(n);

//initilize vector with 0:
vector<int> v3(n,0);

v.push_back();
v.insert(v.begin(),value);
v.insert( v.end(), v2.begin(), v2.end() );

v.pop_back();
v.pop_front();

cout<<v.front();
cout<<v.back();

v.erase(iterator);
v.erase(iterator1, iterator 2);
v.clear();

//Sortint:
sort(v.begin(), v.end());
reverse(v.begin(),v.end());
sort(v.begin(),v.end(),greater<int>());





///////////////////////////////////////////////////////////////////////////////////////////////////

// 8. list:

// - linked list

//Access: O(n)
//Insertion and Deletion: O(1)

list<int> l;

l.push_back(10);
l.push_front(20);

l.insert(l.begin(),value);
l.insert( l.end(), l2.begin(), l2.end() );

cout<<l.front();
cout<<l.back();

l.pop_back();
l.pop_front();

l.erase(iterator);
l.erase(iterator1, iterator 2);
l.remove(value);

l.sort();
l.reverse();

//Traversing:
list<int>::iterator itr;
for(itr=l.begin(); itr!=l.end(); itr++)
    cout<<*itr;





//////////////////////////////////////////////////////////////////////////////////////////////////

//10. Creating reverse sorted containers:

// Ascending order:
priority_queue< int, vector<int>, greater<int> > pq;

//Descending Order:
map<int, greater<int>> m;
set<int, greater<int>> s;
priority_queue<int> pq;



