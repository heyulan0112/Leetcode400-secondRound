/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Idea: level traverse
    // Time complexity O(n)
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* node = q.front();
                q.pop();
                if(size == 0){
                    node->next = NULL;
                }
                else{
                    node->next = q.front();
                }
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
