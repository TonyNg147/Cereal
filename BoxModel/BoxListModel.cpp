#include "BoxListModel.h"


BoxListModel::BoxListModel(QObject* parent)
    :QAbstractListModel{parent}
{
}

BoxListModel::~BoxListModel(){

}

int BoxListModel::rowCount(const QModelIndex& index) const{
	if (index.isValid()) return 0;
	return m_boxes.size();
}

QVariant BoxListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
        return QVariant();
    }

    const int pos = index.row();
	if (pos < 0 || pos >= m_boxes.size()){
        return QVariant();
    }

    switch(role){
		case BoxListModel::Role::BoxX:{
            return m_boxes.at(pos).x;
        }
		case BoxListModel::Role::BoxY:{
            return m_boxes.at(pos).y;
        }
        case BoxListModel::Role::Color:{
			return m_boxes.at(pos).color.c_str();
        }
        default:{
            break;
        }
    }

    return QVariant();
}

bool BoxListModel::setData(const QModelIndex &id, const QVariant &value, int role)
{
	if (!id.isValid()){
        return false;
    }

	const int pos = id.row();
	if (pos < 0 || pos >= m_boxes.size()){
        return false;
    }

    bool neededToBeUpdated=false;

    switch(role){
		case BoxListModel::Role::BoxX:{
            if (const int xValue=value.toInt(); m_boxes[pos].x != xValue){
                m_boxes[pos].x = xValue;
                neededToBeUpdated=true;
            }
            break;
        }
		case BoxListModel::Role::BoxY:{
            if (const int yValue=value.toInt(); m_boxes[pos].y != yValue){
                m_boxes[pos].y = yValue;
                neededToBeUpdated=true;
            }
            break;
        }
        case BoxListModel::Role::Color:{
			if (const std::string colorValue=value.toString().toStdString(); m_boxes[pos].color != colorValue){
                m_boxes[pos].color = colorValue;
                neededToBeUpdated=true;
            }
            break;
        }
        default:{
            break;
        }
    }

    if (neededToBeUpdated){
        emit dataChanged(index(pos),index(pos),QVector<int>()<<role);
		return true;
    }

	return false;

}

QHash<int,QByteArray> BoxListModel::roleNames() const{
    return {
		{Role::BoxX,"boxX"},
		{Role::BoxY,"boxY"},
		{Role::Color,"boxColor"}
    };
}

void BoxListModel::addBox(const BoxInfo& boxInfo)
{
	const int currentSize = m_boxes.size();
	beginInsertRows(QModelIndex(),currentSize,currentSize);
    m_boxes.push_back(boxInfo);
	endInsertRows();
}

void BoxListModel::createNewBox(){
    BoxInfo info{
        .x=0,
        .y=0,
        .color="red"
    };

    addBox(info);
}

