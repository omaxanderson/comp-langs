// current issues: prog8
// needs to recognize the ENDFOR and continue to look for stuff after that


#include <iostream>
#include<fstream>
#include<stdio.h>
#include<map>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<vector>

using namespace std;

// Broad variable structure that can have either an int or string value
struct var {
	bool isInt;
	int intValue;
	string stringValue;
} ;

// Map containing all the variables created in the Z+- program
map<string, var> variables;

// Forward declarations
bool evaluate(string line);
void assignVariable(vector<string> assignment);
void updateVariable(vector<string> assignment);
void printVariable(string variable);
void createLoop(vector<string> loop);
bool isInteger(string s);

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		printf("Error! No file provided\n");
	}	
	ifstream infile;
	infile.open(argv[1]);
	
	vector<string> program;
	string temp;	
	while (getline(infile, temp)) {
		program.push_back(temp);
	}
	
	for (string s : program) {
		evaluate(s);
	}

	return 0;
}

bool evaluate( string line ) {
	// Tokenize the string
	istringstream iss(line);
	string temp;
	vector<string> tokens;

	while (iss >> temp) {
		tokens.push_back(temp);
	}

	if (tokens[1].find('=') != string::npos && variables.find(tokens[0]) == variables.end() && tokens.back() == ";" ) {
		assignVariable(tokens);
	} else if (tokens[1].find('=') != string::npos && tokens.back() == ";") {
		updateVariable(tokens);
	} else if ( tokens[0] == "PRINT" ) {
		printVariable(tokens[1]);
	} else if ( tokens[0] == "FOR" ) {
		createLoop(tokens);
	}	
	

	return true;
}



void assignVariable(vector<string> assignment) {
	// Check to see if we are assigning a literal or a variable
	var variable;
	if (assignment[1] != "=") {
		cout << "Error: invalid variable assignment" << endl;
	}
	
	// If it has quotation marks we are assigning a string literal
	if (assignment[2].find("\"") != string::npos) {
		variable.isInt = false;
		variable.stringValue = assignment[2].substr(1, assignment[2].length() - 2 );
	} else if ( variables.find(assignment[2]) != variables.end() ) {	// if the value is a variable
		if (variables[assignment[2]].isInt) { 			// if the variable is an integer
			int value = variables[assignment[2]].intValue;
			variable.isInt = true;
			variable.intValue = value;
		} else {						// If variable is a string
			string value = variables[assignment[2]].stringValue;
			variable.isInt = false;
			variable.stringValue = value;
		}
	} else if ( isInteger(assignment[2])) {				// If the value is an integer
		try {
			int value = stoi(assignment[2]);
			variable.isInt = true;
			variable.intValue = value;
		} catch (...) {
			cout << "Integer conversion error" << endl;
		}
	}

	variables.insert(pair<string, var>(assignment[0], variable));

}

