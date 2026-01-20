#include <iostream>
using namespace std;

class TreeType {
    public: 
        TreeType();
        ~TreeType();
        bool IsEmpty() const;
        int NumberOfNodes() const;
        void RetrieveItem(int item, bool& found) const;
        void InsertItem(int item);
        void DeleteItem(int item);
        void PrintTree() const;
        private:
            struct TreeNode {
                int info;
                TreeNode* left;
                TreeNode* right;
            };
            TreeNode* root;
            void Destroy(TreeNode*&);
        };

TreeType::TreeType() {
    root = nullptr;
}