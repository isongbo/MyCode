#ifndef DATE_H
#define DATE_H
class  Date{
	private:
    int  year;
	int  month;
	int  day;
	public:
	Date(int year=2015,int month=1,int day=1);
    void setDate(int year=1970,int month=1,
		int  day=1);
	void show();
};
#endif
