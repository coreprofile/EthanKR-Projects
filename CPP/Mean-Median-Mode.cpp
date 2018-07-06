#include<iostream> //duh..
#include<vector> //for a vector array to hold our numbers
#include<string> //for storing the user input with std::string
#include<algorithm> //for std::sort to order our vector array
#include<map> //for std::map to hold a key value(our incrementer), and a key(our float value)

using namespace std;

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
                //if we cant find the number we entered in the map then we insert with a counter of zero
                ModeMap.insert(pair<float, int>(TempNumStorage, 0));
            }
            else
                //if we do find it we add one to its counter
                ModeMap.find(TempNumStorage)->second += 1;
                Storage.push_back(TempNumStorage);
        }
        //FIX seg fault we cant find the first value
        else
        {
            Storage[Storage.size()] = TempNumStorage;
            IsError = false;
        }
        //resetting our string and float storage;
        TempStorage = "";
        TempNumStorage = 0;

    }

    sort(Storage.begin(), Storage.end());
    //WHERE SECOND IS THE INDEX AND FIRST IS THE FLOATING POINT VALUE
    Mean = Sum/Storage.size();
    cout<<"Mean : "<<Mean<<"\n";
    int CurrentMode = 0;
    bool IsFinished = false;

    // push to another vector array then once done push new array to old and clear new

    for(ITR = ModeMap.begin(); ITR != ModeMap.end(); ++ITR)
    {

        if (ITR->second > CurrentMode)
        {
            std::cout<<"DELETED ITR--"<<std::endl;
            IsFinished = false;
            CurrentMode = ITR->first;
            ModeMap.erase(ITR--);
        } else
            IsFinished = true;
        if(IsFinished)
        {
            //iterating through final map
            for(ITR = ModeMap.begin(); ITR != ModeMap.end(); ++ITR)
            {
                //FIX LOOP
                std::cout<<"Number : "<<ITR->first<<std::endl;
            }
        }
    }

    Mode = CurrentMode;
    float CurrentMax = 0.0f;


    //IF ODD AMOUNT OF ELEMENTS IN DATA SET THEN CALL THIS
    if(Storage.size() % 2 != 0)
    {
        int Indexer = Storage.size();

        Median = Storage[Indexer/2];
        cout<<"Median : "<<Median<<"\n";
        if(Mode != 0)
        {
            cout<<"Mode : "<<Mode<<std::endl;
        }
        else
        {
            cout<<"Mode : No Mode"<<endl;
        }
        sort(Storage.begin(), Storage.end());
        Range = Storage.back() - Storage.front();
        cout<<"Range : "<<Range<<endl;
        Indexer = 0;
        Median = 0.0f;
        Mean = 0.0f;
        Mode = 0.0f;
        Range = 0.0f;
        cout<<"Your ordered data set : "<<endl;
        for(int n : Storage)
        {
            cout<<n<<", ";
        }
        cout<<"\n";
        Storage.clear();
        ModeMap.clear();

        cout<<"Would you like to go again? (y/n) "<<endl;
        getline(cin, TempStorage);
        if(TempStorage == "y" || TempStorage == "Y" || TempStorage == "yes" || TempStorage == "Yes")
        {
            main();
        }
    }
        //IF EVEN AMOUNT OF ELEMENTS IN DATA SET THEN CALL THIS
    else
    {
        //CHANGE PLUS 1 ON FIRST
        int Indexer = Storage.size();
        Median = (Storage[Indexer/2 - 1] + Storage[Indexer / 2]) /2;
        cout<<"Median : "<<Median<<"\n";
        if(Mode != 0)
        {
            cout<<"Mode : "<<Mode<<std::endl;
        }
        else
        {
            cout<<"Mode : No Mode"<<endl;
        }
        sort(Storage.begin(), Storage.end());
        Range = Storage.back() - Storage.front();
        cout<<"Range : "<<Range<<endl;
        Indexer = 0;
        Median = 0.0f;
        Mean = 0.0f;
        Mode = 0.0f;
        Range = 0.0f;
        cout<<"Your ordered data set : "<<endl;
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
    return 0;
}
