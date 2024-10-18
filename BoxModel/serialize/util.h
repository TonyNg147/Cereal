#pragma once

#include <cereal/archives/xml.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/types/polymorphic.hpp>



// We need to define the designated function for XMLOutputArchive
// and XMLInputArchive like extern template void below
// Without the existance of them, Cereal won't be able to find the correct
// implementation for the serialization


#define SPLIT_SERIALIZATION_EXTERN(CLASS) \
    template<typename Ar> \
	void save(Ar&, const CLASS&,uint32_t); \
    template<typename Ar> \
	void load(Ar&, CLASS&,uint32_t); \
	extern template void save(cereal::XMLOutputArchive &, const CLASS &,     \
						  std::uint32_t);                                    \
	extern template void load(cereal::XMLInputArchive &, CLASS &, std::uint32_t);

#define SERIALIZATION_INSTANTIATE_ARCHIVE(CLASS) \
	template \
	void save(cereal::XMLOutputArchive&, const CLASS&,uint32_t); \
	template \
	void load(cereal::XMLInputArchive&, CLASS&,uint32_t);
