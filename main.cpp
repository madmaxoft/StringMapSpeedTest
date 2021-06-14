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





/** Stress-tests the container.
Creates many instances and fill each one with many items, then delete all the instances.
Measures the time it takes to fill the containers and the time it takes to clear the containers. */
template <typename StringType, typename ContainerType>
void runTest(const std::string & aTestName)
{
	QElapsedTimer timer;
	timer.start();

	std::vector<ContainerType> containers;
	containers.reserve(NUM_CONTAINERS);
	for (int i = 0; i < NUM_CONTAINERS; ++i)
	{
		ContainerType container;
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			StringType key("minecraft");
			key[5] = 'A' + j;
			container[key] = QString("SomeValue");
		}
		containers.push_back(std::move(container));
	}
	std::cout << aTestName << ": Filling  the containers took " << timer.elapsed() << " msec" << std::endl;

	timer.restart();
	containers.clear();
	std::cout << aTestName << ": Clearing the containers took " << timer.elapsed() << " msec" << std::endl;
}





int main(int, char *[])
{
	runTest<QString,     QMap<QString, QVariant>>                  ("QMapQString");
	runTest<QString,     std::map<QString, QVariant>>              ("QStdMapQString");
	runTest<std::string, std::map<std::string, QVariant>>          ("StdMapStdString");
	runTest<std::string, QMap<std::string, QVariant>>              ("QMapStdString");
	runTest<QString,     std::unordered_map<QString, QVariant>>    ("StdUnorderedMapQString");
	runTest<std::string, std::unordered_map<std::string, QVariant>>("StdUnorderedMapStdString");

	// MSVC: Put a breakpoint on the following line to keep the program from terminating without seeing the output, when run in the debugger
	std::cout << "All done." << std::endl;
}
