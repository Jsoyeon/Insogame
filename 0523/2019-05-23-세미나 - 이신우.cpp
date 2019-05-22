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
	// 랜덤 함수 시드 설정 & 벡터 v 선언
	srand((unsigned)time(0));
	vector <Word> v;

	// 정보 주입
	v.push_back(Word("human", "인간"));
	v.push_back(Word("baby", "아기"));
	v.push_back(Word("emotion", "감정"));
	v.push_back(Word("painting", "그림"));
	v.push_back(Word("doll", "인형"));
	v.push_back(Word("trade", "거래"));

	// 벡터의 사이즈 저장
	int size = v.size();

	// 게임 시작 안내문 출력
	cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료 합니다." << endl;

	// 게임 시작 loop
	for (;;) {
	
		// ======= 1. 전처리부 =======

		// 벡터의 인덱스와 선택지문의 인덱스를 매핑하기 위한 벡터 테이블 선언
		int vectorTable[4];
		for (int i = 0; i < 4; i++) {
			vectorTable[i] = rand() % 4;
			for (int j = 0; j < i; j++) {
				if (vectorTable[i] == vectorTable[j])
					i--;
			}
		}

		// ======= 2. 문제 출력부 =======

		// 정답의 인덱스 설정
		int answer = vectorTable[rand()%4];
		
		// 문제 출력
		cout << v[answer].getEng() << "?" << endl;
		for (int i = 0; i < 4; i++)
			cout << "(" << i+1 << ") " << v[vectorTable[i]].getKor() << " ";
		cout << ":>";
		

		// ======= 3. 결과 출력부 =======

		// 답안 입력
		int response;
		cin >> response;

		// 허용하는 입력이 아닌 경우 종료
		if (cin.fail() || (response < 1 || response > 4))
			exit(0);

		// 결과 출력
		if (vectorTable[response-1] == answer)
			cout << "Excellent !!" << endl;
		else
			cout << "No. !!" << endl;

	}
}