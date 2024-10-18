#include "BoxStorage.h"

#include <serialize/util.h>
#include <fstream>
#include <serialize/BoxInfo_s.h>
#include <serialize/BoxListModel_s.h>

namespace{
	const std::string storageLocation = "Boxes4.xml";
}

BoxStorage::BoxStorage(QObject* parent)
    :QObject{parent}
{
	m_model = std::make_shared<BoxListModel>();
	QObject::connect(m_model.get(),&QAbstractListModel::dataChanged,this,[this](const QModelIndex &, const QModelIndex &, QVector<int>){
		save();
	});
	load();
}

BoxStorage::~BoxStorage()
{
	save();
}

BoxListModel* BoxStorage::getBoxListModel()
{
	return m_model.get();
}

void BoxStorage::save(){
    std::ofstream output(storageLocation);
	cereal::XMLOutputArchive archive(output);
	archive(m_model);
}

void BoxStorage::load(){
    std::ifstream input(storageLocation);
    if (input){
        cereal::XMLInputArchive archive(input);
        archive(m_model);
    }
}
