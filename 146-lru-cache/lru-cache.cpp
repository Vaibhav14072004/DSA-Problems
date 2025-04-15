// Approach 2 -> Optimized (Doubly Linked List)
// TC= O(1)

class LRUCache {
public:
    
    class Node{
      public:
         int key;
         int val;
         Node* next;
         Node* prev;

         Node(int key,int val){
            this->val= val;
            this->key= key;
         }
    };

    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    // {key, Node*}
    unordered_map<int,Node*> mp;
    int n;

    LRUCache(int capacity) {
        n= capacity;
        head->next= tail;
        tail->prev= head;
    }


    void deleteNode(Node* temp)
    {
       Node* prevNode= temp->prev;
       Node* nextNode= temp->next;
       prevNode->next= nextNode;
       nextNode->prev= prevNode;
    }


    void addNode(Node* temp)
    {
        Node* headNext= head->next;
        temp->next= headNext;
        temp->prev= head;
        head->next= temp;
        headNext->prev= temp;
    }

    
    int get(int key)
    {
        int val= -1;
        if(mp.find(key) != mp.end())
        {
            Node* temp= mp[key];
            val= temp->val;
            mp.erase(key);

            deleteNode(temp);
            addNode(temp);

            mp[key]= head->next;
        }
       return val; 
    }


    void put(int key, int value)
    {
        if(mp.find(key) != mp.end())
        {
           Node* temp= mp[key];
           mp.erase(key);

           deleteNode(temp);
           addNode(new Node(key,value));
           mp[key]= head->next;  
           return;
        }

        // if key is NOT found in map, check capacity of cache
        // if caoacity is full, delete the tail->prev node

        if(mp.size()== n)
        {
            Node* tailPrev= tail->prev;
            deleteNode(tailPrev);
            mp.erase(tailPrev->key);
        }

        addNode(new Node(key,value));
        mp[key]= head->next;
    }
};








// ------- TLE -------------
// Brute Force Approach -> Using vector<pair<int,int>> 
// TC= O(N^2)

/*

class LRUCache {
public:
    vector<pair<int,int>> vec;
    int n;

    LRUCache(int capacity) {
        n= capacity;
    }
    
    int get(int key) 
    {
        int val= -1;
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i].first== key)
            {
                val= vec[i].second;

                // erase the entry from middle and put it in back, showing that it is recently used
                pair<int,int> temp= vec[i];
                vec.erase(vec.begin()+i);   // erase STL function takes O(N) time
                vec.push_back(temp);
            }
        }
        return val;
    }
    

    void put(int key, int value)
    {
        // first find key, if it exists, update the value and push it in back
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i].first== key)
            {
                vec.erase(vec.begin()+i);
                vec.push_back({key,value});
                return;
            }
        }

        // if this key,value pair is NOT found, check the size
        // if size is already full, delete first element that was not recently used
        if(vec.size()== n)
        {
            vec.erase(vec.begin());
        }   
         
        vec.push_back({key,value});
    }
};

*/



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */