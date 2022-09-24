#include<iostream>
using namespace std;
class Node
{
    int data;
    Node* left;
    Node* right;
    public:
        Node(int data=-9999 , Node*right = NULL , Node* left = NULL)
        {
            setData(data);
            setRight(right);
            setLeft(left);
        }
        void setData(int data)
        {
           this->data = data;
        }
        int getData()
        {
            return data;
        }
        void setLeft(Node * left)
        {
             this->left = left;
        }
        Node* getLeft()
        {
            return left;
        }
        void setRight(Node * right)
        {
            this->right = right;
        }
        Node* getRight()
        {
            return right;
        }
};

//Binary Search Tree Class

class BST
{
    Node * root;
    public:
        void setRoot(Node* root)
        {
            this->root = root;
        }
        Node *getRoot()
        {
            return root;
        }
        BST(Node* root = NULL)
        {
            setRoot(root);
        }
        bool isEmpty()
        {
            return (root == NULL);
        }

        void visitRoot(Node * root)
        {
            cout<<root->getData();
        }
        void preOrder(Node * now)
        {
            if(now == NULL)
                return;
        visitRoot(now);
        preOrder(now->getLeft());
        preOrder(now->getRight());
        }


        void inOrder(Node * now)
        {
            if(now == NULL)
                return;
        inOrder(now->getLeft());
        visitRoot(now);
        inOrder(now->getRight());
        }


        void postOrder(Node * now)
        {
            if(now == NULL)
                return;
        postOrder(now->getLeft());
        postOrder(now->getRight());
        visitRoot(now);
        }


        //Functions of Pre , In and Post order to display the elements of tree

        void preOrder()
        {
            cout<<"Pre-Order Traversal is here : ";
            preOrder(root);
            cout<<"\n";
        }

        void inOrder()
        {
            cout<<"In-Order Traversal is here : ";
            inOrder(root);
            cout<<"\n";
        }

        void postOrder()
        {
            cout<<"Post-Order Traversal is here : ";
            postOrder(root);
            cout<<"\n";
        }

        void printAll()
        {
            inOrder(root);
        }


        void insertVal(int x)
        {
            Node * temp = new Node(x);
            if(isEmpty())
            {
                root = temp;
                return;
            }
            Node * now = root;
            while(true)
            {
                if(x > now->getData())
                {
                    if(now->getRight() == NULL)
                    {
                        now->setRight(temp);
                        return;
                    }
                    now = now->getRight();
                }

                else{
                    if(x < now->getData())
                    {
                        if(now->getLeft() == NULL)
                    {
                        now->setLeft(temp);
                        return;
                    }
                    now = now->getLeft();
                    }
                }
            }
        }


        //Childless Element
        bool isLeaf(Node* now)
        {
            if(now->getLeft()==NULL&& now->getRight()==NULL)
            {
                return true;
            }
            else
            return false;
        }


        //Leaf Nodes ???
        bool isExternal(Node* now)
        {
            if(isLeaf(now)==false)
            {
                return true;
            }
            else
            return false;
        }

        //Parent or Not
        bool isFullParent(Node* now)
        {
            if(now->getLeft()!=NULL && now->getRight()!=NULL)
            {
                return true;
            }
            else
            return false;
        }


        //Single Parent??
        bool isSingleParent(Node* now)
        {
            if(!isLeaf(now))
            {
                return true;
            }
            else
            return false;
        }


        //Eldest Child of Family
        int LargestElement(Node* now)
        {
            LargestElement(now->getRight());
            if(now->getRight()==NULL)
            {
                return now->getData();
            }
        }


        //Choota Packet of Family
        int LowestElement(Node* now)
        {
            if(now->getLeft()==NULL)
            {
                return now->getData();
            }
            LowestElement(now->getRight());
        }

        //Next Generation
        int Successor(Node* now)
        {
            return LowestElement(now->getRight());
        }

        //Bhara Buzurg of Family
        int Predeccessor(Node* now)
        {
            return LargestElement(now->getLeft());
        }

        void deleteElement(Node* now,int x)
        {
            if(now==NULL)
            return;
            
            
            if(x<now->getData())
            deleteElement(now->getLeft(),x);
            
            
            else if(x>now->getData())
            deleteElement(now->getRight(),x);

            else
            {
                if(now->getLeft()==NULL && now->getRight()==NULL)
                {
                    delete now;
                    now=NULL;
                    return;
                }
                else if(now->getLeft() == NULL)
                {
                    Node* temp=now->getRight();
                    delete now;
                    now=temp;
                    return;
                }
                else if(now->getRight() == NULL)
                {
                    Node* temp=now->getLeft();
                    delete now;
                    now=temp;
                    return;
                }
                Node* temp1;
                //temp1 = LowestElement(root->getRight());
                //root->getData() = temp1->getData();
                deleteElement(now->getRight(),temp1->getData());
            }
            return;
        }
};



int main()
{
    BST s , s1;
    s.insertVal(1);
    s.insertVal(2);
    s.insertVal(3);
    s.insertVal(4);
    

    s.postOrder();
    s.inOrder();
    s.preOrder();


    s1.insertVal(71);
    s1.insertVal(72);
    s1.insertVal(73);
    s1.insertVal(74);

    //s1.isFullParent(root);
    
    return 0;
}
