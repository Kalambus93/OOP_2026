#include <fmt/core.h>
#include <fmt/color.h>
import std;

class CounterWins
{
private:
	int _count_computer_wins = 0;
	int _count_human_wins = 0;
	int _draw = 0;

public:
	CounterWins() = default;

	void Reset()
	{
		_count_computer_wins = 0;
		_count_human_wins = 0;
		_draw = 0;
	}

	void IncreasedWinsComputer()
	{
		++_count_computer_wins;
	}

	void IncreasedWinsHuman()
	{
		++_count_human_wins;
	}

	void IncreasedDraw()
	{
		++_draw;
	}

	int getComputerWins() const
	{
		return _count_computer_wins;
	}
	int getHumanWins() const
	{
		return _count_human_wins;
	}
	int getDraw() const
	{
		return _draw;
	}
};

enum RockPaperScissors
{
	Rock = 1,
	Paper = 2,
	Scissors = 3
};

void Game(int motion, CounterWins &count, std::mt19937 &generator)
{
	std::uniform_int_distribution<> dis(1, 3);

	int computer_motion = dis(generator);

	if (motion == computer_motion)
	{
		count.IncreasedDraw();
		fmt::print(fg(fmt::color::yellow), "Draw!\n");
	}
	else if ((motion == Rock && computer_motion == Scissors) ||
			 (motion == Paper && computer_motion == Rock) ||
			 (motion == Scissors && computer_motion == Paper))
	{
		count.IncreasedWinsHuman();
		fmt::print(fg(fmt::color::lime_green), "You win!\n");
	}
	else
	{
		count.IncreasedWinsComputer();
		fmt::print(fg(fmt::color::orange_red), "You lose(\n");
	}
}

int main()
{
	fmt::print(fg(fmt::color::gold) | fmt::emphasis::bold, "Hi! This is a rock-paper-scissors game.\n");

	CounterWins count;

	int point_menu = 0;
	int motion = 0;
	std::random_device seed;
	std::mt19937 generator(seed());

	while (point_menu != 4)
	{
		std::println("\nSelect a menu item:\n"
					 "1. Reset Score\n"
					 "2. Continue game\n"
					 "3. View score\n"
					 "4. Exit");
		fmt::print(fg(fmt::color::steel_blue), "> ");
		std::cin >> point_menu;
		switch (point_menu)
		{
		case 1:
			count.Reset();
			fmt::print(fg(fmt::color::white), "Score reset.\n");
			break;
		case 2:
			do
			{
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