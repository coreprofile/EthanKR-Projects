#include<iostream> //duh..
#include<vector> //for a vector array to hold our numbers
#include<string> //for storing the user input with std::string
#include<algorithm> //for std::sort to order our vector array
#include<map> //for std::map to hold a key value(our incrementer), and a key(our float value)

using namespace std;

//to do : I think median is returning the wrong value so check that out, but i need to finish Mode Marked with //FIX NOW
int main(void)
{
    /* Init variables and tell user instructions*/
    cout<<"Put numbers in one by one followed by the return (enter) key between each one,"<<"\n"
    <<"You may put them in whatever order you want,"<<"\n"<<"after you enter your last number hit return,"
    "then hit the D key and return."<<"\n"<<"THIS PROGRAM DOES NOT FIND MODE IF THERE IS MULTIPLE MODES, BUT IT WILL TRY!"<<"\n";
    
    vector<float> Storage;
    string TempStorage;
    float TempNumStorage;
    float Median = 0.0f;
    float Mean = 0.0f;
    float Range = 0.0f;
    bool IsDone = false;
    float Sum = 0.0f;
    bool IsError = false;
    float Mode = 0.0f;
    map<float, int> ModeMap;
    map<float, int>::iterator ITR;
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
                Sum += n;
            }
        break;
        }
    
    //converting out input into a floating point value
    try
    {
    TempNumStorage = stof(TempStorage);
    }
    catch(const invalid_argument& ia)
    {
        IsError = true;
        cerr<<"Invalid Input"<<endl;
    }
    //WE ALREADY HAVE THE MODE IN THE MAP WE JUST NEED TO EXTRACT
    //pushing the converted floating point value into our vector array
    if(!IsError)
    {
            if(ModeMap.find(TempNumStorage) == ModeMap.end())
            {
                ModeMap.insert(pair<float, int>(TempNumStorage, 0));
            }
            else
            ModeMap.find(TempNumStorage)->second += 1;
            Storage.push_back(TempNumStorage);
    }
    else
    {
        Storage[Storage.size()] = TempNumStorage;
        IsError = false;
    }
    //resetting our string and float storage;
    TempStorage = "";
    TempNumStorage = 0;

    }
    //end while
    
    sort(Storage.begin(), Storage.end());
    
    Mean = Sum/Storage.size();
    cout<<"Mean : "<<Mean<<"\n";
    int CurrentMode = 0;

    for(ITR = ModeMap.begin(); ITR != ModeMap.end(); ++ITR)
    {
        if(ITR->second > CurrentMode)
        {
            CurrentMode = ITR->first;
        }
    }
    Mode = CurrentMode;
    float CurrentMax = 0.0f;

    if(Storage.size() % 2 != 0)
    {
        int Indexer = Storage.size();
        
        Median = Storage[Indexer/2];
        cout<<"Median : "<<Median<<"\n";
        cout<<"Mode "<<Mode<<std::endl;
        sort(Storage.begin(), Storage.end());
        Range = Storage.end() - Storage.begin() - 1;
        cout<<"Range : "<<Range<<endl;
        Indexer = 0;
        Median = 0.0f;
        Mean = 0.0f;
        cout<<"Your pretty ordered data set : "<<endl;
        for(int n : Storage)
        {
            cout<<n<<", ";
        }
        cout<<"\n";
        Storage.clear();
        ModeMap.clear();
        
        cout<<"Would you like to go again? (y/n) "<<endl;
        getline(cin, TempStorage);
        if(TempStorage == "y" || TempStorage == "Y")
        {
            main();
        }
    }
    else
    {
        int Indexer = Storage.size();
        Median = (Storage[Indexer/2 + 1] + Storage[Indexer / 2]) /2;
        cout<<"Median : "<<Median<<"\n";
        cout<<"Mode : "<<Mode<<std::endl;
        sort(Storage.begin(), Storage.end());
        Range = Storage.end() - Storage.begin() - 1;
        Indexer = 0;
        Median = 0.0f;
        Mean = 0.0f;
        cout<<"Your pretty ordered data set : "<<endl;
        for(int n : Storage)
        {
            cout<<n<<", ";
        }
        cout<<"\n";
        Storage.clear();
        ModeMap.clear();
        cout<<"Would you like to go again? (y/n) "<<endl;
        getline(cin, TempStorage);
        if(TempStorage == "y" || TempStorage == "Y")
        {
            main();
        }
    }
    cout<<"Exiting... Return 0"<<"\n";
    return 0;
}