void updateVariable(vector<string> assignment) {
	// If the update is simply a new assignment
	if (assignment[1] == "=") {
		if (assignment[2].find("\"") != string::npos) {		// if the update value is a string
			variables[assignment[0]].isInt = false;
			variables[assignment[0]].stringValue = assignment[2].substr(1, assignment[2].length() - 2);
		} else if (variables.find(assignment[2]) != variables.end() ) {
			if (variables[assignment[2]].isInt) {		// if the update value is a known variable
				variables[assignment[0]].isInt = true;  // update the variable
				variables[assignment[0]].intValue = variables[assignment[2]].intValue;
			} else {
				variables[assignment[0]].isInt = false;
				variables[assignment[0]].stringValue = variables[assignment[2]].stringValue;
			}
		} else if (isInteger(assignment[2])) {
			try {
				variables[assignment[0]].isInt = true;
				variables[assignment[0]].intValue = stoi(assignment[2]);
			} catch (...) {
				cout << "Integer conversion error" << endl;
			}
		}
	} else if (assignment[1] == "+=" ) {
		if (variables[assignment[0]].isInt) {
			// Check for variables
			if (variables.find(assignment[2]) == variables.end() ) { // if not variable
				if (isInteger(assignment[2])) {
					variables[assignment[0]].intValue += stoi(assignment[2]);
				} else {
					cout << "Error: invalid types for addition. Cannot add integers and strings." << endl;
				}
			} else {
				if (variables[assignment[2]].isInt) {
					variables[assignment[0]].intValue += variables[assignment[2]].intValue;
				} else {
					cout << "Error: invalid types for addition. Cannot add integers and strings." << endl;
				}
			}
		} else {
			if (variables.find(assignment[2]) == variables.end() ) {
				if (!isInteger(assignment[2])) {
					variables[assignment[0]].stringValue += assignment[2].substr(1, assignment[2].length() - 2);
				} else {
					cout << "Error: invalid types for addition. Cannot add integers and strings." << endl;
				}
			} else {
				if (!variables[assignment[2]].isInt) {
					variables[assignment[0]].stringValue += variables[assignment[2]].stringValue;
				}
			}
		}
	} else if (assignment[1] == "*=") {
		
		if (variables.find(assignment[2]) == variables.end() ) {
			if (variables[assignment[0]].isInt && isInteger(assignment[2])) {
				variables[assignment[0]].intValue *= stoi(assignment[2]);
			} else {
				cout << "Error: invalid types for multiplication. Strings cannot be multiplied." << endl;
			}
		} else {
			if (variables[assignment[0]].isInt && variables[assignment[2]].isInt ){
				variables[assignment[0]].intValue *= variables[assignment[2]].intValue;
			} else {
				cout << "Error: invalid types for multiplication. Strings cannot be multiplied." << endl;
			}
		}
	} else if (assignment[1] == "-=") {
		if (variables.find(assignment[2]) == variables.end() ) {
			
			if (variables[assignment[0]].isInt && isInteger(assignment[2])) {
				variables[assignment[0]].intValue -= stoi(assignment[2]);
			} else {
		   		cout << "Error: invalid types for subtraction. Strings cannot be subtracted." << endl;
			}
		} else {
			if (variables[assignment[0]].isInt && variables[assignment[2]].isInt) {
				variables[assignment[0]].intValue -= variables[assignment[2]].intValue;
			} else {
				cout << "Error: invalid types for subtraction. Strings cannot be subtracted." << endl;
			}
		}
	}
}

void printVariable(string variable) {
	if (variables[variable].isInt) {
		cout << variables[variable].intValue << endl;
	} else {
		cout << variables[variable].stringValue << endl;
	}
}

void createLoop(vector<string> loop) {
	int numLoops;
	try {	
		numLoops = stoi(loop[1]);
	} catch (...) {
		cout << "Invalid number of loops" << endl;
	}
	vector< vector< string >> instructions;
	vector<string> tempVec;
	for (int i = 2; i < loop.size(); i++) {
		tempVec.push_back(loop[i]);
		if (loop[i] == ";") {
			instructions.push_back(tempVec);
			tempVec.clear();
		} else if (loop[i] == "ENDFOR") {
			// do something
			break;
		}
	}

	for (int i = 0; i < numLoops; i++) {
		for (int j = 0; j < instructions.size(); j++) {
			if ( instructions[j][1].find("=") != string::npos && variables.find(instructions[j][0]) == variables.end() 
					&& instructions[j].back() == ";") {
				assignVariable(instructions[j]);
			} else if (instructions[j][1].find("=") != string::npos && instructions[j].back() == ";") {
				updateVariable(instructions[j]);
			} else if (instructions[j][0] == "PRINT") {
				printVariable(instructions[j][1]);
			} else if (instructions[j][0] == "FOR") {
				createLoop(instructions[j]);
			}
		}
	
	}	
}

bool isInteger(string s) {
	try {
		stoi(s);
		return true;
	} catch(...) {
		return false;
	}
}



