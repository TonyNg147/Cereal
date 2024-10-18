#pragma once
#include <cereal/archives/xml.hpp>


#define CEREAL_FRIEND_SPLIT_SERIALIZATION_VERSION(Class) \
	template<typename Archive> \
	friend void load(Archive& ar, Class&, uint32_t); \
	template<typename Archive> \
	friend void save(Archive& ar, const Class&, uint32_t);