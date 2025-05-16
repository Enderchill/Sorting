#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <fstream>

using namespace std;

void modifiedSortGPA(double array1[], int array2[], string array3[], int numElems);
void modifiedSortID(int array2[], double array1[], string array3[], int numElems);
//double randGPA();
int getUserChoice();
int linearSearchID(int arr[], int numElems, int ID, int &nIter);
int binarySearchID(int arr[], int numElems, int ID, int &nIter);

int main()
{
    /********************************************
     Start of code that Students should copy and paste
     *******************************************/
    const int NUM_ELMTS = 18;
    
    // netID and GPA are parallel arrays
    int netID[NUM_ELMTS]; // Original netID array
    double GPA[NUM_ELMTS]; // Original GPA array
    string major[NUM_ELMTS]; // Original major array
    
    // sortedNetIDbyGPA and sortedGPAbyGPA are parallel arrays
    int sortedNetIDbyGPA[NUM_ELMTS]; // netID array,sorted by GPA
    double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
    string sortedMajorbyGPA[NUM_ELMTS]; // Major array, sorted by GPA
    
    // sortedNetIDbyID and sortedGPAbyID are parallel arrays
    int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
    double sortedGPAbyID[NUM_ELMTS]; // GPA array, sorted by netID
    string sortedMajorbyID[NUM_ELMTS]; // Major array, sorted by netID
    
    /********************************************
     End of code that Students should copy and paste
     *******************************************/
    
    //ask user for input and store then attempt to open file
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    ifstream inputFile(filename);
    
    if (!inputFile) //check if the file can be
    {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl; //check endl
        return 0;
    }
    else
    {
        //read in inital values into orginal array
        int count = 0;
        while(inputFile >> netID[count] >> major[count] >> GPA[count]) {
            count++;
        }
        
        
        //Copy Orginal to arrays
        
        for (int i = 0;i< count;i++)
        {
            sortedGPAbyGPA[i] = GPA[i];
            sortedMajorbyGPA[i] = major[i];
            sortedNetIDbyGPA[i] = netID[i];
            
            sortedGPAbyID[i] = GPA[i];
            sortedMajorbyID[i] = major[i];
            sortedNetIDbyID[i] = netID[i];
        }
        
        
        
        
        
        
        //Display Arrays
        cout << fixed;
        //setup for orginal array
        cout << "Original arrays:" << endl;
        cout << "----------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(7) << "GPA" << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(7) << "GPA" << endl;
        
        //loop until all have been printed
        for (int i = 0;i<count;i++)
        {
            cout << setw(7) << i << setw(7) << netID[i] << setw(7) << major[i] << setw(7) << setprecision(2) << GPA[i];
            if (i % 2 > 0) //formating
            {
                cout << endl; //if the index is odd than it goes to a new line
            }
        }
        
        //display GPA array
        modifiedSortGPA(sortedGPAbyGPA, sortedNetIDbyGPA, sortedMajorbyGPA, count);
        
        
        cout << "Arrays sorted by GPA:" << endl;
        cout << "---------------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(7) << "GPA" << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(7) << "GPA" << endl; //formatting
        
        //loop until all have been printed
        for (int i = 0;i<count;i++)
        {
            cout << setw(7) << i << setw(7) << sortedNetIDbyGPA[i] << setw(7) << sortedMajorbyGPA[i] << setw(7) << setprecision(2) << sortedGPAbyGPA[i]; //format
            if (i % 2 > 0)
            {
                cout << endl; //if the index is odd than it goes to a new line
            }
        }
        
        
        //display NETID array
        modifiedSortID(sortedNetIDbyID, sortedGPAbyID, sortedMajorbyID, count);
        
        
        cout << "Arrays sorted by netID:" << endl;
        cout << "-----------------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(7) << "GPA" << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(7) << "GPA" << endl; //format
        
        //loop until all have been printed
        for (int i = 0;i<count;i++)
        {
            cout << setw(7) << i << setw(7) << sortedNetIDbyID[i] << setw(7) << sortedMajorbyID[i] << setw(7) << setprecision(2) << sortedGPAbyID[i]; //format
            if (i % 2 > 0)
            {
                cout << endl; //if the index is odd than it goes to a new line
            }
        }
        
        
        
        //Print Menu loop
        
        while(true)
        {
            cout << endl; //check format endl
            cout << "***************" << endl; //menu format
            cout << "Menu of choices" << endl;
            cout << "***************" << endl;
            cout << "1 - List top n students" << endl;
            cout << "2 - Search on a netID" << endl;
            cout << "3 - Quit" << endl;
            
            //process user input
            int choice = 0;
            cin >> choice;
            
            if(choice == 3) //terminate
            {
                cout << "Exiting" << endl;
                inputFile.close();
                return 0; //end program
            }
            else if(choice == 2) // initate linear and binary search for a net id
            {
                //prompt user and store answer
                int idChoice = 0;
                cout << "Enter netID: ";
                cin >> idChoice;
                
                cout << endl; //format endl check
                
                //call function and declare iteration variable and output
                int iter = 0;
                int index = linearSearchID(netID, count, idChoice, iter);
                cout << "Result of linear search:" << endl;
                cout << "------------------------" << endl;
                if (index > -1) //if found, print results
                {
                    cout << "Student found at index " << index << ", GPA is " << setprecision(2)<<GPA[index] << endl;
                    cout << "It took " << iter << " iterations" << endl;
                }
                else//if return -1, means nothing is found
                {
                    cout << "Student not found" << endl;
                    cout << "It took " << iter << " iterations" << endl;
                }
                
                cout << endl; //format endl check
                
                //call function and output
                index = binarySearchID(sortedNetIDbyID, count, idChoice, iter); //call
                cout << "Result of binary search:" << endl;
                cout << "------------------------" << endl;
                if (index > -1) //if found, print results
                {
                    cout << "Student found at index " << index << ", GPA is " << setprecision(2)<<sortedGPAbyID[index] << endl;
                    cout << "It took " << iter << " iterations" << endl;
                }
                else //if return -1, means nothing is found
                {
                    cout << "Student not found" << endl;
                    cout << "It took " << iter << " iterations" << endl;
                }
                cout << endl; //format endl check
                
            }
            else if(choice == 1)
            {
                int nRange = 0; //the user choice
                cout << "Enter n: "; //prompt
                cin >> nRange;
                if (nRange > count) //if user choice surpasses max elemnts, print only max elemns
                {
                    cout << "Top 10 students are:" << endl;
                }
                else
                {
                    cout << "Top " << nRange << " students are:" << endl; //print top n
                }
                cout << endl; //format endl check;
                
                for (int i = count - 1; i >= 0 && i > count - nRange;i--)
                {
                    cout << "netID: " << sortedNetIDbyGPA[i] << ", major: " << sortedMajorbyGPA[i] << ", GPA: " << setprecision(2)<< sortedGPAbyGPA[i] << endl; //format
                }
                
                cout << endl; //format endl check
            }
        }
        
    }
}



