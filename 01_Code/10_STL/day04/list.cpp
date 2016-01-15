// 双向线性链表容器
#include <cstring>
#include <iostream>
#include <stdexcept>
using namespace std;
// 链表模板
template<typename T>
class List {
public:
	// 构造、析构、拷贝构造、拷贝赋值
	List (void) : m_head (NULL),
		m_tail (NULL) {}
	~List (void) {
		clear ();
	}
	List (List const& that) : m_head (NULL),
		m_tail (NULL) {
		for (Node* node = that.m_head;
				node; node = node->m_next)
			push_back (node->m_data);
	}
	List& operator= (List const& rhs) {
		if (&rhs != this) {
			List list = rhs;
			swap (m_head, list.m_head);
			swap (m_tail, list.m_tail);
		}
		return *this;
	}
	// 获取首元素
	T& front (void) {
		if (empty ())
			throw underflow_error (
				"链表下溢！");
		return m_head->m_data;
	}
	T const& front (void) const {
		return const_cast<List*> (
			this)->front ();
	}
	// 向首部压入
	void push_front (T const& data) {
		m_head = new Node (data, NULL,m_head);
		if (m_head->m_next)
			m_head->m_next->m_prev = m_head;
		else
			m_tail = m_head;
	}
	// 从首部弹出
	void pop_front (void) {
		if (empty ())
			throw underflow_error (
				"链表下溢！");
		Node* next = m_head->m_next;
		delete m_head;
		m_head = next;
		if (m_head)
			m_head->m_prev = NULL;
		else
			m_tail = NULL;
	}
	// 获取尾元素
	T& back (void) {
		if (empty ())
			throw underflow_error (
				"链表下溢！");
		return m_tail->m_data;
	}
	T const& back (void) const {
		return const_cast<List*> (
			this)->back ();
	}
	// 向尾部压入
	void push_back (T const& data) {
		m_tail = new Node (data, m_tail);
		if (m_tail->m_prev)
			m_tail->m_prev->m_next = m_tail;
		else
			m_head = m_tail;
	}
	// 从尾部弹出
	void pop_back (void) {
		if (empty ())
			throw underflow_error (
				"链表下溢！");
		Node* prev = m_tail->m_prev;
		delete m_tail;
		m_tail = prev;
		if (m_tail)
			m_tail->m_next = NULL;
		else
			m_head = NULL;
	}
	// 删除所有匹配元素
	void remove (T const& data) {
		for (Node* node = m_head, *next;
			node; node = next) {
			next = node->m_next;
			if (equal (node->m_data, data)) {
				if (node->m_prev)
					node->m_prev->m_next =
						node->m_next;
				else
					m_head = node->m_next;
				if (node->m_next)
					node->m_next->m_prev =
						node->m_prev;
				else
					m_tail = node->m_prev;
				delete node;
			}
		}
	}
	// 清空
	void clear (void) {
		for (Node* next; m_head;
			m_head = next) {
			next = m_head->m_next;
			delete m_head;
		}
		m_tail = NULL;
	}
	// 判空
	bool empty (void) const {
		return ! m_head && ! m_tail;
	}
	// 大小
	size_t size (void) const {
		size_t counter = 0;
		for (Node* node = m_head; node;
			node = node->m_next)
			++counter;
		return counter;
	}
	// 下标，性能不佳
	T& operator[] (size_t i) {
		for (Node* node = m_head; node;
			node = node->m_next)
			if (i-- == 0)
				return node->m_data;
		throw out_of_range ("下标越界！");
	}
	// 输出
	friend ostream& operator<< (ostream& os,
		List const& list) {
		for (Node* node = list.m_head; node;
			node = node->m_next)
			os << *node;
		return os;
	}
private:
	// 节点模板
	class Node {
	public:
		Node (T const& data,
			Node* prev = NULL,
			Node* next = NULL) :
			m_data (data), m_prev (prev),
			m_next (next) {}
		friend ostream& operator<< (
			ostream& os, Node const& node) {
			return os << '[' << node.m_data
				<< ']';
		}
		T     m_data; // 数据
		Node* m_prev; // 前指针
		Node* m_next; // 后指针
	};
	// 相等性判断函数的通用版本
	bool equal (T const& a, T const& b) const{
		return a == b;
	}
	Node* m_head; // 头指针
	Node* m_tail; // 尾指针
public:
	// 正向迭代器
	class Iterator {
	public:
		Iterator (Node* head = NULL,
			Node* tail = NULL,
			Node* node = NULL) :
			m_head (head), m_tail (tail),
			m_node (node) {}
		bool operator== (
			Iterator const& rhs) const {
			return m_node == rhs.m_node;
		}
		bool operator!= (
			Iterator const& rhs) const {
			return ! (*this == rhs);
		}
		Iterator& operator++ (void) {
			if (m_node)
				m_node = m_node->m_next;
			else
				m_node = m_head;
			return *this;
		}
		Iterator const operator++ (int) {
			Iterator old = *this;
			++*this;
			return old;
		}
		Iterator& operator-- (void) {
			if (m_node)
				m_node = m_node->m_prev;
			else
				m_node = m_tail;
			return *this;
		}
		Iterator const operator-- (int) {
			Iterator old = *this;
			--*this;
			return old;
		}
		T& operator* (void) const {
			return m_node->m_data;
		}
		T* operator-> (void) const {
			return &**this;
		}
	private:
		Node* m_head;
		Node* m_tail;
		Node* m_node;
		friend class List;
	};
	// 获取起始正向迭代器
	Iterator begin (void) {
		return Iterator (m_head, m_tail,
			m_head);
	}
	// 获取终止正向迭代器
	Iterator end (void) {
		return Iterator (m_head, m_tail);
	}
	// 常正向迭代器：ConstIterator
	// 反向迭代器：ReverseIterator
	// 常反向迭代器：ConstReverseIterator
	// 在给定迭代器所标识的元素之前插入
	Iterator insert (Iterator loc,
		T const& data) {
		if (loc == end ()) {
			push_back (data);
			return Iterator (m_head, m_tail,
				m_tail);
		}
		else {
			Node* node = new Node (data,
				loc.m_node->m_prev,
				loc.m_node);
			if (node->m_prev)
				node->m_prev->m_next = node;
			else
				m_head = node;
			node->m_next->m_prev = node;
			return Iterator (m_head, m_tail,
				node);
		}
	}
	// 删除给定迭代器所标识的元素
	Iterator erase (Iterator loc) {
		if (loc == end ())
			throw invalid_argument (
				"无效参数！");
		if (loc.m_node->m_prev)
			loc.m_node->m_prev->m_next =
				loc.m_node->m_next;
		else
			m_head = loc.m_node->m_next;
		if (loc.m_node->m_next)
			loc.m_node->m_next->m_prev =
				loc.m_node->m_prev;
		else
			m_tail = loc.m_node->m_prev;
		Node* next = loc.m_node->m_next;
		delete loc.m_node;
		return Iterator (m_head, m_tail,next);
	}
};
// 相等性判断函数针对char const*类型的特化版本
template<>
bool List<char const*>::equal (
	char const* const& a,
	char const* const& b) const {
	return ! strcmp (a, b);
}
// 线性查找
template<typename IT, typename T>
IT find (IT begin, IT end, T key) {
	IT it;
	for (it = begin; it != end; ++it)
		if (*it == key)
			break;
	return it;
}
// 测试用例
void test1 (void) {
	List<int> list;
	list.push_front (50);
	list.push_front (40);
	list.push_front (30);
	list.push_front (20);
	list.push_front (10);
	cout << list << endl; // 10 20 30 40 50
	++list.front ();
	cout << list << endl; // 11 20 30 40 50
	List<int> const& cr = list;
//	cr.front () = 10;
	cout << cr.front () << endl;
	list.pop_front ();
	cout << list << endl; // 20 30 40 50
	list.push_back (60);
	list.push_back (70);
	list.push_back (80);
	list.push_back (90);
	cout << list << endl;
	// 20 30 40 50 60 70 80 90
	list.back () -= 5;
	cout << list << endl;
	// 20 30 40 50 60 70 80 85
	List<int> const* cp = &list;
//	cp->back () = 90;
	cout << cp->back () << endl;
	list.pop_back ();
	cout << list << endl;
	// 20 30 40 50 60 70 80
	list.push_back (20);
	list.push_back (90);
	list.push_back (20);
	cout << list << endl;
	// 20 30 40 50 60 70 80 20 90 20
	list.remove (20);
	cout << list << endl;
	// 30 40 50 60 70 80 90
	cout << list.size () << endl; // 7
	cout << boolalpha << list.empty() << endl;
	// false
	list.clear ();
	cout << list.size () << endl; // 0
	cout << list.empty () << endl; // true
	list.push_back (100);
	list.push_back (200);
	list.push_back (300);
	List<int> list2 = list; // 拷贝构造
	cout << list << endl; // 100 200 300
	cout << list2 << endl; // 100 200 300
	list.pop_front ();
	list2.back ()++;
	cout << list << endl; // 200 300
	cout << list2 << endl; // 100 200 301
	list = list2; // 拷贝赋值
	cout << list << endl; // 100 200 301
	cout << list2 << endl; // 100 200 301
	list.front ()--;
	list2.pop_back ();
	cout << list << endl; // 99 200 301
	cout << list2 << endl; // 100 200
}
void test2 (void) {
	char sa[][256] = {"北京", "上海",
		"北京", "天津", "重庆", "北京",
		"广州"};
//	char const* sa[] = {"北京", "上海",
//		"北京", "天津", "重庆", "北京",
//		"广州"};
//	List<string> list;
	List<char const*> list;
	for (size_t i = 0; i < sizeof (sa) /
		sizeof (sa[0]); ++i)
		list.push_back (sa[i]);
	cout << list << endl;
	list.remove ("北京");
	cout << list << endl;
}
void test3 (void) {
	List<int> list;
	list.push_back (10);
	list.push_back (20);
	list.push_back (30);
	list.push_back (40);
	list.push_back (50);
	cout << list << endl; // 10 20 30 40 50
	++list[2];
	cout << list << endl;
	size_t size = list.size ();
	// O(N^2)
	for (size_t i = 0; i < size; ++i)
		cout << list[i] << endl;
	List<int>::Iterator it = list.begin ();
	++++++it;
	*it = 45;
	cout << list << endl;
	// O(N)
	for (it = list.begin (); it != list.end();
		it++)
		cout << *it << endl;
	cout << "--------" << endl;
	for (--it; it != list.end (); --it)
		cout << *it << endl;
}
void test4 (void) {
	List<char> list;
	list.insert (list.end (), 'A');
	list.insert (list.end (), 'D');
	list.insert (list.end (), 'G');
	cout << list << endl; // ADG
	List<char>::Iterator loc = list.begin ();
	list.insert (
		list.insert (++loc, 'C'), 'B');
	cout << list << endl; // ABCDG
	loc = list.end ();
	list.insert (
		list.insert (--loc, 'F'), 'E');
	cout << list << endl; // ABCDEFG
	loc = list.begin ();
	++++loc;
	list.erase (
		list.erase (
			list.erase (loc)));
	cout << list << endl; // ABFG
	List<int> li;
	li.push_back (13);
	li.push_back (22);
	li.push_back (17);
	li.push_back (19);
	li.push_back (28);
	li.push_back (34);
	li.push_back (44);
	li.push_back (15);
	cout << li << endl;
	List<int>::Iterator it = li.begin ();
	while (it != li.end ()) {
		if (*it % 2 == 0)
			it = li.erase (it);
			// delete it.m_node
		else
			++it;
			// m_node = m_node->m_next
	}
	cout << li << endl;
}
void test5 (void) {
	int arr[] = {13, 33, 19, 27, 48};
	int* pi = find (&arr[0], &arr[5],
		19/*17*/);
	if (pi == &arr[5])
		cout << "没找到！" << endl;
	else
		cout << "找到了：" << *pi << endl;
	List<string> ls;
	ls.push_back ("济南");
	ls.push_back ("滨州");
	ls.push_back ("菏泽");
	ls.push_back ("临沂");
	ls.push_back ("青岛");
	List<string>::Iterator it = find (
		ls.begin (), ls.end (),
		"菏泽"/*"淄博"*/);
	if (it == ls.end ())
		cout << "没找到！" << endl;
	else
		cout << "找到了：" << *it << endl;
}
int main (void) {
//	test1 ();
//	test2 ();
//	test3 ();
//	test4 ();
	test5 ();
	return 0;
}
