/****\
|  File Name: Logger.hpp
|  Description: declares Logger class
\****/

/*// includes //*/
#include <string>
/*// end includes //*/


/****\
|  Class Name: Logger
|  Description: Wrapper class simplifying event log output
\****/
class Logger
{
public:
	void Info(const char* msg);
	void Warn(char* msg);
	void Error(char* msg);
	void Create(std::string msg);
	void Destroy(std::string msg);
private:
	static unsigned int refcount;
};
/** end class Logger **/
