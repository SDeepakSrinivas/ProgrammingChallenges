#include <iostream>


using namespace std;

char values[13][9] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
char suits[4][9] = {"Clubs", "Diamonds", "Hearts", "Spades"};
int types[100][52];
int present[52];


void shuffle_input(int n_shuff) {
	for(int i=0; i<n_shuff; i++) {
		for (int j=0; j<52; j++) {
			cin >> types[i][j];
		}
	}
}


void shuffle_once(int s_id) {
	int temp[52];
	for (int i=0; i<52; i++) {
		temp[i] = present[types[s_id][i] - 1];
	}
	for (int i=0; i<52;i++) {
		present[i] = temp[i];
	}
}


int main () {
	int t;
	int n;
	int s;
	cin >> t;

	for (int i=0; i<t; i++) {
		cin >> n;

		for (int p=0; p<52; p++) {
			present[p] = p;
		}


		shuffle_input(n);

		for (int j=0; j<n; j++) {
			cin >> s;
			shuffle_once(s - 1);
		}

		for (int k=0; k<52; k++) {
			cout << values[present[k] % 13] << " of " << suits[present[k] / 13] << endl;
		}
		if (i < (t - 1)) {
			cout << endl;
		}
	}

}

