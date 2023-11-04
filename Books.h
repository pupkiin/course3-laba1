#include <fstream>
#include "Keeper.h"
using namespace std;

class Books {
public:
	Books();
	virtual ~Books();
	virtual void p() = 0;
};
