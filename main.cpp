#include<iostream>
#include<vector>

using namespace std;

int main() {
	int height, width;
	vector<vector<int>> matrix; // 0x12412467921

	cout << "Enter height: ";
	cin >> height;
	cout << "Enter width: ";
	cin >> width;

	for (int i = 0; i < height; i++) {
		vector<int> row;
		matrix.push_back(row);

		for (int j = 0; j < width; j++) {
			matrix[i].push_back(rand() % 10);
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	char direction;
	int _stepCount = 0, stepCountVertical, stepCountHorizontal;

	cout << "Enter direction: ";
	cin >> direction;
	cout << "Enter stepCount: ";
	cin >> _stepCount;

	stepCountVertical = _stepCount > height
		? _stepCount % height
		: _stepCount;

	stepCountHorizontal = _stepCount > width
		? _stepCount % width
		: _stepCount;

	switch (direction) {
		case 'u':
			for (int i = stepCountVertical; i < height; i++) {
				for (int j = 0; j < width; j++) {
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
			for (int i = 0; i < stepCountVertical; i++) {
				for (int j = 0; j < width; j++) {
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 'd':
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
			for (int i = 0; i < height - stepCountVertical; i++) {
				for (int j = 0; j < width; j++) {
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 'l':
			for (int i = 0; i < height; i++) {
				for (int j = stepCountHorizontal; j < width; j++) {
					cout << matrix[i][j] << " ";
				}

				for (int j = 0; j < stepCountHorizontal; j++) {
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}

			break;
		case 'r':
			for (int i = 0; i < height; i++) {
				for (int j = width - stepCountHorizontal; j < width; j++) {
					cout << matrix[i][j] << " ";
				}
				for (int j = 0; j < width - stepCountHorizontal; j++) {
					cout << matrix[i][j] << " ";
				}

				cout << endl;
			}
			break;
		default:
			break;
	}
}