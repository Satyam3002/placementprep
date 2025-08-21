struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int k, int v)
    {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
public:
    int capacity;
    unordered_map<int, Node *> dic;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (dic.find(key) == dic.end())
        {
            return -1;
        }
        Node *node = dic[key];
        remove(node);
        add(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (dic.find(key) != dic.end())
        {
            Node *oldNode = dic[key];
            remove(oldNode);
        }
        Node *node = new Node(key, value);
        dic[key] = node;
        add(node);

        if (dic.size() > capacity)
        {
            Node *TailPrevNode = tail->prev;
            remove(TailPrevNode);
            dic.erase(TailPrevNode->key);
        }
    }

    void add(Node *node)
    {
        Node *HeadNext = head->next;
        head->next = node;
        node->next = HeadNext;
        node->prev = head;
        HeadNext->prev = node;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */