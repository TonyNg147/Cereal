#pragma once
#include <QObject>

class BoxListModel;
#include <BoxListModel.h>
class BoxStorage: public QObject{
    Q_OBJECT
    public:
        BoxStorage(QObject* parent=nullptr);

        ~BoxStorage();

		BoxListModel* getBoxListModel();

    private:
        void save();

        void load();

        
    private:
		std::shared_ptr<BoxListModel> m_model;

};
