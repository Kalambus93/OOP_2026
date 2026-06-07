module;

#include <fmt/color.h>
#include <fmt/core.h>

export module LogicGame;

import std;

export namespace LogicGame{
	class CounterWins {
	private:
		int _count_computer_wins = 0;
		int _count_human_wins = 0;
		int _draw = 0;
	public:
		CounterWins() = default;

		void Reset() {
			_count_computer_wins = 0;
			_count_human_wins = 0;
			_draw = 0;
		}

		void IncreasedWinsComputer() {
			++_count_computer_wins;
		}

		void IncreasedWinsHuman() {
			++_count_human_wins;
		}

		void IncreasedDraw() {
			++_draw;
		}

		int getComputerWins() const {
			return _count_computer_wins;
		}
		int getHumanWins() const {
			return _count_human_wins;
		}
		int getDraw() const {
			return _draw;
		}
	};

	enum Moves { Rock = 1, Paper = 2, Scissors = 3 };

	void Game(int motion, CounterWins& count, std::mt19937& generator) {
		std::uniform_int_distribution<> dis(1, 3);

		int computer_motion = dis(generator);

		if (motion == computer_motion) {
			count.IncreasedDraw();
			fmt::print(fg(fmt::color::yellow), "Draw!\n");
		}
		else if ((motion == Moves::Rock && computer_motion == Moves::Scissors) ||
			(motion == Moves::Paper && computer_motion == Moves::Rock) ||
			(motion == Moves::Scissors && computer_motion == Moves::Paper)) {
			count.IncreasedWinsHuman();
			fmt::print(fg(fmt::color::lime_green), "You win!\n");
		}
		else {
			count.IncreasedWinsComputer();
			fmt::print(fg(fmt::color::orange_red), "You lose(\n");
		}

	}
}