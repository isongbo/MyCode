// 数据访问对象(DAO)
// 通过引入抽象降低业务逻辑和数据存储的耦合
// 通过增加工厂类型进一步降低业务逻辑和数据
// 存储的耦合
// 通过抽象工程生产抽象产品，通过具体工厂生
// 产具体产品
// ————抽象工厂模式
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
class Department {};
class DaoDepartment {
public:
	virtual ~DaoDepartment (void) {}
	virtual void insert (
		Department const& department)const=0;
	virtual Department select (
		int id) const = 0;
};
class SQLServerDepartment :
	public DaoDepartment {
public:
	void insert (
		Department const& department) const {
		cout << "在SQLServer数据库中"
			"插入部门记录..." << endl;
	}
	Department select (int id) const {
		cout << "在SQLServer数据库中"
			"查询部门记录..." << endl;
	}
};
class OracelDepartment :
	public DaoDepartment {
public:
	void insert (
		Department const& department) const {
		cout << "在Oracel数据库中"
			"插入部门记录..." << endl;
	}
	Department select (int id) const {
		cout << "在Oracel数据库中"
			"查询部门记录..." << endl;
	}
};
class DaoFactory {
public:
	virtual ~DaoFactory (void) {}
	virtual DaoEmployee* createEmployee (
		void) const = 0;
	virtual DaoDepartment* createDepartment (
		void) const = 0;
};
class SQLServerFactory : public DaoFactory {
public:
	SQLServerEmployee* createEmployee (
		void) const {
		return new SQLServerEmployee;
	}
	SQLServerDepartment* createDepartment (
		void) const {
		return new SQLServerDepartment;
	}
};
class OracelFactory : public DaoFactory {
public:
	OracelEmployee* createEmployee (
		void) const {
		return new OracelEmployee;
	}
	OracelDepartment* createDepartment (
		void) const {
		return new OracelDepartment;
	}
};
void daoClient (DaoFactory const& factory) {
	DaoEmployee* daoEmployee =
		factory.createEmployee ();
	Employee employee;
	daoEmployee->insert (employee);
	employee = daoEmployee->select (123);
	delete daoEmployee;
	DaoDepartment* daoDepartment =
		factory.createDepartment ();
	Department department;
	daoDepartment->insert (department);
	department = daoDepartment->select (10);
	delete daoDepartment;
}
int main (void) {
	daoClient (SQLServerFactory ());
	daoClient (OracelFactory ());
	return 0;
}
