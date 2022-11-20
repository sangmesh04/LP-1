//============================================================================
// Name        : assembly_passes.cpp
// Author      : Sangmeshwar Mahajan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<algorithm>
#include <fstream>
#include "Assembler.h"
using namespace std;

class Pass1{
public:
	vector<string> symbol;
	vector<string> literal;
	void readCode();
	void pass2();
};

void Pass1::readCode(){
	//opening code file
	Assembly a;
	fstream fcode;
	int sym = 0;
	int lit = 0;
	fcode.open("/home/pict/Documents/31332_LP1/assembly_passes/src/code.txt", ios::in); //read
	if(fcode.is_open()){
		string s, opclass;
		ofstream psf;
		cout<<"<--- Pass 1 --->"<<endl;
		psf.open("/home/pict/Documents/31332_LP1/assembly_passes/src/pass1.txt",ios::out); //write
		psf<<"";
		while(getline(fcode,s)){
//			cout<<s<<endl;
			string sarr[4] = {""};
			string word = "";
			int index = 0;
			for (auto x : s) {
			    if(x == ' '){
			        sarr[index] = word;
			        index++;
			    	//cout << word << endl;
			         word = "";
			        }else {
			            word += x;
			        }
			}
			sarr[index] = word;
			index++;
//			cout<<index<<endl;
			string var, pass1linestr = "";
			int flag = 1;
			for(int i=0;i<index;i++){
				var = sarr[i];
				if(flag==0){
					cout<<var;
					pass1linestr += var;
					flag=1;
				}else if(flag==2){
					cout<<"(C,"<<var<<") ";
					pass1linestr += "(C,"+var+") ";
					flag=1;
				}else{

					if(a.opClass(var) != "-1"){
						if(a.opClass(var)=="OPERATOR"){
							cout<<" "<<var<<" ";
							pass1linestr += " " + var + " ";
							flag = 0;
						}else if(a.opClass(var)=="REG"){
							cout<<" ("<<a.opCode(var)<<") ";
							pass1linestr += " (" + to_string(a.opCode(var)) + ") ";
						}
						else{
							if(a.opClass(var)=="DL"){
								flag = 2;
							}
							cout<<" ("<<a.opClass(var)<<","<<a.opCode(var)<<") ";
							pass1linestr += " (" + a.opClass(var) +","+ to_string(a.opCode(var)) +") ";
						}
					}else{
							if(var[0] != '='){
								auto it = find(symbol.begin(),symbol.end(),var);
								if(it != symbol.end()){
									int ind = it - symbol.begin();
									cout<<" (S,"<<ind+1<<") ";
									pass1linestr += " (S," + to_string(ind+1) + ") ";
								}else{
									sym++;
									symbol.push_back(var);
									cout<<" (S,"<<sym<<") ";
									pass1linestr += " (S," + to_string(sym) + ") ";
								}
							}else{
								auto it = find(literal.begin(),literal.end(),var);
								if(it != literal.end()){
									int ind = it - literal.begin();
									cout<<" (L,"<<ind+1<<") ";
									pass1linestr += " (L," + to_string(ind+1) + ") ";
								}else{
									lit++;
									literal.push_back(var);
									cout<<" (L,"<<lit<<") ";
									pass1linestr += " (L," + to_string(lit) + ") ";
								}
							}
					}
				}
			}
			ofstream psf;
			psf.open("/home/pict/Documents/31332_LP1/assembly_passes/src/pass1.txt",ios::app);
			psf<<pass1linestr<<endl;
			psf.close();
			cout<<endl;
//			if(s != " "){
//			opclass = a.opClass(s);
//			opcode = a.opCode(s);
//			cout<<opclass<<" "<<opcode<<endl;
//			}
		}
	}else{
		cout<<"Code file not found!"<<endl;
	}
}


void Pass1::pass2(){
	fstream p2;
	p2.open("/home/pict/Documents/31332_LP1/assembly_passes/src/pass1.txt",ios::in);
	if(p2.is_open()){
		string s;
		cout<<"\n<--- Pass 2 --->"<<endl;
		while(getline(p2,s)){
//			cout<<s<<endl;
			vector<string> vs(6);
			string word = "";
			int index = 0;
			int len = 0;
			//cout<<s.length()<<endl;
			cout<<"+ ";
			for (auto x : s) {
				if(x == ' '){
					if(word != ""){
						vs[index] = word;
						index++;
						//cout << word.length();
						 word = "";
					}
				}else {
						word += x;
						len++;
				}
			}
			//cout<<"len: "<<len<<endl;
			vs.push_back(word);
			index++;
			//cout<<"Index: "<<index<<endl;
			string var = "";
			for(int i=0;i<index;i++){
				var = vs[i];
				//cout<<"Var: "<<var<<endl;
				//cout<<var.length();
				if(var.length() > 1){
				if(var.length()==3){
					if((var[1] == '+' || var[1] =='-' || var[1] =='*' || var[1]=='/')){

					}else{
						cout<<var[1]<<"  ";
					}
				}
				else{
					if(var[1]=='I' && var[2]=='S'){
						cout<<"0"<<var[4]<<"  ";
					}else if(var[1]=='D' && var[2]=='L'){
						string u = vs[i+1];
						cout<<"00"<<"  "<<"0  "<<"00"<<u[3];
						break;
					}else if((var[1]=='A' && var[2]=='D') || (var[1]=='S')){

					}else if(var[1]=='L'){
						cout<<var[3];
					}
					else{
						cout<<var[1];
					}
				}
				}
			}
			cout<<endl;
		}
		}
		cout<<endl;
	}



int main() {
	Pass1 p;
	p.readCode();
	p.pass2();

	return 0;
}
