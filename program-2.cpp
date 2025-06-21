#include<iostream>
#include<vector>
using namespace std;

class Searching
{
public:
    // Displaying Current Array 
    void DisplayArray(vector<int>& array)
    {
        cout << "Current Array Is :- ";
        for (int i = 0; i < array.size(); i++)
        {
            cout << array.at(i) << " ";
        }
    }

    // Inserting Element 
    void Insert(vector<int>& array)
    {
        int num;
        cout << "Enter An Element To Insert At " << array.size() << " :- ";
        cin >> num;
        array.push_back(num);
    }

    // Quick Sort Algorithm
    void QuickSort(vector<int>& array,int start,int end)
    {
        if (start < end)
        {
            int pivot = Partition(array,start,end);
            QuickSort(array,start,pivot - 1);
            QuickSort(array,pivot + 1,end);
        }
    }

    // Partitioning Algorithm To Help In Quick Sorting
    int Partition(vector<int>& array,int start,int end)
    {
        int PivotIndex = array[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (array[j] < PivotIndex)
            {
                i++;
                swap(array[i],array[j]);
            }
        }
        swap(array[i + 1],array[end]);
        return i + 1;
        
    }

    // Merge Algorithm To Help In Merge Sorting
    void Merge(vector<int>& array,int start,int mid,int end)
    {
        vector<int> temp;
        int i = start,j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (array[i] < array[j])
            {
                temp.push_back(array[i++]);
            }
            else
            {
                temp.push_back(array[j++]);
            }
        }

        while (i <= mid)
        {
            temp.push_back(array[i++]);
        }

        while (j <= end)
        {
            temp.push_back(array[j++]);
        }
        
        for (int k = 0; i < temp.size(); i++)
        {
            array[start + k] = temp[k];
        }
    }
    
    // Merge Sort Algorithm
    void MergeSort(vector<int>& array,int start,int end)
    {
        if (start < end)
        {            
            int mid = start + (end - start) / 2;
            MergeSort(array,start,mid);
            MergeSort(array,mid + 1,end);
            Merge(array,start,mid,end);       
        }
    }

    // Binary Sort Algorithm
    int BinarySearch(vector<int>& array,int start,int end)
    {
        DisplayArray(array);
        cout << endl;
        
        int target;

        if (IsSorted(array))
        {
            cout << endl << "Enter An Element To Search :- ";
            cin >> target;

            int mid = start + (end - start) / 2;

            if (mid == target)
            {
                return mid;
            }
            else if (target < mid)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }            
            return -1;
        }
        else
        {
            return -2;
        }        
    }

    // IsSorted Algorithm That Checks If The Array Is Sorted Or Not
    bool IsSorted(vector<int>& array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] > array[i + 1]) return false;
        }
        return true;
    }

};

int main()
{
    // Taken A Object To Access All The Method Of Class
    Searching obj;
    // Declared A Dynamic Vector
    vector<int> array;
    cout << "=============================" << endl;
    cout << "Welcome To Algorithm Checker." << endl;
    cout << "=============================" << endl;
    int choice,result;
    do
    {
        cout << endl << "========== Menu =========" << endl;
        cout << "1. Insert." << endl;
        cout << "2. Display List." << endl;
        cout << "3. Current Size." << endl;
        cout << "4. Sort Array." << endl;
        cout << "5. Binary Search." << endl;
        cout << "0. To Exit." << endl;
        cout << "====================" << endl;

        // TAking Chaoce As Input
        cout << "Enter Your Choice :- ";
        cin >> choice;

        // Switch Case Will Run A Block Of Code According To User Choice
        switch (choice)
        {
        case 0:
            cout << "Program Is Sucessfully Executed...." << endl;
            cout << "Thanks For Comming Have A Good Day...." << endl;
            cout << "Press Enter To Exit....";
            cin.ignore();
            cin.get();
            break;
        case 1: obj.Insert(array); break;
        
        case 2: obj.DisplayArray(array); break;
        
        case 3: cout << "Current Size Of Array Is :- " << array.size() << endl; break;
        
        case 4:
            int choice_1;
                cout << endl << "========== Menu =========" << endl;
                cout << "1. Merge Sort." << endl;
                cout << "2. Quick Sort." << endl;
                cout << "0. To Exit." << endl;
                cout << "====================" << endl;

                cout << "Enter Your Choice :- ";
                cin >> choice_1;

                switch (choice_1)
                {
                case 1:
                    obj.MergeSort(array,0,array.size() - 1);
                    break;
                
                case 2:
                    obj.QuickSort(array,0,array.size() - 1);
                    break;
                    
                case 0:
                    cout << "Program Is Successfully Executed." << endl;
                    break;

                default:
                    cout << "Wrong Choice Please Try Again..." << endl;
                    break;
                }
            break;

        case 5:
            result = obj.BinarySearch(array,0,array.size());
            if (result > 0 && result < array.size())
            {
                cout << endl << "The Element Is Founded At " << result << " Index." << endl;
            }
            else if (result == -1)
            {
                cout << endl << "The Element Is Not Founded In The Array." << endl;
            }
            else
            {
                cout << endl << "The Array Is Not Sorted Please Sort It First." << endl;
            }
            break;
            
        default:
            cout << endl << "Invaild Option.... Please Try Again" << endl;
            break;
        }

    } while (choice != 0);
    
    return 0;
}