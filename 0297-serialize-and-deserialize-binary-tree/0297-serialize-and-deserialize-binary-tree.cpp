class Codec {
public:


string serialize(TreeNode* root) {
    if (root == nullptr) {
        return "null,";
    }

    return to_string(root->val) + "," +
           serialize(root->left) +
           serialize(root->right);
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    string value;

    getline(ss, value, ',');

    if (value == "null") {
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(value));

    root->left = deserializeHelper(ss);
    root->right = deserializeHelper(ss);

    return root;
}


private:


TreeNode* deserializeHelper(stringstream& ss) {
    string value;

    getline(ss, value, ',');

    if (value == "null") {
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(value));

    root->left = deserializeHelper(ss);
    root->right = deserializeHelper(ss);

    return root;
}


};
