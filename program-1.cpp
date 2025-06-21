#include<iostream>
using namespace std;

class Node
{
public:
    // Data
    int data;
    // Pointer To The Next Node 
    Node* link;
    
    Node(int data)
    {
        this->data = data;
        this->link = nullptr;
    }
};

class LinkedList
{
public:
    Node* head;
    int size;

    // CONSTRUCTOR
    LinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    // Printing The Entire List
    void DisplayList()
    {
        Node* ptr = this->head;
        cout << "Current List :- ";
        for (int i = 0; i < this->size; i++)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->link;
        }
        cout << "NULL" << endl;
    }

    // Insert A New Node At Front  
    void InsertAtFront()
    {
        int data;
        cout << "Enter Data To Insert At Fornt :- ";
        cin >> data;
        Node* NewNode = new Node(data);
        NewNode->link = this->head;
        this->head = NewNode;
        this->size++;
        cout << "Insertion Is Done Successfully." << endl;
    }

    // Inserting A New Node At End
    void InsertAtEnd()
    {
        if (this->head == nullptr)
        {
            InsertAtFront();
        }
        else
        {
            int data;
            cout << "Enter Data To Insert At End :- ";
            cin >> data;
            Node* newNode = new Node(data);

            Node* ptr = this->head;
            while (ptr->link != nullptr)
            {
                ptr = ptr->link;
            }
            ptr->link = newNode;
            this->size++;
            cout << "Insertion Is Done Successfully." << endl;
        }
    }

    // Inserting A New Node At Index
    void InsertAtIndex()
    {
        int index,data;
        cout << "Enter Index To Add Element At :- ";
        cin >> index;

        if (index < 0 || index > this->size)
        {
            cout << endl << "Index Out Of Bound....Please Try Again" << endl;
            while (index < 0 || index > this->size)
            {
                cout << "Enter Index To Add Element At :- ";
                cin >> index;
            }
        }

        if (this->head == nullptr)
        {
            InsertAtFront();
        }
        else
        {
            cout << "Enter Data To Insert At " << index << " Index :- ";
            cin >> data;
            Node* newNode = new Node(data);
            Node* ptr = this->head;
            
            for (int i = 0; i < index - 1; i++)
            {
                ptr = ptr->link;
            }
            newNode->link = ptr->link;
            ptr->link = newNode;
            this->size++;
            cout << "Insertion Is Done Successfully." << endl;
        }
    }
    
    // Deleting A Node From Front
    void DeleteAtFront()
    {
        if (this->head == nullptr)
        {
            cout << endl << "The List Is Already Empty Nothing To Delete." << endl;
        }
        else
        {
            this->head = this->head->link;
            this->size--;
            cout << "Deletion Is Done Successfully." << endl;
        }
    }
    // Deleting A Node From End
    void DeleteAtEnd()
    {
        if (this->head == nullptr)
        {
            cout << endl << "The List Is Already Empty Nothing To Delete." << endl;
        }
        else
        {
            Node* ptr = this->head;
            while (ptr->link->link != nullptr)
            {
                ptr = ptr->link;
            }
            ptr->link = nullptr;
            this->size--;
            cout << "Deletion Is Done Successfully." << endl;
        }
    }

    // Deleting A Node At Index
    void DeleteAtIndex()
    {
        int index,data;
        cout << "Enter Index To Delete Element At :- ";
        cin >> index;

        if (index < 0 || index > this->size)
        {
            cout << endl << "Index Out Of Bound....Please Try Again" << endl;
            while (index < 0 || index > this->size)
            {
                cout << "Enter Index To Delete Element At :- ";
                cin >> index;
            }
        }
        if (this->head == nullptr)
        {
            cout << endl << "The List Is Already Empty Nothing To Delete." << endl;
        }
        else
        {
            Node* ptr = this->head;
            for (int i = 0; i < index-1; i++)
            {
                ptr = ptr->link;
            }
            ptr->link = ptr->link->link;
            this->size--;
            cout << "Deletion Is Done Successfully." << endl;
        }
    }

    // Updating A Node data At Index
    void Update()
    {
        int index,data;
        cout << "Enter Index To Update Element At :- ";
        cin >> index;

        if (index < 0 || index > this->size)
        {
            cout << endl << "Index Out Of Bound....Please Try Again" << endl;
            while (index < 0 || index > this->size)
            {
                cout << "Enter Index To Update Element At :- ";
                cin >> index;
            }
        }

        if (this->head == nullptr)
        {
            InsertAtFront();
        }
        else
        {
            cout << "Enter Data To Update At " << index << " Index :- ";
            cin >> data;
            Node* newNode = new Node(data);
            Node* ptr = this->head;
            
            for (int i = 0; i < index; i++)
            {
                ptr = ptr->link;
            }
            ptr->data = data;
            cout << "Updation Is Done Successfully." << endl;
        }
    }

    // Returning The Current Size
    int Size()
    {
        return this->size;
    }

    // Clear Whole List
    void ClearList()
    {
        this->head = nullptr;
        this->size = -1;
        cout << "List Is Cleared Successfully." << endl;
    }
};

int main()
{
    // Taking To Access All The Method Of Class
    LinkedList obj;
    cout << "================================" << endl;
    cout << "Welcome To Linked List Programs." << endl;
    cout << "================================" << endl;
    int choice;
    do
    {
        cout << endl << "========== Menu =========" << endl;
        cout << "1. Insert At Front." << endl;
        cout << "2. Insert At End." << endl;
        cout << "3. Insert At Index." << endl;
        cout << "4. Delete At Front." << endl;
        cout << "5. Delete At End." << endl;
        cout << "6. Delete At Index." << endl;
        cout << "7. Update An Element." << endl;
        cout << "8. Display List." << endl;
        cout << "9. Current Size." << endl;
        cout << "10. Clear List." << endl;
        cout << "0. To Exit." << endl;
        cout << "====================" << endl;

        // Taking Choice To Perform Task
        cout << "Enter Your Choice :- ";
        cin >> choice;

        // Different Cases Will Run According To User Choice
        switch (choice)
        {
        case 1: obj.InsertAtFront(); break;
        
        case 2: obj.InsertAtEnd(); break;
        
        case 3: obj.InsertAtIndex(); break;
        
        case 4: obj.DeleteAtFront(); break;
        
        case 5: obj.DeleteAtEnd(); break;
        
        case 6: obj.DeleteAtIndex(); break;
        
        case 7: obj.Update(); break;
        
        case 8: obj.DisplayList(); break;
        
        case 9: cout << "The Current Size If The List Is :- " << obj.Size() << "."; break;
        
        case 10: obj.ClearList(); break;

        case 0:
            cout << "Program Is Sucessfully Executed...." << endl;
            cout << "Thanks For Comming Have A Good Day...." << endl;
            cout << "Press Enter To Exit....";
            cin.ignore();
            cin.get();
            break;
        
        default:
            cout << endl << "Invaild Option.... Please Try Again" << endl;
            break;
        }
    } while (choice != 0);
    
    return 0;
}