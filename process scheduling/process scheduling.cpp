/*
    Simulate CPU scheduling algorithms
    1. FCFS
    2. SJF (pre-emptive)
    3. Priority
    4. Round robin (pre-emptive)
*/

#include<iostream>
using namespace std;

struct process{
    string name;
    int arrTime, burstTime, priority;
    process * next;
    bool isComplete;
    process(){
        name = "";
        arrTime = burstTime = priority = 0;
        next = NULL;
        isComplete = false;
    }
};

class ProcessScheduling{
public:
        void roundRobin(){
        cout<<"\n---- ROUND ROBIN ----"<<endl;
        process *p;
        process * processArr[100] = {NULL};
        int n, arr, burst,  quantum;
        cout<<"\nEnter the number of processes: ";
        cin>>n;
        cout<<"Enter the quantum time: ";
        cin>>quantum;
        for(int i=0;i<n;i++){
            string ps = "P" + to_string(i+1);
            cout<<"\nEnter details of process "<<ps<<": "<<endl;
            cout<<"Enter arrival time: ";
            cin>>arr;
            cout<<"Enter burst time: ";
            cin>>burst;
            p = new process;
            p->name = ps;
            p->arrTime = arr;
            p->burstTime = burst;


            if(processArr[arr]==NULL){
                processArr[arr] = p;
            }else{
                for(int i=arr;i<100;i++){
                    if(processArr[i]==NULL){
                        processArr[i] = p;
                        break;
                    }
                }
            }
        }
        int ctime = 0;
        for(int i=0;i<100;i++){
            process *x = NULL;

            for(int j=0;j<=ctime;j++){
                if(processArr[j] != NULL && processArr[j]->isComplete == false){
                    x = processArr[j];
                    break;
                }
            }

            if(x==NULL){
                for(int j=0;j<=i;j++){
                    if(processArr[j] != NULL && processArr[j]->isComplete == false){
                        x = processArr[j];
                        break;
                    }
                }
            }

            if(x != NULL && x->isComplete == false){
                if(x->burstTime>=quantum){
                    x->burstTime -= quantum;
                    ctime += quantum;
                }else{
                    ctime += x->burstTime;
                    x->burstTime = 0;
                }
                if(x->burstTime==0){
                    x->isComplete = true;
                    cout<<"Turn around time: "<<ctime-(x->arrTime)<<endl;
                    cout<<"Waiting time: "<<ctime-(x->arrTime)-(x->burstTime)<<endl;
                }
                cout<<"\nProcess "<<x->name<<": "<<endl;
                cout<<"Arrival time: "<<x->arrTime<<endl;
                cout<<"Burst time: "<<x->burstTime<<endl;
            }
        }
        }

        void sjf(){
        cout<<"\n---- SHORTEST JOB FIRST ----"<<endl;
        process *p;
        process * processArr[100] = {NULL};
        int n, arr, burst;
        cout<<"\nEnter the number of processes: ";
        cin>>n;
        for(int i=0;i<n;i++){
            string ps = "P" + to_string(i+1);
            cout<<"\nEnter details of process "<<ps<<": "<<endl;
            cout<<"Enter arrival time: ";
            cin>>arr;
            cout<<"Enter burst time: ";
            cin>>burst;
            p = new process;
            p->name = ps;
            p->arrTime = arr;
            p->burstTime = burst;


            if(processArr[arr]==NULL){
                processArr[arr] = p;
            }else{
                for(int i=arr;i<100;i++){
                    if(processArr[i]==NULL){
                        processArr[i] = p;
                        break;
                    }
                }
            }
        }
        int ctime = 0;
        for(int i=0;i<100;i++){
            int pr = INT_MAX;
            process *x = NULL;

            for(int j=0;j<=ctime;j++){
                if(processArr[j] != NULL && processArr[j]->isComplete == false){
                    if(processArr[j]->burstTime<pr){
                        x = processArr[j];
                        pr = processArr[j]->burstTime;
                    }
                }
            }

            if(x==NULL){
                for(int j=0;j<=i;j++){
                    if(processArr[j] != NULL && processArr[j]->isComplete == false){
                        if(processArr[j]->burstTime<pr){
                            x = processArr[j];
                            pr = processArr[j]->burstTime;
                        }
                    }
                }
            }

            if(x != NULL && x->isComplete == false){
                x->burstTime--;
                if(x->burstTime==0){
                    x->isComplete = true;
                    cout<<"Turn around time: "<<ctime-(x->arrTime)<<endl;
                    cout<<"Waiting time: "<<ctime-(x->arrTime)-(x->burstTime)<<endl;
                }
                ctime += 1;
                cout<<"\nProcess "<<x->name<<": "<<endl;
                cout<<"Arrival time: "<<x->arrTime<<endl;
                cout<<"Burst time: "<<x->burstTime<<endl;
            }
        }
    }

