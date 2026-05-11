#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "serializer";
	data.value = 3.14159;

	Data *original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data *restored = Serializer::deserialize(raw);

	std::cout << "original: " << original << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "restored: " << restored << std::endl;
	std::cout << "match: " << (original == restored ? "true" : "false") << std::endl;

	return 0;
}
