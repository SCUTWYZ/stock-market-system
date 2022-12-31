#ifndef SUCCESS_H
#define SUCCESS_H

#include <QDialog>

namespace Ui {
class success;
}

class success : public QDialog//成功交易的反馈对话框
{
    Q_OBJECT

public:
    explicit success(QWidget *parent = nullptr);
    ~success();

private:
    Ui::success *ui;
};

#endif // SUCCESS_H
