#include <bits/stdc++.h>
// #include <windows.h>
// doctor prescription programme
using namespace std;
class Medicine{
private:
    vector<pair<string,int>>med;
    
public:
    auto add_medicine(string name,int dose)->void{
        med.push_back({name,dose});
    }
    void List_medicine(){
        system("Color 0A");
         cout<<"------------------------------------------\n";
        // cout<<"Name:  "<<name<<"\t\t"<<"Age: "<<age<<endl;
        cout<<"Mdicine name\t\t"<<"Dose\n";
        for(auto it:med){
            cout<<"|"<<it.first<<"\t"<<it.second<<"|"<<endl;
        }
        
        cout<<"------------------------------------------\n";
    }
    friend class prescription;
};

class prescription{
  private:
  vector<pair<string,int>>list;
    // string Med_name;
    // int dose;
    
public:
    void add(string name,int d){
        // Med_name=name;
        // dose=d;
        list.push_back({name,d});
        // cout<<list[0].first<<endl;
        // cout<<list[0].second<<endl;
    }
    void print(string name,int age){
        cout<<"------------------------------------------\n";
        cout<<"Name:  "<<name<<"\t\t"<<"Age: "<<age<<endl;
        for(auto it:list){
            cout<<"|"<<it.first<<"\t"<<it.second<<"|"<<endl;
        }
        
        cout<<"------------------------------------------\n";
        
        // cout<<"review in pres\n";
    }
};

class Patient{
private:
    string Name;
    int age;
    string Address;
    string Complications="";
    // vector<pair<string,int>>prescription;
    prescription pr;
public:
    Patient(string Name,int age,string Address,string Complications=""){
        this->Name=Name;
        this->age=age;
        this->Address;
        this->Complications=Complications;
    }
    void Review_pre(){
        // cout<<"Reviewing in Patient"<<endl;
        cout<<Name<<endl;
        pr.print(Name,age);
    }
    void include(string name,int d){
        pr.add(name,d);
    }
    Patient(){
        
    }
};

int main()
{
    // cout<<"Hello World";
    Medicine Med;
    int number;
    cout<<"Go with number 0 if wanted to modify medicine data\n";
    cout<<"Go with number 1 if wanted to continue with patient\n";
    cin>>number;
    if(number==0){
        string Med_name;
        int Dose;
        do{
            // cout<<"Press number 1 for Creaing prescription"<<endl;
            cout<<"Press number 2 for Adding medicine"<<endl;
            cout<<"Press number 3 for Listing medicine"<<endl;
            cout<<"Press 0 to exit"<<endl;
            cin>>number;
            switch (number){
                
                
                case 2:
                    cout<<"Enter Medicine name\n";
                    cin>>Med_name;
                    cout<<"Enter Dose for the medicine\t" <<Med_name<<endl;
                    cin>>Dose;
                    Med.add_medicine(Med_name,Dose);
                    break;
                    
                case 3:
                    Med.List_medicine();
                
                    
            }
        }while(number!=0);
        cout<<"Go with number 0 if wanted to modify medicine data\n";
        cout<<"Go with number 1 if wanted to continue with patient\n";
        cin>>number;
    
    }
    
    if (number ==1){
        Patient* p;
        string Med_name;
        int Dose;
        int stop=0;
        do{
            if(!stop)
                cout<<"Press number 1 for Creaing prescription"<<endl;
            cout<<"Press number 2 for Reviewing prescription"<<endl;
            cout<<"Press number 3 for Adding  medicine"<<endl;
            cout<<"Press 0 to exit"<<endl;
            cin>>number;
            switch (number){
                case 1:{
                    
                    string Name,Address,Complications;
                    int age;
                    cout<<"Enter Name of Patient"<<endl;
                    cin>>Name;
                    cout<<"Enter Age of Patient"<<endl;
                    cin>>age;
                    cout<<"Enter Address of Patient"<<endl;
                    cin>>Address;
                    cout<<"If there are any Complications press 5 \n";
                    cout<<"If there is no complication press 0\n";
                    int flag;
                    cin>>flag;
                    if(flag==5)
                    {
                        cout<<"Enter Complications"<<endl;
                        cin>>Complications;
                    }
                    stop=1;
                    p=new Patient(Name,age,Address,Complications);
                    break;
                }
                case 2:{
                    p->Review_pre();
                    break;
                }
                case 3:{
                    int temp,d;
                    string name;
                    cout<<"Press -1 to stop creating prescription\n";
                    cout<<"press 5 for adding\n";
                    cin>>temp;
                    if(temp==5){
                        cin>>name>>d;
                        p->include(name,d);
                    }
                    break;
                }
            }
        }while(number!=0);
    }
    // cout<<"Press number 1 for Creaing prescription"<<endl;
    // cout<<"Press number 2 for Adding medicine"<<endl;
    // cout<<"Press number 3 for Listing medicine"<<endl;
    // cin>>number;
    // Doc1.add_medicine("Test1",25);
    // Doc1.List_medicine();
    
    
    return 0;
}