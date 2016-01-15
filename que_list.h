#ifdef __QUELIST_HEAD
struct  tick_struct
{
		unsigned int Tick_num;//票号
		long tick_get_time;//取号时间
		long tick_call_time;//叫号时间
		long tick_finish_time;//票号完成时间
		long work_num;//完成工号或窗口号
};
	
struct  teshutick_struct
{
		
		char	nYewuId;//表明此票号是在哪个业务内
		short	nWindowID;//表明此票号必须在哪个窗口办理 0：表明是没有指定窗口
		int Tick_num;//票号
		short	nWaiNum;//表明此票号在延后所等待的人数，如果为0，则表明此票号没咽喉或延后后已经结束
		long tick_get_time;//取号时间
		long tick_call_time;//叫号时间
		long tick_finish_time;//票号完成时间
		long work_num;//完成工号或窗口号

};

struct  window_ticking_struct
{
	short	nYewuId;//表明此票号是在哪个业务内
	int 	Tick_num;//票号 0：表示没有
	long	tick_get_time;//取号时间
	long	tick_call_time;//叫号时间
	long	tick_finish_time;//票号完成时间
	long	work_num;//完成工号或窗口号
};	
struct  window_fenpeiticking_struct
{
		char    isTeshufou;//是否特殊队列里取的 0:表明不是特殊队列的 1：表名内是
		char	nYewuId;//表明此票号是在哪个业务内 
		short	fenpei_time;//分配的状态存在的时间，如果为0，则需要返回到队列中
		int  Tick_num; //票号 》0:表示票号  
		short	nWaiNum;//表明此票号在延后所等待的人数，如果为0，则表明此票号没咽喉或延后后已经结束
		long tick_get_time;//取号时间
		long tick_call_time;//叫号时间
		long tick_finish_time;//票号完成时间
		long work_num;//完成工号或窗口号
		long fenpei_start_time;//分配的起始时间 //gaojian_add_10_13
};
struct window_info_struct
{
	short	isBusy;//表明窗口是否空闲 0:表明空闲 1：表示此窗口忙
    short   isStop;
	short	current_worknum;//此窗口登陆的工号
	struct  window_ticking_struct dealingorlasttick;//窗口正在处理或处理完的前一个票号
	struct  window_fenpeiticking_struct fenpeitick;//此窗口正在分配的票号
	unsigned char window_yewu_info[18];//窗口的业务信息，包含业务优先级的基本信息
	long busyTime;//空闲时间
};
struct show_tick_info_struct
{
	unsigned char nWindowNo;//窗口号
	unsigned char nYewuNo;//业务号
	int tick;//票号
	long fenpei_start_time;//此票号的分配起始时间 gaojian_add_10_13
};
#endif	
 