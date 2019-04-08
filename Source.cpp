#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

pair<int, int> factor(int n);
int main()
{

	int T, N, L;

	vector<string> output(2);
	vector<int> input(2);
	vector<int> prime(2);

	cin >> T;
	output.resize(T);
	for (int i = 0; i < T; i++) {
		cin >> N >> L;
		input.resize(L);
		prime.resize(L + 1);
		int temp;
		for (int j = 0; j < L; j++) {
			cin >> temp;
			input.at(j) = temp;
		}
		pair<int, int> p;
		pair<int, int> p1;
		p = factor(input.at(0));
		p1 = factor(input.at(1));
		if ((p.first == p1.first) || (p.first == p1.second)) {
			prime.at(0) = p.second;
			prime.at(1) = p.first;
			if (p.first == p1.first)
				prime.at(2) = p1.second;
			else prime.at(2) = p1.first;
		}
		else {
			prime.at(0) = p.first;
			prime.at(1) = p.second;
			if (p1.first == p.second) prime.at(2) = p1.second;
			else prime.at(2) = p1.first;
		}
		for (int k = 3; k < L + 1; k++) {
			prime.at(k) = (input.at(k - 1)) / (prime.at(k - 1));
			if (prime.at(k)>N) return 0;
		}
		vector<int> trier(L + 1);
		vector<pair<char, int>> letters(L + 1);
		pair<char, int> p2;
		trier = prime;
		sort(trier.begin(), trier.end());
		//test affichage de trier
		/*for (int x = 0; x < L + 1; x++) {
		cout << trier.at(x) << " ";
		}*/
		char car = 'A';
		p2 = make_pair(car, trier.at(0));
		letters.at(0) = p2;
		for (int k = 1; k < L + 1; k++) {
			if (trier.at(k) == trier.at(k - 1))
				letters.at(k) = letters.at(k - 1);
			else {
				car++;
				p2 = make_pair(car, trier.at(k));
				letters.at(k) = p2;
			}
		}
		//test affichage de letters
		/*cout << endl << "affichage de letters" << endl;
		for (int x = 0; x < L + 1; x++) {
		cout << letters.at(x).first << " " << letters.at(x).second << endl;
		}*/

		string out = "";
		for (int l = 0; l < L + 1; l++) {
			for (int m = 0; m < L + 1; m++) {
				if (prime.at(l) == letters.at(m).second) {
					out += letters.at(m).first;
					break;
				}
			}
		}
		output.at(i) = out;
	}
	for (int i = 0; i < T-1; i++) {
		cout << "Case #" << i + 1 << ": " << output.at(i) << endl;
	}
	cout << "Case #" << T << ": " << output.at(T - 1) << endl;

	system("pause");
	return 0;
}

pair<int, int> factor(int n) {
	pair<int, int> p;
	int cpt = 0;
	for (int i = 1; i < n; ++i)
	{
		if ((n % i == 0) && (i != 1)) {
			if (cpt == 0) {
				p.first = i;
				cpt++;
			}
			else p.second = i;
		}
	}
	return p;
}
