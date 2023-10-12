#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;
class funs {
private:
	vector<int> vars;
public:
	funs():vars(26){ //intializing the vector var size to 26 with constructor 
	}
	void cont(int n) {
		for (int i = 0; i < vars.size(); i++) {
			if (n == vars[i]) {
				cout << count(vars.begin(), vars.end(), n)<<endl;
				break;
			}
		}
	}
	void unset(int n) {
		vars[n] = 0;
	}
	void set(int i ,int n) {
		vars[i] = n;
	}
	void get(int n) {
		if (vars[n] == 0)
			cout << "null";
		else
			cout << vars[n] << endl;
	}
	int size() {
		return vars.size();
	}
};


int main() {
	bool flag = false;
	vector<funs> trans;

	funs temp;
	trans.push_back(temp);

	int i,j;
	string s;
	char temp1;
	int temp2;

	while (1) {
		cin >> s;
		i = trans.size() - 1;
		if (s == "SET") {
			cin >> temp1;
			cin >> temp2;
			trans[i].set(temp1 - 'a', temp2);
		}

		else if (s == "GET") {
			cin >> temp1;
			trans[i].get(temp1 - 'a');
		}

		else if (s == "UPDATE") {
			cin >> temp1;
			if (temp1 - 'a' > trans.size() && trans.size() != 0)
				cout << "Variable not found";
			else {
				cin >> temp2;
				trans[i].set(temp1 - 'a', temp2);
			}
		}

		else if (s == "UNSET") {
			cin >> temp1;
			trans[i].unset(temp1 - 'a');
		}

		else if (s == "COUNT") {
			cin >> temp2;
			trans[i].cont(temp2);
		}

		else if (s == "BEGIN") {
			trans.push_back(trans[i]); //copying the object to next index(last in index in every case)
		}

		else if (s == "ROLLBACK") {
			if (j != i) 
				trans.pop_back(); //removing any changes that have been made in the object by poping it off the vector
			else
				cout << "the changes has been committed";
		}

		else if (s == "COMMIT") {
			trans.push_back(trans[i]); //copying the object to next index(last in index in every case)
			j = i;
		}

		else if (s == "EXIT") {
			cout << "Transactions ended";
			break;
		}
	}
}