class Tree {
private:
    int height;
    char symbol;
    string color;

    int** tab;
    int x, y;

public:
    void printTree();
    Tree(int h, char s, string c);

    ~Tree();

    friend class Forest;
};