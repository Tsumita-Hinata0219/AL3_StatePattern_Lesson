#include "Engine.h"
#include <iostream>
#include <cstdlib>

int main() {
	
	Engine engine;

	while (true) {
		// 状態を切り替える
		int no;
		std::cout << "0:down 1:up  2:state表示  9:終了 ==> ";
		std::cin >> no;

		if (no == 0) engine.down();
		if (no == 1) engine.up();
		if (no == 2) engine.showNowState();
		if (no == 9) break;
	}

	system("pause");

	return 0;
}