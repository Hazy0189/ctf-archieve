#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef struct{
	long long user;
	char title[20];
	string body;
} task;

void init(){
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
}

void printMainMenu(){
	cout << "\n1. Show tasks" << endl;
	cout << "2. Show users" << endl;
	cout << "3. Exit" << endl;
	cout << ">";
}

void printTaskMenu(){
	cout << "\n1. Show next task" << endl;
	cout << "2. Edit this task" << endl;
	cout << "3. Delete task" << endl;
	cout << "4. Exit" << endl;
	cout << ">";
}

void printUserMenu(){
	cout << "\n1. Show next user" << endl;
	cout << "2. Edit this user's name" << endl;
	cout << "3. Exit" << endl;
	cout << ">";
}

int main(){
	init();
	vector<task> taskList{{0, "testTask01", "test task."}, {1, "testTask02", "test task."}, {0, "testTask03", "test task."}};
	vector<string> userName{"soramea", "testUser01", "testUser02"};
	string select;

	while(1){
		printMainMenu();
		cin >> select;
		if(atoi(select.c_str()) == 1){
			for (auto v = taskList.begin(); v != taskList.end();v++){
				cout  << "\ntaskName: " << v->title << "\nDescription: "<< v->body << "\nAssigned to user " << userName[v->user] << ".\n" <<endl;
				printTaskMenu();
				cin >> select;
				if(atoi(select.c_str()) == 1){
					if(v == taskList.end()-1){
						cout << "No more tasks" << endl;
						break;
					}else{
						continue;
					}
				}else if(atoi(select.c_str()) == 2){
					cout << "Enter new task name: ";
					string newName;
					cin >> newName;
					if(strlen(newName.c_str()) > 19){
						cout << "Task name is too long" << endl;
						break;
					}
					for (int i = 0; i < strlen(newName.c_str()); i++){
						v->title[i] = newName[i];
					}
					v->title[strlen(newName.c_str())] = '\0';
					cout << "Enter new task description: ";
					string newDesc;
					cin >> newDesc;
					v->body = newDesc;
					cout << "Successfully changed task name to " << v->title << " and description to " << v->body << endl;
					cout << "Return to main menu..." << endl;
					break;
				}else if(atoi(select.c_str()) == 3){
					taskList.erase(v);
					cout << "Successfully deleted task" << endl;
				}else if(atoi(select.c_str()) == 4){
					break;
				}else{
					cout << "Invalid selection" << endl;
					break;
				}
			}
		}else if(atoi(select.c_str()) == 2){
			for (int i = 0; i < userName.size();i++){
				cout << "\nUser " << i+1 << ": " << userName[i] << endl;
				printUserMenu();
				cin >> select;
				if(atoi(select.c_str()) == 1){
					if(i == userName.size()-1){
						cout << "No more users" << endl;
						break;
					}else{
						continue;
					}
				}else if(atoi(select.c_str()) == 2){
					cout << "Enter new name: ";
					string newName;
					cin >> newName;
					userName[i] = newName;
					cout << "Successfully changed name to " << userName[i] << endl;
					cout << "Return to main menu..." << endl;
					break;
				}else if(atoi(select.c_str()) == 3){
					break;
				}else{
					cout << "Invalid selection" << endl;
					break;
				}
			}
			cout << "\n";
		}else if(atoi(select.c_str()) == 3){
			break;
		}else{
			cout << "Invalid selection" << endl;
			break;
		}
	}

	cout << "See you!" << endl;
	return 0;
}
