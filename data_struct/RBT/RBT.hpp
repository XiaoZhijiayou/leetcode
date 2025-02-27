//红黑树的性质
//1.节点非黑即红
//2.根节点是黑色
//3.叶子节点(NIL节点)是黑色
//4.如果一个节点是红色节点，那么这个节点的子节点都是黑色，也就说不会有相邻的红色节点
//5.从根节点出发到叶子节点的路径上，黑色节点的数量相同
//本质上，红黑树也是通过树高来控制平衡。
//红黑树比AV L AVLAVL树树高控制条件要更松散，红黑树在发生节点插入和删除后，发生调整的概率比AVL树要更小
//注意的点：
//1.特性(3)中的叶子节点，是只为空(NIL或null)的节点。
//2.特性(5)，确保没有一条路径会比其他路径长出俩倍。因而，红黑树是相对是接近平衡的二叉树。
//调整策略
//1.插入调整站在祖父节点向下看
//2.删除调整站在父节点看
//3.插入和删除的情况一共五种

#pragma once
#include <iostream>

enum RBTColor{RED,BLACK};
template <class T>
class RBTNode{
    public:
        RBTColor color;//颜色
        T key;          //关键字（键值）
        RBTNode *left;  //左孩子
        RBTNode *right;//右孩子
        RBTNode *parent;//父节点
        RBTNode(T value,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r):
            key(value),color(c),parent(p),left(l),right(r){}
};
template<class T>
class RBTree{
    private:
        RBTNode<T> *mRoot;//根节点
    public:
        RBTree();
        ~RBTree();

        //前序遍历红黑树
        void preOrder();
        //中序遍历
        void inOrder();
        //后序遍历
        void postOrder();

        //（递归实现）查找"红黑树"中键值为key的节点
        RBTNode<T>* search(T key);
        //(非递归实现)查找"红黑树"中键值为key的节点
        RBTNode<T>* iterativeSearch(T key);

        //查找最小节点：返回最小节点的键值
        T minimum();
        //查找最大节点：返回最大节点的键值
        T maximum();

        // 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
        RBTNode<T>* successor(RBTNode<T> *x);
         // 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
        RBTNode<T>* predecessor(RBTNode<T> *x);

        // 将结点(key为节点键值)插入到红黑树中
        void insert(T key);

        // 删除结点(key为节点键值)
        void remove(T key);

        // 销毁红黑树
        void destroy();

        // 打印红黑树
        void print();
    private:
        // 前序遍历"红黑树"
        void preOrder(RBTNode<T>* tree) const;
        // 中序遍历"红黑树"
        void inOrder(RBTNode<T>* tree) const;
        // 后序遍历"红黑树"
        void postOrder(RBTNode<T>* tree) const;

        // (递归实现)查找"红黑树x"中键值为key的节点
        RBTNode<T>* search(RBTNode<T>* x, T key) const;
        // (非递归实现)查找"红黑树x"中键值为key的节点
        RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

        // 查找最小结点：返回tree为根结点的红黑树的最小结点。
        RBTNode<T>* minimum(RBTNode<T>* tree);
        // 查找最大结点：返回tree为根结点的红黑树的最大结点。
        RBTNode<T>* maximum(RBTNode<T>* tree);

        // 左旋
        void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
        // 右旋
        void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
        // 插入函数
        void insert(RBTNode<T>* &root, RBTNode<T>* node);
        // 插入修正函数
        void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
        // 删除函数
        void remove(RBTNode<T>* &root, RBTNode<T> *node);
        // 删除修正函数
        void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

        // 销毁红黑树
        void destroy(RBTNode<T>* &tree);

        // 打印红黑树
        void print(RBTNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)        
};

template<class T>
void RBTree<T>::preOrder(RBTNode<T> *node) const{
    if (node != nullptr) {
        std::cout << node->key << " ";  // Output the key
        preOrder(node->left);           // Traverse left subtree
        preOrder(node->right);          // Traverse right subtree
    }
}

template<class T>
void RBTree<T>::inOrder(RBTNode<T> *node) const{
    if (node != nullptr) {
        inOrder(node->left);            // Traverse left subtree
        std::cout << node->key << " ";  // Output the key
        inOrder(node->right);           // Traverse right subtree
    }
}

template<class T>
void RBTree<T>::postOrder(RBTNode<T> *node) const{
    if (node != nullptr) {
        postOrder(node->left);          // Traverse left subtree
        postOrder(node->right);         // Traverse right subtree
        std::cout << node->key << " ";  // Output the key
    }
}

//左旋部分代码
template<class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root,RBTNode<T>* x){
    RBTNode<T> *y = x->right;
    //这是x的右节点部分
    x->right = y->left;
    if(y->left)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == nullptr){
        root = y;   //如果x为根节点，就将y设为根节点
    }
    else{
        if(x->parent->left == x)
            x->parent->left = y;//如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
        else
            x->parent->right = y;// 如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
    }
    // 将 “x” 设为 “y的左孩子”
    y->left = x;
    // 将 “x的父节点” 设为 “y”
    x->parent = y;
}

