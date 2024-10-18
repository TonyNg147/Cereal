#pragma once
#include "util.h"
#include "../BoxListModel.h"
#include "BoxInfo_s.h"
#include <cereal/types/vector.hpp>

CEREAL_REGISTER_TYPE(BoxListModel)
CEREAL_CLASS_VERSION(BoxListModel, 401)


SPLIT_SERIALIZATION_EXTERN(BoxListModel)
CEREAL_SPECIALIZE_FOR_ALL_ARCHIVES(BoxListModel, cereal::specialization::non_member_load_save)