        void priority(){
        cout<<"\n---- PRIORITY ----"<<endl;
        process *p;
        process * processArr[100] = {NULL};
        int n, arr, burst, prio;
        cout<<"\nEnter the number of processes: ";
        cin>>n;
        for(int i=0;i<n;i++){
            string ps = "P" + to_string(i+1);
            cout<<"\nEnter details of process "<<ps<<": "<<endl;
            cout<<"Enter arrival time: ";
            cin>>arr;
            cout<<"Enter burst time: ";
            cin>>burst;
            cout<<"Enter priority(1 to 5)(with 5 max priority): ";
            cin>>prio;
            p = new process;
            p->name = ps;
            p->arrTime = arr;
            p->burstTime = burst;
            p->priority = prio;

            if(processArr[arr]==NULL){
                processArr[arr] = p;
            }else{
                for(int i=arr;i<100;i++){
                    if(processArr[i]==NULL){
                        processArr[i] = p;
                        break;
                    }
                }
            }
        }
        int ctime = 0;
        for(int i=0;i<100;i++){
            int pr = 0;
            process *x = NULL;
            for(int j=0;j<=ctime;j++){
                if(processArr[j] != NULL && processArr[j]->isComplete == false){
                    if(processArr[j]->priority>pr){
                        x = processArr[j];
                        pr = processArr[j]->priority;
                    }
                }
            }

            if(x==NULL){
                for(int j=0;j<=i;j++){
                    if(processArr[j] != NULL && processArr[j]->isComplete == false){
                        if(processArr[j]->priority>pr){
                            x = processArr[j];
                            pr = processArr[j]->priority;
                        }
                    }
                }
            }

            if(x != NULL && x->isComplete == false){
                x->isComplete = true;
                ctime += x->burstTime;
                cout<<"\nProcess "<<x->name<<": "<<endl;
                cout<<"Arrival time: "<<x->arrTime<<endl;
                cout<<"Burst time: "<<x->burstTime<<endl;
                cout<<"Turn around time: "<<ctime-(x->arrTime)<<endl;
                cout<<"Waiting time: "<<ctime-(x->arrTime)-(x->burstTime)<<endl;
            }
        }
    }

        void fcfs(){
        cout<<"\n---- FIRST COME FIRST SERVE ----"<<endl;
        process *p;
        process * processArr[100] = {NULL};
        int n, arr, burst;
        cout<<"\nEnter the number of processes: ";
        cin>>n;
        for(int i=0;i<n;i++){
            string ps = "P" + to_string(i+1);
            cout<<"\nEnter details of process "<<ps<<": "<<endl;
            cout<<"Enter arrival time: ";
            cin>>arr;
            cout<<"Enter burst time: ";
            cin>>burst;
            p = new process;
            p->name = ps;
            p->arrTime = arr;
            p->burstTime = burst;

            if(processArr[arr]==NULL){
                processArr[arr] = p;
            }else{
                for(int i=arr;i<100;i++){
                    if(processArr[i]==NULL){
                        processArr[i] = p;
                        break;
                    }
                }
            }
        }
        int ctime = 0;
        for(int i=0;i<100;i++){
            if(processArr[i] != NULL){
                p = processArr[i];
                p->isComplete = true;
                ctime += p->burstTime;
                cout<<"\nProcess "<<p->name<<": "<<endl;
                cout<<"Arrival time: "<<p->arrTime<<endl;
                cout<<"Burst time: "<<p->burstTime<<endl;
                cout<<"Turn around time: "<<ctime-(p->arrTime)<<endl;
                cout<<"Waiting time: "<<ctime-(p->arrTime)-(p->burstTime)<<endl;
            }
        }
    }
};

int main(){
    ProcessScheduling ps;
    int option = 1;
    while(option>0 && option<5){
        cout<<"<---- MENU ---->"<<endl;
        cout<<"1. FCFS \n2. Priority \n3. SJF \n4. Round Robin \n5. Exit"<<endl;
        cout<<"Enter option: ";
        cin>>option;
        switch(option){
            case 1: ps.fcfs();
                    break;
            case 2: ps.priority();
                    break;
            case 3: ps.sjf();
                    break;
            case 4: ps.roundRobin();
                    break;
            default: cout<<"Program exited successfully!"<<endl;
                     exit(1);
                     break;
        }
    }

    //ps.fcfs();
    //ps.priority();
    //ps.sjf();
    //ps.roundRobin();
    return 0;
}
