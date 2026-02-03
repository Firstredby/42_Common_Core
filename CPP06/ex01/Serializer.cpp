#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer&)
{
}

Serializer& Serializer::operator=(const Serializer&)
{
	return (*this);
}

Serializer::~Serializer()
{
}
uintptr_t	Serializer::serialize(void* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

void*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<void*>(raw));
}
