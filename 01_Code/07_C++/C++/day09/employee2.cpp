// 数据访问对象(DAO)
// 通过引入抽象降低业务逻辑和数据存储的耦合
#include <iostream>
using namespace std;
class Employee {};
class DaoEmployee {
public:
	virtual ~DaoEmployee (void) {}
	virtual void insert (
		Employee const& employee) const = 0;
	virtual Employee select (
		int id) const = 0;
};
class SQLServerEmployee : public DaoEmployee {
public:
	void insert (
		Employee const& employee) const {
		cout << "在SQLServer数据库中"
			"插入员工记录..." << endl;
	}
	Employee select (int id) const {
		cout << "在SQLServer数据库中"
			"查询员工记录..." << endl;
	}
};
class OracelEmployee : public DaoEmployee {
public:
	void insert (
		Employee const& employee) const {
		cout << "在Oracel数据库中"
			"插入员工记录..." << endl;
	}
	Employee select (int id) const {
		cout << "在Oracel数据库中"
			"查询员工记录..." << endl;
	}
};
void daoClient (
	DaoEmployee const& daoEmployee) {
	Employee employee;
	daoEmployee.insert (employee);
	employee = daoEmployee.select (123);
}
int main (void) {
	daoClient (SQLServerEmployee ());
	daoClient (OracelEmployee ());
	return 0;
}
