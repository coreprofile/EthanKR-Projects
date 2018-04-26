#include<iostream> //duh..
#include<vector> //for a vector array to hold our numbers
#include<string> //for storing the user input
#include<algorithm> //for std::sort and 

using namespace std;

int main(void)
{
    /* Init variables and tell user instructions*/
    cout<<"Put numbers in one by one followed by the return (enter) key between each one,"<<"\n"
    <<"You may put them in whatever order you want,"<<"\n"<<"after you enter your last number hit return,"
    "then hit the D key and return."<<"\n";
    vector<float> Storage;
    string TempStorage;
    float TempNumStorage;
    float Median = 0.0f;
    float Mean = 0.0f;
    bool IsDone = false;
    float Sum = 0.0f;
    /*End Init*/
    
    //start while
    while(!IsDone)
    {
    getline(cin, TempStorage);
    /* DO INPUT CHECKING TO SEE IF NUMBER*/
        if(TempStorage == "d" || TempStorage == "D")
        {
            IsDone = true;
             for(int n : Storage)
        {
            cout<<n<<"\n";
            Sum += n;
        }
            break;
        }
    
    //converting out input into a floating point value
    TempNumStorage = stof(TempStorage);
    //pushing the converted floating point value into our vector array
    Storage.push_back(TempNumStorage);
    
    //resetting our string and float storage;
    TempStorage = "";
    TempNumStorage = 0;
    //done resetting.
    
    }
    //end while
    
    sort(Storage.begin(), Storage.end());
    
    Mean = Sum/Storage.size();
    cout<<"Mean : "<<Mean<<"\n";
    if(Storage.size() % 2 != 0)
    {
        int Indexer = Storage.size();
        Median = Storage[Indexer/2];
        cout<<"Median : "<<Median<<"\n";
        cout<<"Mode has not been implemented yet "<<"\n";
    }
    else
    {
        float Indexer = Storage.size();
        Median = (Storage[Indexer/2 + 1] + Storage[Indexer])/2;
        cout<<"Median : "<<Median<<"\n";
        cout<<"Mode has not been implemented yet "<<"\n";
    }
    cout<<"Exiting... Return 0"<<"\n";
    return 0;
}





