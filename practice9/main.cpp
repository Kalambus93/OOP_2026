#include <fmt/core.h>
#include <fmt/color.h>
import std;
import LogicGame;

int main() {
	fmt::print(fg(fmt::color::gold) | fmt::emphasis::bold, "Hi! This is a rock-paper-scissors game.\n");

	CounterWins count;

	int point_menu = 0;
	int motion = 0;
	std::random_device seed;
	std::mt19937 generator(seed());

	while (point_menu != 4) {
		std::println("\nSelect a menu item:\n"
			"1. Reset Score\n"
			"2. Continue game\n"
			"3. View score\n"
			"4. Exit");
		fmt::print(fg(fmt::color::steel_blue), "> ");
		std::cin >> point_menu;
		switch (point_menu) {
		case 1:
			count.Reset();
			fmt::print(fg(fmt::color::white), "Score reset.\n");
			break;
		case 2:
			do {
				fmt::print("\nChoose your weapon:\n");
				fmt::print("   1. Rock\n");
				fmt::print("   2. Paper\n");
				fmt::print("   3. Scissors\n");
				fmt::print(fg(fmt::color::steel_blue), "> ");
				std::cin >> motion;
			} while (motion < 1 || motion > 3);
			Game(motion, count, generator);
			break;
		case 3:
			fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "\n--- Scoreboard ---\n");
			fmt::print("Computer winners: {}\n", count.getComputerWins());
			fmt::print("Human winners:    {}\n", count.getHumanWins());
			fmt::print("Draws:            {}\n", count.getDraw());
			fmt::print("------------------\n");
			break;
		case 4:
			fmt::print(fg(fmt::color::blue), "Goodbye!\n");
			break;
		}
	}

	return 0;
}