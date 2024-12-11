/*
 * Salma Gamal Kamel
 * 8/12/2024 updated 9/12/2024
 *  Skip List
 */
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int maxLevel = 4; // Maximum Level of the skip list

struct  node {
    public:
    int data;
    vector<node*> next;     // To maintain the levels of the skip list
    node(int d,int l):data(d),next(l+1,nullptr){}// declaring the data and the level of the node
};
// The skipList
// A skip list is a data structure that allows for efficient search,
// insertion and deletion of elements in a sorted list.It is a probabilistic data structure,
// skip lists provide a simple and efficient alternative to balanced trees for certain use cases, particularly when the average number of elements in the list is large.

class skipList
{
private:
    node* header;
    int level;
public:
    skipList();
    ~skipList();

    void insert(int data);
    void remove(int data);
    bool search(int data);
    void display();
};

//constructor of the skipList class
skipList::skipList()
{
    header=new node(0, maxLevel);
    level=0;
}

//destructor
skipList::~skipList() {
    delete header;
}


//                    *Insertion in skip list*
//The average time complexity of insertion in a skip list is O(log n)
void skipList::insert(int data)
{
    int newLevel = 0;
    // Deciding the level of inserting node on the basis of coin toss
    //rand() returns a random integer
    while (newLevel < maxLevel && rand() % 2 == 1) {  // Simulate coin toss
        newLevel++;
    }
    // Resizing the size of the levels .
    if (level< newLevel)
    {
        header->next.resize(newLevel + 1);
        level = newLevel;

    }

    node* curr = header; //pointer to the header to traverse through the skip list
    vector<node*> update(level+1,nullptr); // To store the update node at each level
    // Loop over the levels upto which we want the value to be inserted
    for (int i = level; i >= 0; i--)
    {
        // Finding the place for the inserting value
        while (curr->next[i]  && curr->next[i]->data < data)
        {
            curr = curr->next[i];
        }
        update[i] = curr;
    }
    curr = curr->next[0];   // Moves the current to the next node at level 0
    if(curr==nullptr || curr->data != data) // if the current is null then it does not exist we need to insert the value
    {
        node* newNode = new node(data, level);
        for (int i=0; i <= newLevel; i++)
        {
            newNode->next[i] = update[i]->next[i]; // Make new node point to the next node
            update[i]->next[i] = newNode;  // Make the previous node point to the new node
        } cout << data << " inserted successfully.\n";

    }
    else
    {
        cout<< data << " already exists.\n";  // Incase if value already exists
    }
}

//                    *Deletion in skip list*
//The average time complexity of deletion in a skip list is O(log n)

void skipList::remove(int data) {
    node* curr = header;  // start by setting a current pointer to the header node
    vector<node*> update(level+1); // Create an update vector to store the updated node at each level,

    for (int i = level; i >= 0; i--)
    {
        while (curr->next[i]  && curr->next[i]->data < data)
        {
            curr = curr->next[i];
        }
        update[i] = curr;
    }

    curr = curr->next[0]; // Set the current pointer to the next node at level 0.
    if(curr != nullptr && curr->data == data)// If the value is present then delete the value
    {
        for (int i=0; i <= level; i++)  // Deleting the value from each level
        {
            //setting the pointers
            if(update[i]->next[i]!=curr)
                break;
            update[i]->next[i] = curr->next[i];
        }
        delete curr; // deleting the node

        while (level > 0 && header->next[level]==nullptr)// decrement the level variable incase there is not any value at that level
        {
            level--;//when a level becomes completely empty.
        }

        cout<< data << " deleted successfully.\n";
    }
    else
    {
        cout << data << " not found.\n";
    }
}


//                    *Searching in skip list*
//The efficient searching mechanism gives the skip list priority over the other data structure. While searching, it utilizes the advantage of skipping over large portions of the data from the upper layers
// This helps achieve a faster search time compared to a simple linked list, while still being simpler and more flexible than more complex balanced trees like AVL or Red-Black trees.
//he average time complexity of search in a skip list is O(log n)

bool skipList::search(int data)
{
  node* curr = header;

    for (int i = level; i >= 0; i--)// Begin traversing from the top level and iteratively approaching the bottom of the skip list
    {
        while (curr->next[i]  and curr->next[i]->data < data)// keep on moving forward if the value of the next node is less than the searching node otherwise  move downward (handled by outer for loop)
        {
            curr = curr->next[i];// moving forward
        }
    }
    curr = curr->next[0];// Move to the next of the node at level 0
    if (curr != nullptr && curr->data == data) //if value is found
    {
        cout << data << " found.\n";
        return true;
    }
    else // Incase value does not exist
    {
        cout << data << " not found.\n";
        return false;
    }
}

//*Display skip list*
void skipList::display()
{
    cout<<"Displaying the list:\n";
    for (int i = level; i >= 0; i--) {
        node* curr = header;
        cout<<"Level "<<i<<": ";
        while (curr->next[i])
        {
            cout<<curr->next[i]->data<<" ";
            curr = curr->next[i];
        }cout<<"\n";
    }
}

int main()
{

    skipList SkipList;

    SkipList.insert(10);
    SkipList.insert(20);
    SkipList.insert(60);
    SkipList.insert(30);
    SkipList.insert(40);
    SkipList.insert(50);
    SkipList.insert(60);
    SkipList.insert(70);
    SkipList.insert(80);
    SkipList.insert(90);
    SkipList.insert(100);

    SkipList.display();



    SkipList.search(20);
    SkipList.search(40);
    SkipList.search(120);


    SkipList.remove(20);
    SkipList.remove(40);
    SkipList.remove(120);


    SkipList.display();

    return 0;
}
