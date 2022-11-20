#include<iostream>
using namespace std;

class Assembly{
public:
//	string IS[11] = {"STOP", "ADD", "SUB", "MULT", "MOVER", "MOVEM", "COMP", "BC", "DIV", "READ", "PRINT"};
//	string AD[6] = {"", "START", "END", "ORIGIN", "EQU", "LTOR"};
//	string DL[3] = {"", "DC", "DS"};
//	string condition[7] = {"", "LT", "LE", "EQ", "GT", "GE", "ANY"};

	int opCode(string);
	string opClass(string);
	int conditionCode(string);
};

int Assembly::opCode(string s){
	if(s=="STOP"){
		return 0;
	}
	else if(s=="ADD"){
			return 1;
	}
	else if(s=="SUB"){
			return 2;
	}
	else if(s=="MULT"){
			return 3;
	}
	else if(s=="MOVER"){
			return 4;
	}
	else if(s=="MOVEM"){
			return 5;
	}
	else if(s=="COMP"){
			return 6;
	}
	else if(s=="BC"){
			return 7;
	}
	else if(s=="DIV"){
			return 8;
	}
	else if(s=="READ"){
			return 9;
	}
	else if(s=="PRINT"){
			return 10;
	}
	else if(s=="START"){
		return 1;
	}
	else if(s=="END"){
		return 2;
	}
	else if(s=="ORIGIN"){
		return 3;
	}
	else if(s=="EQU"){
		return 4;
	}
	else if(s=="LTORG"){
		return 5;
	}
	else if(s=="DC"){
		return 1;
	}else if(s=="DS"){
		return 2;
	}else if(s == "LT"){
		return 1;
	}else if(s == "LE"){
		return 2;
	}else if(s == "EQ"){
		return 3;
	}else if(s == "GT"){
		return 4;
	}else if(s == "GE"){
		return 5;
	}else if(s == "ANY"){
		return 6;
	}else if(s == "AREG"){
		return 1;
	}else if(s == "BREG"){
		return 2;
	}else if(s == "CREG"){
		return 3;
	}else if(s == "DREG"){
		return 4;
	}
	return -1;
}

string Assembly::opClass(string opcode){
	if(opcode == "STOP"  || opcode == "ADD"  || opcode == "SUB"  || opcode == "MULT"  || opcode == "MOVER"  || opcode == "MOVEM"  || opcode == "COMP"  || opcode == "BC"  || opcode == "DIV"  || opcode == "READ"  || opcode == "PRINT"){
		return "IS";
	}else if(opcode == "START" || opcode == "END" || opcode == "ORIGIN" || opcode == "EQU" || opcode == "LTORG"){
		return "AD";
	}else if(opcode == "DC" || opcode == "DS"){
		return "DL";
	}else if(opcode == "LT" || opcode == "LE" || opcode == "GT" || opcode == "GE" || opcode == "EQ" || opcode == "ANY"){
		return "CON";
	}else if(opcode == "AREG" || opcode == "BREG" || opcode == "CREG" || opcode == "DREG"){
		return "REG";
	}else if(opcode == "+" || opcode == "-" || opcode == "*" || opcode =="/"){
		return "OPERATOR";
	}
	return "-1";
}

int Assembly::conditionCode(string condition){
	if(condition == "LT"){
		return 1;
	}
	if(condition == "LE"){
		return 2;
	}
	if(condition == "EQ"){
		return 3;
	}
	if(condition == "GT"){
		return 4;
	}
	if(condition == "GE"){
		return 5;
	}
	if(condition == "ANY"){
		return 6;
	}

	return -1;
}
