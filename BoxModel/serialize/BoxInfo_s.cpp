#include "BoxInfo_s.h"

using namespace cereal;

template<typename Archive>
void load(Archive &ar, BoxInfo& box, uint32_t version)
{

	ar(
		make_nvp("x",box.x),
		make_nvp("y",box.y),
		make_nvp("color",box.color)
	);
}

template <typename Archive>
void save(Archive &ar, const BoxInfo &box, uint32_t)
{
	using namespace cereal;
	ar(
		make_nvp("x",box.x),
		make_nvp("y",box.y),
		make_nvp("color",box.color)
	);
}

SERIALIZATION_INSTANTIATE_ARCHIVE(BoxInfo)
