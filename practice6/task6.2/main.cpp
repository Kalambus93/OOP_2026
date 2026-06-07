import std;

class StringBuilder {
private:
	std::string _buffer;
public:
	void Reserve(size_t new_size) {
		_buffer.reserve(new_size);
	}

	StringBuilder() = default;

	StringBuilder& append(const std::string& str) {
		_buffer.append(str);
		return *this;
	}

	StringBuilder& append(int number) {
		_buffer.append(std::to_string(number));
		return *this;
	}

	StringBuilder& append(float number) {
		_buffer.append(std::to_string(number));
		return *this;
	}

	std::string build() const& {
		return _buffer;
	}

	std::string build()&& {
		return std::move(_buffer);
	}

};
int main() {
	std::println("\n=== Тест StringBuilder ===");
	StringBuilder sb;
	sb.Reserve(64);
	sb.append("Студент набрал ").append(95).append(" из ").append(100.0f).append(" баллов");

	std::string res = sb.build();
	std::println("3. Lvalue build: '{}'", res);
	std::println("   Размер: {}", sb.build().size());

	std::string temp = StringBuilder().append("Temp ").append(123).build();
	std::println("4. Rvalue build: '{}'", temp);

	return 0;
}