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
	std::println("Value: {}", bc.getValue());
	std::println("Limit: {}", bc.IsLimitReached());

	std::println("\nCyclicCounter");
	CyclicCounter cc(2);
	cc.increment();
	cc.increment();
	cc.increment();
	std::println("Value: {}", cc.getValue());

	std::println("\nStepCounter");
	StepCounter sc(10, 3);
	sc.increment();
	sc.increment();
	sc.increment();
	sc.increment();
	std::println("Value: {}", sc.getValue());
	std::println("Type: {}", sc.getType());

	return 0;
}