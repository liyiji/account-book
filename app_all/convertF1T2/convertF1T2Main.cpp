
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMessageBox::critical(0,
                          "Error",
                          "This Program is not finished.");

    return 1;
}
