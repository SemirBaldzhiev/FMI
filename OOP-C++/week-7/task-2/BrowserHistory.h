#ifndef BROWSER_HISTORY_H
#define	BROWSER_HISTORY_H

#include <cstdlib>
#include "Website.h"

class BrowserHistory {
private:
	Website* history;
	size_t size;

public:
	BrowserHistory();
	BrowserHistory(const BrowserHistory& other);
	BrowserHistory& operator=(const BrowserHistory& other);
	~BrowserHistory();

	void addNewSiteToHistory(const Website& newWebsite);
	Website findURL(const char* name);
	size_t getCountOfVisits(const char* name);
	void clearHistory();

	Website* getHistory() const;
	size_t getSize() const;

private:
	void copy(const BrowserHistory& other);
	void clear();

};

#endif // !BROWSER_HISTORY_H

