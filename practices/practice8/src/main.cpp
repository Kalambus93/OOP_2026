import std;
import List;
import Dictionary;
import HashSet;
import Queue;
import Stack;

int main()
{
    List<int> list;
    list.Add(10);
    list.Add(20);
    list.Add(30);
    std::println("List: Count={}, Contains 20={}, [1]={}", list.Count(), list.Contains(20), list[1]);
    list.RemoveAt(0);

    Dictionary<std::string, int> dict;
    std::string one = "One";
    std::string two = "Two";
    KeyValuePair onepair(one, 1);
    KeyValuePair twopair(two, 2);

    dict.Add(onepair);
    dict.Add(twopair);
    dict["Three"] = 3;
    std::println("Dict: Count={}, dict['One']={}", dict.Count(), dict["One"]);
    dict.Remove(twopair);
    std::println("Dict Count after remove: {}", dict.Count());

    HashSet<int> set;
    set.Add(5);
    set.Add(10);
    set.Add(5);
    std::println("HashSet: Count={}, Contains 10={}", set.Count(), set.Contains(10));
    set.Remove(5);

    Queue<int> q;
    q.Enqueue(100);
    q.Enqueue(200);
    std::println("Queue: Count={}, Peek={}, Dequeue={}", q.Count(), q.Peek(), q.Dequeue());

    Stack<int> s;
    s.Push(1000);
    s.Push(2000);
    std::println("Stack: Count={}, Peek={}, Pop={}", s.Count(), s.Peek(), s.Pop());

    std::print("List iteration: ");
    auto it = list.GetEnumerator();
    while (it->MoveNext())
        std::print("{} ", it->Current());
    std::println("");

    return 0;
}