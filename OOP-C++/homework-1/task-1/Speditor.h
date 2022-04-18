#ifndef SPEDITOR_H
#define SPEDITOR_H

#include "ComputerStore.h"
#include "Configuration.h"
#include "Date.h"


class Speditor {
private:
	ComputerStore store;

public:
	Speditor(const ComputerStore& store);

	void processConfigurationOrder(const Configuration& config, Date date);

private:
	bool containsAllConfigsInStore(const Configuration& config) const;
	void writeOrder(const Configuration& config, Date date);
};

#endif // !SPEDITOR_H