void modifiedSortGPA(double array1[], int array2[], string array3[], int size)
{
    //selection sort
    for (int start = 0; start < size -1; start++)
    {
        double i = array1[start]; //initlize min value/index
        int j = start;
        for (int index = start + 1; index < size;index++)
        {
            
            if (array1[index] < i)
            {
                i = array1[index];
                j = index;
            }
        }
        swap (array1[j],array1[start]); //swap primary array and then make sure other arrays stay parallel
        swap (array2[j],array2[start]);
        swap (array3[j],array3[start]);
    }
}
    
    
    
    
void modifiedSortID(int array2[], double array1[], string array3[], int size)
{
    
    //selection
    for (int start = 0; start < size -1; start++)
    {
        double i = array2[start]; //initlize min value/index
        int j = start;
        for (int index = start + 1; index < size;index++)
        {
            
            if (array2[index] < i)
            {
                i = array2[index];
                j = index;
            }
        }
        swap (array2[j],array2[start]); //swap primary array and then make sure other arrays stay parallel
        swap (array1[j],array1[start]);
        swap (array3[j],array3[start]);
    }
}


int linearSearchID(int arr[], int numElems, int value, int &nIter)
{
    nIter = 0; //make sure vari is set to 0 everytime we search
    for (int i = 0; i < numElems;i++)
    {
        nIter++; //increase iteration count
        if (arr[i] == value)
        {
            return i; //return index
        }
    }
    return -1;
}


int binarySearchID(int arr[], int numElems, int value, int &nIter)
{
    //binary search
    nIter = 0;
    int middle = 0;
    int low = 0; //set low and high
    int high = numElems - 1;
    while (low <= high)
    {
        nIter++; //increase iter
        middle = (low + high) / 2;
        if (arr[middle] == value)
        {
            return middle;
        }
        else if (arr[middle] < value) //if middle is lower, make low equal to middle +1
        {
            low = middle +1;
        }
        else if (arr[middle] > value) //if the middle is higher than key, lower high to middle -1
        {
            high = middle -1;
        }
        
    }
    return -1;
}
