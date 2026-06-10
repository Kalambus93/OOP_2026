import std;
import Counters;

int main()
{
	std::println("\nBoundedCounter");
	BoundedCounter bc(3);
	bc.increment();
	bc.increment();
	bc.increment();
	bc.increment();
	std::println("Значение: {}", bc.getValue());
	std::println("Лимит достигнут: {}", bc.IsLimitReached());

	std::println("\nCyclicCounter");
	CyclicCounter cc(2);
	cc.increment();
	cc.increment();
	cc.increment();
	std::println("Значение: {}", cc.getValue());

	std::println("\nStepCounter");
	StepCounter sc(10, 3);
	sc.increment();
	sc.increment();
	sc.increment();
	sc.increment();
	std::println("Значение: {}", sc.getValue());
	std::println("Тип: {}", sc.getType());

	return 0;
}