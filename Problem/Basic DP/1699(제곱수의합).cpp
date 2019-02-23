#include <stdio.h>
#include <iostream>
int arr[100001];
int dp[100001];

using namespace std;

int main() {
	int n;
	//제곱수는 무조건 1개 제곱수보다 최소개수가 많을수가없음
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = i;
		for (int j = 2; j*j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1) {
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	cout << dp[n] << '\n';
	

	return 0;
}