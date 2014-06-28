/****\
|  File Name: Logger.hpp
|  Description: declares Logger class
\****/


/****\
|  Class Name: Logger
|  Description: Wrapper class simplifying event log output
\****/
class Logger
	{
	public:
		Info(const char* msg);
		Warn(char* msg);
		Error(char* msg);
	};
/** end class Logger **/
