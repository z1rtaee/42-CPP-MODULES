#include "iter.hpp"
#include <string>
#include <cctype>

/*my main*/

template <typename T>
void printElement(const T &value) {
	std::cout << value << std::endl;
}

template <typename T>
void increment(T &value) {
	value += 1;
}

void toUpperChar(char &c) {
	c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

struct Student {
	std::string name;
	int grade;

	Student(const std::string &n = "", int g = 0) : name(n), grade(g) {}
};

std::ostream &operator<<(std::ostream &o, const Student &student) {
	o << student.name << " (" << student.grade << ")";
	return (o);
}

void boostGrade(Student &student) {
	student.grade += 5;
}

int main(void) {
	std::cout << "######### ITER TESTS (ex01) #########" << std::endl;

	std::cout << "\n[Phase 1] int array print" << std::endl;
	int numbers[] = {1, 2, 3, 4, 5};
	iter(numbers, 5, printElement<int>);

	std::cout << "\n[Phase 2] int array mutate (increment)" << std::endl;
	iter(numbers, 5, increment<int>);
	iter(numbers, 5, printElement<int>);

	std::cout << "\n[Phase 3] const string array print" << std::endl;
	const std::string words[] = {"hello", "from", "cpp07", "iter"};
	iter(words, 4, printElement<std::string>);

	std::cout << "\n[Phase 4] char array mutate (toupper)" << std::endl;
	char letters[] = {'a', 'b', 'c', 'd'};
	iter(letters, 4, toUpperChar);
	iter(letters, 4, printElement<char>);

	std::cout << "\n[Phase 5] custom type mutate/print" << std::endl;
	Student team[] = {
		Student("Ana", 12),
		Student("Joao", 15),
		Student("Rita", 9)
	};
	std::cout << "Before boost:" << std::endl;
	iter(team, 3, printElement<Student>);
	iter(team, 3, boostGrade);
	std::cout << "After boost:" << std::endl;
	iter(team, 3, printElement<Student>);

	std::cout << "\n[Phase 6] null pointer safety" << std::endl;
	int *nullArray = NULL;
	iter(nullArray, 5, printElement<int>);
	std::cout << "No crash with NULL array pointer." << std::endl;

	std::cout << "\n######### END OF TESTS #########" << std::endl;
	return (0);
}
