#include "BoxListModel_s.h"
#include <cereal/types/vector.hpp>
using namespace cereal;

template<typename Archive>
void load(Archive &ar, BoxListModel& boxListModel, uint32_t)
{

	ar(make_nvp("boxes",boxListModel.m_boxes));
}

template <typename Archive>
void save(Archive &ar, const BoxListModel &boxListModel, uint32_t)
{
	using namespace cereal;
	ar(make_nvp("boxes",boxListModel.m_boxes));
}


SERIALIZATION_INSTANTIATE_ARCHIVE(BoxListModel)
