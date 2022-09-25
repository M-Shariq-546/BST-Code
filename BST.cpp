#include<iostream>
using namespace std;
class Node
{
    int data;
    Node* left;
    Node* right;
    public:
        //Node Constructor to initialize the values
        Node(int data=-1 , Node*right = NULL , Node* left = NULL)
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

        //Recursion occurs here
        void preOrder(Node * now)
        {
            if(now == NULL)
                return;
        visitRoot(now);
        preOrder(now->getLeft());
        preOrder(now->getRight());
        }


        //Recursion occurs here
        void inOrder(Node * now)
        {
            if(now == NULL)
                return;
        inOrder(now->getLeft());
        visitRoot(now);
        inOrder(now->getRight());
        }

        //Recursion occurs here
        void postOrder(Node * now)
        {
            if(now == NULL)
                return;
        postOrder(now->getLeft());
        postOrder(now->getRight());
        visitRoot(now);
        }

        //Functions of Pre , In and Post order to display the elements of tree

        void preOrderTraversal()
        {
            cout<<"Pre-Order Traversal is here : ";
            //Recursion initiated here and start the traversal
            preOrder(root);
            cout<<"\n";
        }

        void inOrderTraversal()
        {
            cout<<"In-Order Traversal is here : ";
            //Recursion initiated here and start the traversal
            inOrder(root);
            cout<<"\n";
        }

        void postOrderTraversal()
        {
            cout<<"Post-Order Traversal is here : ";
            //Recursion initiated here and start the traversal
            postOrder(root);
            cout<<"\n";
        }
        //Sab Hazir hon.....
        void printAll()
        {
            inOrder(root);
        }

        //New Member Entry in Family
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
            return (now->getLeft()==NULL&& now->getRight()==NULL);
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

        //Bhara Buzurg of Family ...
        int Predeccessor(Node* now)
        {
            return LargestElement(now->getLeft());
        }
        //Bacha ghr ha k ni .....
        bool doesExist(int x)
        {
            Node * now = root;
            while(now != NULL)
            {
                if(x < now->getData())
                {
                    now = now->getLeft();
                }
                else if(x > now->getData())
                {
                    now = now->getRight();
                }

                return true;
                
            }
            return false;
        }

};

int main()
{
    Node * root = NULL;
    BST s , s1;
    s.insertVal(1);
    s.insertVal(2);
    s.insertVal(3);
    s.insertVal(4);
    
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"\t"<<"First Tree Info : "<<endl;

    s.postOrderTraversal();
    s.inOrderTraversal();
    s.preOrderTraversal();
    cout<<"All Elements of Tree through inorder Traversal : ";
    s.printAll();
    cout<<endl<<"Value Exist or Not (1 for YES , 0 for NO) : "<<s.doesExist(3)<<endl;
    //cout<<s.Predeccessor(root)<<endl;
    
    s1.insertVal(71);
    s1.insertVal(72);
    s1.insertVal(73);
    s1.insertVal(74);

    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"\t"<<"Second Tree Info : "<<endl;

    s1.postOrderTraversal();
    s1.inOrderTraversal();
    s1.preOrderTraversal();
    cout<<"All Elements of Tree through inorder Traversal : ";
    s1.printAll();
    cout<<endl<<"Value Exist or Not (1 for YES , 0 for NO) : "<<s1.doesExist(72)<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    return 0;
}