template<class T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y){
    // 设置x是当前节点的左孩子。
    RBTNode<T>* x = y->left;
    // 将 “x的右孩子” 设为 “y的左孩子”；
    // 如果"x的右孩子"不为空的话，将 “y” 设为 “x的右孩子的父亲”
    y->left = x->right;
    if(x->right)
        x->right->parent = y;
    // 将 “y的父亲” 设为 “x的父亲”
    x->parent = y->parent;
    if(y->parent == nullptr){
        root = x;               //如果 “y的父亲” 是空节点，则将x设为根节点
    }
    else{
        if(y->parent->left == y)     // 如果 y是它父节点的右孩子，则将x设为“y的父节点的右孩子”
            y->parent->left = x;    // (y是它父节点的左孩子) 将x设为“x的父节点的左孩子”
        else 
            y->parent->right = x;
    }
    // 将 “y” 设为 “x的右孩子”
    x->right = y;
    // 将 “y的父节点” 设为 “x”
    y->parent = x;
}
//root 红黑树的根结点
//node 插入的结点 
template<class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node){
    RBTNode<T> *y = nullptr;
    RBTNode<T> *x = root;

    //1.将红黑树当作一颗二叉查找树，将结点添加到二叉查找树中
    while(x != NULL){
        y = x;//这个操作是将y与x进行绑定，让x为null时候的，y正好是他的parent结点，正好x进行插入上node结点
        if(node->key < x->key)
            x = x->left;
        else 
            x = x->right;
    }

    node->parent = y;//这一步是将node向y进行连接起来

    if(y != nullptr){
        if(node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else 
        root = node;
    //这一部分就是用来将y与node进行连接

    //2.将加进来的结点颜色变为红色
    node->color = RED;
    //3.将他重新修正为一颗二叉查找树
    insertFixUp(root,node);
}
template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root,RBTNode<T>* node){
    RBTNode<T> *parent,*gparent;
    //若“父节点存在，并且父节点的颜色是红色
    while((parent = rb_parent(node))&&rb_is_red(parent)){//这里是因为：node也是红，父节点也是红，违反了红不能连红的错误
        gparent = rb_parent(parent);

        //若“父节点”是祖父结点的左孩子
        if(parent = gparent->left){
            //case1:叔叔结点颜色是红色
            {
                RBTNode<T> *uncle = gparent->right;
                if(uncle && rb_is_red(uncle)){
                    //红叔:叔父爷染色，爷变成新节点
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;//相当于继续进行下一次的while循环形式
                }
            }
            // Case 2条件：叔叔是黑色是gparent的右孩子，且当前节点是右孩子,父亲结点是gparent的左孩子
            if(parent->right == node){//这种情况下，应该是LR形式：左右双旋，儿换爷+染色
                //这一部分先进行了简单的左旋，然后把左旋之后，把下次右旋的部分重新补上，改一下parent的和新节点的分布
                RBTNode<T> *tmp;
                leftRotate(root,parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            //Case 3条件：叔叔是黑色，且当前节点是左孩子。
            //这种情况下是：LL就直接转换就可以了父亲换爷并染色
            rb_set_black(parent);
            rb_set_red(gparent);
            rightRotate(root,gparent);
        }else{//若“z的父节点”是“z的祖父节点的右孩子”
            // Case 1条件：叔叔节点是红色
            {
                RBTNode<T> *uncle = gparent->left;
                if (uncle && rb_is_red(uncle)){
                    //红叔:叔父爷染色，爷变成新节点
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }
            //Case 2条件：叔叔是黑色，且当前节点是左孩子
            if(parent->left == node){//RL:右左双旋，儿换爷+染色
                RBTNode<T> *tmp;
                rightRotate(root,parent);
                tmp = parent;
                parent = node;
                node = tmp;//这样的就变成了全右的排列形式
            }
            //Case 3条件：叔叔是黑色，且当前节点是右孩子。
            rb_set_black(parent);
            rb_set_red(gparent);
            leftRotate(root,gparent);
        }
    }
    //将根节点设为黑色
    rb_set_black(root);
}
// Constructor
template<class T>
RBTree<T>::RBTree() : mRoot(nullptr) {}

// Destructor
template<class T>
RBTree<T>::~RBTree() {
    destroy(mRoot);
}

// (Recursive) Search
template<class T>
RBTNode<T>* RBTree<T>::search(T key) {
    return search(mRoot, key);
}

// (Iterative) Search
template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key) {
    return iterativeSearch(mRoot, key);
}

// Minimum node search
template<class T>
T RBTree<T>::minimum() {
    RBTNode<T>* node = minimum(mRoot);
    if (node)
        return node->key;
    return T(); // return default value if no node
}


//这下面的都是public函数
template<class T>
void RBTree<T>::insert(T key){
    RBTNode<T> *z = nullptr;
    if((z = new RBTNode<T>(key,BLACK,nullptr,nullptr,nullptr)) == nullptr)
        return ;
    insert(mRoot,z);
}
template<class T>
void RBTree<T>::preOrder() {
    preOrder(mRoot);                    // Call the recursive pre-order function
    std::cout << std::endl;
}

template<class T>
void RBTree<T>::inOrder() {
    inOrder(mRoot);                     // Call the recursive in-order function
    std::cout << std::endl;
}

template<class T>
void RBTree<T>::postOrder() {
    postOrder(mRoot);                   // Call the recursive post-order function
    std::cout << std::endl;
}





