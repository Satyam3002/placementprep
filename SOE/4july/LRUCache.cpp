struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
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
        head->prev = tail;
        tail->next = head;
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
            Node *nodeToDelete = tail->next;
            remove(nodeToDelete);
            dic.erase(nodeToDelete->key);
        }
    }

    void add(Node *node)
    {
        Node *firstNode = head->prev;
        firstNode->next = node;
        node->prev = firstNode;
        node->next = head;
        head->prev = node;
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