#ifndef ABTRANSACTIONDETAIL_H
#define ABTRANSACTIONDETAIL_H

#include "ui_ABTransactionDetail.h"
#include "ABDefines.h"

class ABTransactionDetail : public QDialog {
    Q_OBJECT

    Ui_ABTransactionDetailDialog *ui;
    TransactionType m_dialogType;
    bool            m_bDataChanged;

public:
    QString m_strCategory;
    int     m_iYear, m_iMonth, m_iDay, m_iHour, m_iMinute;
    double  m_fSum;
    QString m_strFromAccount;
    QString m_strToAccount;
    QString m_strDetail;

    bool    m_bNewCategory;
    bool    m_bNewToAccount;

public:
    ABTransactionDetail(TransactionType dialogType, QWidget *parent = 0);
    virtual ~ABTransactionDetail();

    void            setInitData(QDate date,
                                QTime time,
                                ABCategory category,
                                QString fromAccount,
                                QString toAccount,
                                double sum,
                                QString detail);

    QString         getTypeStr();
    TransactionType getType();

    bool            isDataChanged();

private:
    void initUiByType(TransactionType dialogType);
    void initConnection();

private slots:
    void accept();

    void slotChangeDataSpinValue();
    void slotSelectCalenderWidget();
    void slotCalenderWidgetPageChange();

    void slotChangeDate(QDate);
    void slotChangeTime(QTime);
    void slotChangeSum(double);
    void slotChangeDetail(QString);

    void slotChangeCategory();
    void slotChangeFromAccount(QString);
    void slotChangeToAccount();
};

#endif // ABTRANSACTIONDETAIL_H
