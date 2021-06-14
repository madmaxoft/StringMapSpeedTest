#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <QString>
#include <QVariant>
#include <QElapsedTimer>




/** Number of containers to create. */
static const int NUM_CONTAINERS = 50000;

/** Number of items to insert into each container. */
static const int NUM_ITEMS = 30;





void runQMapQString()
{
	QElapsedTimer timer;
	timer.start();

	using ContainerType = QMap<QString, QVariant>;
	std::vector<ContainerType> containers;
	containers.reserve(NUM_CONTAINERS);
	for (int i = 0; i < NUM_CONTAINERS; ++i)
	{
		ContainerType container;
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			QString key("minecraft");
			key[5] = 'A' + j;
			container[key] = QString("SomeValue");
		}
		containers.push_back(std::move(container));
	}
	std::cout << "QMapQString: Filling  the containers took " << timer.elapsed() << " msec" << std::endl;

	timer.restart();
	containers.clear();
	std::cout << "QMapQString: Clearing the containers took " << timer.elapsed() << " msec" << std::endl;
}





void runStdMapQString()
{
	QElapsedTimer timer;
	timer.start();

	using ContainerType = std::map<QString, QVariant>;
	std::vector<ContainerType> containers;
	containers.reserve(NUM_CONTAINERS);
	for (int i = 0; i < NUM_CONTAINERS; ++i)
	{
		ContainerType container;
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			QString key("minecraft");
			key[5] = 'A' + j;
			container[key] = QString("SomeValue");
		}
		containers.push_back(std::move(container));
	}
	std::cout << "StdMapQString: Filling  the containers took " << timer.elapsed() << " msec" << std::endl;

	timer.restart();
	containers.clear();
	std::cout << "StdMapQString: Clearing the containers took " << timer.elapsed() << " msec" << std::endl;
}





void runStdMapStdString()
{
	QElapsedTimer timer;
	timer.start();

	using ContainerType = std::map<std::string, QVariant>;
	std::vector<ContainerType> containers;
	containers.reserve(NUM_CONTAINERS);
	for (int i = 0; i < NUM_CONTAINERS; ++i)
	{
		ContainerType container;
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			std::string key("minecraft");
			key[5] = 'A' + j;
			container[key] = QString("SomeValue");
		}
		containers.push_back(std::move(container));
	}
	std::cout << "StdMapStdString: Filling  the containers took " << timer.elapsed() << " msec" << std::endl;

	timer.restart();
	containers.clear();
	std::cout << "StdMapStdString: Clearing the containers took " << timer.elapsed() << " msec" << std::endl;
}





void runQMapStdString()
{
	QElapsedTimer timer;
	timer.start();

	using ContainerType = QMap<std::string, QVariant>;
	std::vector<ContainerType> containers;
	containers.reserve(NUM_CONTAINERS);
	for (int i = 0; i < NUM_CONTAINERS; ++i)
	{
		ContainerType container;
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			std::string key("minecraft");
			key[5] = 'A' + j;
			container[key] = QString("SomeValue");
		}
		containers.push_back(std::move(container));
	}
	std::cout << "QMapStdString: Filling  the containers took " << timer.elapsed() << " msec" << std::endl;

	timer.restart();
	containers.clear();
	std::cout << "QMapStdString: Clearing the containers took " << timer.elapsed() << " msec" << std::endl;
}





void runStdUnorderedMapQString()
{
	QElapsedTimer timer;
	timer.start();

	using ContainerType = std::unordered_map<QString, QVariant>;
	std::vector<ContainerType> containers;
	containers.reserve(NUM_CONTAINERS);
	for (int i = 0; i < NUM_CONTAINERS; ++i)
	{
		ContainerType container;
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			QString key("minecraft");
			key[5] = 'A' + j;
			container[key] = QString("SomeValue");
		}
		containers.push_back(std::move(container));
	}
	std::cout << "StdUnorderedMapQString: Filling  the containers took " << timer.elapsed() << " msec" << std::endl;

	timer.restart();
	containers.clear();
	std::cout << "StdUnorderedMapQString: Clearing the containers took " << timer.elapsed() << " msec" << std::endl;
}





void runStdUnorderedMapStdString()
{
	QElapsedTimer timer;
	timer.start();

	using ContainerType = std::unordered_map<std::string, QVariant>;
	std::vector<ContainerType> containers;
	containers.reserve(NUM_CONTAINERS);
	for (int i = 0; i < NUM_CONTAINERS; ++i)
	{
		ContainerType container;
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			std::string key("minecraft");
			key[5] = 'A' + j;
			container[key] = QString("SomeValue");
		}
		containers.push_back(std::move(container));
	}
	std::cout << "StdUnorderedMapStdString: Filling  the containers took " << timer.elapsed() << " msec" << std::endl;

	timer.restart();
	containers.clear();
	std::cout << "StdUnorderedMapStdString: Clearing the containers took " << timer.elapsed() << " msec" << std::endl;
}





int main(int, char *[])
{
	runQMapQString();
	runStdMapQString();
	runStdMapStdString();
	runQMapStdString();
	runStdUnorderedMapQString();
	runStdUnorderedMapStdString();

	// MSVC: Put a breakpoint on the following line to keep the program from terminating without seeing the output, when run in the debugger
	std::cout << "All done." << std::endl;
}
