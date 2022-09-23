#include<iostream>
using namespace std;
class Node
{
    Node * left;
    Node * right;
    int data;
    public:
        Node(int data)
        {
            right = left = NULL;
            data = this->data;
        }
        void setData(int data)
        {
            data = this->data;
        }
        int getData()
        {
            return this->data;
        }
        void setLeft(Node * left)
        {
            left = this->left;
        }
        Node* getLeft()
        {
            return this->left;
        }
        void setRight(Node * right)
        {
            right = this->right;
        }
        Node* getRight()
        {
            return this->right;
        }
};



class BST
{
    Node * root;
    public:
        bool isEmpty(Node * root)
        {
            return (root == NULL);
        }

        bool isFull(Node* root)
        {
            if(root->getLeft() && root->getRight())
            {
                return true;
            }
            if((root->getRight())&& (root->getLeft()))
            {
                return (isFull(root->getLeft())&&isFull(root->getRight()));
            }

            return false;
        }
        Node * getRoot(Node *root)
        {
            return root;
        }
        Node * getRightChild(Node * root)
        {
            return root->getRight();
        }
        Node * getLeftChild(Node * root){
            return root->getLeft();
        }
        void visitRoot(Node * root)
        {
            cout<<root->getData();
        }
        void preOrder(Node * root)
        {
            if(root == NULL)
                return;
        visitRoot(root);
        preOrder(root->getLeft());
        preOrder(root->getRight());
        }


        void inOrder(Node * root)
        {
            if(root == NULL)
                return;
        inOrder(root->getLeft());
        visitRoot(root);
        inOrder(root->getRight());
        }


        void postOrder(Node * root)
        {
            if(root == NULL)
                return;
        postOrder(root->getLeft());
        postOrder(root->getRight());
        visitRoot(root);
        }


        void printAll()
        {
            inOrder(root);
        }


        void insertVal(int x , Node * root)
        {
            Node *temp = root;
            Node * A = new Node(x);
            if(x <= temp->getData())
            {
                insertVal(x, temp->getLeft());
            }
            else{
                insertVal(x , temp->getRight());
            }
        }


        //Childless Element
        bool isLeaf(Node* root)
        {
            if(root->getLeft()==NULL&& root->getRight()==NULL)
            {
                return true;
            }
            else
            return false;
        }


        //Leaf Nodes ???
        bool isExternal(Node* root)
        {
            if(isLeaf(root)==true)
            {
                return true;
            }
            else
            return false;
        }

        //Having Atleast 1 child
        bool isInternal(Node* root)
        {
            return !isLeaf(root);
        }

        //Parent or Not
        bool isFullParent(Node* root)
        {
            if(root->getLeft()!=NULL&&root->getRight()!=NULL)
            {
                return true;
            }
            else
            return false;
        }


        //Single Parent??
        bool isSingleParent(Node* root)
        {
            if(!isLeaf(root)&&!isFull(root))
            {
                return true;
            }
            else
            return false;
        }


        //Eldest Child of Family
        int LargestElement(Node* root)
        {
            LargestElement(root->getRight());
            if(root->getRight()==NULL)
            {
                return root->getData();
            }
        }


        //Choota Packet of Family
        int LowestElement(Node* root)
        {
            if(root->getLeft()==NULL)
            {
                return root->getData();
            }
            LowestElement(root->getRight());
        }

        //Next Generation
        int Successor(Node* root)
        {
            return LowestElement(root->getRight());
        }

        //Bhara Buzurg of Family
        int Predeccessor(Node* root)
        {
            return LargestElement(root->getLeft());
        }

        void deleteElement(Node* root,int x)
        {
            if(root==NULL)
            return;
            
            
            if(x<root->getData())
            deleteElement(root->getLeft(),x);
            
            
            else if(x>root->getData())
            deleteElement(root->getRight(),x);

            else
            {
                if(root->getLeft()==NULL && root->getRight()==NULL)
                {
                    delete root;
                    root=NULL;
                    return;
                }
                else if(root->getLeft() == NULL)
                {
                    Node* temp=root->getRight();
                    delete root;
                    root=temp;
                    return;
                }
                else if(root->getRight() == NULL)
                {
                    Node* temp=root->getLeft();
                    delete root;
                    root=temp;
                    return;
                }
                Node* temp1;
                //temp1 = LowestElement(root->getRight());
                //root->getData() = temp1->getData();
                deleteElement(root->getRight(),temp1->getData());
            }
            return;
        }
};



int main()
{
    BST s;
    Node* root=NULL;
    s.insertVal(1, root);
    s.insertVal(2, root);
    s.insertVal(3, root);
    s.insertVal(4, root);
    
    s.isFullParent(root);
    
    return 0;
}