struct demo
{
private:
	//ABOVE(3) : 1) 'struct' has by default public access specifier..
	
	int iNo1;
	int iNo2;
	//ABOVE(6,7) : 'characteristics'

public:
	void Scan();
	void Print();
	int Add();
	//ABOVE(11,12,13) : 'behaviour'
};
