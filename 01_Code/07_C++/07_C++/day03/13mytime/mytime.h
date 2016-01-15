#ifndef  MYTIME_H
#define  MYTIME_H
extern  int  g_var;
void  show();
class  MyTime{
    private:
	int  hour;
	int  min;
	int  sec;
	public:
	MyTime(int hour=0,int min=0,int sec=0);
	void  setTime(int h=12,int m=0,int s=0);
    void  show();
};
#endif
