#ifdef __QUELIST_HEAD
struct  tick_struct
{
		unsigned int Tick_num;//Ʊ��
		long tick_get_time;//ȡ��ʱ��
		long tick_call_time;//�к�ʱ��
		long tick_finish_time;//Ʊ�����ʱ��
		long work_num;//��ɹ��Ż򴰿ں�
};
	
struct  teshutick_struct
{
		
		char	nYewuId;//������Ʊ�������ĸ�ҵ����
		short	nWindowID;//������Ʊ�ű������ĸ����ڰ��� 0��������û��ָ������
		int Tick_num;//Ʊ��
		short	nWaiNum;//������Ʊ�����Ӻ����ȴ������������Ϊ0���������Ʊ��û�ʺ���Ӻ���Ѿ�����
		long tick_get_time;//ȡ��ʱ��
		long tick_call_time;//�к�ʱ��
		long tick_finish_time;//Ʊ�����ʱ��
		long work_num;//��ɹ��Ż򴰿ں�

};

struct  window_ticking_struct
{
	short	nYewuId;//������Ʊ�������ĸ�ҵ����
	int 	Tick_num;//Ʊ�� 0����ʾû��
	long	tick_get_time;//ȡ��ʱ��
	long	tick_call_time;//�к�ʱ��
	long	tick_finish_time;//Ʊ�����ʱ��
	long	work_num;//��ɹ��Ż򴰿ں�
};	
struct  window_fenpeiticking_struct
{
		char    isTeshufou;//�Ƿ����������ȡ�� 0:��������������е� 1����������
		char	nYewuId;//������Ʊ�������ĸ�ҵ���� 
		short	fenpei_time;//�����״̬���ڵ�ʱ�䣬���Ϊ0������Ҫ���ص�������
		int  Tick_num; //Ʊ�� ��0:��ʾƱ��  
		short	nWaiNum;//������Ʊ�����Ӻ����ȴ������������Ϊ0���������Ʊ��û�ʺ���Ӻ���Ѿ�����
		long tick_get_time;//ȡ��ʱ��
		long tick_call_time;//�к�ʱ��
		long tick_finish_time;//Ʊ�����ʱ��
		long work_num;//��ɹ��Ż򴰿ں�
		long fenpei_start_time;//�������ʼʱ�� //gaojian_add_10_13
};
struct window_info_struct
{
	short	isBusy;//���������Ƿ���� 0:�������� 1����ʾ�˴���æ
    short   isStop;
	short	current_worknum;//�˴��ڵ�½�Ĺ���
	struct  window_ticking_struct dealingorlasttick;//�������ڴ���������ǰһ��Ʊ��
	struct  window_fenpeiticking_struct fenpeitick;//�˴������ڷ����Ʊ��
	unsigned char window_yewu_info[18];//���ڵ�ҵ����Ϣ������ҵ�����ȼ��Ļ�����Ϣ
	long busyTime;//����ʱ��
};
struct show_tick_info_struct
{
	unsigned char nWindowNo;//���ں�
	unsigned char nYewuNo;//ҵ���
	int tick;//Ʊ��
	long fenpei_start_time;//��Ʊ�ŵķ�����ʼʱ�� gaojian_add_10_13
};
#endif	
 