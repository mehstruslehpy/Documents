#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QLabel *label = new QLabel("<h2><i>Howdy friendo!</i>""<b><font color=red> Welcome to my header.</font></b></h2>");
	label->show();
	return app.exec();
}
