#pragma once

#include <stdint.h>

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);
	~Serializer();
public:
	static uintptr_t	serialize(void* ptr);
	static void*		deserialize(uintptr_t raw);
};
