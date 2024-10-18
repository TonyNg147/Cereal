#pragma once
#include <QAbstractListModel>
#include "BoxInfo.h"
#include <serializeDeclare.h>

class BoxListModel: public QAbstractListModel{
	Q_OBJECT
    private:

    enum Role{
		BoxX = Qt::UserRole+1,
		BoxY,
        Color
    };
    
    public:
        BoxListModel(QObject* parent=nullptr);

        ~BoxListModel();

		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const final;

		int	rowCount(const QModelIndex &parent = QModelIndex()) const final;

        QHash<int,QByteArray> roleNames() const final;

        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) final;

		void addBox(const BoxInfo&);

    public slots:

        void createNewBox();

    private:
		std::vector<BoxInfo> m_boxes;

		CEREAL_FRIEND_SPLIT_SERIALIZATION_VERSION(BoxListModel);
};
