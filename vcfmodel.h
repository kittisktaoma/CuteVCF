#ifndef VCFMODEL_H
#define VCFMODEL_H
#include <QtCore>
#include "vcfline.h"
#include "tabix.hpp"
using namespace  std;

class VcfModel : public QAbstractListModel
{
public:

    VcfModel(QObject * parent = Q_NULLPTR);

    void setRegion(const QString& region);
    QString filename() const;
    void setFilename(const QString &filename);
    const VcfLine& line(const QModelIndex& index);



protected:
     int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
     int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
     QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
     QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;


private:
     QList<VcfLine> mLines;
     QString mFilename;
      Tabix mTabixFile;



};

#endif // VCFMODEL_H
