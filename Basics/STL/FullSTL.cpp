#include <bits/stdc++.h>

using namespace std;

// Algorithms
// Containers
// Fnctions
// Iterators

void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << "" << p.second;
    pair<int, pair<int, int>> p1 = {1, {2, 3}};
    cout << p1.first << " " << p1.second.second << "" << p1.second.first << endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second;
}

void explainVector()
{
    vetor<int> v;

    v.push_back(1);
    v.emplace_back(2);
    // emplace back and push back do the same thing but emplace back is faster
    vector<pair<int, int>> vec;
    // you can create a vector of pairs.

    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    vector<int> v2(5, 100); // This means that v2 is of size 5 where each character is of 100
    vector<int> v3(5, 20);
    vector<int> v4(5);  // this only specifies the size of the vector and the system will automatically assign any garbage value
    vector<int> v5(V3); // This means that we are copying the contents of the vector.

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
        /* code */
    }
    // This is an iterator. It points to the memory location of the vector and iterates over it .
    // So if we only print "it" then it will print the memory location not the content stored at that memory location.
    // So we use pointer * to print the contents.

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << endl;

    it = it + 2;
    cout << *(it) << " ";

    vector<int>::iterator it = v.end();
    vector<int>::iterator it = v.rend();
    vector<int>::iterator it = v.rbegin(); // this will point to the last element of the vector and when you increase the value, it will move towards the first.

    cout << v[0] << " " << v.at(0);
    cout << v.back() << " ";

    for (auto it = v.begin(); it != v.end(); it++)
    {
        /* code */
        cout << *(it) << endl;
    }
    // IN nor for loop, when we use auto it becomes an iterator.
    // but when you use for Each it is assigned to integer.
    for (auto it : v)
    {
        cout << *(it) << endl;
    }

    v.erase(v.begin() + 1);
    v.erase(v.begin() + 2, v.begin() + 4);

    vector<int> v(2, 100);
    v.insert(v.begin(), 300);
    v.insert(v.begin() + 1, 2, 10); // this will insert 2 10 at begin+1 so if v={1,2,3} then after this v={1,10,10,2,3}

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end()); // this will insert the entire copy vector in the start of vector v

    cout << v.size();

    v.pop_back(); // pops out the last element
    v.clear();    // Erases the enitre vector contents.
    v1.swap(v2);

    cout << v.empty(); // bool output
}

void explainList()
{
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);
    // push front is very cheap in comparison to vector insert
    ls.emplace_front();
    {2, 4};

    // rest of the functions are saem as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void Dequeue()
{
    // all function are same as vector
}

void stack()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << st.top(); // prints 6
    st.pop();         // removes the latest addded element that is 6

    cout << st.top();
    cout << st.size();
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);

    // Every Operation happens in O(1).
}

void QUEUE()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);
    q.back() += 5;
    cout << q.back();
    cout << q.front();
    q.pop();
    cout << q.front();
}

void PriorityQueue()
{
    priority_queue<int> pq;

    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(10);

    cout << pq.top();

    pq.pop();
    cout << pq.top();

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << pq.top();

    // push happens in log(N)
    // pop happens in log(N)
    // top happens in O(1)
}

// Set --> It is sorted and only has unique elements.
// Operation --> find, erase, count,

// MultiSet --> It is sorted but can contain multiple instances of the same element that is it is not unique
// All Ooperations are same as set except erase. In erase , it only deletes that elements rather than all the saem elements .

// unorder set --> in this the set contains unique elements only and they are notsorted
// Most of the operations are O(1) and there is only 1 case where o(N) is present which is the worst case.

// Map --> map<int , int> where first int is key and second is value.
// All the keys are unique in sorted order but can have same value.
//  the data type can be anything from int to char, to pair.

// MultiMap is same as multiset is to set. We can basically store duplicate keys
//  only mpp[kye] cannot be used here

// Unordered Map --> same difference as set and unodered set that is it is not sorted but the keys are unique

// WE can also sort . there is a build in function sort(a,b) which will sort it .

//__builtin_popcount() tells us how many ones does a number's binary form has fro example for 7 it will return 3
//__builtin_popcountll() is used if the number is long long.

// next_permutation permutates all the possible next sequence . for example 231 will be 123,etc. Note that for having all permutations it should be sorted
//  *max_element is used to get the max element in a range.
z

    int
    main()
{
    explainPair();
    return 0;
}