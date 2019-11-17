#ifndef person_h
#define person_h

class person
{
protected:
	std::string _name{""};
	int _age{ 0 };
public:
	person() = default;
	virtual ~person(){};
	virtual void printInfo() const = 0
	{
		//should be implemented in derived classes
	}
};
#endif