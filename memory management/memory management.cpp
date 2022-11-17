/*
Write a program to simulate memory placement strategies
   1. First fit
   2. Best fit
   3. Worst fit
   4. Next fit
*/


#include<iostream>
using namespace std;


struct block{
    int blockSize, pSize;
    string pname;
    bool isFree;
    block * next;

    block(){
        isFree = true;
        pSize = 0;
        blockSize = 0;
        pname = "";
        next = NULL;
    }
};

class memoryPlacement{
public:
    block *head = NULL, *currNode = NULL;

    void createBlock(){
        int n;
        cout<<"Enter the number of memory blocks: ";
        cin>>n;
        for(int i=0;i<n;i++){
            int fb, mb;
            cout<<"Is "<<i+1<<" block free(1/0): ";
            cin>>fb;
            if(fb){
                cout<<"Enter size of memory block: ";
                cin>>mb;
                if(head == NULL){
                    head = new block;
                    head->blockSize = mb;
                    head->isFree = true;
                }else{
                    block *p = head;
                    while(p->next != NULL){
                        p = p->next;
                    }
                    block *q = new block;
                    p->next = q;
                    q->blockSize = mb;
                    q->isFree = true;
                }
            }else{
                cout<<"Enter size of memory block: ";
                cin>>mb;
                string ps;
                cout<<"Enter name of process: ";
                cin>>ps;
                int psize;
                cout<<"Enter size of process: ";
                cin>>psize;

                if(head == NULL){
                    head = new block;
                    head->blockSize = mb;
                    head->isFree = false;
                    head->pname = ps;
                    head->pSize = psize;
                    cout<<"Head: "<<head<<endl;
                }else{
                    block *p = head;
                    while(p->next != NULL){
                        p = p->next;
                    }
                    block *q = new block;
                    p->next = q;
                    q->blockSize = mb;
                    q->isFree = false;
                    q->pname = ps;
                    q->pSize = psize;
                }
            }
        }
    }


    void displayBlocks(){
        block *p = head;
        int i = 0;
        while(p != NULL){
            if(p->isFree){
                cout<<"Block no. "<<i+1<<" :"<<endl;
                cout<<"Block Size: "<<p->blockSize<<endl;
                cout<<"Block is free? : "<<p->isFree<<endl;
                cout<<endl;
            }else{
                cout<<"Block no. "<<i+1<<" :"<<endl;
                cout<<"Block Size: "<<p->blockSize<<endl;
                cout<<"Block is free? : "<<p->isFree<<endl;
                cout<<"Name of process: "<<p->pname<<endl;
                cout<<"Size of process: "<<p->pSize<<endl;
                cout<<"Available memory: "<<(p->blockSize - p->pSize)<<endl;
                cout<<endl;
            }
            p = p->next;
            i++;
        }
    }

    void firstFit(){
        string ps;
        cout<<"\nEnter name of process: ";
        cin>>ps;
        int psize;
        cout<<"Enter size of process: ";
        cin>>psize;
        block * p = head;
        int flag = 0;
        while(p != NULL){
            if(p->isFree && (p->blockSize >= psize)){
                p->isFree = false;
                p->pname = ps;
                p->pSize = psize;
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag){
            cout<<"Process assigned memory block successfully!"<<endl;
        }else{
            cout<<"Memory block is not available for process"<<endl;
        }
    }

    void bestFit(){
        string ps;
        cout<<"\nEnter name of process: ";
        cin>>ps;
        int psize;
        cout<<"Enter size of process: ";
        cin>>psize;
        block * p = head, *x =NULL;
        int flag = 0, maxDiff = INT_MAX;
        while(p != NULL){
            if(p->isFree && (p->blockSize >= psize)){
                flag = 1;
                if(maxDiff > (p->blockSize - psize)){
                    x = p;
                    maxDiff = (p->blockSize - psize);
                }
            }
            p = p->next;
        }
        if(flag){
            x->isFree = false;
            x->pname = ps;
            x->pSize = psize;
            cout<<"Process assigned memory block successfully!"<<endl;
        }else{
            cout<<"Memory block is not available for process"<<endl;
        }
    }

    void worstFit(){
        string ps;
        cout<<"\nEnter name of process: ";
        cin>>ps;
        int psize;
        cout<<"Enter size of process: ";
        cin>>psize;
        block * p = head, *x = NULL;
        int flag = 0, minDiff = 0;
        while(p != NULL){
            if(p->isFree && (p->blockSize >= psize)){
                flag = 1;
                if(minDiff < (p->blockSize - psize)){
                    x = p;
                    minDiff = (p->blockSize - psize);
                }
            }
            p = p->next;
        }
        if(flag){
                x->isFree = false;
                x->pname = ps;
                x->pSize = psize;
            cout<<"Process assigned memory block successfully!"<<endl;
        }else{
            cout<<"Memory block is not available for process"<<endl;
        }
    }

    void nextFit(){
        cout<<"-- Next Fit --"<<endl;
        string ps;
        cout<<"\nEnter name of process: ";
        cin>>ps;
        int psize;
        cout<<"Enter size of process: ";
        cin>>psize;

        block * p = head;

        if(currNode != NULL){
            p = currNode;
        }

        int flag = 0;
        while(p != NULL){
            if(p->isFree && (p->blockSize >= psize)){
                p->isFree = false;
                p->pname = ps;
                p->pSize = psize;
                flag = 1;
                currNode = p;
                break;
            }
            p = p->next;
        }
        if(flag){
            cout<<"Process assigned memory block successfully!"<<endl;
        }else{
            cout<<"Memory block is not available for process"<<endl;
        }
    }
};


int main(){
    memoryPlacement mp;
    int option = 1;
    while(option>=0 && option<=7){
        cout<<"<--- MENU --->"<<endl;
        cout<<"1. Create memory blocks \n2. First fit \n3. Best fit \n4. Worst fit \n5. Next fit \n6. Display \n7. Exit"<<endl;
        cout<<"Enter option: ";
        cin>>option;
        switch(option){
            case 1: mp.createBlock();
                    break;
            case 2: mp.firstFit();
                    break;
            case 3: mp.bestFit();
                    break;
            case 4: mp.worstFit();
                    break;
            case 5: mp.nextFit();
                    break;
            case 6: mp.displayBlocks();
                    break;
            case 7: exit(0);
        }
    }
    cout<<"\nProgram ended successfully!"<<endl;
    return 0;
}
