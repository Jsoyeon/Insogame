#include <stdio.h>

int main() {
	int i;
	int arr[5], count[4];
	for (i = 0; i <= 4; i++) {	//다섯 개의 숫자 입력받음
		scanf_s("%d", &arr[i]);
	}
	count[0] = arr[1];	//입력받은 배열의 1번 값은 그대로 변환 배열로 이동
	if (arr[0] == 1) {//첫 입력값이 1이면 그레이코드->이진수
		for (i = 0; i <= 2; i++) {
			if (arr[i + 2] == count[i])//XOR한 결과
				count[i + 1] = 0;
			else
				count[i + 1] = 1;
		}
	}
	else {//첫 입력값이 0이면 이진수->그레이코드
		for (i = 0; i <= 2; i++) {
			if (arr[i + 1] == arr[i + 2])//XOR한 결과
				count[i + 1] = 0;
			else
				count[i + 1] = 1;
		}
	}

	if (arr[0] == 1)
		printf("이진수 ");
	else
		printf("그레이코드 ");

	for (i = 0; i <= 3; i++) {
		printf("%d", count[i]);
	}
	printf("\n");

	return 0;

}
