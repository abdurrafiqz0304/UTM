#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Car {
    string model;
    string color;
    double price;
    double deposit;
};

struct TreeNode {
    Car info;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(Car item) {
    TreeNode* newNode = new TreeNode;
    newNode->info = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertItem(TreeNode* root, Car item) {
    if (root == NULL) {
        return createNode(item);
    }

    if (item.model < root->info.model) {
        root->left = insertItem(root->left, item);
    } else if (item.model > root->info.model) {
        root->right = insertItem(root->right, item);
    }

    return root;
}

void printTree(TreeNode* root) {
    if (root != NULL) {
        printTree(root->left);

        cout << fixed << setprecision(2);
        cout << "Model   : " << root->info.model << endl;
        cout << "Color   : " << root->info.color << endl;
        cout << "Price   : RM " << root->info.price << endl;
        cout << "Deposit : RM " << root->info.deposit << endl;
        cout << "--------------------------" << endl;

        printTree(root->right);
    }
}

TreeNode* retrieveItem(TreeNode* root, string model) {
    if (root == NULL)
        return NULL;

    if (model == root->info.model)
        return root;
    else if (model < root->info.model)
        return retrieveItem(root->left, model);
    else
        return retrieveItem(root->right, model);
}

TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

TreeNode* deleteItem(TreeNode* root, string model) {
    if (root == NULL)
        return root;

    if (model < root->info.model) {
        root->left = deleteItem(root->left, model);
    } 
    else if (model > root->info.model) {
        root->right = deleteItem(root->right, model);
    } 
    else {
        // Node found
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->info = temp->info;
        root->right = deleteItem(root->right, temp->info.model);
    }
    return root;
}

int main() {
    TreeNode* root = NULL;
    int choice;
    Car car;
    string model;

    do {
        cout << "\n=== MYCAR COMPANY SYSTEM ===\n";
        cout << "1. Insert Car\n";
        cout << "2. Delete Car\n";
        cout << "3. Search Car\n";
        cout << "4. Print All Cars\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Car Model: ";
            getline(cin, car.model);
            cout << "Color Type: ";
            getline(cin, car.color);
            cout << "Price: ";
            cin >> car.price;
            cout << "Deposit: ";
            cin >> car.deposit;
            root = insertItem(root, car);
            cout << "Car inserted successfully.\n";
            break;

        case 2:
            cout << "Enter car model to delete: ";
            getline(cin, model);
            root = deleteItem(root, model);
            cout << "Car deleted (if existed).\n";
            break;

        case 3:
            cout << "Enter car model to search: ";
            getline(cin, model);
            {
                TreeNode* result = retrieveItem(root, model);
                if (result != NULL) {
                    cout << "Car Found!\n";
                    cout << "Model   : " << result->info.model << endl;
                    cout << "Color   : " << result->info.color << endl;
                    cout << "Price   : RM " << result->info.price << endl;
                    cout << "Deposit : RM " << result->info.deposit << endl;
                } else {
                    cout << "Car not found.\n";
                }
            }
            break;

        case 4:
            printTree(root);
            break;

        case 5:
            cout << "Thank you.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    system("pause");
    return 0;
}
