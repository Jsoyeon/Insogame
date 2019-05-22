#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Word {
	string eng;
	string kor;
public:
	Word(string eng, string kor) { this->eng = eng; this->kor = kor;}
	string getKor() { return kor; }
	string getEng() { return eng; }
};

int main() {
	// ���� �Լ� �õ� ���� & ���� v ����
	srand((unsigned)time(0));
	vector <Word> v;

	// ���� ����
	v.push_back(Word("human", "�ΰ�"));
	v.push_back(Word("baby", "�Ʊ�"));
	v.push_back(Word("emotion", "����"));
	v.push_back(Word("painting", "�׸�"));
	v.push_back(Word("doll", "����"));
	v.push_back(Word("trade", "�ŷ�"));

	// ������ ������ ����
	int size = v.size();

	// ���� ���� �ȳ��� ���
	cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� ���� �մϴ�." << endl;

	// ���� ���� loop
	for (;;) {
	
		// ======= 1. ��ó���� =======

		// ������ �ε����� ���������� �ε����� �����ϱ� ���� ���� ���̺� ����
		int vectorTable[4];
		for (int i = 0; i < 4; i++) {
			vectorTable[i] = rand() % 4;
			for (int j = 0; j < i; j++) {
				if (vectorTable[i] == vectorTable[j])
					i--;
			}
		}

		// ======= 2. ���� ��º� =======

		// ������ �ε��� ����
		int answer = vectorTable[rand()%4];
		
		// ���� ���
		cout << v[answer].getEng() << "?" << endl;
		for (int i = 0; i < 4; i++)
			cout << "(" << i+1 << ") " << v[vectorTable[i]].getKor() << " ";
		cout << ":>";
		

		// ======= 3. ��� ��º� =======

		// ��� �Է�
		int response;
		cin >> response;

		// ����ϴ� �Է��� �ƴ� ��� ����
		if (cin.fail() || (response < 1 || response > 4))
			exit(0);

		// ��� ���
		if (vectorTable[response-1] == answer)
			cout << "Excellent !!" << endl;
		else
			cout << "No. !!" << endl;

	}
}