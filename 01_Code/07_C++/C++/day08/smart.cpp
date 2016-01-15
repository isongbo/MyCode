#include <iostream>
using namespace std;
// 电话
class Phone {
public:
	Phone (string const& no) : m_no (no) {
		cout << "Phone构造：" << this << endl;
	}
	~Phone (void) {
		cout << "Phone析构：" << this << endl;
	}
	void call (string const& no) {
		cout << m_no << "呼叫" << no << endl;
	}
private:
	string m_no;
};
// 播放器
class Player {
public:
	Player (string const& media) :
		m_media (media) {
		cout << "Player构造：" << this
			<< endl;
	}
	~Player (void) {
		cout << "Player析构：" << this
			<< endl;
	}
	void play (string const& clip) {
		cout << m_media << "播放" << clip
			<< endl;
	}
private:
	string m_media;
};
// 电脑
class Computer {
public:
	Computer (string const& os) : m_os (os) {
		cout << "Computer构造：" << this
			<< endl;
	}
	~Computer (void) {
		cout << "Computer析构：" << this
			<< endl;
	}
	void run (string const& app) {
		cout << "在" << m_os << "上运行"
			<< app << endl;
	}
private:
	string m_os;
};
// 智能手机
class SmartPhone : public Phone,
	public Player, public Computer {
public:
	SmartPhone (string const& no,
		string const& media,
		string const& os) : 
		Phone (no), Player (media),
		Computer (os) {
		cout << "SmartPhone构造：" << this
			<< endl;
	}
	~SmartPhone (void) {
		cout << "SmartPhone析构：" << this
			<< endl;
	}
};
int main (void) {
	SmartPhone sp ("13910110072",
		"MP3/MP4/3GP", "Android");
	sp.call ("01062332018");
	sp.play ("小苹果");
	sp.run ("C++大战Java");
	Phone* pPhone = &sp;
	cout << "&sp = " << &sp << endl;
	cout << "pPhone = "<< pPhone << endl;
	Player* pPlayer = &sp;
	cout << "pPlayer = " << pPlayer << endl;
	Computer* pComputer = &sp;
	cout << "pComputer = " << pComputer
		<< endl;
	/*
	SmartPhone* pSmart =
		static_cast<SmartPhone*> (pComputer);
	*//*
	SmartPhone* pSmart =
		(SmartPhone*)pComputer;
	*/
	SmartPhone* pSmart =
		reinterpret_cast<SmartPhone*> (
			pComputer);
	cout << "pSmart = " << pSmart << endl;
	return 0;
}
