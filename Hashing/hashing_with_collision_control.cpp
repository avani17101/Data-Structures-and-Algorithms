#include<bits/stdc++.h>

using namespace std;

int capacity = 20;
vector<vector<int> > hashTable(capacity);

int hashFunc(int n){
	return n%capacity;
}

void insert(int s)
{
	int index = hashFunc(s);
	hashTable[index].push_back(s);
}

void search(int s)
{

        int index = hashFunc(s);

        for(int i = 0;i < hashTable[index].size();i++)
        {
            if(hashTable[index][i] == s)
            {
                cout << s << " is found! at key " << index << endl;
                return;
            }
        }
        cout << s << " is not found!" << endl;
}

void deletea(int s){
	int index = hashFunc(s);
	for(int i = 0;i < hashTable[index].size();i++)
        {
            if(hashTable[index][i] == s)
            {
                hashTable[index].erase(hashTable[index].begin()+i);
                return;
            }
        }
}

int main(){


	l:
	cout << "\n" << endl;
	cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5.Exit\n" << endl;

	int swi;
	cin >> swi;
	switch(swi){
		case 1:
			int x;
			cin >> x;
			insert(x);
			goto l;
		
		case 2:
			cin >> x;
			deletea(x);
			
			goto l;

		case 3:

			cin >> x;
			search(x);
			goto l;
			
		case 4:
			cout << "Key\tValue\n";
			for(int i = 0;i<capacity;i++){
				if(hashTable[i].size() > 0){
					cout << i << "\t";
					for(int j = 0;j < hashTable[i].size();j++)
						cout   << hashTable[i][j] << " ";
					cout << endl;
				}
			}
			cout << endl;
			goto l;
			
		case 5:
			break;
	}

	return 0;
}

