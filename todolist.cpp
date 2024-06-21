#include<iostream>
#include<vector>
#include<ctime>
#include<string>
#include<stdio.h>
#include<map>
using namespace std;
struct store{
    public:
    int no;
    string task;
    string date;
    bool status;
    string disc;
};
class storage{
    public:
    vector<store>& bin;
    storage(vector<store>& bin) : bin(bin) {}
    void addtask(string task,string date,bool status,string disc,int taskno){
        store newstore;
        newstore.task=task;
        newstore.date=date;
        newstore.status=status;
        newstore.disc=disc;
        newstore.no=taskno;
        bin.push_back(newstore);
    }
    void show(){
        for (const auto& newstore : bin) {
            cout << "Task No: " << newstore.no << endl;
            cout << "Task: " << newstore.task << endl;
            cout << "Date: " <<newstore.date << endl;
            cout << "Status: " << (newstore.status ? "Completed" : "Pending") << endl;
            cout << "Description: " <<newstore.disc << endl;
            cout << "---------------------------" << endl;
        }
    }
    void mark(int taskno) {
        for (auto& newstore : bin) {
            if (newstore.no == taskno) {
                if (newstore.status == false) {
                    newstore.status = true;
                    cout << "Task marked as completed" << endl;
                } 
                else {
                    cout << "Task is already completed" << endl;
                }
                return ;
            }
        }
        cout << "Task not found" << endl;
    }
    void deletetask(int taskno){
        int hold=0;
        int cat=0;
        for(auto& newstore : bin){
            if(newstore.no==taskno){
                bin.erase(bin.begin()+hold);
                cout<<"Task deleted successfully"<<endl;
                cat=1;
            }
            else{
                hold++;
            }
        }
        if(cat!=1){
            cout<<"Invalid task number"<<endl;
        }
    }
};
void todolist(){
    vector<store> storeVector;
    storage ram(storeVector);
    int op;
    do{
    cout<<"---------welcome to your TO-DO-LIST-----------"<<endl;
    cout<<"1. To add a new entry"<<endl;
    cout<<"2. To show the existing entries"<<endl;
    cout<<"3. To mark task as complete"<<endl;
    cout<<"4. To delete an existing task"<<endl;
    cout<<"5.To Exit"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Enter the operation"<<endl;
    cin>>op;
    if(op==1){
        int taskno;
        cout<<"enter task no. "<<endl;
        cin>>taskno;
        cin.ignore();
        string task;
        string date;
        bool status;
        string disc;
        cout<<"enter task -: "<<endl;
        getline(cin,task);
        cout<<"enter due date (DD/MM/YYYY) - "<<endl;
        getline(cin,date);
        cout<<"task completed ? - (1-true/0-false) "<<endl;
        cin>>status;
        cin.ignore();
        cout<<"enter discription (if any) "<<endl;
        getline(cin,disc);
        ram.addtask(task,date,status,disc,taskno);
    }
    else if(op==2){
        ram.show();
    }
    else if(op==3){
        int tasknumber;
        cout<<"enter the task number for which you have to mark completed"<<endl;
        cout<<"here are the information of the stored tasks"<<endl;
        ram.show();
        cin>>tasknumber;
        ram.mark(tasknumber);
    }
    else if(op==4){
        int num;
        cout<<"enter the task number you want to delete"<<endl;
        cout<<"here are the information of the stored tasks"<<endl;
        ram.show();
        cin>>num;
        ram.deletetask(num);
    }
    }while(op!=5);
}
int main(){
    todolist();
    return 0;
}