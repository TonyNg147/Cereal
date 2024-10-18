#pragma once


#include "../BoxModel/BoxInfo.h"
#include "util.h"

CEREAL_CLASS_VERSION(BoxInfo, 401)

SPLIT_SERIALIZATION_EXTERN(BoxInfo)

CEREAL_SPECIALIZE_FOR_ALL_ARCHIVES(BoxInfo, cereal::specialization::non_member_load_save)
