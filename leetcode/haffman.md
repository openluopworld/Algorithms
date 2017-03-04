# Haffman算法
2014.11.03

Huffman编码，C++实现，只是为了说明大致的思路，还有很多不完美之处，比如在输入数据超出限制等条件下会出现错误。

```C++
#include<iostream>
#include<string>
using namespace std;
#define MAX 20

/*
** 用二叉树表示的Huffman节点
*/
typedef struct NodeTag {
    char c;                     // 字母
    int weight;                 // 频率
    string code;                // 编码后的字符串
    struct NodeTag * lchild;    // 左孩子
    struct NodeTag * rchild;    // 右孩子
} Node; 


class Container {
    
    private:
        Node *nodes[MAX];       // 保存各节点指针的数组
        int size;               // 节点的个数
    
    public:
        Container () {
            size = 0;
            for ( int i = 0; i < MAX; i++ ) {
                nodes[i] = NULL;
            }
        }
        
        /*
        ** 采用插入排序的方法，将节点node加入到数组nodes中，按照weight从小到大排列
        */
        void push ( Node *node ) {
            int weight = node->weight;
            int i = size-1;
            while ( i >= 0 && weight > nodes[i]->weight ) {
                nodes[i+1] = nodes[i];
                i--;
            }
            nodes[i+1] = node;
            size++;
        }

        /*
        ** 返回weight值最小的一个节点
        */
        Node * pop () {
            Node *node = nodes[size-1]; 
            size--;
            return node;
        }
        
        /*
        ** 返回当前的节点数目
        */
        int getSize() {
            return size;
        }
    
};

/*
** 对所有的叶子节点进行编码，得到各字母的码表
** root：指向根节点的指针；code：本节点的编码
*/
int huffmanCode( Node *root, const string code ) {

    root->code = code;
    string temp;

    if( root != NULL ){

        // 叶子节点，则输出编码方式
        if( root->rchild == NULL && root->lchild == NULL ) {
            cout<<root->c<<":"<<root->weight<<" "<<root->code<<endl;
        } else {
            temp = code;
            huffmanCode ( root->lchild, temp.append("0") );   // 会增加上去，不用重新赋值
            temp = code;
            huffmanCode ( root->rchild, temp.append("1") );
        }

    }

    return 0;

}

/*
** Huffman编码的函数
** letter：字母表；weight：各字母的频率；length：字母的总个数
*/
void haffman ( char letter[], int weight[], int length ) {

    Node *node = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Container *obj = NULL;
    
    obj = new Container();
    
    for ( int i = 0; i < length; i++ ) {
        /*
        ** 创建一个新节点node,节点字符为c[i],频率为weight[i],左右孩子都为Null;
        ** 将node按从小到大的顺序加入到容器obj中;
        */
        node = new Node();
        node->c = letter[i];
        node->weight = weight[i];
        node->lchild = NULL;
        node->rchild = NULL;
        obj->push(node);
    }
    
    cout<<"All nodes are pushed into the queue:"<<obj->getSize()<<endl;
    
    /*
    ** 当容器中只有一个元素时，该元素即为指向Huffman编码二叉树的根节点的指针
    */
    while ( obj->getSize() > 1 ) {
        /*
        ** 选出最小的两个元素,创建一个新的父节点,频率为两者之和,将父节点加入到队列中;
        */
        first = obj->pop();
        second = obj->pop();
        node = new Node();
        node->weight = first->weight + second->weight;   // 非根节点的字母不重要，故不用赋值
        node->lchild = first;
        node->rchild = second;
        obj->push(node);
    }
    
    cout<<"After the Haffman code:"<<obj->getSize()<<endl;
    
    /*
    ** 采用中根次序遍历方法对二叉树进行遍历，得到每个叶子节点的编码
    */
    node = obj->pop();
    cout<<node->weight<<endl;
    huffmanCode( node, "");
    
}

int main () {
    char letter[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int weight[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int length = 8;
    haffman( letter, weight, length );
    return 0;
}
```
